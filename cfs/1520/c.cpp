using namespace std;
#include<bits/stdc++.h>

int n;

int main() {

	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		if (n == 2) {
			cout << -1 << "\n";
			continue;
		}
		vector<int> a;
		for (int i=1; i<=n*n; i+=2) a.push_back(i);
		for (int i=2; i<=n*n; i+=2) a.push_back(i);
		int cnt = 0;
		for (auto c : a) {
			cnt++;
			cout << c << " ";
			if (cnt%n == 0) cout << "\n";
		}
	}

 return 0;	
}