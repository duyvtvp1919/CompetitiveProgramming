using namespace std;
#include<bits/stdc++.h>

int n;
string s;

int main() {

	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		cin >> s;
		//cout << s.size() << "\n";
		bool ok = true;
		for (char c='A'; c <= 'Z'; ++c) {
			int pos = -1;
			//cout << "--------------" << c << "\n";
			for (int i=0; i<s.size(); ++i) {
				if (s[i] == c) {
					if (pos == -1) pos = i;
					else {
						if (i - pos > 1) ok = false;
						pos = i;
					}
				}
			}
		}
		cout << (ok == true? "Yes": "No") << "\n";
	}

 return 0;	
}