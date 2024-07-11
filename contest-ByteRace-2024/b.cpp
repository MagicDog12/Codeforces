#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool canTransform(int n, int m, vector<string>& a, vector<string>& b) {
    vector<vector<int>> delta(n, vector<int>(m, 0));
    
    // Calculate the difference required for each cell
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            delta[i][j] = (b[i][j] - a[i][j] + 3) % 3;
        }
    }

    // Apply the transformations to the grid
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            int t = delta[i][j];
            delta[i][j + 1] = (delta[i][j + 1] + t) % 3;
            delta[i + 1][j] = (delta[i + 1][j] + t) % 3;
            delta[i + 1][j + 1] = (delta[i + 1][j + 1] + t) % 3;
        }
    }

    // Check the last row and column
    for (int i = 0; i < n; ++i) {
        if (delta[i][m-1] != 0) return false;
    }
    for (int j = 0; j < m; ++j) {
        if (delta[n-1][j] != 0) return false;
    }

    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        if (canTransform(n, m, a, b)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
