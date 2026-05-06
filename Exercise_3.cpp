#include <iostream> 
#include <memory>
#include <vector>

using namespace std;

// Returns a dynamically allocated shared_ptr to a vector of integers
shared_ptr<vector<int>> createVector(int size) {
    shared_ptr<vector<int>> vec_ptr = make_shared<vector<int>>(size);
    for (int i = 0; i < size; i++) {
        (*vec_ptr)[i] = i;
    }
    return vec_ptr;
}

// Gives values to the elements of the vector from standard input
shared_ptr<vector<int>> modifyVector(shared_ptr<vector<int>> vec_ptr) {
    for (int i = 0; i < vec_ptr->size(); i++) {
        cout << "Enter a value for element " << i + 1 << ": ";
        cin >> (*vec_ptr)[i];
    }
    return vec_ptr;
}

// Prints the elements of the vector to standard output
shared_ptr<vector<int>> printVector(shared_ptr<vector<int>> vec_ptr) {
    cout << "The elements in the vector are: ";
    for (int i = 0; i < vec_ptr->size(); i++) {
        cout << (*vec_ptr)[i] << " ";
    }
    cout << "\n";
    return vec_ptr;
}

int main() {
    int size = 0;
    cout << "Enter the size of the vector: ";
    cin >> size;
    shared_ptr<vector<int>> vec = createVector(size);
    vec = modifyVector(vec);
    vec = printVector(vec);
    return 0;
}