#include <iostream>
#include <cstdlib>
#include <algorithm> // For sort function

using namespace std;

struct node
{
    int value;
    node *left;
    node *right;
};

typedef node *Tree;

void init(Tree &t)
{
    t = nullptr;
}

void addNode(Tree &t, int value)
{
    if (t == nullptr)
    {
        node *p = new node();
        p->value = value;
        p->left = nullptr;
        p->right = nullptr;
        t = p;
    }
    else
    {
        if (value < t->value)
        {
            addNode(t->left, value);
        }
        else if (value > t->value)
        {
            addNode(t->right, value);
        }
    }
}

void printNode(Tree t)
{
    if (t != nullptr)
    {
        printNode(t->left);
        cout << t->value << " ";
        printNode(t->right);
    }
}

void findReplacementNode(Tree &t, Tree &p)
{
    if (p->right != nullptr)
    {
        findReplacementNode(t, p->right);
    }
    else
    {
        t->value = p->value;
        t = p;
        p = p->left;
    }
}

void deleteNode(Tree &t, int value)
{
    if (t == nullptr)
        return;

    if (value < t->value)
    {
        deleteNode(t->left, value);
    }
    else if (value > t->value)
    {
        deleteNode(t->right, value);
    }
    else
    {
        node *temp = t;
        if (t->left == nullptr)
        {
            t = t->right;
        }
        else if (t->right == nullptr)
        {
            t = t->left;
        }
        else
        {
            findReplacementNode(temp, t->right);
        }
        delete temp;
    }
}

Tree findNearestAncestor(Tree t, int n1, int n2)
{
    if (t == nullptr)
    {
        return nullptr;
    }

    if (t->value > n1 && t->value > n2)
    {
        return findNearestAncestor(t->left, n1, n2);
    }

    else if (t->value < n1 && t->value < n2)
    {
        return findNearestAncestor(t->right, n1, n2);
    }
    else
    {
        return t;
    }
}

int countNodes(node *t)
{
    if (!t)
        return 0;
    return 1 + countNodes(t->left) + countNodes(t->right);
}

int find(node *t, int serialNo, int target, int &value)
{
    if (!t)
        return serialNo;
    serialNo = find(t->left, serialNo, target, value);

    serialNo++;
    if (serialNo == target)
        value = t->value;

    serialNo = find(t->right, serialNo, target, value);
    return serialNo;
}

float findMedian(Tree t)
{
    int n = countNodes(t);

    if (n % 2)
    {
        int mid = 0;
        find(t, 0, 1 + n / 2, mid);
        return mid;
    }
    else
    {
        int mid1 = 0, mid2 = 0;
        find(t, 0, n / 2, mid1);
        find(t, 0, 1 + n / 2, mid2);
        return ((float)(mid1 + mid2)) / 2.0;
    }
}

// Function to get the inorder traversal of the binary tree and store it in arr[]
void getArr(int arr[], int &index, node *root)
{
    if (root == nullptr)
        return;

    // recursively traverse the left subtree
    getArr(arr, index, root->left);

    // store the data of current node in arr[] and increment the index
    arr[index] = root->value;
    index++;

    // recursively traverse the right subtree
    getArr(arr, index, root->right);
}

// Function to convert the binary tree to BST
void convertToBST(node *root, int arr[], int &index)
{
    if (root == nullptr)
        return;

    // recursively convert the left subtree
    convertToBST(root->left, arr, index);

    // replace the data of current node with the corresponding arr[] element and increment the index
    root->value = arr[index];
    index++;

    // recursively convert the right subtree
    convertToBST(root->right, arr, index);
}

// Function to get the total number of nodes in the binary tree
int totalNodes(node *root)
{
    if (root == nullptr)
        return 0;

    return (1 + totalNodes(root->left) + totalNodes(root->right));
}

// Function to convert the binary tree to a binary search tree (BST)
Tree binaryTreeToBST(Tree root)
{
    if (root == nullptr)
        return nullptr;

    int n = totalNodes(root);
    int *arr = new int[n];

    int index = 0;
    getArr(arr, index, root);

    sort(arr, arr + n);

    index = 0;
    convertToBST(root, arr, index);

    delete[] arr;
    return root;
}

bool searchForValue(Tree t, int value)
{
    if (t == nullptr)
        return false;

    if (t->value == value)
        return true;
    else if (value < t->value)
        return searchForValue(t->left, value);
    else
        return searchForValue(t->right, value);
}

void countPairsRecursive(Tree root1, Tree root2, int x, int &count)
{
    if (root1 == nullptr)
        return;

    // Recursively visit left subtree
    countPairsRecursive(root1->left, root2, x, count);

    // Check if the complement of root1->value exists in root2
    if (searchForValue(root2, x - root1->value))
        count++;

    // Recursively visit right subtree
    countPairsRecursive(root1->right, root2, x, count);
}

int countPairs(Tree root1, Tree root2, int x)
{
    int count = 0;
    countPairsRecursive(root1, root2, x, count);
    return count;
}

void printMenu()
{
    cout << "Menu:" << endl;
    cout << "1. Add Node" << endl;
    cout << "2. Delete Node" << endl;
    cout << "3. Print Tree" << endl;
    cout << "4. Find Nearest Ancestor" << endl;
    cout << "5. Find Median" << endl;
    cout << "6. Convert Tree to BST" << endl;
    cout << "7. Count Pairs with Sum X (between two BSTs)" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
}

void handleMenuChoice(Tree &t, int choice)
{
    int value;
    switch (choice)
    {
    case 1:
    {
        cout << "Enter value to add: ";
        cin >> value;
        addNode(t, value);
        break;
    }
    case 2:
    {
        cout << "Enter value to delete: ";
        cin >> value;
        deleteNode(t, value);
        break;
    }
    case 3:
    {
        cout << "Tree contents: ";
        printNode(t);
        cout << endl;
        break;
    }
    case 4:
    {
        int n1, n2;
        cout << "Enter the values of the two nodes to find their nearest ancestor: ";
        cin >> n1 >> n2;
        Tree ancestor = findNearestAncestor(t, n1, n2);
        if (ancestor != nullptr)
        {
            cout << "Nearest ancestor of nodes " << n1 << " and " << n2 << " is: " << ancestor->value << endl;
        }
        else
        {
            cout << "No ancestor found." << endl;
        }
        break;
    }
    case 5:
    {
        float median = findMedian(t);
        cout << "Median value of the tree is: " << median << endl;
        break;
    }
    case 6:
    {
        t = binaryTreeToBST(t);
        cout << "Tree has been converted to BST." << endl;
        break;
    }
    case 7: // Count Pairs with Sum X
    {
        Tree t2;
        init(t2);

        cout << "Enter values for the second BST (end with -1):" << endl;
        while (true)
        {
            cin >> value;
            if (value == -1)
                break;
            addNode(t2, value);
        }

        int x;
        cout << "Enter the target sum X: ";
        cin >> x;

        int pairCount = countPairs(t, t2, x);
        cout << "Number of pairs with sum " << x << " is: " << pairCount << endl;

        break;
    }
    case 0:
    {
        cout << "Exiting program." << endl;
        break;
    }
    default:
    {
        cout << "Invalid choice. Please try again." << endl;
        break;
    }
    }
}

void menu(Tree &t)
{
    int choice;
    do
    {
        printMenu();
        cin >> choice;
        handleMenuChoice(t, choice);
    } while (choice != 0);
}

int main()
{
    Tree t;
    init(t);
    menu(t);
    return 0;
}
