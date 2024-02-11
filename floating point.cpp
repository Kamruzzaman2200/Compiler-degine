#include <iostream>
#include <string>
#include <cctype>

using namespace std;

enum State {
    q0,
    q1,
    q2,
    q3,
    q4
};

bool floatingPoint(string lexeme) {
    State currentState = q0;

    for (char ch : lexeme) {
        switch (currentState) {
            case q0:
                if (isdigit(ch)) {
                    currentState = q1;
                } else if (ch == '.') {
                    currentState = q2;
                }
                else {
                    return false;
                }
                break;

            case q1:
                if (isdigit(ch)) {
                } else if (ch == '.') {
                    currentState = q2;
                } else {
                    return false;
                }
                break;

            case q2:
                if (isdigit(ch)) {
                    currentState = q4;
                } else {
                    return false;
                }
                break;

            case q3:
                if (isdigit(ch)) {
                    currentState = q4;
                } else {
                    return false;
                }
                break;

            case q4:
                if (isdigit(ch)) {
                } else {
                    return false;
                }
                break;
        }
    }

    return currentState == q1 || currentState == q4;
}

int main() {
    string i;

    cout << "Enter a lexeme: ";
    cin >> i;

    if (floatingPoint(i)) {
        cout << "Valid floating-point number!" << endl;
    } else {
        cout << "Not a valid floating-point number." << endl;
    }

    return 0;
}
