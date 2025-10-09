#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Represents a rule: IF fact1 and fact2 are true THEN conclusion is true
struct Rule {
    string condition1;
    string condition2;
    string conclusion;
};

// The backward chaining algorithm
bool backward_chaining(const string& goal, const vector<string>& facts, const vector<Rule>& rules) {
    // Check if the goal is already a known fact
    for (const string& fact : facts) {
        if (fact == goal) {
            cout << "Goal '" << goal << "' is a known fact. Success!" << endl;
            return true;
        }
    }

    cout << "Goal '" << goal << "' is not a known fact. Trying to prove it..." << endl;

    // Search for a rule whose conclusion matches the goal
    for (const auto& rule : rules) {
        if (rule.conclusion == goal) {
            cout << "Found a rule: IF " << rule.condition1 << " AND " << rule.condition2 << " THEN " << rule.conclusion << endl;

            // Recursively try to prove the conditions of this rule
            if (backward_chaining(rule.condition1, facts, rules) &&
                backward_chaining(rule.condition2, facts, rules)) {
                
                cout << "Successfully proved the conditions for goal '" << goal << "'. Success!" << endl;
                return true; // The goal is proven
            }
        }
    }

    // If no rule can prove the goal, it is unprovable
    cout << "Could not prove goal '" << goal << "'. Failure." << endl;
    return false;
}

int main() {
    // Initial known facts
    vector<string> facts = {"A", "C"};

    // Knowledge base (rules)
    vector<Rule> rules = {
        {"A", "C", "E"}, // Rule 1: IF A and C THEN E
        {"E", "C", "D"}, // Rule 2: IF E and C THEN D
        {"D", "C", "B"}  // Rule 3: IF D and C THEN B
    };

    // The goal we want to prove
    string goal_to_prove = "G";

    cout << "Attempting to prove the goal: " << goal_to_prove << endl;
    
    if (backward_chaining(goal_to_prove, facts, rules)) {
        cout << "\nConclusion: The goal '" << goal_to_prove << "' has been proven." << endl;
    } else {
        cout << "\nConclusion: The goal '" << goal_to_prove << "' could not be proven." << endl;
    }

    return 0;
}