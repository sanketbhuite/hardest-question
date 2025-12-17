#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    vector<vector<int>> grid;
    ifstream f("grid.csv");
    string ln;
    while (getln(f, ln)) {
        stringstream ss(ln);
        string v;
        vector<int> r;
        while (getln(ss, v, ',')) {
            r.push_back(stoi(v));
        }
        grid.push_back(r);
    }
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = grid[0][0];
    for (int j = 1; j < m; j++) {
        dp[0][j] = dp[0][j - 1] ^ grid[0][j];
    }
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] ^ grid[i][0];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) ^ grid[i][j];
        }
    }
    cout << "Min XOR Path: " << dp[n - 1][m - 1] << endl;
    return 0;
}
