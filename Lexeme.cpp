#include <iostream>
#include <string>
#include <cctype>

using namespace std;

enum State { 
    q,
    q1
};
bool valid(string lexeme) {
    
    State currentState = q;

   
    for (char ch : lexeme) {
        switch (currentState) {
            case q:
                if (isalpha(ch) || ch == '_') {
                    currentState = q1;
                } else {
                    return false; 
                }
                break;

            case q1:
                
                if (isalnum(ch) || ch == '_') {
                    
                } else {
                    return false;  
                }
                break;
        }
    }
    return currentState == q1;
}

int main() {
   
    string i;

    cout << "Enter lexeme: ";
    cin >> i;

    if (valid(i)) {
        cout << "Valid identifier!" << endl;
    } else {
        cout << "Not valid identifier." << endl;
    }

    return 0;
}
