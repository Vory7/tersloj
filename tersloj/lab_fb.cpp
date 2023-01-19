#include <iostream>
#include <fstream>
#include <math.h>
#define inf 100000
using namespace std;
struct Edges {
    int a, b, w;
};
int e;

void bellman_ford(Edges edge[], int n, int start) {
    int i, j, d[n] = {inf};
    d[start] = 0;
    
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < e; j++) {
            if (d[edge[j].a] != inf) {
                if (d[edge[j].a] + edge[j].w < d[edge[j].b]) {
                    d[edge[j].b] = d[edge[j].a] + edge[j].w;
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (d[i] == inf) {
            cout << start + 1 << "->" << i + 1 << " = " << "Not" << endl;
        } else {
            cout << start + 1 << "->" << i + 1 << " = " << d[i] << endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    int n, w, start;
    ifstream in("matrix.txt");
    e = 0;
    cout << "Количество вершин > ";    
    in >> n;
    Edges edge[n * n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            edge[e].a = i;
            edge[e].b = j;
            cout << "Вес " << i + 1 << "->" << j + 1 << " > ";
            //w = rand() % 10 - 11; cout << w << endl;
            //cin >> w;
            in >> w; cout << w << endl;
            edge[e].w = w;
            e++;
        }
    }
    cout << "Стартовая вершина > ";
    cin >> start;
    bellman_ford(edge, n, start - 1);
}
