#include <iostream>
#include <string>
#include <algorithm> // Untuk sort
#include <iomanip>   // Untuk setw
#include <conio.h>   // Untuk _getche

using namespace std;

// Deklarasi Struktur untuk menyimpan karakter dan indeks 
struct KarakterIndeks_152 {
    char karakter_152;
    int indeks_152;
};

// Fungsi binary search untuk mencari sebuah huruf dalam sebuah kalimat
bool binarySearch(const KarakterIndeks_152 *kalimat, int ukuran, char huruf, int &indeksAsli) {
    // Inisialisasi indeks awal dan akhir pencarian
    int awal = 0;
    int akhir = ukuran - 1;

    // Perulangan terus berjalan selama program pencarian masih valid
    while (awal <= akhir) {
        // Hitung indeks tengah interval saat ini
        int tengah = (awal + akhir) / 2;

        // Jika elemen tengah adalah elemen yang dicari, kembalikan true
        if (kalimat[tengah].karakter_152 == huruf) {
            indeksAsli = kalimat[tengah].indeks_152;
            return true;

        // Jika elemen tengah kurang dari elemen yang dicari
        } else if (kalimat[tengah].karakter_152 < huruf) {
            awal = tengah + 1;
        // Jika elemen tengah lebih besar dari elemen yang dicari
        } else {
            akhir = tengah - 1;
        }
    }
// Jika elemen tidak ditemukan dalam perulangan, kembalikan false
    return false;
}

int main() {
    // Loop untuk mengulangi pencarian huruf dalam kalimat
    char ulang;
    do {
        // Input kalimat dan huruf yang akan dicari
        string kalimat;
        char huruf;

        cout << "|--------------------------------------------------------------|" << endl;

    
        const int lebarKonsol = 62;
        string header = "--- PROGRAM PENCARIAN HURUF PADA KALIMAT ---";
        int paddingKiri = (lebarKonsol - header.length()) / 2;

        cout << setw(paddingKiri + header.length()) << header << endl;

        cout << "|--------------------------------------------------------------|" << endl;
        cout << "Masukkan sebuah kalimat: ";
        getline(cin, kalimat);

        cout << "Masukkan huruf yang ingin Anda cari: ";
        
        huruf = _getche(); // Menggunakan _getche untuk mendapatkan input tanpa menekan tombol enter
        cout << endl;


        // Ubah huruf menjadi huruf kecil jika huruf besar
        if (isupper(huruf)) {
            huruf = tolower(huruf);
        }

        // Buat array dinamis untuk pasangan karakter dan indeks aslinya
        int panjangKalimat = kalimat.length();
        KarakterIndeks_152 *kalimatDenganIndeks = new KarakterIndeks_152[panjangKalimat];

      // Mengubah setiap karakter dalam kalimat menjadi huruf kecil dan menyimpannya beserta indeksnya
        for (int i = 0; i < panjangKalimat; i++) {
            kalimatDenganIndeks[i].karakter_152 = tolower(kalimat[i]);
            kalimatDenganIndeks[i].indeks_152 = i;
        }
        // Urutkan array kalimatDenganIndeks berdasarkan karakter
        sort(kalimatDenganIndeks, kalimatDenganIndeks + panjangKalimat, [](const KarakterIndeks_152 &a, const KarakterIndeks_152 &b) {
            // Bandingkan dua karakter, mengembalikan true jika a kurang dari b
            return a.karakter_152 < b.karakter_152;
        });
        // Deklarasi variabel untuk menyimpan indeks asli dari karakter yang dicari
        int indeksAsli;
        // Cari huruf dalam kalimat menggunakan binary search
        bool ditemukan = binarySearch(kalimatDenganIndeks, panjangKalimat, huruf, indeksAsli);

        if (ditemukan) {
            cout << "Huruf (" << huruf << ") ditemukan dalam kalimat pada indeks ke-" << indeksAsli << "." << endl;
        } else {
            cout << "Huruf tidak ditemukan dalam kalimat." << endl;
        }

        delete[] kalimatDenganIndeks;
        cout << "|--------------------------------------------------------------|" << endl;


        // Untuk ngecek apakah user ingin mengulang
        cout << "Apakah Anda ingin mencari huruf lagi? (y/n): ";
        ulang = _getche();
        cout << endl;

    } while (ulang == 'y' || ulang == 'Y');

    return 0;
}
