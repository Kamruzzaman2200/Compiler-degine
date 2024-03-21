#include <iostream>
#include <string>
#include <cctype> // For character classification functions like isdigit, isalpha

using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    string operators = "+-*/%=(){}[],;"; // List of operators
    return operators.find(c) != string::npos; // Check if the character is in the list of operators
}

// Function to check if a string is a keyword
bool isKeyword(const string& token) {
    return (token == "int" || token == "return"); // Check if the token matches any keyword
}

// Function to check if a string is a valid identifier
bool isIdentifier(const string& token) {
    return isalpha(token[0]) || token[0] == '_'; // Check if the first character is alphabetic or underscore
}

// Function to check if a string is an integer
bool isInteger(const string& token) {
    for (char c : token) { // Iterate through each character in the token
        if (!isdigit(c)) { // If any character is not a digit
            return false; // Return false
        }
    }
    return true; // If all characters are digits, return true
}

// Function to tokenize the input string and count different types of tokens
void tokenize(const string& input) {
    int tokenCount = 0, identifierCount = 0, keywordCount = 0, symbolCount = 0, operatorCount = 0, integerCount = 0;

    string token; // Temporary storage for tokens

    for (char c : input) { // Iterate through each character in the input string
        if (isspace(c)) { // If the character is a whitespace
            if (!token.empty()) { // If the token is not empty
                tokenCount++; // Increment token count
                if (isKeyword(token)) {
                    keywordCount++; // Increment keyword count if the token is a keyword
                } else if (isIdentifier(token)) {
                    identifierCount++; // Increment identifier count if the token is an identifier
                } else if (isInteger(token)) {
                    integerCount++; // Increment integer count if the token is an integer
                }
                token.clear(); // Clear the token for the next one
            }
        } else if (isOperator(c)) { // If the character is an operator
            symbolCount++; // Increment symbol count
            if (c == '+' || c == '-') {
                operatorCount++; // Increment operator count if the character is '+' or '-'
            }
        } else { // If the character is neither whitespace nor operator
            token += c; // Append the character to the token
        }
    }

    cout << "Token: " << tokenCount + 1 << endl; // Print token count
    cout << "Identifier: " << identifierCount << endl; // Print identifier count
    cout << "Keyword: " << keywordCount << endl; // Print keyword count
    cout << "Symbol: " << symbolCount << endl; // Print symbol count
    cout << "Operator: " << operatorCount << endl; // Print operator count
    cout << "Integer: " << integerCount << endl; // Print integer count
}

// Main function
int main() {
    cout << "Enter input: ";
    string input;
    getline(cin, input); // Read input from the user
    tokenize(input); // Tokenize the input and count different types of tokens
    return 0;
}
