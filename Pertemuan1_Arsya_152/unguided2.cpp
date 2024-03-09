#include <iostream>
#include <cstring>

// Class
class NIMMahasiswa_152 {
public:
// struct
    char nama[50];
    char nim[15];
    float ipk;
};

int main() {

    NIMMahasiswa_152 mhs1, mhs2, mhs3;

    strcpy(mhs1.nama, "Arsya");
    strcpy(mhs1.nim, "2311102152");
    mhs1.ipk = 3.95;

    strcpy(mhs2.nama, "Nisrin");
    strcpy(mhs2.nim, "2311102156");
    mhs2.ipk = 4.00;

    strcpy(mhs3.nama, "Ayu");
    strcpy(mhs3.nim, "2311102128");
    mhs3.ipk = 3.95;

    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.nama);
    printf("NIM: %s\n", mhs1.nim);
    printf("IPK: %.2f\n", mhs1.ipk);
    printf("\n");

    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.nama);
    printf("NIM: %s\n", mhs2.nim);
    printf("IPK: %.2f\n", mhs2.ipk);
    printf("\n");

    printf("## Mahasiswa 3 ##\n");
    printf("Nama: %s\n", mhs3.nama);
    printf("NIM: %s\n", mhs3.nim);
    printf("IPK: %.2f\n", mhs3.ipk);
    printf("\n");

    return 0;
}
