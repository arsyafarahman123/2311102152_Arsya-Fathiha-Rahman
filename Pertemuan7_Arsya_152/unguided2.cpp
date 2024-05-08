#include <iostream>
using namespace std;

// Deklarasi Struct Node
struct Node {
    string nama_152;
    int nim_152;
    Node* next;
};

// Kelas Queue untuk Mahasiswa
class QueueMahasiswa {
private:
    Node* front;
    Node* back;
    int ukuran_152;
    int ukMax_152;

public:
    QueueMahasiswa(int maxSize) : ukMax_152(maxSize) {
        front = nullptr;
        back = nullptr;
        ukuran_152 = 0;
    }

    bool isFull() {
        return ukuran_152 == ukMax_152;
    }

    bool isEmpty() {
        return ukuran_152 == 0;
    }

    void enqueue(string nama, int nim) {
        if (isFull()) {
            cout << "Antrian penuh" << endl;
            return;
        }

        Node* newNode = new Node();
        newNode->nama_152 = nama;
        newNode->nim_152 = nim;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = newNode;
        } else {
            back->next = newNode;
        }
        back = newNode;
        ukuran_152++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;
        delete temp;
        ukuran_152--;
        if (isEmpty()) {
            back = nullptr;
        }
    }

    int count() {
        return ukuran_152;
    }

    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void view() {
        if (isEmpty()) {
            cout << "Data antrian MAHASISWA:" << endl;
            for (int i = 1; i <= ukMax_152; ++i)
                cout << i << ". (kosong)" << endl;
        } else {
            Node* current = front;
            cout << "Data antrian MAHASISWA:" << endl;
            int posisi_152 = 1;
            while (current != nullptr) {
                cout << posisi_152 << ". Nama: " << current->nama_152 << ", NIM: " << current->nim_152 << endl;
                current = current->next;
                posisi_152++;
            }
            // Mengisi posisi yang kosong dengan "(kosong)"
            while (posisi_152 <= ukMax_152) {
                cout << posisi_152 << ". (kosong)" << endl;
                posisi_152++;
            }
        }
    }
};

int main() {
    QueueMahasiswa queue_152(5);
    queue_152.enqueue("Andi", 231100777);
    queue_152.enqueue("Maya", 231118067);

    queue_152.view();
    cout << "Jumlah antrian = " << queue_152.count() << endl;
    queue_152.dequeue();
    queue_152.view();
    cout << "Jumlah antrian = " << queue_152.count() << endl;
    queue_152.clear();
    queue_152.view();
    cout << "Jumlah antrian = " << queue_152.count() << endl;

    return 0;
}
