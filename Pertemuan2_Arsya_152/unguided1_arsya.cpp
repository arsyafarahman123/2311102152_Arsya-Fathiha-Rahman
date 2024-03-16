#include <iostream>

using namespace std;

/*
by Arsya Fathiha Rahman - 2311102152
*/
int main() {
    int bilangan_152[10];

    // Meminta users untuk inputin angka
    cout << "Data Array: ";

    // array data yang dimasukkan users
    for (int i = 0; i < 10; i++) {
        cin >> bilangan_152[i];
    }

    cout << "\nNomor genap: ";
    for (int i = 0; i < 10; i++) {
        if (bilangan_152[i] % 2 == 0) {
            cout << bilangan_152[i];
            if (i < 9) {
                cout << ", ";
            }
        }
}

    cout << "\nNomor ganjil: ";
    for (int i = 0; i < 10; i++) {
        if (bilangan_152[i] % 2 != 0) {
            cout << bilangan_152[i];
            if (i < 9) {
                cout << ", ";
            }
        }
    }
    
    cout << endl;
    return 0;
}
