#include <iostream>
#include <bitset>
using namespace std;

int main() {
    char pilihan_152 ;
    int BilanganDesimal_152;

    // Meminta pengguna untuk memasukkan angka desimal
    cout << "Masukkan bilangan desimal: ";
    cin >> BilanganDesimal_152;

    // Menampilkan hasil konversi sesuai dengan pilihan (default: heksadesimal)
    cout << "Heksadesimal: " << hex << BilanganDesimal_152 << endl;
    cout << "Biner: " << bitset<32>(BilanganDesimal_152).to_string() << endl;
    cout << "Oktal: " << oct << BilanganDesimal_152 << endl;

    return 0;
}
