#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>> &visited, vector<vector<int>> &m) {
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1) {
        return true;
    }
    return false;
}

void solve(vector<vector<int>> &m, int n, vector<string> &ans, int x, int y, vector<vector<int>> &visited, string path) {
    // base case
    if (x == n - 1 && y == n - 1) {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // Down
    if (isSafe(x + 1, y, n, visited, m)) {
        solve(m, n, ans, x + 1, y, visited, path + 'D');
    }

    // Up
    if (isSafe(x - 1, y, n, visited, m)) {
        solve(m, n, ans, x - 1, y, visited, path + 'U');
    }

    // Left
    if (isSafe(x, y - 1, n, visited, m)) {
        solve(m, n, ans, x, y - 1, visited, path + 'L');
    }

    // Right
    if (isSafe(x, y + 1, n, visited, m)) {
        solve(m, n, ans, x, y + 1, visited, path + 'R');
    }

    visited[x][y] = 0; // backtrack
}

vector<string> ratInMaze(vector<vector<int>> &maze, int n) {
    vector<string> ans;

    if (maze[0][0] == 0) {
        return ans;
    }

    vector<vector<int>> visited(n, vector<int>(n, 0));
    string path = "";
    solve(maze, n, ans, 0, 0, visited, path);

    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    // Example Maze
    vector<vector<int>> maze = {
        {1, 0, 0, 0},             
        {1, 1, 0, 1},
        {0, 1, 1, 0},            
        {1, 1, 1, 1}
    };
    
    int n = maze.size();

    vector<string> paths = ratInMaze(maze, n);

    if (paths.empty()) {
        cout << "No Path Found" << endl;
    } else {
        cout << "Possible Paths are: " << endl;
        for (string p : paths) {
            cout << p << " ";
        }
        cout << endl;
    }

    return 0;
}
