using namespace std;
#include<bits/stdc++.h>

const int maxN = 1e6+19;
long long n;
string s;
long long a[maxN];
long long l[maxN], r[maxN];

int main() {

	long long T;
	cin >> T;
	while (T--) {
		cin >> n;
		cin >> s;
		long long cnt = 0;
		for (long long i=1; i<=n; ++i) {
			if (s[i-1] == '*') {
				cnt++;
				a[cnt] = i-cnt+1;
			}
		}
		l[0] = 0;
		r[cnt+1] = 0;
		long long pos = 1;
		long long res = 1e18+1;
		for (long long i=1; i<=cnt; ++i) l[i] = l[i-1] + a[i];
		for (long long i=cnt; i>=0; --i) r[i] = r[i+1] + a[i];
		for (long long i=1; i<=n-cnt+1; ++i) {
			while (a[pos] <= i && pos <= cnt) pos++; 
			pos--;
            res = min(res, (pos*i-l[pos])+(r[pos+1]-i*(cnt-pos)));
		}
		cout << res << "\n";
	}

 return 0;	
}