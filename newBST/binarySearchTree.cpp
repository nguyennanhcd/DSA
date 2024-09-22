#include <iostream>
#include <iomanip>
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

void addNodeToTree(Tree &t, int x)
{
    if (t == NULL)
    {
        node *p = new node;
        p->data = x;
        p->left = NULL;
        p->right = NULL;
        t = p;
    }
    else
    {
        if (x < t->data)
        {
            addNodeToTree(t->left, x);
        }
        else if (x > t->data)
        {
            addNodeToTree(t->right, x);
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

void printNRL(Tree t)
{
    if (t != NULL)
    {
        cout << t->data << " ";
        printNRL(t->right);
        printNRL(t->left);
    }
}

// in ra các phần tử từ bé đến lớn
void printLNR(Tree t)
{
    if (t != NULL)
    {
        printLNR(t->left);
        cout << t->data << " ";
        printLNR(t->right);
    }
}

// in ra các phần tử từ lớn đến bé
void printRNL(Tree t)
{
    if (t != NULL)
    {
        printRNL(t->right);
        cout << t->data << " ";
        printRNL(t->left);
    }
}

void printLRN(Tree t)
{
    if (t != NULL)
    {
        printLRN(t->left);
        printLRN(t->right);
        cout << t->data << " ";
    }
}

void printRLN(Tree &t)
{
    if (t != NULL)
    {
        printRLN(t->right);
        printRLN(t->left);
        cout << t->data << " ";
    }
}

bool isPrime(int x)
{
    if (x < 2)
        return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

int countPrime(Tree t, int &count)
{
    if (t != NULL)
    {
        if (isPrime(t->data))
        {
            count++;
        }
        countPrime(t->right, count);
        countPrime(t->left, count);
    }
    return count;
}

Tree search(Tree t, int x)
{
    if (t != nullptr)
    {
        if (t->data == x)
        {
            return t;
        }
        else
        {
            if (x > t->data)
            {
                return search(t->right, x);
            }
            else
            {
                return search(t->left, x);
            }
        }
    }
    return nullptr;
}

void print_Node_has_two_children(Tree t)
{
    if (t != nullptr)
    {
        if (t->left != nullptr && t->right != nullptr)
        {
            cout << t->data << " ";
        }
        print_Node_has_two_children(t->left);
        print_Node_has_two_children(t->right);
    }
}

void print_Node_has_one_child(Tree t)
{
    if (t != nullptr)
    {
        if (t->left != nullptr || t->right != nullptr)
        {
            cout << t->data << " ";
        }
        print_Node_has_one_child(t->left);
        print_Node_has_one_child(t->right);
    }
}

void print_Node_has_no_child(Tree t)
{
    if (t != nullptr)
    {
        if (t->left == nullptr && t->right == nullptr)
        {
            cout << t->data << " ";
        }
        print_Node_has_no_child(t->left);
        print_Node_has_no_child(t->right);
    }
}

void maxValue(Tree t)
{
    node *p = t;

    if (t == nullptr)
    {
        cout << "\n\t\tTree is empty.";
        return;
    }

    while (p->right != nullptr)
    {
        p = p->right;
    }

    cout << "\n\t\tMaximum value in the tree: " << p->data;
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

void findReplacementNode(Tree &x, Tree &y)
{
    if (y->right != nullptr)
    {
        findReplacementNode(x, y->right);
    }
    else
    {
        x->data = y->data;
        x = y;
        y = y->left;
    }
}

void deleteNode(Tree &t, int x)
{
    if (t == nullptr)
    {
        return;
    }
    if (x < t->data)
    {
        deleteNode(t->left, x);
    }
    else if (x > t->data)
    {
        deleteNode(t->right, x);
    }
    else // x == t->data
    {
        Node *temp = t;
        if (t->left == nullptr)
        {
            t = t->right;
        }
        else if (t->right == nullptr)
        {
            t = t->left;
        }
        else // node cần xóa là node có 2 con
        {
            findReplacementNode(temp, t->left);
        }
        delete temp;
    }
}

void sumTree(Tree t, int &sum)
{
    if (t != nullptr)
    {
        sum += t->data;
        sumTree(t->left, sum);
        sumTree(t->right, sum);
    }
}

void Menu(Tree &t)
{
    int choice;
    do
    {
        cout << "\n\n\t\t =========== MENU ===========";
        cout << "\n\t\t\t1. Add node to tree";
        cout << "\n\t\t\t2. Print tree";
        cout << "\n\t\t\t3. Count prime numbers in tree";
        cout << "\n\t\t\t4. Search";
        cout << "\n\t\t\t5. Print node has 2 children";
        cout << "\n\t\t\t6. Print node has 1 child";
        cout << "\n\t\t\t7. Print node has no children";
        cout << "\n\t\t\t8. Find max value of tree";
        cout << "\n\t\t\t9. Delete node tree";
        cout << "\n\t\t\t10. Sum";
        cout << "\n\t\t\t0. Exit" << endl;
        cout << "\n\t\tEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int x;
            cout << "\t\tEnter a number to add: ";
            cin >> x;
            addNodeToTree(t, x);
            break;
        }
        case 2:
        {
            cout << "\n\n\t\t =========== Tree ===========";
            cout << "\n";
            printLNR(t);
            cout << "\n\t\t ============================";
            break;
        }
        case 3:
        {
            int count = 0;
            countPrime(t, count);
            cout << "Number of prime elements: " << count;
            break;
        }
        case 4:
        {
            int x;
            cout << "\n\t\tEnter a number to search: ";
            cin >> x;
            Node *p = search(t, x);
            if (p != nullptr)
            {
                cout << "\n\t\tNumber found in the tree and has a value is: " << p->data;
            }
            else
            {
                cout << "\n\t\tNumber not found in the tree.";
            }
            break;
        }
        case 5:
        {
            cout << "\n\n\t\tNode(s) with 2 children: ";
            print_Node_has_two_children(t);
            cout << "\n\t\t ============================";
            break;
        }
        case 6:
        {
            cout << "\n\n\t\tNode(s) with 1 child: ";
            print_Node_has_one_child(t);
            cout << "\n\t\t ============================";
            break;
        }
        case 7:
        {
            cout << "\n\n\t\tNode(s) with no children: ";
            print_Node_has_no_child(t);
            cout << "\n\t\t ============================";
            break;
        }
        case 8:
        {
            maxValue(t);
            break;
        }
        case 9:
        {
            int x;
            cout << "\n\t\tEnter a number to delete: ";
            cin >> x;
            deleteNode(t, x);
            cout << "\n\t\tNode deleted successfully!";
            break;
        }
        case 10:
        {
            int sum = 0;
            sumTree(t, sum);
            cout << "\n\t\t Sum of tree is: " << sum << endl;
        }
        case 0:
            break;
        default:
            cout << "\n\n\t\t Invalid choice! Please try again.";
            break;
        }
    } while (choice != 0);
}

int main()
{
    Tree t;
    init(t);
    Menu(t);
    return 0;
}
