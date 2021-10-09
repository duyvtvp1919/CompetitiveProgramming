using namespace std;
#include<bits/stdc++.h>

const long long maxN = 2e6+19;

struct data {
	long long val;
	long long pos;
};

long long Pow[maxN];

bool cmp(data a, data b) {
	return a.val < b.val;
}

int main() {

	for (long long i=0; i<=1000001; ++i) {
		Pow[i] = i*i*i;
	}

	data a[2000];
	long long T;
	cin >> T;
	for (long long i=1; i<=T; ++i) {
		cin >> a[i].val;
		a[i].pos = i;
	}
	sort(a+1, a+1+T, cmp);
	// for (long long i=1; i<=T; ++i) {
	// 	cout << a[i].val << " " << a[i].pos << "\n";
	// }
	long long curr = 0;
	bool ans[2000];
	memset(ans, false, sizeof(ans));
	long long x[2000];
	for (long long i=1; i<=T; ++i) {
		while (Pow[curr] < a[i].val && curr<=1000000) curr++;
		ans[a[i].pos] = (Pow[curr] == a[i].val ? true : false);
		x[a[i].pos] = a[i].val;
		//curr--;
	}
	for (long long i=1; i<=T; ++i) {
		//cout << a[i].val << " " << a[i].pos << " ";
		//cout << x[i] << " ";
		cout << (ans[i] == true? "YES\n": "NO\n");
	}

 return 0;	
}