#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

bool isIdentifier(string s) {
    return isalpha(s[0]);
}

bool isSymbol(string s) {
    return s.size() == 1 && ispunct(s[0]);
}

bool isOperator(string s) {
    return s == "=" || s == "+" || s == "-" || s == "*" || s == "/" ||
           s == "%" || s == "<" || s == ">" || s == "!" || s == "&" ||
           s == "|" || s == "^" || s == "~" || s == "?" || s == ":" || s == "<<";
}

bool isKeyword(string s) {
    static const set<string> keywords = {"break", "char", "continue", "do",
                                         "double", "else", "float", "for",
                                         "if", "int", "long", "return",
                                         "while", "cout", "cin", "endl"};
    return keywords.count(s);
}

void Tokenizer(const string& input, vector<string>& keywords, vector<string>& identifiers, vector<string>& symbols, vector<string>& operators) {
    istringstream iss(input);
    string token;
    set<string> seen;

    while (iss >> token) {
        if (seen.insert(token).second) {
            if (isKeyword(token))      keywords.push_back(token);
            else if (isIdentifier(token)) identifiers.push_back(token);
            else if (isSymbol(token))   symbols.push_back(token);
            else if (isOperator(token)) operators.push_back(token);
        }
    }
}

int main() {
    string input;
    cout << "Enter input in a single line with spaces between tokens: " << endl;
    cout << "Input: ";
    getline(cin, input);

    vector<string> keywords, identifiers, symbols, operators;
    Tokenizer(input, keywords, identifiers, symbols, operators);

    cout << "Keywords: ";
    for (const string& s : keywords) cout << s << " ";
    cout << endl;

    cout << "Identifiers: ";
    for (const string& s : identifiers) cout << s << " ";
    cout << endl;

    cout << "Symbols: ";
    for (const string& s : symbols) cout << s << " ";
    cout << endl;

    cout << "Operators: ";
    for (const string& s : operators) cout << s << " ";
    cout << endl;

    return 0;
}
