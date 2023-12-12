#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

#define max 10
int front = 0;
int rear = -1;
int itemCount = 0;

struct Mahasiswa
{
    string nim;
    string nama;
};

bool bandingkanNIM(const Mahasiswa &a, const Mahasiswa &b)
{
    return a.nim > b.nim;
}

bool isFull()
{
    return itemCount >= max;
}

bool isEmpty()
{
    return itemCount == 0;
}

void displayQueue(Mahasiswa *antrian)
{
    if (isEmpty())
    {
        cout << "Antrian kosong." << endl;
        return;
    }

    cout << "Isi Antrian Mahasiswa :" << endl;
    int count = 0;
    int i = front;
    do
    {
        cout << "NIM: " << antrian[i].nim << ", Nama: " << antrian[i].nama << endl;
        i = (i + 1) % max;
        count++;
    } while (count < itemCount);
    cout << endl;
}

void enqueue(Mahasiswa *antrian, int jumlah)
{
    if (isFull())
    {
        cout << "Antrian penuh. Tidak dapat menambahkan mahasiswa." << endl;
        return;
    }

    for (int i = 0; i < jumlah; i++)
    {
        Mahasiswa mhs;
        cout << "Masukkan NIM mahasiswa ke-" << itemCount + 1 << ": ";
        cin >> mhs.nim;
        cout << "Masukkan Nama mahasiswa ke-" << itemCount + 1 << ": ";
        cin >> mhs.nama;

        rear = (rear + 1) % max;
        antrian[rear] = mhs;
        itemCount++;

        displayQueue(antrian);
    }
}

void dequeue(Mahasiswa *antrian)
{
    if (isEmpty())
    {
        cout << "Antrian kosong. Tidak ada mahasiswa untuk dihapus." << endl;
        return;
    }

    cout << "Dequeue Operation: NIM: " << antrian[front].nim << ", Nama: " << antrian[front].nama << endl;

    front = (front + 1) % max;
    itemCount--;

    displayQueue(antrian);
}

void tugas1()
{
    x:
    int n, pil;
    string ulang;
    int *ptr = &n;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;

    if (n > max)
    {
        cout << "Nilai melebihi batas!" << endl;
        return;
    }

    Mahasiswa *daftarMahasiswa = new Mahasiswa[max];

    for (int i = 0; i < n; i++)
    {
        cout << "Masukkan NIM mahasiswa ke-" << i + 1 << ": ";
        cin >> daftarMahasiswa[i].nim;
        cout << "Masukkan Nama mahasiswa ke-" << i + 1 << ": ";
        cin >> daftarMahasiswa[i].nama;
    }

    Mahasiswa temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (bandingkanNIM(daftarMahasiswa[j], daftarMahasiswa[j + 1]))
            {
                temp = daftarMahasiswa[j];
                daftarMahasiswa[j] = daftarMahasiswa[j + 1];
                daftarMahasiswa[j + 1] = temp;
            }
        }
    }

    cout << "Daftar Mahasiswa Terurut :" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "NIM: " << daftarMahasiswa[i].nim << ", Nama: " << daftarMahasiswa[i].nama << endl;
    }

    cout << endl;
    cout << endl;

    cout << "Silahkan pilih menu" << endl;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "Masukan pilihan: ";
    cin >> pil;

    if (pil == 1)
    {
        int jml;
        cout << "Berapa banyak data yang ingin ditambahkan: ";
        cin >> jml;
        enqueue(daftarMahasiswa, jml);
    }
    else if (pil == 2)
    {
        dequeue(daftarMahasiswa);
    }

    cout << "Apakah anda ingin mengulang?(Y/y)"; cin >> ulang;
    if (ulang == "Y" || ulang == "y"){
        goto x;
    } else{
        exit(0);
    }
}

int main()
{
    tugas1();
    return 0;
}
