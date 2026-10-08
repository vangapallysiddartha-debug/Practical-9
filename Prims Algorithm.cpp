#include <iostream>
using namespace std;

#define INF 9999

int main() {
    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[20][20];

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];

            // 0 means there is no edge
            if (graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }

    int selected[20] = {0};
    int totalCost = 0;

    // Start from vertex 0
    selected[0] = 1;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (int edge = 0; edge < n - 1; edge++) {

        int minWeight = INF;
        int x = -1, y = -1;

        // Find minimum edge connecting selected to unselected vertex
        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && graph[i][j] < minWeight) {
                        minWeight = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        selected[y] = 1;

        cout << x << " - " << y
             << " : " << minWeight << endl;

        totalCost += minWeight;
    }

    cout << "\nMinimum Cost = " << totalCost << endl;

    return 0;
}
