#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Enumeration to represent the states of the DFA
enum State {
    START,
    ACCEPTING
};

// Function to check if a given lexeme is a valid identifier
bool isValidIdentifier(string lexeme) {
    // Initialize the state of the DFA to START
    State currentState = START;

    // Iterate through each character in the lexeme
    for (char ch : lexeme) {
        switch (currentState) {
            case START:
                // Check if the current character is an alphabet or underscore
                if (isalpha(ch) || ch == '_') {
                    currentState = ACCEPTING;  // Move to the ACCEPTING state
                } else {
                    return false;  // Invalid character encountered in START state
                }
                break;

            case ACCEPTING:
                // Check if the current character is an alphanumeric or underscore
                if (isalnum(ch) || ch == '_') {
                    // Valid identifier character, stay in the ACCEPTING state
                } else {
                    return false;  // Invalid character encountered in ACCEPTING state
                }
                break;
        }
    }

    // Check if the final state is ACCEPTING, indicating a valid identifier
    return currentState == ACCEPTING;
}

int main() {
    // Input variable to store the user-entered lexeme
    string input;

    // Prompt the user to enter a lexeme
    cout << "Enter a lexeme: ";
    cin >> input;

    // Check if the entered lexeme is a valid identifier and display the result
    if (isValidIdentifier(input)) {
        cout << "Valid identifier!" << endl;
    } else {
        cout << "Not a valid identifier." << endl;
    }

    return 0;
}
