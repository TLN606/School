#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

//! Ham nhap danh sach
void input(Node*& head, Node*& tail, int n)
{
    cout << "\n=> Nhap gia tri cua danh sach: " << endl;
    for (int i = 0; i < n; i++)
    {
        int value;
        cout << "Node [" << i << "] = ";
        cin >> value;
        Node* newNode = createNode(value);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
}

//! Ham xuat danh sach
void output(Node* head)
{
    cout << "[ ";
    Node* current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "]" << endl;
}

//! Ham sap xep danh sach
// Insertion sort
void insertionSort(Node* head)
{
    if (!head || !head->next)
        return;

    Node *i, *j;
    for (i = head->next; i != NULL; i = i->next)
    {
        int key = i->data;
        j = i->prev;
        while (j != NULL && j->data > key)
        {
            j->next->data = j->data;
            j = j->prev;
        }
        if (j == NULL)
            head->data = key;
        else
            j->next->data = key;
    }
}

// Selection sort
void selectionSort(Node* head)
{
    if (!head || !head->next)
        return;

    Node *i, *j;
    for (i = head; i->next != NULL; i = i->next)
    {
        Node* min = i;
        for (j = i->next; j != NULL; j = j->next)
        {
            if (j->data < min->data)
                min = j;
        }
        if (min != i)
            swap(min->data, i->data);
    }
}

// Interchange sort
void interchangeSort(Node* head)
{
    if (!head || !head->next)
        return;

    Node* i, *j;
    for (i = head; i->next != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                swap(i->data, j->data);
            }
        }
    }
}


// Bubble sort
void bubbleSort(Node* head)
{
    if (!head || !head->next)
        return;

    bool swapped;
    Node *ptr1, *lptr = NULL;
    do {
        swapped = false;
        ptr1 = head;
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                swap(ptr1->data, ptr1->next->data);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void quickSort(Node* head, Node* tail) {
    if (head != NULL && tail != NULL && head != tail && head->prev != tail) {
        Node* pivot = head;
        Node* left = head->next;
        Node* right = tail;

        while (left != right && right->next != left) {
            while (left->data < pivot->data)
                left = left->next;
            while (right->data > pivot->data)
                right = right->prev;

            if (left != right && right->next != left) {
                swap(left->data, right->data);
            }
        }

        swap(pivot->data, right->data);
        quickSort(head, right->prev);
        quickSort(right->next, tail);
    }
}

int binarySearch(Node* head, int Y) {
    Node* left = head;
    Node* right = NULL;
    while (right == NULL || right != left) {
        Node* mid = left;
        int count = 0;
        while (mid != right && count < 2) {
            mid = mid->next;
            count++;
        }

        if (mid->data == Y)
            return mid->data;

        if (mid->data < Y)
            left = mid->next;
        else
            right = mid;
    }

    return -1;
}


int main()
{
    system("cls");

    int n;
    int Y;
    int choice;
    Node* head = NULL;
    Node* tail = NULL;

    while (true)
    {
        cout << " -=- CHUONG TRINH SAP XEP DANH SACH LIEN KET KEP -=- " << endl;
        cout << "====================================================" << endl;
        cout << "=  1. Chen phan tu vao danh sach.                 =" << endl;
        cout << "=--------------------------------------------------=" << endl;
        cout << "=  2. Insertion sort                               =" << endl;
        cout << "=  3. Selection sort                               =" << endl;
        cout << "=  4. Intercange sort                              =" << endl;
        cout << "=  5. Bubble sort                                  =" << endl;
        cout << "=  6. Quicksort                                    =" << endl;
        cout << "=--------------------------------------------------=" << endl;
        cout << "=  7. Xuat danh sach vua nhap                      =" << endl;
        cout << "=--------------------------------------------------=" << endl;
        cout << "=  8. Tim kiem nhi phan                            =" << endl;
        cout << "=--------------------------------------------------=" << endl;
        cout << "=  9. Thoat chuong trinh                           =" << endl;
        cout << "====================================================" << endl;
        cout << "> Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "\n>> Nhap so luong phan tu cua danh sach: ";
                cin >> n;
                input(head, tail, n);

                break;

            case 2:
                cout << "\n>> Danh sach sau khi duoc sap xep (Insertion sort): " << endl;
                insertionSort(head);
                output(head);

                break;

            case 3:
                cout << "\n>> Danh sach sau khi duoc sap xep (Selection sort): " << endl;
                selectionSort(head);
                output(head);

                break;

            case 4:
                cout << "\n>> Danh sach sau khi duoc sap xep (Interchange sort): " << endl;
                interchangeSort(head);
                output(head);
                break;

            case 5:
                cout << "\n>> Danh sach sau khi duoc sap xep (Bubble sort): " << endl;
                bubbleSort(head);
                output(head);

                break;

            case 6:
                cout << "\n>> Danh sach sau khi duoc sap xep (Quick sort): " << endl;
                quickSort(head, tail);
                output(head);

                break;

            case 7:
                cout << ">> Danh sach vua nhap la: " << endl;
                output(head);

                break;

            case 8:
                cout << ">> Nhap gia tri can tim trong danh sach: ";
                cin >> Y;
                if (binarySearch(head, Y) != -1)
                {
                    cout << "\n=> Gia tri " << Y << " co xuat hien" << endl;
                }
                else
                {
                    cout << "\n=> Gia tri " << Y << " khong co xuat hien" << endl;
                }

                break;

            case 9:
                exit(0);
                break;

            default:
                cout << ">> Lua chon khong hop le! <<" << endl;
        }
    }
}
