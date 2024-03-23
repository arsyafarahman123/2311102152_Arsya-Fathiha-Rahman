/*
by Arsya Fathiha Rahman - 2311102152
*/
#include <iostream>
#include <iomanip> 
#include <string>

using namespace std;

class Node {
public:
    string nama_produk_152;
    double harga;
    Node* prev;
    Node* next;

    Node(string nama, double harga_152) : nama_produk_152(nama), harga(harga_152), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void add_data_152(string nama_produk, double harga) {
        Node* new_node = new Node(nama_produk, harga);
        if (head == nullptr) {
            head = new_node;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new_node;
            new_node->prev = current;
        }
    }

    void tambah_data_urutan_tertentu(string nama_produk, double harga, int urutan) {
        if (urutan < 1) {
            cout << "Urutan tidak valid" << endl;
            return;
        }

        Node* new_node = new Node(nama_produk, harga);
        if (urutan == 1 || head == nullptr) {
            new_node->next = head;
            if (head != nullptr) {
                head->prev = new_node;
            }
            head = new_node;
        } else {
            Node* current = head;
            int pos = 1;
            while (current != nullptr && pos < urutan - 1) {
                current = current->next;
                pos++;
            }
            if (current == nullptr) {
                cout << "Urutan tidak valid" << endl;
                return;
            }
            new_node->next = current->next;
            new_node->prev = current;
            if (current->next != nullptr) {
                current->next->prev = new_node;
            }
            current->next = new_node;
        }
    }

    void hapus_data(string nama_produk) {
        Node* current = head;
        while (current != nullptr) {
            if (current->nama_produk_152 == nama_produk) {
                if (current->prev) {
                    current->prev->next = current->next;
                }
                if (current->next) {
                    current->next->prev = current->prev;
                }
                if (current == head) {
                    head = current->next;
                }
                delete current;
                return;
            }
            current = current->next;
        }
        cout << "Produk tidak ditemukan" << endl;
    }

    void update_data(string nama_produk, string new_nama_produk, double new_harga) {
        Node* current = head;
        while (current != nullptr) {
            if (current->nama_produk_152 == nama_produk) {
                current->nama_produk_152 = new_nama_produk;
                current->harga = new_harga;
                return;
            }
            current = current->next;
        }
        cout << "Produk tidak ditemukan" << endl;
    }

    void hapus_seluruh_data() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
    }

    void hapus_data_urutan_tertentu(int urutan) {
        if (urutan < 1) {
            cout << "Urutan tidak valid" << endl;
            return;
        }
        Node* current = head;
        int pos = 1;
        while (current != nullptr && pos < urutan) {
            current = current->next;
            pos++;
        }
        if (current == nullptr) {
            cout << "Urutan tidak valid" << endl;
            return;
        }
        if (current->prev) {
            current->prev->next = current->next;
        }
        if (current->next) {
            current->next->prev = current->prev;
        }
        if (current == head) {
            head = current->next;
        }
        delete current;
    }

    void tampilkan_data() {
        if (head == nullptr) {
            cout << "Tidak ada data yang tersedia" << endl;
            return;
        }
        cout << left << setw(20) << "Nama Produk" << "Harga" << endl;
        Node* current = head;
        while (current != nullptr) {
            cout << left << setw(20) << current->nama_produk_152 << current->harga << endl;
            current = current->next;
        }
    }
};

int main() {
    DoublyLinkedList dll;

    // add data awal penjualan skincare purwokerto
    dll.add_data_152("Originote", 60000);
    dll.add_data_152("Somethinc", 150000);
    dll.add_data_152("Skintific", 100000);
    dll.add_data_152("Wardah", 50000);
    dll.add_data_152("Hanasui", 30000);

    int pilihan;
    do {
        cout << "\nToko Skincare Purwokerto by Arsya" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;

        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        string nama_produk, new_nama_produk;
        double harga, new_harga;
        int urutan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama Produk: ";
                cin >> nama_produk;
                cout << "Masukkan Harga: ";
                cin >> harga;
                dll.add_data_152(nama_produk, harga);
                break;
                 case 2:
                cout << "Masukkan Nama Produk yang akan dihapus: ";
                cin >> nama_produk;
                dll.hapus_data(nama_produk);
                break;
            case 3:
                cout << "Masukkan Nama Produk yang akan diupdate: ";
                cin >> nama_produk;
                cout << "Masukkan Nama Produk baru: ";
                cin >> new_nama_produk;
                cout << "Masukkan Harga baru: ";
                cin >> new_harga;
                dll.update_data(nama_produk, new_nama_produk, new_harga);
                break;
            case 4:
                cout << "Masukkan Nama Produk baru: ";
                cin >> nama_produk;
                cout << "Masukkan Harga: ";
                cin >> harga;
                cout << "Masukkan Urutan: ";
                cin >> urutan;
                dll.tambah_data_urutan_tertentu(nama_produk, harga, urutan);
                break;
            case 5:
                cout << "Masukkan Urutan produk yang akan dihapus: ";
                cin >> urutan;
                dll.hapus_data_urutan_tertentu(urutan);
                break;
            case 6:
                dll.hapus_seluruh_data();
                cout << "Data telah dihapus semua" << endl;
                break;
            case 7:
                dll.tampilkan_data();
                break;
            case 8:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih kembali." << endl;
        }
    } while (pilihan != 8);

    return 0;
}
