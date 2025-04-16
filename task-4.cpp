#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define BUFFER_SIZE 1024 

void simulateDataTransfer(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile, ios::binary);
    if (!inFile) {
        cerr << "Error: Cannot open input file!" << endl;
        return;
    }

    ofstream outFile(outputFile, ios::binary);
    if (!outFile) {
        cerr << "Error: Cannot create output file!" << endl;
        return;
    }

    vector<char> buffer(BUFFER_SIZE);

    while (!inFile.eof()) {
        inFile.read(buffer.data(), BUFFER_SIZE);
        streamsize bytesRead = inFile.gcount();
        outFile.write(buffer.data(), bytesRead);
    }

    inFile.close();
    outFile.close();

    cout << "Data transfer completed using buffer!" << endl;
}

int main() {
    string inputFile, outputFile;
    cout << "Enter input file name: ";
    cin >> inputFile;
    cout << "Enter output file name: ";
    cin >> outputFile;

    simulateDataTransfer(inputFile, outputFile);
    return 0;
}
