#include <bits/stdc++.h>
using namespace std;

string goal = "12345678_";

vector<string> getNeighbours(string s) {
    vector<string> ans;
    int idx = s.find('_');
    int r = idx / 3, c = idx % 3;

    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
        int nr = r + delrow[i], nc = c + delcol[i];
        if (nr >= 0 && nr < 3 && nc >= 0 && nc < 3) {
            string t = s;
            swap(t[idx], t[nr * 3 + nc]);
            ans.push_back(t);
        }
    }
    return ans;
}

int main() {
    string start = "1234567_8";

    queue<string> q;
    set<string> vis;

    q.push(start);
    vis.insert(start);

    while (!q.empty()) {
        string cur = q.front(); 
        q.pop();

        if (cur == goal) {
            cout << "Goal Found\n";
            return 0;
        }

        for (string nxt : getNeighbours(cur)) {
            if (!vis.count(nxt)) {
                vis.insert(nxt);
                q.push(nxt);
            }
        }
    }

    cout << "Goal NOT reachable\n";
}
