#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

float rumus1(int a, int b)
{
    float hasil;
    hasil = sqrt(pow(a, 2) + pow(b, 2));
    return hasil;
}

float rumus2(int a, int b, int c)
{
    float hasil;
    hasil = pow(b, 2) - (4 * a * c);
    return sqrt(hasil);
}

void menu1()
{
    int a, b, c;
    cout << "Masukan nilai a: ";
    cin >> a;
    cout << "Masukan nilai b: ";
    cin >> b;
    cout << "Masukan nilai c: ";
    cin >> c;

    if (rumus2(a, b, c) > 0)
    {
        cout << rumus2(a, b, c) << endl;
    }
    else
    {
        cout << "Tidak terdevinisi" << endl;
    }
    cout << endl;
    rumus1(a, b);
}

void menu2()
{
    int n = 6;
    int dataBelumTerurut[] = {1, 5, 3, 5, 2, 4};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (dataBelumTerurut[j] > dataBelumTerurut[j + 1])
            {
                int temp = dataBelumTerurut[j];
                dataBelumTerurut[j] = dataBelumTerurut[j + 1];
                dataBelumTerurut[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << dataBelumTerurut[i] << endl;
    }
}

void menu3()
{
    int n;
    cout << "Masukan nilai n: ";
    cin >> n;
    int data[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Masukan nilai: ";
        cin >> data[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (data[j] > data[j + 1])
            {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << data[i] << endl;
    }
}

void menu4()
{
    int n;
    cout << "Masukan nilai n: ";
    cin >> n;
    int data[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Masukan nilai: ";
        cin >> data[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (data[j] < data[j + 1])
            {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << data[i] << endl;
    }
}

void menu5()
{
    int n;
    cout << "Masukan nilai n: ";
    cin >> n;
    char data[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Masukan Huruf: ";
        cin >> data[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (data[j] > data[j + 1])
            {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << data[i] << endl;
    }
}

void menu6()
{
    int n;
    cout << "Masukan nilai n: ";
    cin >> n;
    char data[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Masukan Huruf: ";
        cin >> data[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (data[j] < data[j + 1])
            {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << data[i] << endl;
    }
}

void menu7()
{
    int split, length;
    cout << " Masukkan panjang array: ";
    cin >> length;
    cout << " Masukkan split: ";
    cin >> split;
    int arr1[length];
    for (int i = 0; i < length; i++)
    {
        cout << " Data ke-" << i + 1 << " : ";
        cin >> arr1[i];
    }
    int arr2[length - split];
    for (int i = split; i < length; i++)
    {
        arr2[i - split] = arr1[i];
    }
    cout << " Array 1: ";
    for (int i = 0; i < split; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    cout << " Array 2: ";
    for (int i = 0; i < length - split; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
}

int main()
{
    int i = 1, menu;
    do
    {
        cout << "1. Menghitung rumus pytagoras" << endl;
        cout << "2. Data terurut" << endl;
        cout << "3. Data Dinamis" << endl;
        cout << "4. Sorting terbalik" << endl;
        cout << "5. Data Dinamis huruf" << endl;
        cout << "6. Data Dinamis huruf terbalik" << endl;
        cout << "7. Split array" << endl;
        cout << "Silahkan pilih menu: ";
        cin >> menu;

        if (menu == 1)
        {
            menu1();
        }
        else if (menu == 2)
        {
            menu2();
        }
        else if (menu == 3)
        {
            menu3();
        }
        else if (menu == 4)
        {
            menu4();
        }
        else if (menu == 5)
        {
            menu5();
        }
        else if (menu == 6)
        {
            menu6();
        }
        else if (menu == 7)
        {
            menu7();
        }
        else
        {
            cout << "Masukan menu yang benar" << endl;
        }
    } while (i > 0);

    return 0;
}
