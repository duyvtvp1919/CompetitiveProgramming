using namespace std;
#include<bits/stdc++.h>

void solve() {
	string s;
	cin >> s;
	int cnt[30];
	memset(cnt, 0, sizeof(cnt));
	for (auto c : s) {
		cnt[c-'a']++;
	}
	int one = 0, two = 0;
	for (char c='a'; c<='z'; ++c) {
		if (cnt[c-'a'] == 1) one ++;
		else if (cnt[c-'a'] > 1) two ++;
	}
	cout << (one/2)+two << "\n";
}

int main() {

	int T;
	cin >> T;
	while (T--) {
		solve();
	}

 return 0;	
}