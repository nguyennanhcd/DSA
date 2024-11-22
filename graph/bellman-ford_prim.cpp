#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
};

void readGraph(const string& filename, vector<Edge>& edges, int& V) {
    ifstream file(filename);
    if (!file) {
        cerr << "Khong the mo tep!" << endl;
        exit(1);
    }

    string vertexLine;
    getline(file, vertexLine);
    V = count(vertexLine.begin(), vertexLine.end(), ' ') + 1;

    int u, v, w;
    while (file >> u >> v >> w) {
        edges.push_back({u, v, w});
    }

    file.close();
}

void bellmanFord(int V, int source, const vector<Edge>& edges) {
    vector<int> distance(V + 1, INT_MAX);
    vector<int> parent(V + 1, -1);
    distance[source] = 0;

    for (int i = 1; i < V; ++i) {
        for (const auto& edge : edges) {
            if (distance[edge.u] != INT_MAX && distance[edge.u] + edge.weight < distance[edge.v]) {
                distance[edge.v] = distance[edge.u] + edge.weight;
                parent[edge.v] = edge.u;
            }
        }
    }

    for (const auto& edge : edges) {
        if (distance[edge.u] != INT_MAX && distance[edge.u] + edge.weight < distance[edge.v]) {
            cout << "Do thi co chu trinh trong so am" << endl;
            return;
        }
    }

    cout << "Khoang cach ngan nhat tu dinh nguon " << source << ":\n";
    for (int i = 1; i <= V; ++i) {
        cout << "Dinh " << i << " Khoang cach: " << distance[i] << " Duong di: ";

        vector<int> path;
        for (int v = i; v != -1; v = parent[v]) {
            path.push_back(v);
        }

        reverse(path.begin(), path.end());
        for (const auto& p : path) {
            cout << p << " ";
        }
        cout << endl;
    }
}

void prim(int V, vector<Edge>& edges) {
    vector<vector<pair<int, int>>> adj(V + 1);
    for (const auto& edge : edges) {
        adj[edge.u].emplace_back(edge.v, edge.weight);
        adj[edge.v].emplace_back(edge.u, edge.weight);
    }

    vector<bool> inMST(V + 1, false);
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    pq.emplace(0, 1, -1);
    int mstWeight = 0;
    vector<pair<int, int>> mstEdges;

    while (!pq.empty()) {
        auto [weight, u, parent] = pq.top();
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;
        mstWeight += weight;

        if (parent != -1) {
            mstEdges.emplace_back(parent, u);
        }

        for (const auto& [v, w] : adj[u]) {
            if (!inMST[v]) {
                pq.emplace(w, v, u);
            }
        }
    }

    cout << "Danh sach cac canh trong MST:\n";
    for (const auto& [u, v] : mstEdges) {
        cout << u << " - " << v << endl;
    }
    cout << "tong trong so cua MST: " << mstWeight << endl;
}

int main() {
    string filename = "graph.txt";
    vector<Edge> edges;
    int V;

    readGraph(filename, edges, V);

    cout << "\nThuc hien thuat toan Bellman-Ford...\n";
    bellmanFord(V, 1, edges);

    cout << "\nThuc hien thuat toan Prim...\n";
    prim(V, edges);

    return 0;
}
