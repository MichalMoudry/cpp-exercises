#include <iostream>
#include <string>

using namespace std;

int main() {
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key {"XZNLWEBGJHQDYVTKFUOMPCIAASRxznlwebgjhqdyvtfuompciasr"};

    cout << "Enter secret message: ";
    string secret_message;
    getline(cin, secret_message);

    string encrypted_message (secret_message.length(), ' ');
    size_t char_index;
    char current_char;
    for (int i {}; i < secret_message.length(); i++) {
        current_char = secret_message.at(i);
        char_index = alphabet.find(current_char);
        if (char_index != string::npos) {
            encrypted_message[i] = key[char_index];
        }
        else {
            encrypted_message[i] = current_char;
        }
    }

    string decrypted_message (encrypted_message.length(), ' ');
    for (int i {}; i < encrypted_message.length(); i++) {
        current_char = encrypted_message.at(i);
        char_index = key.find(current_char);
        if (char_index != string::npos) {
            decrypted_message[i] = alphabet.at(char_index);
        }
        else {
            decrypted_message[i] = current_char;
        }
    }

    cout << "Encrypted message: " << encrypted_message << endl;
    cout << "Decrypted message: " << decrypted_message << endl;
    return 0;
}