#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

int main() {
    // Rules: (A,B) -> C   |   (C,D) -> E   |   (E) -> F
    map<vector<string>, string> rules = {
        { {"A", "B"}, "C" },
        { {"C", "D"}, "E" },
        { {"E"}, "F" }
    };

    set<string> facts = {"A", "B", "D"}; // initial facts
    string goal = "F";

    bool derived = true;

    while (derived) {
        derived = false;

        for (auto &r : rules) {
            vector<string> conditions = r.first;
            string conclusion = r.second;

            bool allTrue = true;
            for (auto &c : conditions) {
                if (facts.find(c) == facts.end()) {
                    allTrue = false;
                    break;
                }
            }

            if (allTrue && facts.find(conclusion) == facts.end()) {
                facts.insert(conclusion);
                cout << "Derived: " << conclusion << endl;
                derived = true;

                if (conclusion == goal) {
                    cout << "Goal satisfied!" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "Goal NOT satisfied!" << endl;
    return 0;
}
