#include <bits/stdc++.h>
using namespace std;

int bfsMaxRegion(vector<vector<int>>& matrix, int m, int r) {
    vector<vector<bool>> visited(m, vector<bool>(r, false));
    // Max-heap que almacena pares de valores y sus coordenadas
    priority_queue<pair<int, pair<int, int>>> max_heap;

    // Llenar el max-heap con todos los valores y coordenadas
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < r; j++) {
            max_heap.push({matrix[i][j], {i, j}});
        }
    }

    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int visited_n = 0;

    while (!max_heap.empty()) {
        // Obtener el máximo actual
        auto [value, pos] = max_heap.top();
        max_heap.pop();
        int x = pos.first;
        int y = pos.second;

        // Si ya fue visitado, continuamos con el siguiente elemento en el heap
        if (visited[x][y]) continue;

        // Marcar como visitado y proceder con el BFS desde este punto
        queue<pair<int, int>> q;
        q.push({x, y});
        visited[x][y] = true;
        visited_n++;

        while (!q.empty()) {
            auto [cx, cy] = q.front();
            q.pop();

            for (auto [dx, dy] : directions) {
                int nx = cx + dx, ny = cy + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < r && !visited[nx][ny] && matrix[nx][ny] <= matrix[cx][cy]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    return visited_n;
}

int main() {
    int m, r;
    cin >> m >> r;
    vector<vector<int>> matrix(m, vector<int>(r));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < r; j++){
            int x;
            cin >> x ;
            if(x == 1) {
                matrix[i][j] = 0;
            } else {
                matrix[i][j] = x;
            }
        }
    cout << bfsMaxRegion(matrix, m, r) << endl;
    return 0;
}