using namespace std;
#include<bits/stdc++.h>

const int maxN = 2e5+19;

int n;
long long a[maxN];

int main() {

	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i=1; i<=n; ++i) cin >> a[i];
		map<long long, long long> m;
		long long res = 0;
		for (int i=1; i<=n; ++i) {
			res += m[a[i]-i];
			m[a[i]-i]++;
		}
		cout << res << "\n";
	}

 return 0;	
}