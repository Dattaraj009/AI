#include <bits/stdc++.h>
using namespace std;

string goal = "12345678_";
set<string> visited;

vector<string> getNeighbours(string s) {
    vector<string> res;
    int idx = s.find('_');  // blank index
    int r = idx / 3, c = idx % 3;

    int dr[] = {1, -1, 0, 0};
    int dc[] = {0, 0, 1, -1};

    for (int k = 0; k < 4; k++) {
        int nr = r + dr[k];
        int nc = c + dc[k];
        if (nr >= 0 && nr < 3 && nc >= 0 && nc < 3) {
            string t = s;
            swap(t[idx], t[nr * 3 + nc]);
            res.push_back(t);
        }
    }
    return res;
}

bool DFS(string state) {
    if (state == goal) return true;
    visited.insert(state);

    for (auto next : getNeighbours(state)) {
        if (!visited.count(next)) {
            if (DFS(next)) return true;
        }
    }
    return false;
}

int main() {
    string start = "1234567_8"; // example initial state
    if (DFS(start)) cout << "Goal Found using DFS\n";
    else cout << "Goal NOT reachable\n";
}
