#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// Structure to represent a predicate
struct Predicate {
    string name;
    vector<string> arguments;

    Predicate(string n, vector<string> args) : name(n), arguments(args) {}
};

// Function to perform unification of two predicates
unordered_map<string, string> unify(const Predicate& p1, const Predicate& p2) {
    unordered_map<string, string> substitution;
    if (p1.name != p2.name || p1.arguments.size() != p2.arguments.size()) {
        return substitution; // Predicates are not unifiable
    }

    for (size_t i = 0; i < p1.arguments.size(); ++i) {
        if (p1.arguments[i] != p2.arguments[i]) {
            substitution[p1.arguments[i]] = p2.arguments[i];
        }
    }

    return substitution;
}

// Function to perform resolution of two clauses
vector<Predicate> resolve(const vector<Predicate>& clause1, const vector<Predicate>& clause2) {
    vector<Predicate> resolvents;
    for (const auto& pred1 : clause1) {
        for (const auto& pred2 : clause2) {
            if (pred1.name == pred2.name && pred1.arguments.size() == pred2.arguments.size()) {
                auto substitution = unify(pred1, pred2);
                if (substitution.empty()) {
                    continue; // Predicates are not unifiable
                }

                // Apply substitution to the second clause
                vector<Predicate> resolvent;
                for (const auto& pred : clause2) {
                    Predicate new_pred = pred;
                    for (auto& arg : new_pred.arguments) {
                        if (substitution.find(arg) != substitution.end()) {
                            arg = substitution[arg];
                        }
                    }
                    resolvent.push_back(new_pred);
                }
                resolvents.insert(resolvents.end(), clause1.begin(), clause1.end());
                resolvents.insert(resolvents.end(), resolvent.begin(), resolvent.end());
                return resolvents;
            }
        }
    }

    return resolvents; // No resolvent found
}

int main() {
    // Example clauses
    vector<Predicate> clause1 = {Predicate("P", {"x", "y"}), Predicate("Q", {"z"})};
    vector<Predicate> clause2 = {Predicate("P", {"A", "B"}), Predicate("R", {"C"})};

    // Perform resolution
    vector<Predicate> resolvents = resolve(clause1, clause2);

    // Display resolvents
    cout << "Resolvents:" << endl;
    for (const auto& pred : resolvents) {
        cout << pred.name << "(";
        for (size_t i = 0; i < pred.arguments.size(); ++i) {
            cout << pred.arguments[i];
            if (i < pred.arguments.size() - 1) {
                cout << ", ";
            }
        }
        cout << ")" << endl;
    }

    return 0;
}
