#include <iostream>
using namespace std;

int main()
{
    // Menginputkan ukuran array
    int uk_152;
    cout << "Masukkan ukuran array: ";
    cin >> uk_152;

    // Deklarasi array
    int arr_3D[uk_152][uk_152][uk_152];

    // Mengisi array
    for (int i = 0; i < uk_152; i++)
    {
        for (int j = 0; j < uk_152; j++)
        {
            for (int k = 0; k < uk_152; k++)
            {
                cout << "Input Array[" << i << "][" << j << "][" << k << "] = ";
                cin >> arr_3D[i][j][k];
            }
        }
    }

    // Output elemen array
    cout << "\nData Array:\n";
    for (int i = 0; i < uk_152; i++)
    {
        for (int j = 0; j < uk_152; j++)
        {
            for (int k = 0; k < uk_152; k++)
            {
                cout << "Array[" << i << "][" << j << "][" << k << "] = " << arr_3D[i][j][k] << endl;
            }
        }
    }

    // Tampilan array
    cout << "\nArray View:\n";
    for (int i = 0; i < uk_152; i++)
    {
        for (int j = 0; j < uk_152; j++)
        {
            for (int k = 0; k < uk_152; k++)
            {
                cout << arr_3D[i][j][k] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
