#include <iostream>
#include <iomanip>
using namespace std;

class Node {
public:
    string nama;
    int umur_152;
    Node* next;

    Node(string nama, int umur_152) {
        this->nama = nama;
        this->umur_152 = umur_152;
        this->next = nullptr;
    }
};

class DataMahasiswa_152 {
public:
    Node* head;

    DataMahasiswa_152() {
        head = nullptr;
    }

    void insert_depan(string nama, int umur_152) {
        Node* new_node = new Node(nama, umur_152);
        new_node->next = head;
        head = new_node;
    }

    void insert_belakang(string nama, int umur_152) {
        Node* new_node = new Node(nama, umur_152);
        if (head == nullptr) {
            head = new_node;
            return;
        }
        Node* last_node = head;
        while (last_node->next != nullptr) {
            last_node = last_node->next;
        }
        last_node->next = new_node;
    }

    void hapus(string nama) {
        Node* curr_node = head;
        Node* prev_node = nullptr;

        if (curr_node != nullptr && curr_node->nama == nama) {
            head = curr_node->next;
            delete curr_node;
            cout << "Data " << nama << " berhasil dihapus." << endl;
            return;
        }

        while (curr_node != nullptr && curr_node->nama != nama) {
            prev_node = curr_node;
            curr_node = curr_node->next;
        }

        if (curr_node == nullptr) {
            cout << "Data " << nama << " tidak ditemukan." << endl;
            return;
        }

        prev_node->next = curr_node->next;
        delete curr_node;
        cout << "Data " << nama << " berhasil dihapus." << endl;
    }

   void insert_tengah(string nama, int umur_152, int posisi) {
    if (posisi <= 0) {
        cout << "Posisi tidak valid." << endl;
        return;
    }

    if (posisi == 1 || head == nullptr) {
        insert_depan(nama, umur_152);
        return;
    }

    Node* new_node = new Node(nama, umur_152);
    Node* temp = head;
    int current_pos = 1;

    while (temp != nullptr && current_pos < posisi - 1) {
        temp = temp->next;
        current_pos++;
    }

    if (temp == nullptr) {
        cout << "Posisi tidak valid." << endl;
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
    cout << "Data " << nama << " berhasil ditambahkan di posisi " << posisi << "." << endl;
}

    void insert_awal(string nama, int umur_152) {
        Node* new_node = new Node(nama, umur_152);
        new_node->next = head;
        head = new_node;
        cout << "Data " << nama << " berhasil ditambahkan di awal." << endl;
    }

    void ubah(string nama_lama, string nama_baru, int umur_baru_152) {
        Node* temp = head;
        while (temp != nullptr && temp->nama != nama_lama) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Data " << nama_lama << " tidak ditemukan." << endl;
            return;
        }
        temp->nama = nama_baru;
        temp->umur_152 = umur_baru_152;
        cout << "Data " << nama_lama << " berhasil diubah menjadi " << nama_baru << "." << endl;
    }

    void tampilkan() {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "Data Mahasiswa kosong." << endl;
            return;
        }
        cout << left << setw(20) << "Nama" << setw(10) << "Usia" << endl;
        cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
        while (temp != nullptr) {
            cout << left << setw(20) << temp->nama << setw(10) << temp->umur_152 << endl;
            temp = temp->next;
        }
    }
};

int main() {
    DataMahasiswa_152 Data_mahasiswa_152;

    int choice;
    string nama, nama_baru;
    int umur, umur_baru, posisi;

    do {
        cout << "\nMenu Operasi Data Mahasiswa:" << endl;
        cout << "1. Tambah Data Mahasiswa di Awal" << endl;
        cout << "2. Tambah Data Mahasiswa di Belakang" << endl;
        cout << "3. Tambah Data Mahasiswa di Tengah" << endl;
        cout << "4. Ubah Data Mahasiswa" << endl;
        cout << "5. Hapus Data Mahasiswa" << endl;
        cout << "6. Tampilkan Data Mahasiswa" << endl;
        cout << "7. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan nama mahasiswa: ";
                cin >> nama;
                cout << "Masukkan usia mahasiswa: ";
                cin >> umur;
                Data_mahasiswa_152.insert_awal(nama, umur);
                break;
            case 2:
                cout << "Masukkan nama mahasiswa: ";
                cin >> nama;
                cout << "Masukkan usia mahasiswa: ";
                cin >> umur;
                Data_mahasiswa_152.insert_belakang(nama, umur);
                break;
            case 3:
                cout << "Masukkan nama mahasiswa: ";
                cin >> nama;
                cout << "Masukkan usia mahasiswa: ";
                cin >> umur;
                cout << "Masukkan posisi untuk menyisipkan data: ";
                cin >> posisi;
                Data_mahasiswa_152.insert_tengah(nama, umur, posisi);
                break;
            case 4:
                cout << "Masukkan nama mahasiswa yang ingin diubah: ";
                cin >> nama;
                cout << "Masukkan nama baru: ";
                cin >> nama_baru;
                cout << "Masukkan usia baru: ";
                cin >> umur_baru;
                Data_mahasiswa_152.ubah(nama, nama_baru, umur_baru);
                break;
            case 5:
                cout << "Masukkan nama mahasiswa yang ingin dihapus: ";
                cin >> nama;
                Data_mahasiswa_152.hapus(nama);
                break;
            case 6:
                cout << "Data Mahasiswa:" << endl;
                Data_mahasiswa_152.tampilkan();
                break;
            case 7:
                cout << "Terima kasih, program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
        }
    } while (choice != 7);

    return 0;
}