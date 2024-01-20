#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Enumeration to represent the states of the DFA
enum State { 
    q,
    q1
};

// Function to check if a given lexeme is a valid identifier
bool valid(string lexeme) {
    // Initialize the state of the DFA to q
    State currentState = q;

    // Iterate through each character in the lexeme
    for (char ch : lexeme) {
        switch (currentState) {
            case q:
                // Check if the current character is an alphabet or underscore
                if (isalpha(ch) || ch == '_') {
                    currentState = q1;  // Move to the q1 state
                } else {
                    return false;  // Invalid character encountered in q state
                }
                break;

            case q1:
                // Check if the current character is an alphanumeric or underscore
                if (isalnum(ch) || ch == '_') {
                    // Valid identifier character, stay in the q1 state
                } else {
                    return false;  // Invalid character encountered in q1 state
                }
                break;
        }
    }

    // Check if the final state is q1, indicating a valid identifier
    return currentState == q1;
}

int main() {
    // Input variable to store the user-entered lexeme
    string input;

    // Prompt the user to enter a lexeme
    cout << "Enter a lexeme: ";
    cin >> input;

    // Check if the entered lexeme is a valid identifier and display the result
    if (valid(input)) {
        cout << "Valid identifier!" << endl;
    } else {
        cout << "Not a valid identifier." << endl;
    }

    return 0;
}
