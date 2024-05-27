#include <iostream> // Memasukkan library iostream untuk input-output
#include <iomanip>  // Memasukkan library iomanip untuk manipulasi input-output
using namespace std;

// Struktur data Pohon untuk merepresentasikan node dalam tree
struct Pohon
{
    char data_Arsya_2311102152; // Data yang disimpan di node
    Pohon *left;                // Pointer ke anak kiri
    Pohon *right;               // Pointer ke anak kanan
    Pohon *parent;              // Pointer ke parent (induk)
};

// Deklarasi pointer root dan baru untuk tree
Pohon *root, *baru;

// Fungsi untuk menginisialisasi tree
void init()
{
    root = NULL; // Mengatur root menjadi NULL
}

// Fungsi untuk memeriksa apakah tree kosong
bool isEmpty()
{
    return root == NULL; // Mengembalikan true jika root NULL (tree kosong)
}

// Fungsi untuk membuat node baru sebagai root
void buatNode(char data)
{
    if (isEmpty())
    {
        root = new Pohon();                 // Membuat node baru
        root->data_Arsya_2311102152 = data; // Mengisi data node
        root->left = NULL;                  // Mengatur anak kiri menjadi NULL
        root->right = NULL;                 // Mengatur anak kanan menjadi NULL
        root->parent = NULL;                // Mengatur parent menjadi NULL
        cout << "\n Node " << data << " berhasil dibuat sebagai root." << endl;
    }
    else
    {
        cout << "\n Tree sudah ada!" << endl; // Pesan jika tree sudah ada
    }
}

// Fungsi untuk menambahkan node di anak kiri
Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL; // Mengembalikan NULL jika tree kosong
    }
    else
    {
        if (node->left != NULL)
        {
            cout << "\n Node " << node->data_Arsya_2311102152 << " sudah ada child kiri !" << endl;
            return NULL; // Mengembalikan NULL jika anak kiri sudah ada
        }
        else
        {
            Pohon *baru = new Pohon();          // Membuat node baru
            baru->data_Arsya_2311102152 = data; // Mengisi data node
            baru->left = NULL;                  // Mengatur anak kiri menjadi NULL
            baru->right = NULL;                 // Mengatur anak kanan menjadi NULL
            baru->parent = node;                // Mengatur parent menjadi node
            node->left = baru;                  // Mengatur anak kiri dari node
            cout << "\n Node " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data_Arsya_2311102152 << endl;
            return baru; // Mengembalikan pointer ke node baru
        }
    }
}

// Fungsi untuk menambahkan node di anak kanan
Pohon *insertRight(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL; // Mengembalikan NULL jika tree kosong
    }
    else
    {
        if (node->right != NULL)
        {
            cout << "\n Node " << node->data_Arsya_2311102152 << " sudah ada child kanan !" << endl;
            return NULL; // Mengembalikan NULL jika anak kanan sudah ada
        }
        else
        {
            Pohon *baru = new Pohon();          // Membuat node baru
            baru->data_Arsya_2311102152 = data; // Mengisi data node
            baru->left = NULL;                  // Mengatur anak kiri menjadi NULL
            baru->right = NULL;                 // Mengatur anak kanan menjadi NULL
            baru->parent = node;                // Mengatur parent menjadi node
            node->right = baru;                 // Mengatur anak kanan dari node
            cout << "\n Node " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data_Arsya_2311102152 << endl;
            return baru; // Mengembalikan pointer ke node baru
        }
    }
}

// Fungsi untuk mengupdate data di node
void update(char data, Pohon *node)
{
    if (isEmpty()) // Memeriksa apakah tree kosong/tersedia
    {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Menampilkan pesan jika tree kosong
    }
    else // Jika tree tidak kosong
    {
        if (!node) // Memeriksa apakah node yang ditunjuk ada
        {
            cout << "\n Node yang ingin diganti tidak ada!!" << endl; // Menampilkan pesan jika node tidak ada
        }
        else // Jika node ada
        {
            char temp = node->data_Arsya_2311102152;                                   // Menyimpan data lama
            node->data_Arsya_2311102152 = data;                                        // Mengganti data dengan data baru
            cout << "\n Node " << temp << " berhasil diubah menjadi " << data << endl; // Menampilkan pesan sukses
        }
    }
}

// Fungsi untuk menampilkan data di node
void retrieve(Pohon *node) // Fungsi retrieve dengan parameter pointer ke node dari Pohon
{
    if (isEmpty()) // Mengecek apakah tree kosong
    {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Jika tree kosong, tampilkan pesan
    }
    else // Jika tree tidak kosong
    {
        if (!node) // Mengecek apakah node yang ditunjuk tidak ada (NULL)
        {
            cout << "\n Node yang ditunjuk tidak ada!" << endl; // Jika node tidak ada, tampilkan pesan
        }
        else // Jika node ada
        {
            cout << "\n Data node : " << node->data_Arsya_2311102152 << endl; // Tampilkan data node yang ditunjuk
        }
    }
}

void find(Pohon *node) // Fungsi untuk menemukan dan menampilkan informasi tentang node dalam pohon
{
    if (isEmpty()) // Periksa apakah pohon kosong
    {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Tampilkan pesan jika pohon kosong
    }
    else
    {
        if (!node) // Jika node yang ditunjuk NULL
        {
            cout << "\n Node yang ditunjuk tidak ada!" << endl; // Tampilkan pesan bahwa node tidak ada
        }
        else
        {
            cout << "\n Data Node : " << node->data_Arsya_2311102152 << endl; // Tampilkan data dari node yang ditunjuk
            cout << " Root : " << root->data_Arsya_2311102152 << endl;        // Tampilkan data dari root node

            // Tampilkan informasi tentang sibling node
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << " Sibling : " << node->parent->left->data_Arsya_2311102152 << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << " Sibling : " << node->parent->right->data_Arsya_2311102152 << endl;
            else
                cout << " Sibling : (tidak punya sibling)" << endl;

            // Tampilkan informasi tentang child node kiri
            if (!node->left)
                cout << " Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << " Child Kiri : " << node->left->data_Arsya_2311102152 << endl;

            // Tampilkan informasi tentang child node kanan
            if (!node->right)
                cout << " Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << " Child Kanan : " << node->right->data_Arsya_2311102152 << endl;
        }
    }
}

void preOrder(Pohon *node = root) // Fungsi untuk melakukan traversal PreOrder pada pohon
{
    if (isEmpty()) // Periksa apakah pohon kosong
    {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Tampilkan pesan jika pohon kosong
    }
    else
    {
        if (node != NULL) // Jika node tidak NULL
        {
            cout << node->data_Arsya_2311102152 << ", "; // Tampilkan data dari node
            preOrder(node->left);                        // Lakukan traversal PreOrder pada subtree kiri
            preOrder(node->right);                       // Lakukan traversal PreOrder pada subtree kanan
        }
    }
}

void inOrder(Pohon *node = root) // Fungsi untuk melakukan traversal InOrder pada pohon
{
    if (isEmpty()) // Periksa apakah pohon kosong
    {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Tampilkan pesan jika pohon kosong
    }
    else
    {
        if (node != NULL) // Jika node tidak NULL
        {
            inOrder(node->left);                         // Lakukan traversal InOrder pada subtree kiri
            cout << node->data_Arsya_2311102152 << ", "; // Tampilkan data dari node
            inOrder(node->right);                        // Lakukan traversal InOrder pada subtree kanan
        }
    }
}

void postOrder(Pohon *node = root) // Fungsi untuk melakukan traversal PostOrder pada pohon
{
    if (isEmpty()) // Periksa apakah pohon kosong
    {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Tampilkan pesan jika pohon kosong
    }
    else
    {
        if (node != NULL) // Jika node tidak NULL
        {
            postOrder(node->left);                       // Lakukan traversal PostOrder pada subtree kiri
            postOrder(node->right);                      // Lakukan traversal PostOrder pada subtree kanan
            cout << node->data_Arsya_2311102152 << ", "; // Tampilkan data dari node
        }
    }
}

void deleteSubtree(Pohon *node) // Fungsi untuk menghapus subtree yang dimulai dari node yang diberikan
{
    if (node == NULL) // Jika node NULL, kembalikan
        return;

    // Hapus subtree secara rekursif
    deleteSubtree(node->left);
    deleteSubtree(node->right);

    // Hapus hubungan parent dengan node
    if (node->parent != NULL && node->parent->left == node)
    {
        node->parent->left = NULL;
    }
    else if (node->parent != NULL && node->parent->right == node)
    {
        node->parent->right = NULL;
    }

    // Tampilkan pesan bahwa node berhasil dihapus
    cout << "\n Node " << node->data_Arsya_2311102152 << " berhasil dihapus." << endl;

    // Hapus node dari memory
    delete node;
}

// Fungsi untuk menampilkan informasi tentang child dan descendant
void showChildAndDescendant(Pohon *node) // Fungsi untuk menampilkan informasi tentang child dan descendant dari suatu node
{
    if (isEmpty()) // Periksa apakah pohon kosong
    {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Tampilkan pesan jika pohon kosong
    }
    else
    {
        if (!node) // Jika node yang ditunjuk NULL
        {
            cout << "\n Node yang ditunjuk tidak ada!" << endl; // Tampilkan pesan bahwa node tidak ada
        }
        else
        {
            cout << "\n Data Node : " << node->data_Arsya_2311102152 << endl; // Tampilkan data dari node yang ditunjuk
            if (!node->left)                                                  // Jika tidak ada child kiri
            {
                cout << " Child Kiri : (tidak punya Child kiri)" << endl; // Tampilkan pesan bahwa tidak ada child kiri
            }
            else
            {
                cout << " Child Kiri : " << node->left->data_Arsya_2311102152 << endl; // Tampilkan data dari child kiri
                cout << " Descendant dari Child Kiri : ";
                inOrder(node->left); // Tampilkan descendant dari child kiri dengan traversal InOrder
                cout << endl;
            }

            if (!node->right) // Jika tidak ada child kanan
            {
                cout << " Child Kanan : (tidak punya Child kanan)" << endl; // Tampilkan pesan bahwa tidak ada child kanan
            }
            else
            {
                cout << " Child Kanan : " << node->right->data_Arsya_2311102152 << endl; // Tampilkan data dari child kanan
                cout << " Descendant dari Child Kanan : ";
                inOrder(node->right); // Tampilkan descendant dari child kanan dengan traversal InOrder
                cout << endl;
            }
        }
    }
}

// Deklarasi fungsi findParent
void findParent(Pohon *node, char parentData, Pohon *&parentNode) // Fungsi untuk mencari parent dari node dengan data tertentu
{
    if (node == NULL) // Jika node NULL, kembalikan
        return;

    if (node->data_Arsya_2311102152 == parentData) // Jika data node sama dengan data parent yang dicari
    {
        parentNode = node; // Simpan node sebagai parent yang ditemukan
        return;
    }

    // Telusuri subtree secara rekursif
    findParent(node->left, parentData, parentNode);
    findParent(node->right, parentData, parentNode);
}

// Fungsi untuk menghitung ukuran tree
int size(Pohon *node = root) // Fungsi size dengan parameter default node yang menunjuk ke root
{
    if (isEmpty()) // Mengecek apakah tree kosong
    {
        cout << "\n Buat tree terlebih dahulu!!" << endl; // Jika tree kosong, tampilkan pesan dan kembalikan ukuran 0
        return 0;
    }
    else // Jika tree tidak kosong
    {
        if (!node) // Mengecek apakah node NULL
        {
            return 0; // Jika node NULL, kembalikan ukuran 0
        }
        else // Jika node tidak NULL
        {
            return 1 + size(node->left) + size(node->right); // Kembalikan jumlah node, termasuk node saat ini dan semua node di subtree kiri dan kanan
        }
    }
}


// Fungsi untuk menghitung tinggi tree
int height(Pohon *node = root) // Fungsi height dengan parameter default node yang menunjuk ke root
{
    if (isEmpty()) // Mengecek apakah tree kosong
    {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Jika tree kosong, tampilkan pesan dan kembalikan tinggi 0
        return 0;
    }
    else // Jika tree tidak kosong
    {
        if (!node) // Mengecek apakah node NULL
        {
            return 0; // Jika node NULL, kembalikan tinggi 0
        }
        else // Jika node tidak NULL
        {
            int heightKiri = height(node->left); // Hitung tinggi subtree kiri
            int heightKanan = height(node->right); // Hitung tinggi subtree kanan
            if (heightKiri >= heightKanan) // Bandingkan tinggi subtree kiri dan kanan
            {
                return heightKiri + 1; // Kembalikan tinggi subtree kiri ditambah 1
            }
            else
            {
                return heightKanan + 1; // Kembalikan tinggi subtree kanan ditambah 1
            }
        }
    }
}
// Fungsi untuk menampilkan karakteristik tree
void characteristic() // Fungsi characteristic tanpa parameter
{
    cout << "\n Size Tree : " << size() << endl; // Tampilkan ukuran tree menggunakan fungsi size()
    cout << " Height Tree : " << height() << endl; // Tampilkan tinggi tree menggunakan fungsi height()
    cout << " Average Node of Tree : " << size() / height() << endl; // Tampilkan rata-rata node dari tree
}

int main()
{
    int pil;   // Variabel untuk menyimpan pilihan menu
    char data; // Variabel untuk menyimpan data node atau parent node

    // Loop utama program
    do
    {
        cout << "\n =====================================";
        cout << "\n        ==  Program Tree C++ ==       ";
        cout << "\n =====================================";
        cout << "\n Menu :                     ";
        cout << "\n 1. Tambah Node Root";
        cout << "\n 2. Tambah Kiri";
        cout << "\n 3. Tambah Kanan";
        cout << "\n 4. Update Data";
        cout << "\n 5. Lihat/Retrive Data";
        cout << "\n 6. Cari Data";
        cout << "\n 7. Traversal PreOrder";
        cout << "\n 8. Traversal InOrder";
        cout << "\n 9. Traversal PostOrder";
        cout << "\n 10. Hapus Subtree";
        cout << "\n 11. Hapus Seluruh Tree";
        cout << "\n 12. Karakteristik Tree";
        cout << "\n 13. Tampilkan Child dan Descendant";
        cout << "\n 0. Exit";
        cout << "\n =====================================";
        cout << "\n Pilih menu : ";

        cin >> pil; // Masukkan pilihan menu

        switch (pil)
        {
        case 1: // Menu untuk menambahkan node root
            cout << "\n Input data : ";
            cin >> data;
            buatNode(data);
            break;

        case 2: // Menu untuk menambahkan node sebelah kiri
        {
            cout << "\n Input data : ";
            cin >> data;
            char parentData;
            cout << " Input parent data: ";
            cin >> parentData;
            Pohon *parentNode = NULL;

            // Cari parent node berdasarkan parentData
            findParent(root, parentData, parentNode);

            if (parentNode)
            {
                insertLeft(data, parentNode);
            }
            else
            {
                cout << "\n Parent node tidak ditemukan!" << endl;
            }
            break;
        }
        case 3: // Menu untuk menambahkan node sebelah kanan
        {
            cout << "\n Input data : ";
            cin >> data;
            char parentData;
            cout << " Input parent data: ";
            cin >> parentData;
            Pohon *parentNode = NULL;

            // Cari parent node berdasarkan parentData
            findParent(root, parentData, parentNode);

            if (parentNode)
            {
                insertRight(data, parentNode);
            }
            else
            {
                cout << "\n Parent node tidak ditemukan!" << endl;
            }
            break;
        }

        case 4: // Menu untuk mengupdate data pada node
        {
            cout << "\n Input data baru : ";                  // Meminta input untuk data baru
            cin >> data;                                      // Membaca data baru dari pengguna
            char nodeData;                                    // Variabel untuk menyimpan data node yang ingin diupdate
            cout << " Input data node yang ingin diupdate: "; // Meminta input data node yang ingin diupdate
            cin >> nodeData;                                  // Membaca data node yang ingin diupdate dari pengguna
            Pohon *node = root;                               // Inisialisasi node yang akan digunakan untuk mencari node yang ingin diupdate
            // Loop untuk mencari node yang ingin diupdate berdasarkan datanya
            while (node && node->data_Arsya_2311102152 != nodeData)
            {
                if (node->left && node->left->data_Arsya_2311102152 == nodeData)
                {
                    node = node->left; // Jika node pada left child sesuai dengan nodeData, pindahkan node ke left child
                }
                else if (node->right && node->right->data_Arsya_2311102152 == nodeData)
                {
                    node = node->right; // Jika node pada right child sesuai dengan nodeData, pindahkan node ke right child
                }
                else if (node->left)
                {
                    node = node->left; // Jika node memiliki left child, pindahkan node ke left child
                }
                else if (node->right)
                {
                    node = node->right; // Jika node memiliki right child, pindahkan node ke right child
                }
                else
                {
                    node = NULL; // Jika tidak ada kondisi di atas yang terpenuhi, atur node menjadi NULL (node tidak ditemukan)
                }
            }
            if (node)
            {
                update(data, node); // Jika node ditemukan, panggil fungsi update untuk mengupdate datanya
            }
            else
            {
                cout << "\n Node tidak ditemukan!" << endl; // Jika node tidak ditemukan, tampilkan pesan kesalahan
            }
            break; // Keluar dari case 4
        }
        case 5: // Menu untuk melihat informasi data pada node
        {
            char nodeData;                                  // Variabel untuk menyimpan data node yang ingin dilihat
            cout << "Input data node yang ingin dilihat: "; // Meminta input data node yang ingin dilihat
            cin >> nodeData;                                // Membaca data node yang ingin dilihat dari pengguna

            Pohon *node = root; // Inisialisasi node yang akan digunakan untuk mencari node yang ingin dilihat

            // Loop untuk mencari node yang ingin dilihat berdasarkan datanya
            while (node && node->data_Arsya_2311102152 != nodeData)
            {
                if (nodeData < node->data_Arsya_2311102152)
                {
                    node = node->left; // Pindah ke left child jika data node lebih kecil dari node saat ini
                }
                else
                {
                    node = node->right; // Pindah ke right child jika data node lebih besar atau sama dengan node saat ini
                }
            }

            if (node)
            {
                // Tampilkan informasi tentang node dan strukturnya
                cout << "Data node: " << node->data_Arsya_2311102152 << endl;
            }
            else
            {
                // Jika node tidak ditemukan, tidak melakukan apa-apa
            }

            break; // Keluar dari case 5
        }

        case 6: // Menu untuk mencari data pada node
        {
            char nodeData;                                  // Variabel untuk menyimpan data node yang ingin dicari
            cout << " Input data node yang ingin dicari: "; // Meminta input data node yang ingin dicari
            cin >> nodeData;                                // Membaca data node yang ingin dicari dari pengguna
            Pohon *node = root;                             // Inisialisasi node yang akan digunakan untuk mencari node yang ingin dicari
            // Loop untuk mencari node yang ingin dicari berdasarkan datanya
            while (node && node->data_Arsya_2311102152 != nodeData)
            {
                if (node->left && node->left->data_Arsya_2311102152 == nodeData)
                {
                    node = node->left; // Jika node pada left child sesuai dengan nodeData, pindahkan node ke left child
                }
                else if (node->right && node->right->data_Arsya_2311102152 == nodeData)
                {
                    node = node->right; // Jika node pada right child sesuai dengan nodeData, pindahkan node ke right child
                }
                else if (node->left)
                {
                    node = node->left; // Jika node memiliki left child, pindahkan node ke left child
                }
                else if (node->right)
                {
                    node = node->right; // Jika node memiliki right child, pindahkan node ke right child
                }
                else
                {
                    node = NULL; // Jika tidak ada kondisi di atas yang terpenuhi, atur node menjadi NULL (node tidak ditemukan)
                }
            }
            if (node)
            {
                // Panggil fungsi find untuk menampilkan informasi tentang node
                find(node);
            }
            else
            {
                cout << "\n Node tidak ditemukan!" << endl; // Jika node tidak ditemukan, tampilkan pesan kesalahan
            }
            break; // Keluar dari case 6
        }

        case 7: // Menu untuk traversal PreOrder
            cout << "\n Traversal PreOrder : ";
            preOrder(root); // Panggil fungsi preOrder untuk melakukan traversal PreOrder
            break;

        case 8: // Menu untuk traversal InOrder
            cout << "\n Traversal InOrder : ";
            inOrder(root); // Panggil fungsi inOrder untuk melakukan traversal InOrder
            break;

        case 9: // Menu untuk traversal PostOrder
            cout << "\n Traversal PostOrder : ";
            postOrder(root); // Panggil fungsi postOrder untuk melakukan traversal PostOrder
            break;

        case 10: // Menu untuk menghapus subtree dari sebuah node
        {
            char nodeData;                                               // Variabel untuk menyimpan data node yang ingin dihapus subtree-nya
            cout << " Input data node yang ingin dihapus subtree-nya: "; // Meminta input data node yang ingin dihapus subtree-nya
            cin >> nodeData;                                             // Membaca data node yang ingin dihapus subtree-nya dari pengguna
            Pohon *node = root;                                          // Inisialisasi node yang akan digunakan untuk mencari node yang ingin dihapus subtree-nya
            // Loop untuk mencari node yang ingin dihapus subtree-nya berdasarkan datanya
            while (node && node->data_Arsya_2311102152 != nodeData)
            {
                if (node->left && node->left->data_Arsya_2311102152 == nodeData)
                {
                    node = node->left; // Jika node pada left child sesuai dengan nodeData, pindahkan node ke left child
                }
                else if (node->right && node->right->data_Arsya_2311102152 == nodeData)
                {
                    node = node->right; // Jika node pada right child sesuai dengan nodeData, pindahkan node ke right child
                }
                else if (node->left)
                {
                    node = node->left; // Jika node memiliki left child, pindahkan node ke left child
                }
                else if (node->right)
                {
                    node = node->right; // Jika node memiliki right child, pindahkan node ke right child
                }
                else
                {
                    node = NULL; // Jika tidak ada kondisi di atas yang terpenuhi, atur node menjadi NULL (node tidak ditemukan)
                }
            }
            if (node)
            {
                // Panggil fungsi deleteSubtree untuk menghapus subtree
                deleteSubtree(node);
            }
            else
            {
                cout << "\n Node tidak ditemukan!" << endl; // Jika node tidak ditemukan, tampilkan pesan kesalahan
            }
            break; // Keluar dari case 10
        }

        case 11: // Menu untuk menghapus seluruh tree
            cout << "\n Hapus Seluruh Tree : ";
            init();                                      // Inisialisasi ulang tree
            cout << "\n Tree berhasil dihapus!" << endl; // Tampilkan pesan berhasil menghapus tree
            break;                                       // Keluar dari case 11

        case 12: // Menu untuk menampilkan karakteristik tree
            characteristic(); // Memanggil fungsi characteristic()

            break; // Keluar dari case 12

        case 13: // Menu untuk menampilkan child dan descendant sebuah node
        {
            char nodeData;                                                            // Variabel untuk menyimpan data node yang ingin dilihat child dan descendant-nya
            cout << " Input data node yang ingin dilihat child dan descendant-nya: "; // Meminta input data node yang ingin dilihat child dan descendant-nya
            cin >> nodeData;                                                          // Membaca data node yang ingin dilihat child dan descendant-nya dari pengguna
            Pohon *node = root;                                                       // Inisialisasi node yang akan digunakan untuk mencari node yang ingin dilihat child dan descendant-nya
            // Loop untuk mencari node yang ingin dilihat child dan descendant-nya berdasarkan datanya
            while (node && node->data_Arsya_2311102152 != nodeData)
            {
                if (node->left && node->left->data_Arsya_2311102152 == nodeData)
                {
                    node = node->left; // Jika node pada left child sesuai dengan nodeData, pindahkan node ke left child
                }
                else if (node->right && node->right->data_Arsya_2311102152 == nodeData)
                {
                    node = node->right; // Jika node pada right child sesuai dengan nodeData, pindahkan node ke right child
                }
                else if (node->left)
                {
                    node = node->left; // Jika node memiliki left child, pindahkan node ke left child
                }
                else if (node->right)
                {
                    node = node->right; // Jika node memiliki right child, pindahkan node ke right child
                }
                else
                {
                    node = NULL; // Jika tidak ada kondisi di atas yang terpenuhi, atur node menjadi NULL (node tidak ditemukan)
                }
            }
            if (node)
            {
                // Panggil fungsi showChildAndDescendant untuk menampilkan child dan descendant
                showChildAndDescendant(node);
            }
            else
            {
                cout << "\n Node tidak ditemukan!" << endl; // Jika node tidak ditemukan, tampilkan pesan kesalahan
            }
            break; // Keluar dari case 13
        }

        case 0:                                                               // Menu untuk keluar dari program
            cout << "\n Terima kasih telah menggunakan program ini!" << endl; // Tampilkan pesan terima kasih
            break;                                                            // Keluar dari case 0

        default:                                            // Default case untuk pilihan menu tidak valid
            cout << "\n Pilihan menu tidak valid!" << endl; // Tampilkan pesan kesalahan untuk pilihan menu tidak valid
        }
    } while (pil != 0); // Loop akan terus berjalan selama pilihan menu yang dimasukkan tidak sama dengan 0, menandakan pengguna masih ingin menggunakan program.

    return 0; // Mengembalikan nilai 0 sebagai tanda bahwa program telah berakhir dengan sukses.
}
