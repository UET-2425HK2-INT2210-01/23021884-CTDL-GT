#include <iostream>
#include <fstream>
#include <vector>
#include <climits> // De dung INT_MIN

using namespace std;

int main() {
    // Mo file dau vao va dau ra
    ifstream inputFile("matrix.txt");
    ofstream outputFile("matrix.out");

    int m, n;
    inputFile >> m >> n; // Doc so hang (m) va so cot (n)

    // Doc ma tran tu file
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            inputFile >> matrix[i][j];

    // Bien luu ket qua lon nhat tim duoc
    int maxSum = INT_MIN;
    int finalLeft = 0, finalRight = 0, finalTop = 0, finalBottom = 0;

    // Duyet qua tat ca cap hang tren - duoi (top-bottom)
    for (int top = 0; top < m; ++top) {
        vector<int> temp(n, 0); // Mang tam dai dien cho tong theo cot

        for (int bottom = top; bottom < m; ++bottom) {
            // Cong don cac gia tri hang tu top toi bottom theo tung cot
            for (int col = 0; col < n; ++col)
                temp[col] += matrix[bottom][col];

            int sum = 0, startCol = 0;
            int localLeft = 0, localRight = 0;
            int localMax = INT_MIN;

            for (int col = 0; col < n; ++col) {
                sum += temp[col];

                if (sum > localMax) {
                    localMax = sum;
                    localLeft = startCol;
                    localRight = col;
                }

                if (sum < 0) {
                    sum = 0;
                    startCol = col + 1; // Bat dau lai day moi
                }
            }

            // Neu tim duoc tong lon hon, cap nhat ket qua
            if (localMax > maxSum) {
                maxSum = localMax;
                finalTop = top;
                finalBottom = bottom;
                finalLeft = localLeft;
                finalRight = localRight;
            }
        }
    }

    // Ghi ket qua ra file (dung chi so bat dau tu 1)
    outputFile << finalTop + 1 << " " << finalLeft + 1 << " "
               << finalBottom + 1 << " " << finalRight + 1 << " "
               << maxSum << endl;

    return 0;
}

