using namespace std;
#include<bits/stdc++.h>

const long long mod = 1e9+7;
const int maxN = 2e5+19;

long long P(long long a, long long n) {
	long long result = 1;
	while (n > 0) {
		if (n % 2 == 1)
			result = (result*a)%mod;
		a = (a*a)%mod;
		n /= 2;
	}
	return result%mod;
}

long long n, k;
long long Pow[maxN], Frac[maxN];

void prep() {
	Frac[0] = 1;
	for (int i=1; i<=maxN-10; ++i) Frac[i] = (Frac[i-1]*i)%mod;
	Pow[0] = 1;	
	for (int i=1; i<=maxN-10; ++i) Pow[i] = (Pow[i-1]*2)%mod;
}

long long Calc(long long k, long long n) {
	long long temp = (Frac[k] * Frac[n - k]) % mod;
	temp = ((P(temp, mod - 2)%mod)*Frac[n])%mod;
	return temp;
}

void solve() {
	cin >> n >> k;
	long long temp = 0;
	for (int i=0; i<n; i+=2) temp = (temp+Calc(i,n))%mod;
	long long ans = 0;
	if (n%2 == 0) {
		for (int i=1; i<=k; ++i) ans = (ans + P(temp, i-1) * P(Pow[k-i], n)%mod)%mod;
        ans = (ans + P(temp, k)) % mod;
	}
	else {
		for (int i=0; i<=k; ++i) ans = (ans + Calc(i, k) * P(temp, k - i)%mod)%mod;
	}
	cout << ans << "\n";
}

int main() {

	int T;
	cin >> T;

	prep();

	while (T--) {
		solve();
	}

 return 0;	
}