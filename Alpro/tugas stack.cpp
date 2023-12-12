#include <iostream>
#include <stdlib.h>

using namespace std;

#define max 5

struct Mahasiswa
{
    string nim;
    string nama;
};

Mahasiswa daftarMahasiswa[max];

int top = 0;

bool isEmpty()
{
    return top == 0;
}

bool isFull()
{
    return top >= max;
}

void bubbleSortNIM()
{
    Mahasiswa temp;
    for (int i = 0; i < top - 1; i++)
    {
        for (int j = 0; j < top - i - 1; j++)
        {
            if (daftarMahasiswa[j].nim > daftarMahasiswa[j + 1].nim)
            {
                temp = daftarMahasiswa[j];
                daftarMahasiswa[j] = daftarMahasiswa[j + 1];
                daftarMahasiswa[j + 1] = temp;
            }
        }
    }
}

void push()
{
    if (!isFull())
    {
        if (top < max)
        {
            cout << "Masukkan NIM mahasiswa ke-" << top + 1 << ": ";
            cin >> daftarMahasiswa[top].nim;
            cout << "Masukkan Nama mahasiswa ke-" << top + 1 << ": ";
            cin >> daftarMahasiswa[top].nama;
            top++;

            bubbleSortNIM();
        }
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
        for (int i = 0; i < top; i++)
        {
            cout << "NIM: " << daftarMahasiswa[i].nim << ", Nama: " << daftarMahasiswa[i].nama << endl;
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

    while (true)
    {
    stack:
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
            goto stack;
        }
        else if (pilihan == 2)
        {
            system("cls");
            pop();
            goto stack;
        }
        else if (pilihan == 3)
        {
            exit(0);
        }
    }

    return 0;
}
