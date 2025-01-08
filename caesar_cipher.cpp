#include <iostream>
#include <string>
using namespace std;

string encrypt(string text, int shift) {
    string result = "";

    for (char c : text) {
        if (isupper(c)) {
            result += char(int(c + shift - 'A') % 26 + 'A');
        } else if (islower(c)) {
            result += char(int(c + shift - 'a') % 26 + 'a');
        } else {
            result += c; 
        }
    }
    return result;
}


string decrypt(string text, int shift) {
    return encrypt(text, 26 - (shift % 26)); 
}

int main() {
    string text;
    int shift;
    int choice;

    cout << "Caesar Cipher Tool\n";
    cout << "1. Encrypt\n";
    cout << "2. Decrypt\n";
    cout << "Choose an option (1 or 2): ";
    cin >> choice;
    cin.ignore(); 

    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter shift (key): ";
    cin >> shift;

    if (choice == 1) {
        cout << "Encrypted Text: " << encrypt(text, shift) << endl;
    } else if (choice == 2) {
        cout << "Decrypted Text: " << decrypt(text, shift) << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
