#include <iostream>
#include <string>
#include <cctype>

using namespace std;

enum State {
    START,
    ACCEPTING
};

bool isValidIdentifier(string lexeme) {
    State currentState = START;

    for (char ch : lexeme) {
        switch (currentState) {
            case START:
                if (isalpha(ch) || ch == '_') {
                    currentState = ACCEPTING;
                } else {
                    return false;  // Invalid character encountered
                }
                break;

            case ACCEPTING:
                if (isalnum(ch) || ch == '_') {
                    // Valid identifier character
                } else {
                    return false;  // Invalid character encountered
                }
                break;
        }
    }

    return currentState == ACCEPTING;
}
int main() {
    string input;
    cout << "Enter a lexeme: ";
    cin >> input;

    if (isValidIdentifier(input)) {
        cout << "Valid identifier!" << endl;
    } else {
        cout << "Not a valid identifier." << endl;
    }

    return 0;
}
