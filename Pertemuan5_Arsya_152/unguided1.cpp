#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const int TABLE_SIZE = 10;

// Class data mahasiswa
class Mahasiswa_152 {
public:
    string nama_152;
    string NIM_152; 
    int nilai_152;

    Mahasiswa_152(string nama, string NIM, int nilai) {
        this->nama_152 = nama;
        this->NIM_152 = NIM;
        this->nilai_152 = nilai;
    }
};

class HashNode {
public:
    Mahasiswa_152* data;

    HashNode(Mahasiswa_152* data) {
        this->data = data;
    }
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];

public:
    int hashFunc(string key) {
        // Menggunakan hash dari jumlah karakter NIM
        return key.length() % TABLE_SIZE;
    }

    // Fungsi untuk menambahkan data baru
    void insert(Mahasiswa_152* mahasiswa) {
        int hash_val = hashFunc(mahasiswa->NIM_152);
        for (auto node : table[hash_val]) {
            if (node->data->NIM_152 == mahasiswa->NIM_152) {
                // Jika NIM sudah ada, update nilai mahasiswa
                node->data->nilai_152 = mahasiswa->nilai_152;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(mahasiswa));
    }

    // Fungsi untuk menghapus data
    void remove(string NIM) {
        int hash_val = hashFunc(NIM);
        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
            if ((*it)->data->NIM_152 == NIM) {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    // Fungsi untuk mencari data berdasarkan NIM
    Mahasiswa_152* searchByNIM(string NIM) {
        int hash_val = hashFunc(NIM);
        for (auto node : table[hash_val]) {
            if (node->data->NIM_152 == NIM) {
                return node->data;
            }
        }
        return nullptr;
    }

    // Fungsi untuk mencari data berdasarkan rentang nilai (80 - 90)
    void searchByScoreRange() {
        cout << "Data dengan nilai antara 80 dan 90:\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            for (auto node : table[i]) {
                if (node->data->nilai_152 >= 80 && node->data->nilai_152 <= 90) {
                    cout << "NIM: " << node->data->NIM_152 << ", Nama: " << node->data->nama_152 << ", Nilai: " << node->data->nilai_152 << endl;
                }
            }
        }
    }

   // Traversal
    void Traverse_152() {
        cout << left << setw(17) << "-NAME-" << setw(17) << "-NIM-" << setw(12) << "-NILAI-" << endl;
        for (int i = 0; i < TABLE_SIZE; i++) { 
            for (auto node : table[i]) { 
                cout << left << setw(17) << node->data->nama_152 << setw(19) << node->data->NIM_152 << setw(12) << node->data->nilai_152 << endl;
            }
        }
    }
};

int main() {
    HashMap mahasiswaMap;
    // Menu
    int choice;
    do {
        cout << "==============================================================" << endl;
        cout << "             PROGRAM HASHTABLE PENCARIAN DATA MAHASISWA       " << endl;
        cout << "==============================================================" << endl;
        cout << "\nMenu:\n";
        cout << setw(3) << "1. " << setw(17) << left << "Tambah data mahasiswa" << endl;
        cout << setw(3) << "2. " << setw(17) << left << "Hapus data mahasiswa" << endl;
        cout << setw(3) << "3. " << setw(17) << left << "Cari data mahasiswa berdasarkan NIM" << endl;
        cout << setw(3) << "4. " << setw(17) << left << "Cari data mahasiswa berdasarkan rentang nilai (80 - 90)" << endl;
        cout << setw(3) << "5. " << setw(17) << left << "Tampilkan semua data mahasiswa" << endl;
        cout << setw(3) << "6. " << setw(17) << left << "Keluar" << endl;
        cout << "Pilih: ";
        cin >> choice;
        cout << "==============================================================" << endl;


        switch (choice) {
            case 1: {
                string nama;
                string NIM; // Menggunakan string untuk NIM
                int nilai;
                cout << "Masukkan nama mahasiswa: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> NIM;
                cout << "Masukkan nilai: ";
                cin >> nilai;
                mahasiswaMap.insert(new Mahasiswa_152(nama, NIM, nilai));
                break;
            }
            case 2: {
                string delNIM; // Menggunakan string untuk NIM
                cout << "Masukkan NIM mahasiswa untuk menghapus data: ";
                cin >> delNIM;
                cout << "Data berhasil dihapus." << endl;

                mahasiswaMap.remove(delNIM);
                break;
            }
            case 3: {
                string searchNIM; // Menggunakan string untuk NIM
                cout << "Masukkan NIM mahasiswa untuk mencari data: ";
                cin >> searchNIM;
                if (Mahasiswa_152* result = mahasiswaMap.searchByNIM(searchNIM)) {
                    cout << "Data ditemukan - NIM: " << result->NIM_152 << ", Nama: " << result->nama_152 << ", Nilai: " << result->nilai_152 << endl;
                } else {
                    cout << "Data tidak ditemukan.\n";
                }
                break;
            }
            case 4:
                mahasiswaMap.searchByScoreRange();
                break;
            case 5:
                cout << "Tabel Hash:\n";
                mahasiswaMap.Traverse_152();
                break;
            case 6:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (choice != 6);
       cout << "=============================================================" << endl;
    cout << "                Made By: ArsyafathihaRahman                     " << endl;
    cout << "=============================================================== " << endl;


    return 0;
}
