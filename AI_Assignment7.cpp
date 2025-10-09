#include <iostream>
#include <vector>

using namespace std;

// Represents a rule: IF fact1 and fact2 are true THEN fact3 becomes true
struct Rule {
    int condition1; // Index of the first fact in the facts vector
    int condition2; // Index of the second fact
    int conclusion; // Index of the fact that becomes true
};

// The forward chaining algorithm
void forward_chaining(vector<bool>& facts, const vector<Rule>& rules) {
    bool new_fact_deduced = true;

    // The loop continues as long as new facts are being deduced
    while (new_fact_deduced) {
        new_fact_deduced = false;

        // Iterate through each rule in our knowledge base
        for (const auto& rule : rules) {
            // Check if both conditions of the rule are met
            if (facts[rule.condition1] && facts[rule.condition2]) {
                // Check if the conclusion is not already true
                if (!facts[rule.conclusion]) {
                    // If the conclusion is new, make it true
                    facts[rule.conclusion] = true;
                    new_fact_deduced = true; // A new fact was deduced, so we need to loop again
                    cout << "Rule fired! A new fact at index " << rule.conclusion << " is now true." << endl;
                }
            }
        }
    }
}

int main() {
    // 0: A, 1: B, 2: C, 3: D, 4: E
    // A and C are initially true
    vector<bool> facts = {true, false, true, false, false};

    // Define the rules based on the original problem logic
    vector<Rule> rules = {
        {0, 2, 4}, // Rule 1: IF A and C THEN E
        {4, 2, 3}, // Rule 2: IF E and C THEN D
        {3, 2, 1}  // Rule 3: IF D and C THEN B
    };

    cout << "Initial facts:" << endl;
    for (int i = 0; i < facts.size(); ++i) {
        cout << "Fact " << (char)('A' + i) << ": " << (facts[i] ? "True" : "False") << endl;
    }
    cout << "\nStarting forward chaining...\n" << endl;

    forward_chaining(facts, rules);

    cout << "\nFinal facts after forward chaining:" << endl;
    for (int i = 0; i < facts.size(); ++i) {
        cout << "Fact " << (char)('A' + i) << ": " << (facts[i] ? "True" : "False") << endl;
    }
    
    return 0;
}