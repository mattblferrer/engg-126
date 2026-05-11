#include <iostream>
#include <memory>
#include <vector>
using namespace std;

shared_ptr<vector<pair<string, long long>>> addExpense(shared_ptr<vector<pair<string, long long>>> expenses,
    const string& category, long long amount) {
    expenses->emplace_back(category, amount);
    return expenses;
}

shared_ptr<vector<pair<string, long long>>> viewExpenses(shared_ptr<vector<pair<string, long long>>> expenses) {
    long long total = 0;
    cout << "Current Expenses:\n";
    for (const auto& item : *expenses) {
        cout << item.first << ": " << item.second << "\n";
        total += item.second;
    }
    cout << "Total Expenses: " << total << "\n\n";
    return expenses;
}

shared_ptr<vector<pair<string, long long>>> viewCategoryStats(shared_ptr<vector<pair<string, long long>>> expenses) {
    const int categoryCount = 6;
    string categories[categoryCount] = {"food", "transport", "school", "rent", "shopping", "utilities"};
    long long totals[categoryCount] = {0, 0, 0, 0, 0, 0};
    long long otherTotal = 0;
    for (const auto& item : *expenses) {
        bool matched = false;
        for (int i = 0; i < categoryCount; i++) {
            if (item.first == categories[i]) {
                totals[i] += item.second;
                matched = true;
                break;
            }
        }
        if (!matched) otherTotal += item.second;
    }
    cout << "Category Totals:\n";
    for (int i = 0; i < categoryCount; i++) {
        cout << categories[i] << ": " << totals[i] << "\n";
    }
    cout << "other: " << otherTotal << "\n\n";
    return expenses;
}

int main() {
    shared_ptr<vector<pair<string, long long>>> expenses = make_shared<vector<pair<string, long long>>>();
    while (true) {
        cout << "Enter a command (add/view/stats/exit): ";
        string command, category;
        long long amount;
        cin >> command;

        if (command == "add") {
            cout << "Enter the category: ";
            cin >> category;
            cout << "Enter the amount for " << category << ": ";
            cin >> amount;
            if (cin.fail()) {
                cerr << "Invalid input. Please enter a valid number for the amount.\n";
                cin.clear(); // Clear the error state
                cin.ignore(10000, '\n'); // Ignore the rest of the line
            }
            else {
                expenses = addExpense(expenses, category, amount);
                cout << "Expense added: " << category << " - " << amount << "\n";
            }
        }
        else if (command == "view") {
            expenses = viewExpenses(expenses);
        }
        else if (command == "stats") {
            expenses = viewCategoryStats(expenses);
        }
        else if (command == "exit") {
            break;
        }
        else {
            cerr << "Unknown command. Please enter 'add', 'view', 'stats', or 'exit'.\n";
        }
    }
    return 0;
}