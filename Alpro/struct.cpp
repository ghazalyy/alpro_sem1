#include <iostream>
#include <iomanip> 

using namespace std;

struct mahasiswa {
    string nim;
    string nama;
    string jurusan;
    int nilai;
};

int main() {
    int jumlahData;    
    cout << "Masukkan jumlah data: "; 
    cin >> jumlahData;
    mahasiswa data[jumlahData];
    int totalNilai = 0; // Inisialisasi total nilai

    for(int i = 0; i < jumlahData; i++) {
        cout << "Data Mahasiswa ke-" << i + 1 << endl;
        cout << "Masukkan Nim: "; 
        cin >> data[i].nim;
        cout << "Masukkan Nama: "; 
        cin >> data[i].nama;
        cout << "Masukkan Jurusan: "; 
        cin >> data[i].jurusan;
        cout << "Masukkan Nilai: "; 
        cin >> data[i].nilai;
        
        // Menambahkan nilai ke total
        totalNilai += data[i].nilai;
    }
    cout << endl;

    for(int i = 0; i < jumlahData; i++) {
        cout << "Tampilan Data Mahasiswa ke-" << i + 1 << endl;
        cout << "Nim: " << data[i].nim << endl;
        cout << "Nama: " << data[i].nama << endl;
        cout << "Jurusan: " << data[i].jurusan << endl;
        cout << "Nilai: " << data[i].nilai << endl;
    }
    
    double rataRata = static_cast<double>(totalNilai) / jumlahData;
    cout << "Nilai Rata-rata: " << fixed << setprecision(2) << rataRata << endl;

    return 0;
}
