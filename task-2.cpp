#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void findAndReplace(const string& fileName, const string& wordToFind, const string& wordToInsert) {
    string path = "D:\\" + fileName;
    ifstream reader(path);
    if (!reader) {
        cerr << "Error: Cannot open file: " << path << endl;
        return;
    }

    string updatedText, currentLine;
    while (getline(reader, currentLine)) {
        size_t index = 0;
        while ((index = currentLine.find(wordToFind, index)) != string::npos) {
            currentLine.replace(index, wordToFind.length(), wordToInsert);
            index += wordToInsert.length();
        }
        updatedText += currentLine + "\n";
    }
    reader.close();

    string newFilePath = "D:\\NewFile.txt";
    ofstream writer(newFilePath);
    if (!writer) {
        cerr << "Error: Cannot create the file: " << newFilePath << endl;
        return;
    }

    writer << updatedText;
    writer.close();
    cout << "Replacement done! Check '" << newFilePath << "'." << endl;
}

int main() {
    string inputFileName, searchWord, newWord;

    cout << "Enter file name (without path, it should be in D:\\): ";
    cin >> inputFileName;
    cout << "Enter word to replace: ";
    cin >> searchWord;
    cout << "Enter replacement word: ";
    cin >> newWord;

    findAndReplace(inputFileName, searchWord, newWord);

    return 0;
}
