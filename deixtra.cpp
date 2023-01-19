#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 100000;

vector<int> dikstra_find(vector<int> d, int n, int begin_index) {
    int** links = new int*[n];
    for (int i = 0; i < n; ++i) {
        links[i] = new int[n];
    }
    for (int i = 0; i < n * n; ++i) {
        links[i / n][i % n] = d[i];
    }
    vector<int> min_dist(n);
    vector<int> visited(n);
    int temp, min_index, min;
    for (int i = 0; i < n; ++i) {
        min_dist[i] = INF;
        visited[i] = 0;
    }
    min_dist[begin_index] = 0;
    do {
        min_index = INF;
        min = INF;
        for (int i = 0; i < n; ++i) {
            if ((visited[i] == 0) && (min_dist[i] < min)) {
                min = min_dist[i];
                min_index = i;
            }
        }
        if (min_index != INF) {
            for (int i = 0; i < n; ++i) {
                if (links[min_index][i] > 0) {
                    temp = min + links[min_index][i];
                    if (temp < min_dist[i]) {
                        min_dist[i] = temp;
                    }
                }
            }
            visited[min_index] = 1;
        }
    } while (min_index < INF);
    return min_dist;
}

void do_dikstra_test() {
    int n = 6;
    vector<int> links = {0, 2, 7, 4, 6, 3,
                         3, 0, 4, 5, 6, 1,
                         2, 4, 0, 8, 7, 0,
                         4, 0, 8, 0, 5, 7,
                         0, 7, 8, 4, 0, 3,
                         2, 4, 0, 7, 8, 0};
    int begin_index;
    cin >> begin_index;
    vector<int> min_dist = dikstra_find(links, n, begin_index - 1);
    cout << "\nDeixtra result\n";
    for (int i = 0; i < n; ++i) {
        cout << begin_index << "->" << i + 1 << " = " << min_dist[i] << endl;
    }
}

int main() {
    do_dikstra_test();
    return 0;
}