using namespace std;
#include<bits/stdc++.h>
const long long oo = 1e18;

long long dp[15][120][3][3];

long long count_setbits(long long N) { 
	long long cnt=0;
	while(N>0) {
		cnt+=(N&1);
		N=N>>1;
	}
	return cnt;
}

void init() {
	memset(dp, -1, sizeof(dp));
}

long long calc(long long id, long long mask, long long ok, long long head, string s, long long k) {
    if(count_setbits(mask) > k) return oo;
    if(id == s.size()) {
        return 0;
    }
    if(dp[id][mask][ok][head] != -1) return dp[id][mask][ok][head];
    long long ret = oo;
    if (ok == true) {
    	for (int i=0; i<=9; ++i) {
        	long long val = calc(id + 1, (head || i != 0) ? (mask | (1ll << i)) : mask, ok | (i != (s[id] - '0')), head | (i != 0),s , k);
        	if(val != oo) {
            	long long tmp = 1;
           		for (int j=id+2; j<=s.size(); ++j) tmp = tmp * 10;
            	ret = tmp * i + val;
            	return ret;
        	}
    	}
    	return ret;
    }
    else {
    	for (int i= (s[id] - '0'); i<=9; ++i) {
	        long long val = calc(id + 1, (head || i != 0) ? (mask | (1ll << i)) : mask, ok | (i != (s[id] - '0')), head | (i != 0), s, k);
	        if(val != oo) {
	            long long tmp = 1;
	            for (int j=id+2; j<=s.size(); ++j) tmp = tmp * 10;
	            ret = tmp * i + val;
	            return ret;
        	}
    	}	
    	return ret;
    }
    
}

void solve() {
	long long n;
	long long k;
	cin >> n >> k;
	string s = to_string(n);
	while (s.size() < 11) s = "0"+s;
	init();
	cout << calc(0, 0, 0, 0, s, k) << '\n';

}

int main() {

	long long T;
	cin >> T;
	while (T--) {
		solve();
	}

 return 0;	
}