#include <iostream>
#include <stack>
#include <string>

using namespace std;

string MembalikkanKata_152(string kalimat_152) {
    stack<char> karakterStack_152;

    //Operasi PUSH
    // Memasukkan setiap karakter kalimat ke dalam stack
    for (char karakterKata : kalimat_152) {
        karakterStack_152.push(karakterKata);
    }

    string balikkanKata_152 = "";

    //Operasi POP
    // Mengeluarkan setiap karakter dari stack untuk membentuk kalimat terbalik
    
    while (!karakterStack_152.empty()) {
        balikkanKata_152 += karakterStack_152.top();
        karakterStack_152.pop();
    }

    return balikkanKata_152;
}

int main() {
    string kalimat;

    cout << "Masukkan Kata: ";
    getline(cin, kalimat);

    string kalimatTerbalik = MembalikkanKata_152(kalimat);
    cout << "DataStack Array: " <<  endl;

    cout << "Data: " << kalimatTerbalik << endl;

    return 0;
}
