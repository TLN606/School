#include <bits/stdc++.h>

using namespace std;

//! Ham nhap danh sach
int input(int A[], int n)
{
    cout << "\n=> Nhap gia tri cua mang: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "A [" << i << "] = ";
        cin >> A[i];
    }
}


//! Ham xuat danh sach
int output(int A[], int n)
{
    cout << "[ ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << "]" << endl;
}

//! Ham sap xep danh sach
// Insertion sort
void insertionSort(int A[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = A[i];
       j = i-1;
       while (j >= 0 && A[j] > key)
       {
           A[j+1] = A[j];
           j = j-1;
       }
       A[j+1] = key;
   }
}

// Selection sort
void selectionSort(int A[], int n)
{
    int i, j, x0;
    for (i = 0; i < n-1; i++)
    {
        x0 = i;
        for (j = i+1; j < n; j++)
        {
            if (A[j] < A[x0])
            {
                x0= j;
            }
            swap(A[x0], A[i]);
        }
    }
}


// Interchange sort
void interchangeSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] > A[j])
            {
                swap(A[i], A[j]);
            }
        }
    }
}

// Bubble sort
void bubbleSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (A[j] < A[j - 1])
            {
                swap(A[j], A[j - 1]);
            }
        }
    }
}

void quickSort(int A[], int left, int right) {
    if (left >= right) {
        return;
    }

    int x = A[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j) {
        while (A[i] < x) {
            i++;
        }
        while (A[j] > x) {
            j--;
        }
        if (i <= j) {
            swap(A[i], A[j]);
            i++;
            j--;
        }
    }

    quickSort(A, left, j);
    quickSort(A, i, right);
}

int linearSearch(int A[], int n, int X)
{
    for (int i = 0; i < n; i++)
    {
        if (A[i] == X)
        {
            return i;
        }
    }
    return -1;
}

void kiemViTri(int A[], int n, int X)
{
    cout << "Vi tri cua phan tu co gia tri " << X << " trong danh sach la: ";
    for (int i = 0; i < n; i++)
    {
        if (A[i] == X)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

int binarySearch(int A[], int n, int Y) {
  int right = n - 1;
  int left = 0;
  while (right >= left) {
    int mid = left + (right - left) / 2;

    if (A[mid] == Y)
      return mid;

    if (A[mid] > Y)
      right = mid - 1;

    if (A[mid] < Y)
      left = mid + 1;
  }

  return -1;
}

int main()
{
    system("cls");

    int n;
    int X, Y;
    int choice;
    int A[100];
    int ketQua;

    while(1)
    {
        cout << " -=- CHUONG TRINH SAP XEP DANH SACH DAC -=- " << endl;
        cout << "============================================" << endl;
        cout << "=  1. Chen phan tu vao mang.               =" << endl;
        cout << "=------------------------------------------=" << endl;
        cout << "=  2. Insertion sort                       =" << endl;
        cout << "=  3. Selection sort                       =" << endl;
        cout << "=  4. Interchange sort                     =" << endl;
        cout << "=  5. Bubble sort                          =" << endl;
        cout << "=  6. Quicksort                            =" << endl;
        cout << "=------------------------------------------=" << endl;
        cout << "=  7. Xuat danh sach vua nhap              =" << endl;
        cout << "=------------------------------------------=" << endl;
        cout << "=  8. Kiem tra gia tri phan tu X           =" << endl;
        cout << "=  9. Xuat cac phan tu co gia tri X        =" << endl;
        cout << "= 10. Tim kiem nhi phan                    =" << endl;
        cout << "=------------------------------------------=" << endl;
        cout << "= 11. Thoat chuong trinh                   =" << endl;
        cout << "============================================" << endl;
        cout << "> Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "\n>> Nhap so phan tu cua mang: ";
                cin >> n;
                input(A, n);

                break;

            case 2:
                cout << "\n>> Danh sach sau khi duoc sap xep (Insertion sort): " << endl;
                insertionSort(A, n);
                output(A, n);

                break;

            case 3:
                cout << "\n>> Danh sach sau khi duoc sap xep (Selection sort): " << endl;
                selectionSort(A, n);
                output(A, n);

                break;

            case 4:
                cout << "\n>> Danh sach sau khi duoc sap xep (Interchange sort): " << endl;
                interchangeSort(A, n);
                output(A, n);

                break;

            case 5:
                cout << "\n>> Danh sach sau khi duoc sap xep (Bubble sort): " << endl;
                bubbleSort(A, n);
                output(A, n);

                break;

            case 6:
                cout << "\n>> Danh sach sau khi duoc sap xep (Quick sort): " << endl;
                quickSort(A, 0, n - 1);
                output(A, n);

                break;

            case 7:
                cout << ">> Danh sach vua nhap la: " << endl;
                output(A, n);

                break;

            case 8:
                cout << ">> Nhap gia tri can kiem tra co trong danh sach: ";
                cin >> X;
                ketQua = linearSearch(A, n, X);

                if (ketQua != -1)
                {
                    cout << "\n=> Gia tri " << X << " co xuat hien" << endl;
                }
                else
                {
                    cout << "\n=>Gia tri " << X << " khong co xuat hien" << endl;
                }

                break;

            case 9:
                cout << ">> Nhap gia tri can xuat ra vi tri trong danh sach: ";
                cin >> X;
                kiemViTri(A, n, X);

                break;

            case 10:
                cout << ">> Nhap gia tri can tim trong danh sach: ";
                cin >> Y;
                ketQua = binarySearch(A, n, Y);

                if (ketQua != -1)
                {
                    cout << "\n=> Gia tri " << Y << " co xuat hien" << endl;
                }
                else
                {
                    cout << "\n=> Gia tri " << Y << " khong co xuat hien" << endl;
                }

                break;

            case 11:
                exit(0);
                break;

            default:
                cout << ">> Lua chon khong hop le! <<" << endl;
        }
    }
}
