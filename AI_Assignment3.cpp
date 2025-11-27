#include <bits/stdc++.h>
using namespace std;

map<string, vector<string>> parentOf;   // child -> parents
map<string, vector<string>> childrenOf; // parent -> children

void add(string parent, string child) {
    parentOf[child].push_back(parent);
    childrenOf[parent].push_back(child);
}

int main() {
    // ----- Knowledge Base -----
    add("John", "A");
    add("Mary", "A");
    add("John", "B");
    add("Mary", "B");
    add("A", "C");

    string q, x;
    cout << "Commands: parent X | children X | siblings X | grandparent X\n";

    while (true) {
        cout << "Query: ";
        cin >> q;
        if (q == "exit") break;
        cin >> x;

        if (q == "parent") {
            for (auto &p : parentOf[x]) cout << p << " ";
            cout << "\n";
        }

        else if (q == "children") {
            for (auto &c : childrenOf[x]) cout << c << " ";
            cout << "\n";
        }

        else if (q == "siblings") {
            vector<string> sib;
            for (auto &p : parentOf[x]) {
                for (auto &c : childrenOf[p])
                    if (c != x) sib.push_back(c);
            }
            for (auto &s : sib) cout << s << " ";
            cout << "\n";
        }

        else if (q == "grandparent") {
            vector<string> gp;
            for (auto &p : parentOf[x]) {
                for (auto &g : parentOf[p])
                    gp.push_back(g);
            }
            for (auto &g : gp) cout << g << " ";
            cout << "\n";
        }

        else cout << "Unknown command\n";
    }
    return 0;
}
