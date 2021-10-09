using namespace std;
#include<bits/stdc++.h>
 
void solve() {
	int n;
	string s;
	cin >> n;
	cin >> s;
	int cnt = 0;
	for (int i=0; i<n; ++i) if (s[i] == '?') cnt++;
	if (cnt == n) {
		string ans = "";
		bool ok = true;
		for (int i=0; i<n; ++i) {
			if (ok == true) {
				ans += "B";
				ok = false;
			}
			else {
				ans += "R";
				ok = true;
			}
		}
		cout << ans << "\n";
		return;
	}
	string ans = s;
	ans = "?"+ans;
	ans = ans+"?";
	for (int i=1; i<=n; ++i) {
		if (ans[i] == '?') {
			if (ans[i-1] == 'B') ans[i] = 'R';
			if (ans[i-1] == 'R') ans[i] = 'B';
		}
	}
	for (int i=n; i>=1; --i) {
		if (ans[i] == '?') {
			if (ans[i+1] == 'B') ans[i] = 'R';
			if (ans[i+1] == 'R') ans[i] = 'B';
		}
	}
	if (ans[1] == '?') {
		ans[1] == 'B';
		for (int i=2; i<=n; ++i) if (ans[i] == '?') {
    			if (ans[i - 1] == 'B') ans[i] = 'R';
    			if (ans[i - 1] == 'R') ans[i] = 'B';
    		}
	}
	for (int i=1; i<=n; ++i) cout << ans[i];
	//cout << ans;
	cout << "\n";
}
 
int main() {
 
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
 
 return 0;	
}