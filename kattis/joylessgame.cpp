using namespace std;
#include<bits/stdc++.h>


int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        if (s[0] != s[s.size()-1]) {
            cout << (s.size()%2 == 0? "Bash": "Chikapu") << "\n";
        }
        else {
            cout << (s.size()%2 == 1? "Bash": "Chikapu") << "\n";
        }
    }
}