// tạo cây nhị phân tìm kiếm để lưu trữ các giá trị trong file input.txt
// Biết file txt có định dạng như sau
// 10
// 6 5 -3 2 12 -5 8 9 1 20
// 1.Xuất các node lá
// 2.Xuất các node có 1 con
// 3.Xuất các node có 2 con
// 4. Tìm phần tử lớn nhất của cây

#include <iostream>
#include <fstream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};

typedef struct node Node;
typedef Node *Tree;

void init(Tree &t)
{
    t = NULL;
}

void addNode(Tree &t, int x)
{
    if (t == NULL)
    {
        Node *tmp = new Node;
        tmp->data = x;
        tmp->left = tmp->right = NULL;
        t = tmp;
    }
    else
    {
        if (x > t->data)
        {
            addNode(t->right, x);
        }
        else if (x < t->data)
        {
            addNode(t->left, x);
        }
    }
}

void printNLR(Tree t)
{
    if (t != NULL)
    {
        cout << t->data << " ";
        printNLR(t->left);
        printNLR(t->right);
    }
}

void find_Leaves_Node(Tree t)
{
    if (t != nullptr)
    {
        if (t->left == nullptr && t->right == nullptr)
        {
            cout << t->data << " ";
        }
        find_Leaves_Node(t->left);
        find_Leaves_Node(t->right);
    }
}

void find_Nodes_with_one_child(Tree t)
{
    if (t != nullptr)
    {
        if (t->left == nullptr || t->right == nullptr)
        {
            cout << t->data << " ";
        }
        find_Nodes_with_one_child(t->left);
        find_Nodes_with_one_child(t->right);
    }
}

void find_Nodes_with_two_children(Tree t)
{
    if (t != nullptr)
    {
        if (t->left != nullptr && t->right != nullptr)
        {
            cout << t->data << " ";
        }
        find_Nodes_with_two_children(t->left);
        find_Nodes_with_two_children(t->right);
    }
}

int maxValue1(Tree t)
{
    if (t->right == nullptr)
    {
        return t->data;
    }
    return maxValue1(t->right);
}

int minValue(Tree t)
{
    if (t->left == nullptr)
    {
        return t->data;
    }
    return minValue(t->left);
}

// khi file là
// 10
// 6 5 -3 2 12 -5 8 9 1 20
void docFile(Tree &t, ifstream &fileIn)
{
    int n;
    fileIn >> n;
    for (int i = 1; i < n; i++)
    {
        int x;
        fileIn >> x;
        addNode(t, x);
    }
}

void docFile1(Tree &t, ifstream &fileIn)
{
    while (true)
    {
        int x;
        fileIn >> x;
        addNode(t, x);
        char c;
        fileIn >> c;
        if (fileIn.eof())
            break;
    }
}

int main()
{
    int n;
    Tree t;
    init(t);
    // ifstream fileIn;
    // fileIn.open("input.txt", ios::in);
    // docFile(t, fileIn);

    ifstream fileIn;
    fileIn.open("input1.txt", ios::in);
    if (fileIn.is_open())
    {
        docFile1(t, fileIn);
        cout << endl;
        cout << "Xuat cay: " << endl;
        printNLR(t);
        cout << endl;
        find_Leaves_Node(t);
        cout << endl;
        find_Nodes_with_one_child(t);
        cout << endl;
        find_Nodes_with_two_children(t);
        cout << endl;
        fileIn.close();
        cout << "File input1.txt was opened successfully" << endl;
    }
    else
    {
        cout << "File input1.txt was not opened" << endl;
    }

    return 0;
}