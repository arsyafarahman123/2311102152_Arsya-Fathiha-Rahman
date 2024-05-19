#include <iostream>
using namespace std;
int main()
{
    int n = 10; // Mendefinisikan jumlah elemen dalam array
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};// Mendefinisikan array dengan 10 elemen
    int cari = 10; // Nilai yang ingin dicari dalam array
    bool ketemu = false;// Variabel untuk menandakan apakah nilai ditemukan
    int i; // Variabel untuk iterasi

    // Algoritma Sequential Search
    for (i = 0; i < n; i++) // Looping melalui setiap elemen array
    {
        if (data[i] == cari) // Jika elemen saat ini sama dengan nilai yang dicari
        {
            ketemu = true; // Set ketemu menjadi true
            break;
        }
    }
    // Menampilkan pesan hasil pencarian

    cout << "\tProgram Sequential Search Sederhana\n"
         << endl;
    cout << "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;
    if (ketemu)
    {
        cout << "\nAngka " << cari << " ditemukan pada indeks ke-"
             << i << endl;
    }
    else
    {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }
    return 0; // Mengembalikan nilai 0 menandakan program selesai dengan sukses
}