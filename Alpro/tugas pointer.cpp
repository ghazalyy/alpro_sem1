#include <iostream>
#include <cmath>

using namespace std;

void menu1(double *x1, double *y1, double *x2, double *y2) {
    double jarak;
    double skala = 1.0;

    cout << "Masukkan nilai x1: ";
    cin >> *x1;
    cout << "Masukkan nilai y1: ";
    cin >> *y1;

    cout << "Masukkan nilai x2: ";
    cin >> *x2;
    cout << "Masukkan nilai y2: ";
    cin >> *y2;

    jarak = skala * sqrt(pow((*x2 - *x1), 2) + pow((*y2 - *y1), 2));

    cout << "Jarak: " << jarak << endl;
}

void menu2() {
    unsigned long long sum = 1;
    int n;
    int *n_ptr = &n; 

    cout << "Masukan nilai n: ";
    cin >> *n_ptr;
    
    for (int i = 2; i <= *n_ptr; i++) {
        if (i % 2 == 0) {
            sum *= i;
            cout << i << "*";
        }
    }

    cout << endl;
    cout << "Hasil: " << sum << endl;
}

void menu3() {
    int n;
    int *ptr_n = &n;
    cout << "Masukkan jumlah karakter yang ingin dimasukkan: ";
    cin >> n;

    char karakter;
    char *ptrKar = &karakter;
    int karakterCount[256] = {0}; 

    for (int i = 0; i < *ptr_n; i++)
    {
        cout << "Data ke-" << i + 1 << ": ";
        cin >> *ptrKar;
        karakterCount[static_cast<int>(*ptrKar)]++;
    }

    cout << "Hasil perhitungan karakter:" << endl;
    for (int i = 0; i < 256; i++) {
        int *ptrKC = &karakterCount[i];
        if (*ptrKC > 0)
        {
            cout << static_cast<char>(i) << ": " << *ptrKC << endl;
        }
    }
}

struct Mahasiswa
{
    string nim;
    string nama;
};

bool bandingkanNIM(const Mahasiswa &a, const Mahasiswa &b)
{
    return a.nim > b.nim;
}

void menu4()
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

    // Menggunakan Bubble Sort dengan pointer untuk mengurutkan mahasiswa berdasarkan NIM
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

void menu5() {
    exit(0);
}

void err() {
    cout << "Pilihan anda salah!!!" << endl;
}

int main() {
    int pil;
    double x1, y1, x2, y2;
    
    do {
        cout << "Selamat Datang, Silahkan pilih menu" << endl;
        cout << "1. Koordinat kartesius" << endl;
        cout << "2. Perkalian faktor bilangan genap" << endl;
        cout << "3. Menghitung karakter" << endl;
        cout << "4. Mengurutkan NIM" << endl;
        cout << "5. Exit" << endl;
        cout << "Silahkan pilih (1/2/3/4/5): ";
        cin >> pil;

        if (pil == 1) {
            menu1(&x1, &y1, &x2, &y2);
        }
        else if (pil == 2) {
            menu2();
        }
        else if (pil == 3) {
            menu3();
        }
        else if (pil == 4) {
            menu4();
        }
        else if (pil == 5) {
            menu5();
        }
        else {
            err();
        }
    } while (pil <= 5);
    
    return 0;
}
