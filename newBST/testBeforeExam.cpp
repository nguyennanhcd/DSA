#include <iostream>
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
    t = NULL;
}

void addNode(Tree &t, int value)
{
    if (t == nullptr)
    {
        node *newNode = new node;
        newNode->value = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        t = newNode;
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

void findReplacementNode(Tree &temp, Tree &left)
{
    if (left->right != nullptr)
    {
        findReplacementNode(temp, left->right);
    }

    temp->value = left->value;
    temp = left;
    temp = temp->left;
}

void deleteNode(Tree &t, int value)
{
    if (t == nullptr)
    {
        return;
    }

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

void printMenu()
{
    cout << "Menu:" << endl;
    cout << "1. Add Node" << endl;
    cout << "2. Delete Node" << endl;
    cout << "3. Print Tree" << endl;
    cout << "4. Find Nearest Ancestor" << endl;
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
    // case 4:
    // {
    //     int n1, n2;
    //     cout << "Enter the values of the two nodes to find their nearest ancestor: ";
    //     cin >> n1 >> n2;
    //     Tree ancestor = findNearestAncestor(t, n1, n2);
    //     if (ancestor != nullptr)
    //     {
    //         cout << "Nearest ancestor of nodes " << n1 << " and " << n2 << " is: " << ancestor->value << endl;
    //     }
    //     else
    //     {
    //         cout << "No ancestor found." << endl;
    //     }
    //     break;
    // }
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
