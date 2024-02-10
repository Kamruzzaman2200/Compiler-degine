#include <iostream>
#include <string>
#include <cctype>

using namespace std;

enum TokenType {
    INTEGER,
    IDENTIFIER,
    OPERATOR,
    INVALID
};

TokenType getTokenType(const string& token) {
    if (token.empty()) return INVALID;

    int currentState = 0;
    for (char c : token) {
        switch (currentState) {
            case 0:
                if (isdigit(c)) currentState = 1;
                else if (isalpha(c)) currentState = 2;
                else if (c == '+' || c == '-' || c == '*' || c == '/') currentState = 3;
                else return INVALID;
                break;
            case 1:
                if (!isdigit(c)) return INVALID;
                break;
            case 2:
                if (!isalnum(c)) return INVALID;
                break;
            case 3:
                return INVALID;
        }
    }

    switch (currentState) {
        case 1: return INTEGER;
        case 2: return IDENTIFIER;
        case 3: return OPERATOR;
        default: return INVALID;
    }
}

int main() {
    string input;
    cout << "Enter a token: ";
    cin >> input;

    switch (getTokenType(input)) {
        case INTEGER: cout << "Token is an Integer" << endl; break;
        case IDENTIFIER: cout << "Token is an Identifier" << endl; break;
        case OPERATOR: cout << "Token is an Operator" << endl; break;
        case INVALID: cout << "Invalid Token" << endl; break;
    }

    return 0;
}
