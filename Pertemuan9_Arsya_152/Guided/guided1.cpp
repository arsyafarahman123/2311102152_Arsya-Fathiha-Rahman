#include <iostream> // Memasukkan library iostream untuk input-output
#include <iomanip>  // Memasukkan library iomanip untuk manipulasi input-output
using namespace std;

// Mendeklarasikan array string yang berisi nama-nama kota
string simpul[7] = {"Ciamis", "Bandung", "Bekasi",
                    "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"};

// Mendeklarasikan matriks busur yang berisi bobot dari setiap busur antar simpul (nama kota)
int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}};

// Fungsi untuk menampilkan graf
void tampilGraph()
{
    // Loop untuk setiap baris (simpul)
    for (int baris = 0; baris < 7; baris++)
    {
        // Menampilkan nama simpul dan mengatur lebar kolom dengan manipulasi output
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        
        // Loop untuk setiap kolom dalam baris tersebut
        for (int kolom = 0; kolom < 7; kolom++)
        {
            // Jika ada busur (bobot tidak nol) antara simpul baris dan kolom
            if (busur[baris][kolom] != 0)
            {
                // Menampilkan nama simpul tujuan dan bobot busur
                cout << " " << simpul[kolom] << "(" << busur[baris][kolom] << ")";
            }
        }
        // Pindah ke baris baru setelah selesai dengan simpul saat ini
        cout << endl;
    }
}

// Fungsi utama program
int main()
{
    // Memanggil fungsi untuk menampilkan graf
    tampilGraph();
    return 0; // Mengembalikan nilai 0 yang menunjukkan program berakhir dengan sukses
}
