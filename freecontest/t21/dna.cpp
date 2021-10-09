//nnd
using namespace std;
#include<bits/stdc++.h>

string s;
int n;

int main() {

	cin >> s;
	cin >> n;
	vector<int> ans;
	for (int i=1; i<=n; ++i) {
		int cnt = 0;
		string s1;
		cin >> s1;
		if (s1.size() != s.size()) continue;
		for (int j=0; j<s.size(); ++j) {
			if (s[j] != s1[j]) cnt++;
		}
		if (cnt <= 2) ans.push_back(i);
	}
	for (auto c : ans) cout << c << " ";

 return 0;    
}