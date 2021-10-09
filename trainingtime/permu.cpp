using namespace std;
#include<bits/stdc++.h>

vector<string> v;

int main() {

	string s = "aabac";
	cin >> s;
	sort(s.begin(), s.end());
	//cout << s << "\n";
	v.push_back(s);
	while (next_permutation(s.begin(), s.end())) {
		//cout << s << "\n";
		v.push_back(s);
	}
	cout << v.size() << "\n";
	for (auto c : v) cout << c << "\n";

 return 0;	
}