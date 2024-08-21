#include <iostream>
using namespace std;
struct Node
{
    int info;
    Node *link;
};

Node *first;
void init()
{
    first = NULL;
}

void process_list()
{
    Node *p = first;
    if (p != NULL)
    {
        do
        {
            cout << p->info << " ";
            p = p->link;
        } while (p != first);
    }
}

void insert_first(int x)
{
    Node *p = new Node;
    p->info = x;
    p->link = first;
    Node *q = first;
    if (q != NULL)
    {
        while (q->link != first)
            q = q->link;
        q->link = p;
    }
    // bởi vì đây là danh sách liên kết vòng nên nếu phần tử đầu tiên null thì next của phần tử đầu tiên sẽ là chính nó
    else
        p->link = p;
    first = p;
}

int delete_first()
{
    if (first != NULL)
    {
        Node *p = first;
        Node *q = first;
        while (q->link != first)
            q = q->link;
        if (p != q)
        {
            first = first->link;
            q->link = first;
        }
        else
            first = NULL;
        delete p;
        return 1;
    }
    return 0;
}

int main()
{
    init();

    int n, value;

    cout << "Nhap so luong phan tu ban muon them vao:  ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Nhap gia tri cua phan tu thu  " << i + 1 << ": ";
        cin >> value;
        insert_first(value);
    }

    cout << "Danh sach hien tai ";
    process_list();
    cout << endl;

    delete_first();
    cout << "Danh sach sau khi xoa phan tu dau tien: ";
    process_list();

    return 0;
}
