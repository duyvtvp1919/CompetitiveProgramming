using namespace std;
#include<bits/stdc++.h>

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef vector<vector<int>> vvi;
typedef vector<vector<int>> vi;
typedef pair<pair<int,int>, int> ppiii;
typedef pair<int, pair<int,int>> pipii;
typedef pair<int,char> pic;
typedef pair<char,int> pci;
typedef pair<string,string> pss;
 
 
int cnt(string& a, char x) {
    int res = 0;
    for (auto it : a) {
        if (it == x) res++;
    }
    return res;
}
int solve(vector<string>& in, char i) {
    vector<pair<int,string>> nn;
    for (auto& it : in) {
        int cc = cnt(it, i);
        cc = cc - (it.size() - cc);
        nn.push_back({cc, it});
    }
    sort(nn.rbegin(), nn.rend());
    int res = 0;
    int tot = 0, wants = 0;
    for (auto& it : nn) {
        int has = cnt(it.second, i);
        int left = it.second.size() - has;
        wants += has;
        tot += left;
        if (wants <= tot) break;
        res++;
    }
    return res;
}
void solve() {
    int n;
    cin >> n;
    vector<string> in(n);
    for (auto& it : in) cin >> it;
    string all = "abcde";
    int res = 0;
    for (char i : all) {
        res = max(res, solve(in, i));
    }
    cout << res << endl;
 
}
 
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while(t--) {
      solve();
  }
}