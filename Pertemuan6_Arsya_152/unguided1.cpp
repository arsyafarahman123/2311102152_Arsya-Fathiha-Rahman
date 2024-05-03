#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isPalindrome_152(string str) {
    stack<char> karakterStack_152;
    int length = str.length();

    // MengPush/Memasukkan karakter-karakter dari string ke stack/tumpukan
    for (int i = 0; i < length; i++) {
        karakterStack_152.push(str[i]);
    }

    // Pop karakter-karakter dari tumpukan dan bandingkan dengan karakter-karakter dalam string
    for (int i = 0; i < length; i++) {
        if (str[i] != karakterStack_152.top()) {
            return false; // Bukan palindrom
        }
        karakterStack_152.pop();
    }

    return true; 
}

int main() {
    string input;
    cout << "Masukkan kalimat: ";
    getline(cin, input);

    if (isPalindrome_152(input)) {
        cout << "Kalimat tersebut adalah palindrom." << endl;
    } else {
        cout << "Kalimat tersebut adalah bukan palindrom." << endl;
    }

    return 0;
}
