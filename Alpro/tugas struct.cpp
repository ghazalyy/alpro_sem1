#include <iostream>
#include <ctime>

using namespace std;

struct Mahasiswa
{
    string nim;
    string nama;
};

bool bandingkanNIM(const Mahasiswa &a, const Mahasiswa &b)
{
    return a.nim > b.nim;
}

void tugas1()
{
    int n;
    int *ptr = &n;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;

    Mahasiswa *daftarMahasiswa = new Mahasiswa[*ptr];

    for (int i = 0; i < *ptr; i++)
    {
        cout << "Masukkan NIM mahasiswa ke-" << i + 1 << ": ";
        cin >> daftarMahasiswa[i].nim;
        cout << "Masukkan Nama mahasiswa ke-" << i + 1 << ": ";
        cin >> daftarMahasiswa[i].nama;
    }

    Mahasiswa temp;
    for (int i = 0; i < *ptr - 1; i++)
    {
        for (int j = 0; j < *ptr - i - 1; j++)
        {
            if (daftarMahasiswa[j].nim > daftarMahasiswa[j + 1].nim)
            {
                temp = daftarMahasiswa[j];
                daftarMahasiswa[j] = daftarMahasiswa[j + 1];
                daftarMahasiswa[j + 1] = temp;
            }
        }
    }

    cout << "Daftar Mahasiswa Terurut :" << endl;
    for (int i = 0; i < *ptr; i++)
    {
        cout << "NIM: " << daftarMahasiswa[i].nim << ", Nama: " << daftarMahasiswa[i].nama << endl;
    }

    delete[] daftarMahasiswa;
}

struct Waktu {
    int jam;
    int menit;
    int detik;
};

void hitungSelisihWaktu(Waktu waktuDatang, Waktu waktuPulang, int &selisihDetik) {
    int selisihJam = waktuPulang.jam - waktuDatang.jam;
    int selisihMenit = waktuPulang.menit - waktuDatang.menit;
    selisihDetik = waktuPulang.detik - waktuDatang.detik;
    selisihDetik += selisihJam * 3600 + selisihMenit * 60;
}

void hitungBiayaParkir(Waktu waktuDatang, Waktu waktuPulang, double &biayaParkir) {
    int selisihDetik;
    hitungSelisihWaktu(waktuDatang, waktuPulang, selisihDetik);

    biayaParkir = 3000;
    if (selisihDetik > 3600) {
        biayaParkir += 3000 * ((selisihDetik / 3600) - 1);
    }

    if (selisihDetik % 3600 != 0) {
        biayaParkir += 3000;
    }
}

void tugas2()
{
    Waktu waktuDatang, waktuPulang;
    double biayaParkir;

    cout << "Masukkan waktu datang (jam menit detik): ";
    cin >> waktuDatang.jam >> waktuDatang.menit >> waktuDatang.detik;

    cout << "Masukkan waktu pulang (jam menit detik): ";
    cin >> waktuPulang.jam >> waktuPulang.menit >> waktuPulang.detik;

    hitungBiayaParkir(waktuDatang, waktuPulang, biayaParkir);

    cout << "Biaya parkir: " << biayaParkir << " Rp" << endl;
}

int main()
{
    int pil;
    do
    {
        cout << "Silahkan pilih!" << endl;
        cout << "1. Tugas no 1" << endl;
        cout << "2. Tugas no 2" << endl;
        cout << "Pilihan: ";
        cin >> pil;

        if (pil == 1)
        {
            tugas1();
        }
        else if (pil == 2)
        {
            tugas2();
        }
        else
        {
            cout << "Pilihan salah!!" << endl;
        }
    } while (pil <= 2);
}
