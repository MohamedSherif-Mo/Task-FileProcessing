#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

const string FILENAME = "data.txt";
const int SHIFT = 3;

void writeText() {
    ofstream file(FILENAME);
    if (!file) {
        cerr << "cant open file!" << endl;
        return;
    }

    string input;
    cout << "enter text to save: ";
    cin.ignore();
    getline(cin, input);

    file << input;
    file.close();
    cout << "data saved correctly!" << endl;
}

void readText() {
    ifstream file(FILENAME);
    if (!file) {
        cerr << "cant open the file!" << endl;
        return;
    }

    string content;
    cout << "file content:\n";
    while (getline(file, content)) {
        cout << content << endl;
    }

    file.close();
}

void lockText() {
    ifstream file(FILENAME);
    if (!file) {
        cerr << "cant open to encrypt!" << endl;
        return;
    }

    string content, encryptedContent;
    while (getline(file, content)) {
        for (char& c : content) {
            c += SHIFT;
        }
        encryptedContent += content + "\n";
    }
    file.close();

    ofstream outFile(FILENAME);
    outFile << encryptedContent;
    outFile.close();

    cout << "file encrypted correctly!" << endl;
}

void unlockText() {
    ifstream file(FILENAME);
    if (!file) {
        cerr << "cant open file to decrypt" << endl;
        return;
    }

    string content, decryptedContent;
    while (getline(file, content)) {
        for (char& c : content) {
            c -= SHIFT;
        }
        decryptedContent += content + "\n";
    }
    file.close();

    ofstream outFile(FILENAME);
    outFile << decryptedContent;
    outFile.close();

    cout << "file decrypted correctly!" << endl;
}

int main() {
    int choice;

    do {
        cout << "\n choose operation: \n";
        cout << "1 - Wriet and save text\n";
        cout << "2 - Read text\n";
        cout << "3 - Lock file\n";
        cout << "4 - Unlouk file\n";
        cout << "5 - exit\n";
        cout << "choose: ";
        cin >> choice;

        switch (choice) {
        case 1:
            writeText();
            break;
        case 2:
            readText();
            break;
        case 3:
            lockText();
            break;
        case 4:
            unlockText();
            break;
        case 5:
            cout << "exit...\n";
            break;
        default:
            cout << "wrong .. choose another.\n";
        }
    } while (choice != 5);
    _getch();
}
