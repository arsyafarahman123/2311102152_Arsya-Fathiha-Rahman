/*
by Arsya Fathiha Rahman - 2311102152
*/
#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0;               // Penanda antrian
int back = 0;                // Penanda
string queueTeller[5];       // Fungsi pengecekan

//Deklarasi Struct Node Linkedlist
struct Node {
    string data;
    Node* next;
};

// Kelas Queue 
class Queue_152 {
private:
    Node* front_152;
    Node* back_152;
    int ukuran_152;
    int ukMax_152;

public:
    Queue_152(int ukuranMaksimal) : ukMax_152(ukuranMaksimal) {
        front_152 = nullptr;
        back_152 = nullptr;
        ukuran_152 = 0;
    }

    bool isFull() {
        return ukuran_152 == ukMax_152;
    }

    bool isEmpty() {
        return ukuran_152 == 0;
    }

    void enqueue(string data) {
        if (isFull()) {
            cout << "Antrian penuh" << endl;
            return;
        }

        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (isEmpty()) {
            front_152 = newNode;
        } else {
            back_152->next = newNode;
        }
        back_152 = newNode;
        ukuran_152++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }

        Node* temp = front_152;
        front_152 = front_152->next;
        delete temp;
        ukuran_152--;
        if (isEmpty()) {
            back_152 = nullptr;
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
        cout << "Data antrian teller:" << endl;
        if (isEmpty()) {
            for (int i = 1; i <= ukMax_152; ++i)
                cout << i << ". (kosong)" << endl;
        } else {
            Node* current = front_152;
            int posisi_152 = 1;
            while (current != nullptr) {
                cout << posisi_152 << ". " << current->data << endl;
                current = current->next;
                posisi_152++;
            }
            while (posisi_152 <= ukMax_152) {
                cout << posisi_152 << ". (kosong)" << endl;
                posisi_152++;
            }
        }
    }
}; 

int main() {
    Queue_152 queue_152(5);
    queue_152.enqueue("Andi");
    queue_152.enqueue("Maya");

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
