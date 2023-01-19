#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

void MultiplyWithOutAMP() {
    int n1, m1, n2, m2, n3, m3;
    ifstream in("matrixpr.txt");
    in >> n1 >> m1;
    int **a = new int*[n1];
    for(int i = 0; i < n1; i++) {
        a[i] = new int[m1];
        for(int j = 0; j < m1; j++) {
            in >> a[i][j];
        }
    }

    in >> n2 >> m2;
    int **b = new int*[n2];
    for(int i = 0; i < n2; i++) {
        b[i] = new int[m2];
        for(int j = 0; j < m2; j++) {
            in >> b[i][j];
        }
    }

    int **c = new int*[n1];
    for(int i = 0; i < n1; i++) {
        c[i] = new int[m2];
        for(int j = 0; j < m2; j++) {
            c[i][j] = 0;
        }
    }


    for (int row = 0; row < n1; row++) {
        for (int col = 0; col < m2; col++) {
            for (int inner = 0; inner < m1; inner++) {
                c[row][col] += a[row][inner] * b[inner][col];
            }
            cout << c[row][col] << "  ";
        }
        cout << "\n";
    }
}

int main() {
    MultiplyWithOutAMP();
    getchar();
}