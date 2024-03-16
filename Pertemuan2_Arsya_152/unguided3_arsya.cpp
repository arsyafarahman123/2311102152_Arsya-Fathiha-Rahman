#include <iostream>
using namespace std;

int main() {
    int pilihan_152;

    do {
        cout << "Menu Pilihan:\n"
             << "1. Mencari Nilai Maksimum\n"
             << "2. Mencari Nilai Minimum\n"
             << "3. Mencari Nilai Rata-rata\n"
             << "0. Keluar\n"
             << "Masukkan pilihan (1/2/3/0): ";
        cin >> pilihan_152;

        if (pilihan_152 >= 1 && pilihan_152 <= 3) {
            int array_152;
            cout << "Masukkan jumlah angka: ";
            cin >> array_152;

            if (array_152 <= 0) {
                cout << "Jumlah angka tidak valid.\n";
                continue;
            }

            int array[array_152];
            cout << "Masukkan " << array_152 << " angka:\n";
            for (int i = 0; i < array_152; i++) {
                cout << "Array ke-" << (i + 1) << ": ";
                cin >> array[i];
            }

            switch (pilihan_152) {
                case 1: {
                    int maks = array[0];
                    for (int i = 1; i < array_152; i++)
                        if (array[i] > maks)
                            maks = array[i];
                    cout << "Nilai maksimum: " << maks << endl;
                    break;
                }
                case 2: {
                    int min = array[0];
                    for (int i = 1; i < array_152; i++)
                        if (array[i] < min)
                            min = array[i];
                    cout << "Nilai minimum: " << min << endl;
                    break;
                }
                case 3: {
                    double total = 0;
                    for (int i = 0; i < array_152; i++)
                        total += array[i];
                    double rataRata = total / array_152;
                    cout << "Nilai rata-rata: " << rataRata << endl;
                    break;
                }
            }
        } else if (pilihan_152 != 0) {
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }

    } while (pilihan_152 != 0);

    cout << "Program selesai.\n";
    return 0;
}
