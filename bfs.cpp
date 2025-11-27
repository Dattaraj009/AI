#include <bits/stdc++.h>
using namespace std;

string goal = "12345678_";

vector<string> getNeighbours(string s) {
    vector<string> res;
    int idx = s.find('_');
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

int main() {
    string start = "1234567_8";

    queue<string> q;
    set<string> vis;

    q.push(start);
    vis.insert(start);

    while (!q.empty()) {
        string cur = q.front(); q.pop();

        if (cur == goal) {
            cout << "Goal found using BFS\n";
            return 0;
        }

        for (auto next : getNeighbours(cur)) {
            if (!vis.count(next)) {
                vis.insert(next);
                q.push(next);
            }
        }
    }
    cout << "Goal NOT reachable\n";
}
