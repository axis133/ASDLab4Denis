#include <iostream>
#include <vector>

using namespace std;

int V = 4;
int E = 4;

void convertToIncidenceMatrix(vector<vector<int>> adjMatrix) {
    vector<vector<int>> incidenceMatrix(V, vector<int>(E));

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adjMatrix[i][j] == 1) {
                int edgeNumber = 0;
                for (int k = 0; k < V; k++) {
                    if (k != i && adjMatrix[k][j] == 1) {
                        edgeNumber = k;
                        break;
                    }
                }

                incidenceMatrix[i][edgeNumber] = 1;
            }
        }
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < E; j++) {
            cout << incidenceMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> adjMatrix = { {0, 1, 1, 1},
                                     {1, 0, 1, 0},
                                     {1, 1, 0, 1},
                                     {1, 0, 1, 0} };

    convertToIncidenceMatrix(adjMatrix);

    return 0;
}