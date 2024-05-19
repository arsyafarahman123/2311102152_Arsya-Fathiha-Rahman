#include <iostream>

using namespace std;

int main()
{
    // Input data array dari pengguna
    int data_152[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int n_152 = sizeof(data_152) / sizeof(data_152[0]); // Jumlah elemen data

    // Menampilkan header
    cout << "|--------------------------------------------------------------|" << endl;

    // Menampilkan nama program
    cout << "| ";
    string header = "--- PROGRAM PENCARIAN ANGKA DALAM DATA ---";
    int padding = (60 - header.length()) / 2;
    cout << string(padding, ' ') << header << string(padding, ' ') << " |" << endl;
    cout << "|--------------------------------------------------------------|" << endl;

    // Menampilkan data array
    cout << "| Masukkan data: ";
    for (int i = 0; i < n_152; i++)
    {
        cout << data_152[i]; // Menampilkan angka pada indeks ke-i
        // Jika bukan elemen terakhir, tambahkan koma dan spasi
        if (i < n_152 - 1)
        {
            cout << ", ";
        }
    }
    cout << "." << endl;
    // Input angka yang dicari dari pengguna
    int angkaDicari;
    cout << "| Masukkan angka yang ingin Anda cari dari data berikut: ";
    cin >> angkaDicari;

    // Inisialisasi jumlah kemunculan angka yang dicari
    int jumlahKemunculan = 0;

    // Algoritma Sequential Search
    for (int i = 0; i < n_152; i++)
    {
        // Memeriksa apakah angka pada indeks ke-i sama dengan angka yang dicari
        if (data_152[i] == angkaDicari)
        {
            jumlahKemunculan++; // Jika iya, tambahkan 1 ke jumlah kemunculan
        }
    }

    // Menampilkan hasil
    cout << "|--------------------------------------------------------------|" << endl;
    cout << "| Banyaknya angka " << angkaDicari << " dalam data adalah " << jumlahKemunculan << ".";
    cout << string(57, ' ') << " |" << endl;
    cout << "|--------------------------------------------------------------|" << endl;

    return 0;
}
