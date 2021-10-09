using namespace std;
#include<bits/stdc++.h>

const int maxN = 3e5+19;
long long a[maxN];

void solve() {
	int n;
	//long long a[maxN];
	cin >> n;
	for (int i=1; i<=n; ++i) cin >> a[i];
	long long Max = a[1];
	long long sum = 0;
	for (int i=1; i<=n; ++i) Max = max(a[i], Max), sum += a[i];
	cout << setprecision(9) << (long double)Max+((long double)sum-(long double)Max)/(long double)(n-1) << "\n";
}

int main() {

	int T;
	cin >> T;
	while (T--) {
		solve();
	}

 return 0;	
}