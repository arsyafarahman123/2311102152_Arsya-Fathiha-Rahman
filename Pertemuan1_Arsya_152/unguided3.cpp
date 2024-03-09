#include <iostream>
#include <map>

using namespace std;

//Program untuk mencari kelas berdasarkan nama mahasiswa menggunakan fungsi Map
int main() {
    map<string, string> kelas_152 = {
        {"Arsya", "IF11A"},
        {"Ayu", "IF11B"},
        {"Nisrin", "IF11C"},
        {"Nisa", "IF11D"}
    };

    // Meminta user menginputkan nama mahasiswa untuk dicari
    string namaCari_152;
    cout << "Masukkan nama mahasiswa yang ingin dicari: ";
    cin >> namaCari_152;

    // Mencari dan menampilkan hasil pencarian
    if (kelas_152.count(namaCari_152) > 0) {
        cout << "Kelas " << namaCari_152 << " adalah " << kelas_152[namaCari_152] << '\n';
    } else {
        cout << "Nama mahasiswa tidak ditemukan.\n";
    }

    return 0;
}
