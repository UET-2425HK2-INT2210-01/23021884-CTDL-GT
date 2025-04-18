#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Mo file dau vao
    ifstream inputFile("numbers.txt");
    // Mo file dau ra
    ofstream outputFile("numbers.sorted");


    vector<double> numbers; // Luu tru cac so thuc
    double num;

    // Doc cac so tu file (co the cach nhau boi khoang trang hoac xuong dong)
    while (inputFile >> num) {
        numbers.push_back(num);
    }

    // Sap xep cac so theo thu tu tang dan
    sort(numbers.begin(), numbers.end());

    // Ghi ket qua da sap xep vao file dau ra
    for (size_t i = 0; i < numbers.size(); ++i) {
        outputFile << numbers[i];
        if (i != numbers.size() - 1) {
            outputFile << " "; // Them dau cach giua cac so
        }
    }

    // Dong cac file
    inputFile.close();
    outputFile.close();

    return 0;
}

