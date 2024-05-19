#include <iostream>
#include <string>
#include <iomanip> // Untuk setw

using namespace std;

// Sequential search untuk memeriksa apakah huruf adalah vokal
bool MenentukanVokal_152(char huruf_152) {
    return (huruf_152 == 'a' || huruf_152 == 'A' ||
            huruf_152 == 'i' || huruf_152 == 'I' ||
            huruf_152 == 'u' || huruf_152 == 'U' ||
            huruf_152 == 'e' || huruf_152 == 'E' ||
            huruf_152 == 'o' || huruf_152 == 'O');
}

// Fungsi untuk menghitung jumlah huruf vokal dalam sebuah kalimat
int hitungVokal_152(const string &kalimat) {
    // Inisialisasi jumlah huruf vokal
    int jumlahVokal = 0;

    // Sequential search: Loop untuk setiap karakter dalam kalimat
    for (int i = 0; i < kalimat.length(); i++) {
        char huruf = kalimat[i];
        // fungsi Menentukan Vokal untuk memeriksa apakah karakter adalah huruf vokal
        if (MenentukanVokal_152(huruf)) {
            jumlahVokal++;
        }
    }

    return jumlahVokal;
}

int main() {
    char ulang;
    do {
        // Input dari pengguna
        string kalimat;
        
        cout << "|--------------------------------------------------------------|" << endl;

        const int lebarKonsol = 62; 
        string header = "--- PROGRAM MENGHITUNG HURUF VOKAL DALAM KALIMAT ---";
        int paddingKiri = (lebarKonsol - header.length()) / 2;

        cout << setw(paddingKiri + header.length()) << header << endl;

        cout << "|--------------------------------------------------------------|" << endl;
        
        cout << "Masukkan sebuah kalimat: ";
        getline(cin, kalimat);

        cout << "|--------------------------------------------------------------|" << endl;
        
        // Panggil fungsi dan cetak hasil
        int jumlah = hitungVokal_152(kalimat);
        cout << "Jumlah huruf vokal dalam kalimat adalah: " << jumlah << endl;

        cout << "|--------------------------------------------------------------|" << endl;

        // Untuk ngecek apakah user ingin mengulang
        cout << "Apakah Anda ingin menghitung huruf vokal lagi? (y/n): ";
        cin >> ulang;
        cin.ignore();
        cout << endl;

    } while (ulang == 'y' || ulang == 'Y');

    return 0;
}
