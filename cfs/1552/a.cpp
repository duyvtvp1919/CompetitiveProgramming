using namespace std;
#include<bits/stdc++.h>



int main() {

	int T;
	cin >> T;
	while (T--) {
		string s;
		int n;
		cin >> n;
		cin >> s;
		string s1 = s;
		sort(s1.begin(), s1.end());
		int ans = 0;
		for (int i=0; i<s.length(); ++i) {
			if (s[i] != s1[i]) ans++;
		}
		cout << ans << "\n";
	}

 return 0;	
}