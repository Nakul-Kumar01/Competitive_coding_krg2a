#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(vector<vector<int>>& isConnected, int node, vector<bool>& visited) {
    visited[node] = true;

    for (int i = 0; i < isConnected.size(); i++) {
        if (isConnected[node][i] == 1 && !visited[i]) {
            dfs(isConnected, i, visited);
        }
    }
}

int countProvinces(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<bool> visited(n, false);

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(isConnected, i, visited);
            count++;
        }
    }

    return count;
}

int main() {
    int n = 3;
    vector<vector<int>> isConnected(n, vector<int>(n, 0));

    isConnected[0][0] = 1;
    isConnected[0][1] = 1;
    isConnected[1][0] = 1;
    isConnected[1][1] = 1;
    isConnected[2][2] = 0;

    int provinces = countProvinces(isConnected);

    cout << "Total number of provinces: " << provinces << endl;

    return 0;
}