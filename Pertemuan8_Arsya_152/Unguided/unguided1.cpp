#include <iostream>  // Untuk input-output standar
#include <string>    // Untuk penggunaan tipe data string
#include <algorithm> // Untuk fungsi sort
#include <iomanip>   // Untuk fungsi setw
#include <conio.h>   // Untuk fungsi _getche

using namespace std;

// Deklarasi Struktur untuk menyimpan karakter dan indeks 
struct KarakterIndeks_152 {
    char karakter_152; // Karakter dalam kalimat
    int indeks_152;     // Indeks karakter dalam kalimat
};

// Fungsi binary search untuk mencari semua huruf yang sama dalam sebuah kalimat
void binarySearch_152(const KarakterIndeks_152 *kalimat, int ukuran, char huruf, int* indeksAsliList, int& jumlah) {
    int awal = 0;          // Indeks awal pencarian
    int akhir = ukuran - 1; // Indeks akhir pencarian

    while (awal <= akhir) {
        int tengah = (awal + akhir) / 2; // Indeks tengah

        // Jika huruf ditemukan pada indeks tengah
        if (kalimat[tengah].karakter_152 == huruf) {
            int kiri = tengah; // Indeks untuk pencarian ke kiri
            int kanan = tengah; // Indeks untuk pencarian ke kanan

            // Cari huruf yang sama ke kiri
            while (kiri >= 0 && kalimat[kiri].karakter_152 == huruf) {
                indeksAsliList[jumlah++] = kalimat[kiri].indeks_152;
                kiri--;
            }

            // Cari huruf yang sama ke kanan
            while (kanan < ukuran && kalimat[kanan].karakter_152 == huruf) {
                if (kanan != tengah) {
                    indeksAsliList[jumlah++] = kalimat[kanan].indeks_152;
                }
                kanan++;
            }

            // Urutkan indeks huruf yang ditemukan
            sort(indeksAsliList, indeksAsliList + jumlah);
            return;
        }
        // Jika huruf berada di sebelah kanan tengah
        else if (kalimat[tengah].karakter_152 < huruf) {
            awal = tengah + 1; // Perbarui indeks awal
        }
        // Jika huruf berada di sebelah kiri tengah
        else {
            akhir = tengah - 1; // Perbarui indeks akhir
        }
    }
}

// Fungsi untuk mencetak data yang sudah diurutkan
void cetakData_152(const KarakterIndeks_152 *kalimatDenganIndeks, int panjangKalimat) {
    cout << "| Data diurutkan menggunakan Ascending menjadi: ";
    int count = 0;
    for (int i = 0; i < panjangKalimat; i++) {
        cout << kalimatDenganIndeks[i].karakter_152 << " ";
        count++;
        if (count >= 10 && i != panjangKalimat - 1) {
            cout << endl    << "|                                                  ";
            count = 0;
        }
    }
    cout << endl;
}

int main() {
    char ulang;
    do {
        string kalimat; // Variabel untuk menyimpan kalimat
        char huruf;     // Variabel untuk menyimpan huruf yang dicari

        // Input kalimat dan huruf
        cout << "Masukkan sebuah kalimat: ";
        getline(cin, kalimat);

        cout << "Masukkan huruf yang ingin Anda cari: ";
        huruf = _getche();
        cout << endl;

        cout << "|---------------------------------------------------------------------|" << endl;
        cout << "|  Sebuah Kalimat               |  Huruf yang anda cari               |" << endl;
        cout << "|---------------------------------------------------------------------|" << endl;

        // Tampilkan kalimat dan huruf yang diinput
        cout << "| " << setw(30) << left << kalimat << "| " << setw(36) << left << huruf  << "|" << endl;
        cout << "|---------------------------------------------------------------------|" << endl;

        // Ubah huruf menjadi huruf kecil jika huruf yang dimasukkan adalah huruf besar
        if (isupper(huruf)) {
            huruf = tolower(huruf);
        }

        int panjangKalimat = kalimat.length(); // Panjang kalimat
        KarakterIndeks_152 *kalimatDenganIndeks = new KarakterIndeks_152[panjangKalimat]; // Array untuk menyimpan karakter dan indeksnya

        // Isi array dengan karakter kalimat dan indeksnya
        for (int i = 0; i < panjangKalimat; i++) {
            kalimatDenganIndeks[i].karakter_152 = tolower(kalimat[i]);
            kalimatDenganIndeks[i].indeks_152 = i;
        }

        // Urutkan array berdasarkan karakter
        sort(kalimatDenganIndeks, kalimatDenganIndeks + panjangKalimat, [](const KarakterIndeks_152 &a, const KarakterIndeks_152 &b) {
            return a.karakter_152 < b.karakter_152;
        });

        cout << "|---------------------------------------------------------------------|" << endl;
        cetakData_152(kalimatDenganIndeks, panjangKalimat);
        cout << "|---------------------------------------------------------------------|" << endl;

        int indeksAsliList[panjangKalimat]; // Array untuk menyimpan indeks huruf yang ditemukan
        int jumlah = 0; // Jumlah huruf yang ditemukan

        // Cari dan simpan indeks huruf yang ditemukan
        binarySearch_152(kalimatDenganIndeks, panjangKalimat, huruf, indeksAsliList, jumlah);

        cout << "|---------------------------------------------------------------------|" << endl;
        // Tampilkan hasil pencarian huruf
        if (jumlah > 0) {
            cout << "| Huruf (" << huruf << ") ditemukan dalam kalimat pada indeks ke- ";
            for (int i = 0; i < jumlah; ++i) {
                cout << indeksAsliList[i];
                if (i < jumlah - 1) {
                    cout << " dan ke-";
                }
            }
            cout << "." << endl;
        } else {
            cout << "| Huruf tidak ditemukan dalam kalimat." << endl;
        }
        cout << "|---------------------------------------------------------------------|" << endl;

        delete[] kalimatDenganIndeks; // Hapus memori yang dialokasikan

        // Minta pengguna apakah ingin mencari huruf lagi
        cout << "Apakah Anda ingin mencari huruf lagi? (y/n): ";
        ulang = _getche();
        cout << endl;

    } while (ulang == 'y' || ulang == 'Y');

    return 0;
}
