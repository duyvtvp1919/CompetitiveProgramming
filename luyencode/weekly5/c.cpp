using namespace std;
#include<bits/stdc++.h>

long long m, n;

long long sol(long long n, long long m) {
	if (m % n == 0) return 0;
	else if (n >= m) return sol(n - m*ceil(n/m), m);
	else return (n*ceil(m/n) + sol(n, m - n*ceil(m/n)));
}

int main() {

	cin >> n >> m;
	cout << sol(n, m);

 return 0;	
}