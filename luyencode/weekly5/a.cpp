using namespace std;
#include<bits/stdc++.h>

int n;

int main() {

	cin >> n;
	char c;
	cin >> c;
	for (int i=1; i<=n; ++i) {
		string s;
		cin >> s;
		bool ok = true;
		for (auto x : s) {
			if (x == c) ok = false;
		}
		if (ok == true) cout << s << "\n";
	}

 return 0;	
}