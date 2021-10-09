#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
string p2[100];
int lcs(string s,int pos){
	int t1=0,t2=0;
	int len_s=s.size();
	int len_2=p2[pos].size();
	while(t1<len_s&&t2<len_2){
		if(s[t1]==p2[pos][t2]) {t1++,t2++;}
		else t1++;
	}
	return t2;
}
void solve(){
	int n;
	cin>>n;
	string s=to_string(n);
	int res=1000;
	for(int i=0;i<=60;i++){
		int add=p2[i].size()-lcs(s,i);
		int cp=s.size()-p2[i].size()+2*add;
//		cout<<"i:"<<i<<' '<<lcs(s,i)<<' '<<cp<<'\n';
		res=min(res,cp);
	}
	cout<<res<<'\n';
}
int32_t main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i=0;i<=60;i++){
		int tmp=1ll<<i;
		p2[i]=to_string(tmp);
//		cout<<p2[i]<<'\n';
	}
    int ntest;
    cin>>ntest;
    while(ntest--) solve();
//	cout<<lcs("1052",10);
 
}