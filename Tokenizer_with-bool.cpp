#include <iostream>    // Include the standard input/output stream header
#include <string>      // Include the string header
#include <sstream>     // Include the string stream header

using namespace std;  // Using the standard namespace to simplify code

bool isOperator(char c) {  // Define a function to check if a character is an operator
    string operators = "+-*/%=(){}[],;";  // Define a string containing all operators
    return operators.find(c) != string::npos;  // Check if the character is found in the operators string
}

bool isKeyword(const string& token) {  // Define a function to check if a token is a keyword
    return token == "int" || token == "return";  // Check if the token is "int" or "return"
}

bool isIdentifier(const string& token) {  // Define a function to check if a token is an identifier
    return isalpha(token[0]) || token[0] == '_';  // Check if the first character is alphabetical or underscore
}

bool isInteger(const string& token) {  // Define a function to check if a token is an integer
    for (char c : token) {  // Iterate through each character in the token
        if (!isdigit(c)) {  // Check if the character is not a digit
            return false;  // If not, return false
        }
    }
    return true;  // If all characters are digits, return true
}

bool isFloat(const string& token) {  // Define a function to check if a token is a float
    bool decimalPoint = false;  // Initialize a boolean flag to track the presence of a decimal point
    for (char c : token) {  // Iterate through each character in the token
        if (c == '.') {  // Check if the character is a decimal point
            if (decimalPoint) {  // If a decimal point has already been found
                return false;  // Return false (more than one decimal point)
            }
            decimalPoint = true;  // Set the flag to true to indicate the presence of a decimal point
        } else if (!isdigit(c)) {  // Check if the character is not a digit
            return false;  // If not, return false
        }
    }
    return decimalPoint;  // Return true if there is at least one decimal point
}

bool isExponential(const string& token) {  // Define a function to check if a token is in exponential notation
    bool foundE = false;  // Initialize a boolean flag to track the presence of 'e' or 'E'
    for (char c : token) {  // Iterate through each character in the token
        if (c == 'e' || c == 'E') {  // Check if the character is 'e' or 'E'
            if (foundE) {  // If 'e' or 'E' has already been found
                return false;  // Return false (more than one 'e' or 'E')
            }
            foundE = true;  // Set the flag to true to indicate the presence of 'e' or 'E'
        } else if (!isdigit(c)) {  // Check if the character is not a digit
            return false;  // If not, return false
        }
    }
    return foundE;  // Return true if there is at least one 'e' or 'E'
}

void tokenize(const string& input) {  // Define a function to tokenize the input string
    istringstream iss(input);  // Create a string stream to extract tokens from the input
    string token;  // Declare a string variable to store each token
    int tokenCount = 0, identifierCount = 0, keywordCount = 0, symbolCount = 0, operatorCount = 0, integerCount = 0, floatCount = 0, exponentialCount = 0;  // Initialize counters for various token types

    while (iss >> token) {  // Read tokens from the string stream until there are no more tokens
        tokenCount++;  // Increment the total token count

        cout << token << " ";  // Print the token followed by a space

        if (isKeyword(token)) {  // Check if the token is a keyword
            keywordCount++;  // Increment the keyword count
        } else if (isIdentifier(token)) {  // Check if the token is an identifier
            identifierCount++;  // Increment the identifier count
        }

        for (char c : token) {  // Iterate through each character in the token
            if (isOperator(c)) {  // Check if the character is an operator
                if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '=') {  // Check if the character is a specific operator
                    operatorCount++;  // Increment the operator count
                } else {
                    symbolCount++;  // Increment the symbol count for other operators
                }
            }
        }

        if (isInteger(token)) {  // Check if the token is an integer
            integerCount++;  // Increment the integer count
        } else if (isFloat(token)) {  // Check if the token is a float
            floatCount++;  // Increment the float count
        } else if (isExponential(token)) {  // Check if the token is in exponential notation
            exponentialCount++;  // Increment the exponential count
        }
    }

    // Output the counts of different token types
    cout << "Token: " << tokenCount << endl;
    cout << "Identifier: " << identifierCount << endl;
    cout << "Keyword: " << keywordCount << endl;
    cout << "Symbol: " << symbolCount << endl;
    cout << "Operator: " << operatorCount << endl;
    cout << "Integer: " << integerCount << endl;
    cout << "Float: " << floatCount << endl;
    cout << "Exponential: " << exponentialCount << endl;
}

int main() {  // Define the main function
    cout << "Enter input string: ";  // Prompt the user to enter an input string
    string input;  // Declare a string variable to store the input
    getline(cin, input);  // Read a line of input from the standard input stream
    tokenize(input);  // Call the tokenize function with the input string
    return 0;  // Return 0 to indicate successful execution
}
