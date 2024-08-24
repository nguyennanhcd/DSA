#include <iostream>
using namespace std;

struct node
{
    int value;
    node *prev;
    node *next;
};

struct douList
{
    node *head;
    node *tail;
};

void insert_front(douList *list)
{
    cout << "\nEnter Data for New Node:";
    node *new_node = new node;
    cin >> new_node->value;

    if (list->head == nullptr)
    {
        new_node->next = new_node;
        new_node->prev = new_node;
        list->head = new_node;
        list->tail = new_node;
    }
    else
    {
        new_node->next = list->head;
        new_node->prev = list->tail;
        list->head->prev = new_node;
        list->tail->next = new_node;
        list->head = new_node;
    }
}

void insert_end(douList *list)
{
    cout << "\nEnter Data for New Node:";
    node *new_node = new node;
    cin >> new_node->value;

    if (list->head == nullptr)
    {
        new_node->next = new_node;
        new_node->prev = new_node;
        list->head = new_node;
        list->tail = new_node;
    }
    else
    {
        new_node->next = list->head;
        new_node->prev = list->tail;
        list->tail->next = new_node;
        list->head->prev = new_node;
        list->tail = new_node;
    }
}

void insert_after(douList *list)
{
    node *new_node = new node;
    cout << "\nEnter Data for New Node:";
    cin >> new_node->value;

    if (list->head == nullptr)
    {
        cout << "\nThere is No element in the List\nCreating a new node";
        new_node->prev = new_node;
        new_node->next = new_node;
        list->head = new_node;
        list->tail = new_node;
    }
    else
    {
        int num;
        cout << "Enter After Element:";
        cin >> num;

        node *curr = list->head;
        do
        {
            if (curr->value == num)
            {
                new_node->next = curr->next;
                new_node->prev = curr;
                curr->next->prev = new_node;
                curr->next = new_node;

                if (curr == list->tail)
                {
                    list->tail = new_node;
                }
                return;
            }
            curr = curr->next;
        } while (curr != list->head);

        cout << "\nEntered Element Not Found in List\n";
    }
}

void insert_before(douList *list)
{
    node *new_node = new node;

    if (list->head == nullptr)
    {
        cout << "List is Empty!! Creating New node...";
        cout << "\nEnter Data for New Node:";
        cin >> new_node->value;
        new_node->prev = new_node;
        new_node->next = new_node;
        list->head = new_node;
        list->tail = new_node;
    }
    else
    {
        int num;
        cout << "\nEnter Before Element:";
        cin >> num;

        if (list->head->value == num)
        {
            insert_front(list);
        }
        else
        {
            node *curr = list->head->next;
            while (curr != list->head)
            {
                if (curr->value == num)
                {
                    new_node->next = curr;
                    new_node->prev = curr->prev;
                    curr->prev->next = new_node;
                    curr->prev = new_node;
                    return;
                }
                curr = curr->next;
            }

            cout << "\nEntered Element Not Found in List!!\n";
        }
    }
}

void delete_front(douList *list)
{
    if (list->head == nullptr)
    {
        cout << "\nList in empty!!\n";
    }
    else if (list->head == list->tail)
    {
        delete list->head;
        list->head = nullptr;
        list->tail = nullptr;
    }
    else
    {
        node *curr = list->head->next;
        curr->prev = list->tail;
        list->tail->next = curr;
        delete list->head;
        list->head = curr;
    }
}

void delete_end(douList *list)
{
    if (list->head == nullptr)
    {
        cout << "\nList is Empty!!\n";
    }
    else if (list->head == list->tail)
    {
        delete list->head;
        list->head = nullptr;
        list->tail = nullptr;
    }
    else
    {
        node *curr = list->tail;
        list->tail = curr->prev;
        list->tail->next = list->head;
        list->head->prev = list->tail;
        delete curr;
    }
}

void delete_mid(douList *list)
{
    if (list->head == nullptr)
    {
        cout << "\nList is Empty!!!";
    }
    else
    {
        cout << "\nEnter Element to be deleted:";
        int num;
        cin >> num;

        if (list->head->value == num)
        {
            delete_front(list);
        }
        else
        {
            node *curr = list->head->next;
            while (curr != list->head)
            {
                if (curr->value == num)
                {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;

                    if (curr == list->tail)
                    {
                        list->tail = curr->prev;
                    }

                    delete curr;
                    return;
                }
                curr = curr->next;
            }

            cout << "\nEntered Element Not Found in List!!\n";
        }
    }
}

void search(douList *list)
{
    if (list->head == nullptr)
    {
        cout << "List is empty!!";
        return;
    }

    int item;
    cout << "Enter item to be searched:";
    cin >> item;

    node *curr = list->head;
    int index = 0, count = 0;

    do
    {
        if (curr->value == item)
        {
            cout << "\nItem found at position:" << index + 1;
            count++;
        }

        index++;
        curr = curr->next;
    } while (curr != list->head);

    if (count == 0)
        cout << "Item searched not found in list";
}

void reverse(douList *list)
{
    if (list->head == nullptr)
    {
        cout << "List is Empty !!";
        return;
    }

    node *curr = list->head;
    do
    {
        node *temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;
        curr = temp;
    } while (curr != list->head);

    list->tail = list->head;
    list->head = list->head->prev;
}

void display(node *head)
{
    if (head == nullptr)
    {
        cout << "\nList is Empty!!";
        return;
    }

    node *curr = head;
    do
    {
        cout << curr->value << "->";
        curr = curr->next;
    } while (curr != head);
}

void display_menu()
{
    cout << "=============================================="
            "======================";
    cout << "\nMenu:\n";
    cout << "1. Insert At Front\n";
    cout << "2. Insert At End\n";
    cout << "3. Insert After Element\n";
    cout << "4. Insert Before Element\n";
    cout << "5. Delete From Front\n";
    cout << "6. Delete From End\n";
    cout << "7. Delete A Node\n";
    cout << "8. Search for an Element\n";
    cout << "9. Reverse the List\n";
    cout << "=============================================="
            "======================";
}

int main()
{
    int choice;
    char repeat_menu = 'y';

    douList list;
    list.head = nullptr;
    list.tail = nullptr;

    display_menu();
    do
    {
        cout << "\nEnter Your Choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            insert_front(&list);
            display(list.head);
            break;
        case 2:
            insert_end(&list);
            display(list.head);
            break;
        case 3:
            insert_after(&list);
            display(list.head);
            break;
        case 4:
            insert_before(&list);
            display(list.head);
            break;
        case 5:
            delete_front(&list);
            display(list.head);
            break;
        case 6:
            delete_end(&list);
            display(list.head);
            break;
        case 7:
            delete_mid(&list);
            display(list.head);
            break;
        case 8:
            search(&list);
            break;
        case 9:
            reverse(&list);
            display(list.head);
            break;
        default:
            cout << "\nWrong Choice!!!";
            display_menu();
            break;
        }
        cout << "\nEnter More(Y/N)";
        cin >> repeat_menu;

    } while (repeat_menu == 'y' || repeat_menu == 'Y');
    return 0;
}
