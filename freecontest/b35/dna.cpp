//nnd
using namespace std;
#include<bits/stdc++.h>

string s;

int main() {

	cin >> s;
	reverse(s.begin(), s.end());
	for (auto c : s) {
		if (c == 'T') cout << "A";
		else if (c == 'A') cout << "T";
		else if (c == 'C') cout << "G";
		else if (c == 'G') cout << "C";
	}

 return 0;    
}