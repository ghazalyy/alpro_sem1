#include <iostream>
#include <string>

using namespace std;

struct Nasabah
{
    int no_rekening;
    string nama;
    string alamat;
    float saldo;
    Nasabah *next;
};

void tambahNasabah(Nasabah *&head)
{
    Nasabah *nsbBaru = new Nasabah();
    cout << "Masukkan No. Rekening: ";
    cin >> nsbBaru->no_rekening;
    cout << "Masukkan Nama: ";
    cin.ignore();
    getline(cin, nsbBaru->nama);
    cout << "Masukkan Alamat: ";
    getline(cin, nsbBaru->alamat);
    cout << "Masukkan Saldo: ";
    cin >> nsbBaru->saldo;
    nsbBaru->next = nullptr;

    if (head == nullptr)
    {
        head = nsbBaru;
        return;
    }

    Nasabah *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = nsbBaru;
}

void tampilkanNasabah(Nasabah *head)
{
    Nasabah *temp = head;
    if (temp == NULL)
    {
        cout << "Tidak ada nasabah." << endl;
        return;
    }
    while (temp != NULL)
    {
        cout << "Daftar Nasabah: " << endl;
        cout << "No. Rekening: " << temp->no_rekening << endl;
        cout << "Nama: " << temp->nama << endl;
        cout << "Alamat: " << temp->alamat << endl;
        cout << "Saldo: " << temp->saldo << endl
             << endl;
        temp = temp->next;
    }
}

void hapusNasabah(Nasabah *&head, int noRek)
{
    Nasabah *skr = head;
    Nasabah *prev = nullptr;

    if (skr != nullptr && skr->no_rekening == noRek)
    {
        head = skr->next;
        delete skr;
        cout << "Data nasabah dengan nomor rekening " << noRek << " telah dihapus." << endl;
        return;
    }

    while (skr != nullptr && skr->no_rekening != noRek)
    {
        prev = skr;
        skr = skr->next;
    }

    if (skr == nullptr)
    {
        cout << "Nasabah dengan nomor rekening " << noRek << " tidak ditemukan." << endl;
        return;
    }

    prev->next = skr->next;
    delete skr;
    cout << "Data nasabah dengan nomor rekening " << noRek << " telah dihapus." << endl;
}

void transaksi(Nasabah *head, int noRek, char jenisTransaksi, float jumlah)
{
    Nasabah *temp = head;

    while (temp != nullptr && temp->no_rekening != noRek)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Nasabah dengan nomor rekening " << noRek << " tidak ditemukan." << endl;
        return;
    }

    if (jenisTransaksi == 'D')
    {
        temp->saldo += jumlah;
        cout << "Transaksi deposit berhasil." << endl;
    }
    else if (jenisTransaksi == 'T')
    {
        if (temp->saldo >= jumlah)
        {
            temp->saldo -= jumlah;
            cout << "Transaksi tarik tunai berhasil." << endl;
        }
        else
        {
            cout << "Saldo tidak mencukupi untuk melakukan transaksi tarik tunai." << endl;
        }
    }
    else
    {
        cout << "Jenis transaksi tidak valid." << endl;
    }
}

void cekSaldo(Nasabah *head, int noRek)
{
    Nasabah *temp = head;

    while (temp != nullptr && temp->no_rekening != noRek)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Nasabah dengan nomor rekening " << noRek << " tidak ditemukan." << endl;
        return;
    }

    cout << "Saldo untuk nasabah " << temp->nama << " (No. Rekening: " << temp->no_rekening << ") adalah: " << temp->saldo << endl;
}

void cariNasabah(Nasabah *head, int noRek)
{
    Nasabah *temp = head;

    while (temp != nullptr && temp->no_rekening != noRek)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Nasabah dengan nomor rekening " << noRek << " tidak ditemukan." << endl;
        return;
    }

    cout << "Data Nasabah: " << endl;
    cout << "No. Rekening: " << temp->no_rekening << endl;
    cout << "Nama: " << temp->nama << endl;
    cout << "Alamat: " << temp->alamat << endl;
    cout << "Saldo: " << temp->saldo << endl;
}

void UpdateData(Nasabah **head)
{
    if (*head == nullptr)
    {
        cout << "Linkedlist masih kosong" << endl;
        return;
    }

    int norek;
    cout << "Masukkan No Rekening Nasabah yang ingin diubah: ";
    cin >> norek;

    Nasabah *temp = *head;
    while (temp != nullptr)
    {
        if (temp->no_rekening == norek)
        {
            cout << "Masukan No Rekening yang baru: ";
            cin >> temp->no_rekening;
            cout << "Masukkan nama yang baru: ";
            cin.ignore();             
            getline(cin, temp->nama);
            cout << "Masukan alamat yang baru: ";
            getline(cin, temp->alamat);
            cout << "Data telah berhasil diubah" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Data tidak ditemukan" << endl;
}

void hapusSemuaNasabah(Nasabah *&head)
{
    Nasabah *temp = head;
    Nasabah *nextNode;

    while (temp != nullptr)
    {
        nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    head = nullptr;
}

float TotalSaldo(Nasabah *head)
{
    float totalSaldo = 0.0;
    Nasabah *temp = head;

    while (temp != nullptr)
    {
        totalSaldo += temp->saldo;
        temp = temp->next;
    }

    return totalSaldo;
}

float RataRataSaldo(Nasabah *head)
{
    int jumlahNasabah = 0;
    float totalSaldo = 0.0;
    Nasabah *temp = head;

    while (temp != nullptr)
    {
        totalSaldo += temp->saldo;
        jumlahNasabah++;
        temp = temp->next;
    }

    if (jumlahNasabah != 0)
    {
        return totalSaldo / jumlahNasabah;
    }
    else
    {
        return 0.0;
    }
}

int main()
{
    Nasabah *HEAD = nullptr;

    int menu;
    while (menu != 11)
    {
        cout << "===SELAMAT DATANG===" << endl;
        cout << "1. Input Data Nasabah" << endl;
        cout << "2. Hapus Data Nasabah" << endl;
        cout << "3. Transaksi" << endl;
        cout << "4. Cek Saldo" << endl;
        cout << "5. Tampilkan Daftar Nasabah" << endl;
        cout << "6. Cari Data Nasabah" << endl;
        cout << "7. Update Data Nasabah" << endl;
        cout << "8. Hapus semua data nasabah" << endl;
        cout << "9. Total saldo nasabah" << endl;
        cout << "10. Rata-rata saldo nasabah" << endl;
        cout << "11. Exit" << endl;

        cout << "Silahkan Pilih Menu: ";
        cin >> menu;

        if (menu == 1)
        {
            system("cls");
            tambahNasabah(HEAD);
        }
        else if (menu == 2)
        {
            system("cls");
            int no_rek;
            cout << "Masukkan nomor rekening yang akan dihapus: ";
            cin >> no_rek;
            hapusNasabah(HEAD, no_rek);
        }
        else if (menu == 3)
        {
            system("cls");
            int no_rek;
            char jenis;
            float jumlah;

            cout << "Masukkan nomor rekening: ";
            cin >> no_rek;
            cout << "Pilih jenis transaksi (D = Deposit, T = Tarik Tunai): ";
            cin >> jenis;
            cout << "Masukkan jumlah: ";
            cin >> jumlah;
            transaksi(HEAD, no_rek, jenis, jumlah);
        }
        else if (menu == 4)
        {
            system("cls");
            int no_rek;
            cout << "Masukkan nomor rekening untuk cek saldo: ";
            cin >> no_rek;

            cekSaldo(HEAD, no_rek);
        }
        else if (menu == 5)
        {
            system("cls");
            tampilkanNasabah(HEAD);
        }
        else if (menu == 6)
        {
            system("cls");
            int no_rek;
            cout << "Masukkan nomor rekening untuk mencari data nasabah: ";
            cin >> no_rek;

            cariNasabah(HEAD, no_rek);
        }
        else if (menu == 7)
        {
            system("cls");
            UpdateData(&HEAD);
        }
        else if (menu == 8)
        {
            hapusSemuaNasabah(HEAD);
            cout << "Seluruh data nasabah telah dihapus." << endl;
        }
        else if (menu == 9)
        {
            float totalSaldo = TotalSaldo(HEAD);
            cout << "Total Saldo Semua Nasabah: " << totalSaldo << endl;
        }
        else if (menu == 10)
        {
            float rataRataSaldo = RataRataSaldo(HEAD);
            cout << "Rata-rata Saldo Nasabah: " << rataRataSaldo << endl;
        }
        else
        {
            cout << "Pilihan tidak ada !" << endl;
        }
    }
    return 0;
}

/*
Muhammad Syifa Ghazaly
3337230085
*/