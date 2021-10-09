using namespace std;
#include<bits/stdc++.h>

const int maxN = 5e4+19;

void solve() {
	int a[maxN][10];
	int n;
	cin >> n;
	for (int i=0; i<=n+1; ++i) {
		for (int j=0; j<=6; ++j) a[i][j] = -1;
	}
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=5; ++j) cin >> a[i][j];
	}
	int p[10];
	int cnt = 0;
	int ans = 1;
	for (int j=1; j<=5; ++j) p[j] = a[1][j];
	for(int i = 2;i <= n;i++){
        cnt = 0;
        for(int j = 1;j <= 5;j++){
            if(a[i][j] < a[i - 1][j])
                cnt++;
            if(cnt == 3) {
                ans = i;
                for(int z = 1; z <= 5;z++)
                    p[z] = a[i][z];
            }
        }
    }
    bool ch = false;
    for(int i=1; i<=n; i++){
            cnt = 0;
            for(int j=1; j<=5; j++) {
                if(p[j] <= a[i][j]) cnt++;
            }
            if(cnt < 3) {
                ch = true;
            }
        }
    if(ch == 1) cout << -1;
        else cout << ans;
    cout << "\n";
}

int main() {

	int T;
	cin >> T;
	while (T--) {
		solve();
	}

 return 0;	
}