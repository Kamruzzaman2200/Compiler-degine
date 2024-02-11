#include<bits/stdc++.h>
using namespace std;


int isvalidstring( string input) {

            int currentstate = 0;

    for (char c : input) {
        switch (currentstate) {
            case 0:
                if (isdigit(c))
                    currentstate = 1;
                else if(c=='.')currentstate=2;
                else
                    return 0;
                break;
            case 1:
                if (isdigit(c))
                    currentstate = 1;
                else if (c == '.')
                    currentstate = 2;
                 else if(c=='e')
                 currentstate=4;
                else
                    return 0;
                break;
            case 2:
                if (isdigit(c))
                    currentstate = 3;
                else
                    return 0;
                break;
            case 3:
                if (isdigit(c))
                    currentstate = 3;
                else if (c == 'e')
                    currentstate = 4;
                else
                    return 0;
                break;
            case 4:
                if (c == '^')
                    currentstate = 5;
                else
                    return 0;
                break;
            case 5:
                if (isdigit(c))
                    currentstate = 6;
                else if(c=='.') currentstate = 7;
                else
                    return 0;
                break;
            case 6:
                if (isdigit(c))
                   currentstate = 6;
                  else if(c=='.') currentstate = 7;
                else return 0;
                break;
                case 7:
                if (isdigit(c))
                   currentstate = 8;
                 else
               return 0;
                break;
            case 8:
                if (isdigit(c))
                   currentstate = 8;
                   else
               return 0;
                break;
        }
    }
     if(currentstate == 6 || currentstate == 8)
    return 1;
}

int main() {


    string input;

    cout << "Enter a string: ";
    cin >> input;

    if ( isvalidstring(input)==1)
        cout << "Valid string.\n";
    else
        cout << "Invalid string.\n";

    return 0;
}

