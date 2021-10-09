using namespace std;
#include<bits/stdc++.h>

string s;
int a[30];

int main() {

    cin >> s;
    for (int i=0; i<s.size(); ++i) {
        a[s[i]-'A']++;
    }
    //s[i] = 'A'
    //=> a[0]++;
    //s[i] = 'B'
    //=> a[1]++

    for (char i='A'; i<='Z'; ++i) {
        cout << i << " " << a[i-'A'] << "\n"; 
    }

 return 0;    
}