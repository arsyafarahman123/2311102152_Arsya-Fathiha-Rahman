#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

int dataArray[7] = {1, 8, 2, 5, 4, 9, 7}; // Array data awal yang akan diurutkan dan dicari
int cari; // Variabel untuk menyimpan nilai yang akan dicari

// Fungsi untuk mengurutkan array dengan algoritma selection sort
void selection_sort() {
    int temp, min, i, j;
    for (i = 0; i < 7; i++) { // Loop untuk setiap elemen dalam array
        min = i; // Anggap elemen pertama sebagai yang terkecil
        for (j = i + 1; j < 7; j++) { // Loop untuk menemukan elemen terkecil di sisa array
            if (dataArray[j] < dataArray[min]) {
                min = j; // Jika ditemukan elemen yang lebih kecil, update indeks min
            }
        }
        // Tukar elemen terkecil yang ditemukan dengan elemen pada indeks i
        temp = dataArray[i];
        dataArray[i] = dataArray[min];
        dataArray[min] = temp;
    }
}

// Fungsi untuk mencari nilai dalam array dengan algoritma binary search
void binarysearch() {
    int awal, akhir, tengah;
    bool b_flag = false;
    awal = 0; // Indeks awal array
    akhir = 6; // Indeks akhir array (karena ada 7 elemen, indeks terakhir adalah 6)
    while (!b_flag && awal <= akhir) {
        tengah = (awal + akhir) / 2; // Hitung indeks tengah
        if (dataArray[tengah] == cari) { // Jika elemen tengah adalah elemen yang dicari
            b_flag = true;
        } else if (dataArray[tengah] < cari) { // Jika elemen tengah lebih kecil dari elemen yang dicari
            awal = tengah + 1; // Pindahkan awal ke kanan tengah
        } else { // Jika elemen tengah lebih besar dari elemen yang dicari
            akhir = tengah - 1; // Pindahkan akhir ke kiri tengah
        }
    }
    if (b_flag) {
        cout << "\nData ditemukan pada index ke- " << tengah << endl; // Jika ditemukan, cetak indeks
    } else {
        cout << "\nData tidak ditemukan\n"; // Jika tidak ditemukan, cetak pesan tidak ditemukan
    }
}

int main() {
    cout << "\tBINARY SEARCH" << endl;
    cout << "\nData: ";
    // Tampilkan data awal
    for (int x = 0; x < 7; x++) {
        cout << setw(3) << dataArray[x];
    }
    cout << endl;
    cout << "\nMasukkan data yang ingin Anda cari: ";
    cin >> cari; // Ambil input dari pengguna untuk nilai yang dicari
    cout << "\nData diurutkan: ";
    // Urutkan data dengan selection sort
    selection_sort();
    // Tampilkan data setelah diurutkan
    for (int x = 0; x < 7; x++) {
        cout << setw(3) << dataArray[x];
    }
    cout << endl;
    // Lakukan pencarian biner pada data yang sudah diurutkan
    binarysearch();
    _getche(); // Tunggu pengguna menekan tombol sebelum program selesai
    return 0;
}