#include <iostream>
#include <string>

using namespace std;

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool isSign(char c) {
    return c == '+' || c == '-';
}

bool isValidString(const string &str) {
    int currentState = 0;
    bool hasDot = false; // To keep track if a dot has been encountered

    for (char c : str) {
        switch (currentState) {
            case 0:
                if (c == '+' || c == '-') // Adding support for signs at the beginning
                    currentState = 1;
                else if (c >= '1' && c <= '9')
                    currentState = 2;
                else if (c == '.')
                    currentState = 3;
                else
                    return false;
                break;
            case 1:
                if (c >= '1' && c <= '9')
                    currentState = 2;
                else if (c == '.')
                    currentState = 3;
                else
                    return false;
                break;
            case 2:
                if (isDigit(c))
                    currentState = 2;
                else if (c == '.')
                    currentState = 4;
                else if (c == 'e' || c == 'E')
                    currentState = 6;
                else
                    return false;
                break;
            case 3:
                if (isDigit(c)) {
                    currentState = 5;
                    hasDot = true;
                } else
                    return false;
                break;
            case 4:
                if (isDigit(c))
                    currentState = 5;
                else
                    return false;
                break;
            case 5:
                if (isDigit(c))
                    currentState = 5;
                else if (c == 'e' || c == 'E')
                    currentState = 6;
                else
                    return false;
                break;
            case 6:
                if (isSign(c))
                    currentState = 7;
                else if (isDigit(c))
                    currentState = 8;
                else
                    return false;
                break;
            case 7:
                if (isDigit(c))
                    currentState = 8;
                else
                    return false;
                break;
            case 8:
                if (isDigit(c))
                    currentState = 8;
                else
                    return false;
                break;
        }
    }

    // To ensure there's at least one digit and if dot is present, it should not be at the end
    return (currentState == 2 || currentState == 5 || currentState == 8) && (!hasDot || currentState != 3);
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    if (isValidString(input)) {
        cout << "Valid string" << endl;
    } else {
        cout << "Invalid string" << endl;
    }

    return 0;
}
