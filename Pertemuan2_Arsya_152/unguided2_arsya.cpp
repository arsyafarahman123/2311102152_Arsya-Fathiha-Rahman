#include <iostream>
using namespace std;

int main() {
    // Menginputkan uk array
    int ukX, ukY, ukZ;
    cout << "Masukkan ukuran array (X Y Z): ";
    cin >> ukX >> ukY >> ukZ;

    // Deklarasi array
    int arr_152[ukX][ukY][ukZ];

    for (int x = 0; x < ukX; x++) {
        for (int y = 0; y < ukY; y++) {
            for (int z = 0; z < ukZ; z++) {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr_152[x][y][z];
            }
        }
    }

    // Output elemen array
    cout << "\nData Array:\n";
    for (int x = 0; x < ukX; x++) {
        for (int y = 0; y < ukY; y++) {
            for (int z = 0; z < ukZ; z++) {
                cout << "Array[" << x << "][" << y << "][" << z << "] = " << arr_152[x][y][z] << endl;
            }
        }
    }

    // Tampilan array
    cout << "\nArray View:\n";
    for (int x = 0; x < ukX; x++) {
        for (int y = 0; y < ukY; y++) {
            for (int z = 0; z < ukZ; z++) {
                cout << arr_152[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
