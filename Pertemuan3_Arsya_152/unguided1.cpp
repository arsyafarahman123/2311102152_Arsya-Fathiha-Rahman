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
        Node* temp = head;
        int current_pos = 1;

        while (temp != nullptr && current_pos != posisi) {
            temp = temp->next;
            current_pos++;
        }

        if (temp == nullptr) {
            cout << "Posisi tidak valid." << endl;
            return;
        }

        Node* new_node = new Node(nama, umur_152);
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

    // Memasukkan data mahasiswa
    Data_mahasiswa_152.insert_depan("Arsya Fathiha", 18);  // Data Saya
    Data_mahasiswa_152.insert_belakang("John", 19);
    Data_mahasiswa_152.insert_belakang("Jane", 20);
    Data_mahasiswa_152.insert_belakang("Michael", 18);
    Data_mahasiswa_152.insert_belakang("Yusuke", 19);
    Data_mahasiswa_152.insert_belakang("Akechi", 20);
    Data_mahasiswa_152.insert_belakang("Hoshino", 18);
    Data_mahasiswa_152.insert_belakang("Karin", 18);

   // Operasi Pemanggilan 
  
    cout << "\nd. Add data Igor di awal:" << endl;
    Data_mahasiswa_152.insert_awal("Igor", 20);
    Data_mahasiswa_152.tampilkan();

    cout << "\ne. Ubah data Michael menjadi Reyn:" << endl;
    Data_mahasiswa_152.ubah("Michael", "Reyn", 18);
    Data_mahasiswa_152.tampilkan();

    cout << "\nf. Tampilkan seluruh data:" << endl;
    Data_mahasiswa_152.tampilkan();

    return 0;
}
