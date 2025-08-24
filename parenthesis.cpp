#include<iostream>
#include<vector>
using namespace std;

void solve(int n, int open, int close, string output, vector<string> &ans) {
    // base case
    if (output.size() == 2 * n) {
        ans.push_back(output);
        return;
    }

    // add '(' if possible
    if (open < n) {
        solve(n, open + 1, close, output + "(", ans);
    }

    // add ')' if possible
    if (close < open) {
        solve(n, open, close + 1, output + ")", ans);
    }
}

int main() {
    int n;
    cin >> n;

    vector<string> ans;
    solve(n, 0, 0, "", ans);

    cout << "Valid Parentheses combinations are:\n";
    for (auto s : ans) {
        cout << s << endl;
    }

    return 0;
}
