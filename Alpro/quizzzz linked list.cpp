#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <cstring>

using namespace std;

const int MAX_USERS = 5;

struct Barang
{
    int kodeBuku;
    string judulBuku;
    double biaya;
    string status;
    int jK;
    struct Barang *next;
};

struct User
{
    string username;
    string password;
};

bool login(User users[], int numUsers)
{
    string inputUsername, inputPassword;

    cout << "Masukkan username: ";
    cin >> inputUsername;
    cout << "Masukkan password: ";
    cin >> inputPassword;

    for (int i = 0; i < numUsers; ++i)
    {
        if (inputUsername == users[i].username && inputPassword == users[i].password)
        {
            return true;
        }
    }
    return false;
}

void tambah(Barang **head)
{
    Barang *brg = new Barang();
    cout << "Masukkan kode buku: ";
    cin >> brg->kodeBuku;
    cout << "Masukan judul buku: ";
    cin.ignore();
    getline(cin, brg->judulBuku);
    cout << "Biaya pinjam buku: ";
    cin >> brg->biaya;
    cout << "Status buku: ";
    cin.ignore();
    getline(cin, brg->status);
    cout << "Jumlah ketersediaan: ";
    cin >> brg->jK;
    brg->next = NULL;

    if (*head == NULL)
    {
        (*head) = brg;
        return;
    }

    Barang *temp = (*head);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = brg;
}

void hapus(Barang *head, int kodeB)
{
    Barang *skr = head;
    Barang *sbl = NULL;

    if (skr != NULL && skr->kodeBuku == kodeB)
    {
        head = skr->next;
        delete skr;
        cout << "Data buku dengan kode buku " << kodeB << " telah dihapus." << endl;
        return;
    }

    while (skr != NULL && skr->kodeBuku != kodeB)
    {
        sbl = skr;
        skr = skr->next;
    }

    if (skr == NULL)
    {
        cout << "Buku dengan kode buku " << kodeB << " tidak ditemukan." << endl;
        return;
    }

    sbl->next = skr->next;
    delete skr;
    cout << "Data buku dengan kode buku " << kodeB << " telah dihapus." << endl;
}

void tampil(Barang *head)
{
    Barang *temp = head;

    if (temp == NULL)
    {
        cout << "Data masih kosong" << endl;
        return;
    }

    while (temp != NULL)
    {
        cout << "Masukkan kode buku : " << temp->kodeBuku << endl;
        cout << "Masukan judul buku : " << temp->judulBuku << endl;
        cout << "Jumlah ketersediaan: " << temp->jK << endl;
        temp = temp->next;
    }
    cout << endl;
}

void transaksi(Barang *head, int kBk, string awalPin, string kembali)
{
    Barang *temp = head;
    while (temp != NULL)
    {
        if (temp->kodeBuku == kBk)
        {
            if (temp->jK > 0)
            {
                int kembaliDay = stoi(kembali.substr(8, 2));
                int kembaliMonth = stoi(kembali.substr(5, 2));
                int kembaliYear = stoi(kembali.substr(0, 4));

                int pinjamDay = stoi(awalPin.substr(8, 2));
                int pinjamMonth = stoi(awalPin.substr(5, 2));
                int pinjamYear = stoi(awalPin.substr(0, 4));

                struct std::tm start_date;
                memset(&start_date, 0, sizeof(start_date));
                start_date.tm_mday = kembaliDay;
                start_date.tm_mon = kembaliMonth - 1;
                start_date.tm_year = kembaliYear - 1900;

                struct std::tm end_date;
                memset(&end_date, 0, sizeof(end_date));
                end_date.tm_mday = pinjamDay;
                end_date.tm_mon = pinjamMonth - 1;
                end_date.tm_year = pinjamYear - 1900;

                std::time_t start_time = std::mktime(&start_date);
                std::time_t end_time = std::mktime(&end_date);

                double seconds = std::difftime(end_time, start_time);
                double days = seconds / (60 * 60 * 24);

                temp->jK--;
                if (temp->jK == 0)
                {
                    temp->status = "Tidak Tersedia";
                }

                double biayaPerhari = 5000;
                double biayaTotal = days * biayaPerhari;
                temp->biaya = biayaTotal;

                cout << "Peminjaman berhasil untuk buku dengan kode " << kBk << endl;
                cout << "Jumlah yang harus dibayar: " << biayaTotal << " rupiah" << endl;

                double uangBayar;
                cout << "Masukkan uang yang dibayarkan: ";
                cin >> uangBayar;

                double uangKembali = uangBayar - biayaTotal;

                system("cls");
                //printBuktiTransaksi(kBk, biayaTotal, uangBayar, uangKembali, temp->judulBuku, awalPin, kembali);

                return;
            }
            else
            {
                cout << "Buku dengan kode " << kBk << " tidak tersedia." << endl;
                return;
            }
        }
        temp = temp->next;
    }
    cout << "Buku dengan kode " << kBk << " tidak ditemukan." << endl;
}

void printBuktiTransaksi(int kodeBuku, double biayaTotal, double uangBayar, double uangKembali, string judulBuku, string tanggalPinjam, string tanggalKembali)
{
    cout << "===== BUKTI TRANSAKSI =====" << endl;
    cout << "Kode Buku         : " << kodeBuku << endl;
    cout << "Judul Buku        : " << judulBuku << endl;

    struct std::tm tmPinjam;
    memset(&tmPinjam, 0, sizeof(tmPinjam));
    tmPinjam.tm_mday = stoi(tanggalPinjam.substr(8, 2));
    tmPinjam.tm_mon = stoi(tanggalPinjam.substr(5, 2)) - 1;
    tmPinjam.tm_year = stoi(tanggalPinjam.substr(0, 4)) - 1900;

    struct std::tm tmKembali;
    memset(&tmKembali, 0, sizeof(tmKembali));
    tmKembali.tm_mday = stoi(tanggalKembali.substr(8, 2));
    tmKembali.tm_mon = stoi(tanggalKembali.substr(5, 2)) - 1;
    tmKembali.tm_year = stoi(tanggalKembali.substr(0, 4)) - 1900;

    cout << "Tanggal Peminjaman: " << std::put_time(&tmPinjam, "%d-%m-%Y") << endl;
    cout << "Tanggal Pengembalian: " << std::put_time(&tmKembali, "%d-%m-%Y") << endl;

    cout << "Biaya Total       : " << biayaTotal << " rupiah" << endl;
    cout << "Uang Bayar        : " << uangBayar << " rupiah" << endl;
    cout << "Uang Kembalian    : " << uangKembali << " rupiah" << endl;
    cout << "Terima kasih telah melakukan transaksi!" << endl;
}

int main()
{
    User users[MAX_USERS] = {
        {"user1", "pass1"},
        {"user2", "pass2"},
        {"user3", "pass3"},
    };

    if (!login(users, MAX_USERS))
    {
        cout << "Login gagal. Program akan keluar." << endl;
        return 0;
    }

    struct Barang *HEAD = NULL;
    int menu;
    while (menu != 5)
    {
        cout << "Selamat datang" << endl;
        cout << "1. Tambah data barang" << endl;
        cout << "2. Hapus data barang" << endl;
        cout << "3. Tampil data barang" << endl;
        cout << "4. Transaksi" << endl;
        cout << "Masukan pilihan: ";
        cin >> menu;

        if (menu == 1)
        {
            tambah(&HEAD);
        }
        else if (menu == 2)
        {
            int kodeB;
            cout << "Masukkan kode buku yang akan dihapus: ";
            cin >> kodeB;
            hapus(HEAD, kodeB);
        }
        else if (menu == 3)
        {
            tampil(HEAD);
        }
        else if (menu == 4)
        {
            int kBk;
            string awalPin;
            string kembali;

            cout << "Masukan kode buku yang akan dipinjam: ";
            cin >> kBk;
            cout << "Masukan tanggal awal peminjaman: ";
            cin >> awalPin;
            cout << "Masukan tanggal penggembalian: ";
            cin >> kembali;
            transaksi(HEAD, kBk, awalPin, kembali);
        }
        else
        {
            cout << "Pilihan tidak tersedia!!!" << endl;
        }
    }
    return 0;
}
