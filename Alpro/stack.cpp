#include <iostream>
#include <stdlib.h>

using namespace std;

#define max 5

string dt[max];
int top = 0;

bool isEmpty()
{
    return top == 0;
}

bool isFull()
{
    return top >= max;
}

void push()
{
    if (!isFull())
    {
        cout << "Masukan data: ";
        cin >> dt[top];
        top++;
    }
    else
    {
        cout << "Stack sudah penuh." << endl;
    }
}

void pop()
{
    if (!isEmpty())
    {
        top--;
    }
    else
    {
        cout << "Stack kosong." << endl;
    }
}

void display()
{
    if (!isEmpty())
    {
        cout << "Data tersimpan:" << endl;
        for (int a = 0; a < top; a++)
        {
            cout << a + 1 << ". " << dt[a] << endl;
        }
    }
    else
    {
        cout << "Data tidak tersedia" << endl;
    }
}

int main()
{
    int pilihan;
    string isi;

    while (true)
    {
        system("cls");
        display();
        cout << "Menu utama" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Exit" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1)
        {
            system("cls");
            push();
        }
        else if (pilihan == 2)
        {
            system("cls");
            pop();
        }
        else if (pilihan == 3)
        {
            break;
        }
    }

    return 0;
}
