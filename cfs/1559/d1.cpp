using namespace std;
#include<bits/stdc++.h>

const int maxN = 2e3;

struct data {
	int x, y;
};

int n, m1, m2;
int dad[maxN][10], cnt[maxN][10];
vector<data> ans;

int get(int u, int k) {
    if (dad[u][k] == u) return u;
    return dad[u][k] = get(dad[u][k], k);
}

void join1(int u, int v) {
    int tempu = get(u, 1), tempv = get(v, 1);
    if (cnt[tempu][1] < cnt[tempv][1]) swap(tempu, tempv);
    dad[tempv][1] = tempu; cnt[tempu][1] += cnt[tempv][1];
}

void join2(int u, int v) {
    int tempu = get(u, 2), tempv = get(v, 2);
    if (cnt[tempu][2] < cnt[tempv][2]) swap(tempu, tempv);
    dad[tempv][2] = tempu; cnt[tempu][2] += cnt[tempv][2];
}

bool ok(int u, int v) {
    int tempu = get(u, 1), tempv = get(v, 1);
    if (tempu == tempv) return false;
    tempu = get(u, 2), tempv = get(v, 2);
    if (tempu == tempv) return false;
    join1(u, v); join2(u, v);
    return true;
}

void init() {
	for (int i=1; i<=maxN-10; ++i) dad[i][2] = dad[i][1] = i, cnt[i][1] = cnt[i][2] = 1;
}

void solve() {
	cin >> n >> m1 >> m2;
	init();
	for (int i=1; i<=m1; ++i) {
		int u, v;
		cin >> u >> v;
		join1(u, v);
	}
	for (int i=1; i<=m2; ++i) {
		int u, v;
		cin >> u >> v;
		join2(u, v);
	}
	for (int i=1; i<=n; ++i) {
		for (int j=i+1; j<=n; ++j) {
			if (ok(i, j)) {
				data temp;
				temp.x = i;
				temp.y = j;
				ans.push_back(temp);
			}
		}
	}
	cout << ans.size() << "\n";
	for (auto c : ans) {
		cout << c.x << " " << c.y << "\n";
	}
}

int main() {

	solve();

 return 0;	
}