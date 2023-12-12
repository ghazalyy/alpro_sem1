#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

#define max 10

struct Mahasiswa
{
    string nim;
    string nama;
};

queue<Mahasiswa> antrian;

bool isFull()
{
    return antrian.size() >= max;
}

bool isEmpty()
{
    return antrian.empty();
}

void sortAntrian(Mahasiswa *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j].nim > arr[j + 1].nim)
            {
                Mahasiswa temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void view()
{
    if (isEmpty())
    {
        cout << "Antrian kosong." << endl;
        return;
    }

    cout << "Isi Antrian Mahasiswa:" << endl;

    int size = antrian.size();
    Mahasiswa *tempArray = new Mahasiswa[size];
    for (int i = 0; i < size; i++)
    {
        tempArray[i] = antrian.front();
        antrian.pop();
    }

    sortAntrian(tempArray, size);

    for (int i = 0; i < size; i++)
    {
        antrian.push(tempArray[i]);
    }

    int count = 1;
    queue<Mahasiswa> temp = antrian;

    while (!temp.empty())
    {
        Mahasiswa mhs = temp.front();
        cout << count << ". NIM: " << mhs.nim << ", Nama: " << mhs.nama << endl;
        temp.pop();
        count++;
    }

    cout << endl;

    delete[] tempArray;
}

void enqueue()
{
    if (isFull())
    {
        cout << "Antrian penuh. Tidak dapat menambahkan mahasiswa." << endl;
        return;
    }

    Mahasiswa mhs;
    cout << "Masukkan NIM mahasiswa: ";
    cin >> mhs.nim;
    cout << "Masukkan Nama mahasiswa: ";
    cin >> mhs.nama;

    antrian.push(mhs);
    cout << "Mahasiswa berhasil ditambahkan ke dalam antrian." << endl;
    cout << endl;
    view();
}

void dequeue()
{
    if (isEmpty())
    {
        cout << "Antrian kosong. Tidak ada mahasiswa untuk dihapus." << endl;
        return;
    }

    Mahasiswa mhs = antrian.front();
    cout << "Dequeue Operation: NIM: " << mhs.nim << ", Nama: " << mhs.nama << endl;

    antrian.pop();

    view();
}

void tugas1()
{
    int n;
    int *ptr = &n;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;

    if (n > max)
    {
        cout << "Nilai melebihi batas!" << endl;
        return;
    }

    Mahasiswa *daftarMahasiswa = new Mahasiswa[*ptr];

    for (int i = 0; i < *ptr; i++)
    {
        cout << "Masukkan NIM mahasiswa ke-" << i + 1 << ": ";
        cin >> daftarMahasiswa[i].nim;
        cout << "Masukkan Nama mahasiswa ke-" << i + 1 << ": ";
        cin >> daftarMahasiswa[i].nama;

        antrian.push(daftarMahasiswa[i]);
    }

    cout << "Daftar Mahasiswa Terurut :" << endl;
    view();

    delete[] daftarMahasiswa;
}

int main()
{
    int menu;

    while (true)
    {
        cout << "1. Input Jumlah Mahasiswa" << endl;
        cout << "2. Enqueue" << endl;
        cout << "3. Dequeue" << endl;
        cout << "4. Exit" << endl;
        cout << "Pilihan: ";
        cin >> menu;

        if (menu == 1)
        {
            tugas1();
        }
        else if (menu == 2)
        {
            enqueue();
        }
        else if (menu == 3)
        {
            dequeue();
        }
        else if (menu == 4)
        {
            break;
        }
        else
        {
            cout << "Pilihan tidak valid. Silahkan coba lagi." << endl;
        }
    }

    return 0;
}
