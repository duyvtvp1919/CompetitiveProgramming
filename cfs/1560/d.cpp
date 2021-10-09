using namespace std;
#include<bits/stdc++.h>

const long long inf = 1e18;

string p2[100];

int lcs(string s,int pos){
	int t1=0,t2=0;
	int len_s=s.size();
	int len_2=p2[pos].size();
	while(t1<len_s && t2<len_2){
		if(s[t1] ==p2[pos][t2]) {t1++,t2++;}
		else t1++;
	}
	return t2;
}

void solve() {
	long long n;
	cin >> n;
	string s = to_string(n);
	long long res = inf;
	for(int i=0; i<=60; i++){
		long long cp = s.size()-p2[i].size()+2*(p2[i].size()-lcs(s,i));
		res = min(res, cp);
	}
	cout<<res<<'\n';
}

int main() {

for(int i=0;i<=60;i++){
		int tmp=1ll<<i;
		p2[i]=to_string(tmp);
//		cout<<p2[i]<<'\n';
	}
	int T;
	cin >> T;
	while (T--) {
		solve();
	}

 return 0;	
}