#include <iostream> // Memasukkan library iostream untuk input-output
#include <iomanip>  // Memasukkan library iomanip untuk manipulasi input-output
using namespace std;

// Struktur data Pohon untuk merepresentasikan node dalam tree
struct Pohon
{
    char data;        // Data yang disimpan di node
    Pohon *left;      // Pointer ke anak kiri
    Pohon *right;     // Pointer ke anak kanan
    Pohon *parent;    // Pointer ke parent (induk)
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
        root = new Pohon();      // Membuat node baru
        root->data = data;       // Mengisi data node
        root->left = NULL;       // Mengatur anak kiri menjadi NULL
        root->right = NULL;      // Mengatur anak kanan menjadi NULL
        root->parent = NULL;     // Mengatur parent menjadi NULL
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
            cout << "\n Node " << node->data << " sudah ada child kiri !" << endl;
            return NULL; // Mengembalikan NULL jika anak kiri sudah ada
        }
        else
        {
            Pohon *baru = new Pohon(); // Membuat node baru
            baru->data = data;         // Mengisi data node
            baru->left = NULL;         // Mengatur anak kiri menjadi NULL
            baru->right = NULL;        // Mengatur anak kanan menjadi NULL
            baru->parent = node;       // Mengatur parent menjadi node
            node->left = baru;         // Mengatur anak kiri dari node
            cout << "\n Node " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
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
            cout << "\n Node " << node->data << " sudah ada child kanan !" << endl;
            return NULL; // Mengembalikan NULL jika anak kanan sudah ada
        }
        else
        {
            Pohon *baru = new Pohon(); // Membuat node baru
            baru->data = data;         // Mengisi data node
            baru->left = NULL;         // Mengatur anak kiri menjadi NULL
            baru->right = NULL;        // Mengatur anak kanan menjadi NULL
            baru->parent = node;       // Mengatur parent menjadi node
            node->right = baru;        // Mengatur anak kanan dari node
            cout << "\n Node " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
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
            char temp = node->data; // Menyimpan data lama
            node->data = data;      // Mengganti data dengan data baru
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
            cout << "\n Data node : " << node->data << endl; // Tampilkan data node yang ditunjuk
        }
    }
}


// Fungsi untuk menemukan informasi tentang node
void find(Pohon *node) // Fungsi find dengan parameter pointer ke node dari Pohon
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
            cout << "\n Data Node : " << node->data << endl; // Tampilkan data node yang ditunjuk
            cout << " Root : " << root->data << endl; // Tampilkan data root dari tree
            
            if (!node->parent) // Mengecek apakah node tidak punya parent
                cout << " Parent : (tidak punya parent)" << endl; // Jika tidak punya parent, tampilkan pesan
            else
                cout << " Parent : " << node->parent->data << endl; // Jika punya parent, tampilkan data parent
            
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node) // Mengecek apakah node adalah anak kanan dari parent dan parent punya anak kiri
                cout << " Sibling : " << node->parent->left->data << endl; // Jika ya, tampilkan data sibling (anak kiri dari parent)
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node) // Mengecek apakah node adalah anak kiri dari parent dan parent punya anak kanan
                cout << " Sibling : " << node->parent->right->data << endl; // Jika ya, tampilkan data sibling (anak kanan dari parent)
            else
                cout << " Sibling : (tidak punya sibling)" << endl; // Jika tidak punya sibling, tampilkan pesan
            
            if (!node->left) // Mengecek apakah node tidak punya anak kiri
                cout << " Child Kiri : (tidak punya Child kiri)" << endl; // Jika tidak punya anak kiri, tampilkan pesan
            else
                cout << " Child Kiri : " << node->left->data << endl; // Jika punya anak kiri, tampilkan data anak kiri
            
            if (!node->right) // Mengecek apakah node tidak punya anak kanan
                cout << " Child Kanan : (tidak punya Child kanan)" << endl; // Jika tidak punya anak kanan, tampilkan pesan
            else
                cout << " Child Kanan : " << node->right->data << endl; // Jika punya anak kanan, tampilkan data anak kanan
        }
    }
}


// Fungsi untuk traversal preOrder
void preOrder(Pohon *node = root) // Fungsi preOrder dengan parameter default node yang menunjuk ke root
{
    if (isEmpty()) // Mengecek apakah tree kosong
    {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Jika tree kosong, tampilkan pesan
    }
    else // Jika tree tidak kosong
    {
        if (node != NULL) // Mengecek apakah node tidak NULL
        {
            cout << " " << node->data << ", "; // Tampilkan data node
            preOrder(node->left); // Traversal preOrder ke subtree kiri
            preOrder(node->right); // Traversal preOrder ke subtree kanan
        }
    }
}

// Fungsi untuk traversal inOrder
void inOrder(Pohon *node = root) // Fungsi inOrder dengan parameter default node yang menunjuk ke root
{
    if (isEmpty()) // Mengecek apakah tree kosong
    {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Jika tree kosong, tampilkan pesan
    }
    else // Jika tree tidak kosong
    {
        if (node != NULL) // Mengecek apakah node tidak NULL
        {
            inOrder(node->left); // Traversal inOrder ke subtree kiri
            cout << " " << node->data << ", "; // Tampilkan data node
            inOrder(node->right); // Traversal inOrder ke subtree kanan
        }
    }
}


// Fungsi untuk traversal postOrder
void postOrder(Pohon *node = root) // Fungsi postOrder dengan parameter default node yang menunjuk ke root
{
    if (isEmpty()) // Mengecek apakah tree kosong
    {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Jika tree kosong, tampilkan pesan
    }
    else // Jika tree tidak kosong
    {
        if (node != NULL) // Mengecek apakah node tidak NULL
        {
            postOrder(node->left); // Traversal postOrder ke subtree kiri
            postOrder(node->right); // Traversal postOrder ke subtree kanan
            cout << " " << node->data << ", "; // Tampilkan data node
        }
    }
}


/// Fungsi untuk menghapus seluruh tree
void deleteTree(Pohon *node) // Fungsi deleteTree dengan parameter node
{
    if (isEmpty()) // Mengecek apakah tree kosong
    {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Jika tree kosong, tampilkan pesan
    }
    else // Jika tree tidak kosong
    {
        if (node != NULL) // Mengecek apakah node tidak NULL
        {
            if (node != root) // Mengecek apakah node bukan root
            {
                node->parent->left = NULL; // Menghapus hubungan dengan parent dari anak kiri
                node->parent->right = NULL; // Menghapus hubungan dengan parent dari anak kanan
            }
            deleteTree(node->left); // Rekursif: Hapus subtree kiri
            deleteTree(node->right); // Rekursif: Hapus subtree kanan
            if (node == root) // Jika node adalah root
            {
                delete root; // Hapus root
                root = NULL; // Atur root menjadi NULL
            }
            else // Jika node bukan root
            {
                delete node; // Hapus node
            }
        }
    }
}
// Fungsi untuk menghapus subtree
void deleteSub(Pohon *node) // Fungsi deleteSub dengan parameter node
{
    if (isEmpty()) // Mengecek apakah tree kosong
    {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Jika tree kosong, tampilkan pesan
    }
    else // Jika tree tidak kosong
    {
        deleteTree(node->left); // Hapus subtree kiri dari node
        deleteTree(node->right); // Hapus subtree kanan dari node
        cout << "\n Node subtree " << node->data << " berhasil dihapus." << endl; // Tampilkan pesan bahwa subtree berhasil dihapus
    }
}


// Fungsi untuk menghapus seluruh tree
void clear() // Fungsi clear tanpa parameter
{
    if (isEmpty()) // Mengecek apakah tree kosong
    {
        cout << "\n Buat tree terlebih dahulu!!" << endl; // Jika tree kosong, tampilkan pesan
    }
    else // Jika tree tidak kosong
    {
        deleteTree(root); // Panggil fungsi deleteTree untuk menghapus seluruh tree dengan root sebagai parameter
        cout << "\n Pohon berhasil dihapus." << endl; // Tampilkan pesan bahwa pohon berhasil dihapus
    }
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

// Fungsi utama program
int main()
{
    // Membuat node root
    buatNode('A');

    // Deklarasi pointer untuk node-node lain
    Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI, *nodeJ;

    nodeB = insertLeft('B', root); // Menambahkan node B sebagai anak kiri dari root
    nodeC = insertRight('C', root); // Menambahkan node C sebagai anak kanan dari root
    nodeD = insertLeft('D', nodeB); // Menambahkan node D sebagai anak kiri dari node B
    nodeE = insertRight('E', nodeB); // Menambahkan node E sebagai anak kanan dari node B
    nodeF = insertLeft('F', nodeC); // Menambahkan node F sebagai anak kiri dari node C
    nodeG = insertLeft('G', nodeE); // Menambahkan node G sebagai anak kiri dari node E
    nodeH = insertRight('H', nodeE); // Menambahkan node H sebagai anak kanan dari node E
    nodeI = insertLeft('I', nodeG); // Menambahkan node I sebagai anak kiri dari node G
    nodeJ = insertRight('J', nodeG); // Menambahkan node J sebagai anak kanan dari node G

    update('Z', nodeC); // Mengupdate data di node C menjadi 'Z'
    update('C', nodeC); // Mengupdate data di node C kembali menjadi 'C'

    retrieve(nodeC); // Menampilkan data dari node C

    find(nodeC); // Menemukan informasi dari node C

     // Menampilkan karakteristik dari tree
    characteristic(); // Memanggil fungsi characteristic()

    // Menampilkan traversal preOrder
    cout << "\n PreOrder :" << endl;
    preOrder(root);
    cout << "\n" << endl;

    // Menampilkan traversal inOrder
    cout << " InOrder :" << endl;
    inOrder(root);
    cout << "\n" << endl;

    // Menampilkan traversal postOrder
    cout << " PostOrder :" << endl;
    postOrder(root);
    cout << "\n" << endl;



    return 0; // Mengembalikan nilai 0 yang menunjukkan program berakhir dengan sukses
}
