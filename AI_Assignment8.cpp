#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

set<string> facts = {"A", "B", "D"}; // base facts

map<string, vector<string>> rules = {
    {"C", {"A", "B"}},
    {"E", {"C", "D"}},
    {"F", {"E"}}
};

bool backwardChaining(string goal) {
    // If goal is already a fact, return true
    if (facts.find(goal) != facts.end())
        return true;

    // If no rule produces this goal, fail
    if (rules.find(goal) == rules.end())
        return false;

    // Get prerequisites
    vector<string> reqs = rules[goal];

    // Check each requirement
    for (string r : reqs) {
        if (!backwardChaining(r))
            return false;
    }
    return true;
}

int main() {
    string goal = "F";

    if (backwardChaining(goal))
        cout << "Goal can be derived!" << endl;
    else
        cout << "Goal CANNOT be derived!" << endl;

    return 0;
}
