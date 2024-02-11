#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <map> // Include map to store token counts

using namespace std;

bool isIdentifier(const string& s) {
    return isalpha(s[0]);
}

bool isSymbol(const string& s) {
    return s.size() == 1 && ispunct(s[0]);
}

bool isOperator(const string& s) {
    static const string operators[] = {"=", "+", "-", "*", "/", "%", "<", ">", "!", "&", "|", "^", "~", "?", ":", "<<", ">>"};
    for (const string& op : operators) {
        if (s == op) return true;
    }
    return false;
}

bool isKeyword(const string& s) {
    static const set<string> keywords = {"break", "char", "continue", "do",
                                         "double", "else", "float", "for",
                                         "if", "int", "long", "return",
                                         "while", "cout", "cin", "endl"};
    return keywords.count(s);
}

void Tokenizer(const string& input, vector<string>& keywords, vector<string>& identifiers, vector<string>& symbols, vector<string>& operators, map<string, int>& tokenCounts) {
    istringstream iss(input);
    string token;

    while (iss >> token) {
        if (tokenCounts.find(token) == tokenCounts.end()) { // If token is encountered for the first time, initialize its count to 1
            tokenCounts[token] = 1;
        } else { // If token has been encountered before, increment its count
            tokenCounts[token]++;
        }

        if (isKeyword(token))      keywords.push_back(token);
        else if (isIdentifier(token)) identifiers.push_back(token);
        else if (isSymbol(token))   symbols.push_back(token);
        else if (isOperator(token)) operators.push_back(token);
    }
}

int main() {
    string input;
    cout << "Enter input in a single line with spaces between tokens: " << endl;
    cout << "Input: ";
    getline(cin, input);

    vector<string> keywords, identifiers, symbols, operators;
    map<string, int> tokenCounts;

    Tokenizer(input, keywords, identifiers, symbols, operators, tokenCounts);

    cout << "Token counts:" << endl;
    int totalTokens = 0;
    for (const auto& pair : tokenCounts) {
        cout << pair.first << ": " << pair.second << endl;
        totalTokens += pair.second;
    }
    cout << "Total tokens: " << totalTokens << endl;

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
