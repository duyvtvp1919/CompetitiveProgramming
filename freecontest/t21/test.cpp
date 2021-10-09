//nnd
using namespace std;
#include<bits/stdc++.h>


const int maxN = 1e4+19;
const long long oo = 1e18;
#define ii pair<long long, long long>

long long n, m, a;
vector<ii> V[maxN];
long long p[10];

priority_queue<ii,vector<ii>,greater<ii> > H;
long long d[10][maxN];

bool fre[maxN];
long long res,curres[10],cura;
bool chosen[10];

void dijkstra(long long x) {
	while (!H.empty()) H.pop();
	for (long long i=1; i<=n; i++)
		d[x][i] = oo;
	d[x][p[x]] = 0;
	H.push(ii(0, p[x]));
	memset(fre, true, sizeof(fre));
	do {
		long long u = H.top().second;
		H.pop();
		if (!fre[u]) continue;
		fre[u] = false;
		for (auto it=V[u].begin(); it!=V[u].end(); it++) {
			long long v = (*it).first;
			long long l = (*it).second;
			if (d[x][v] > d[x][u]+l) {
				d[x][v] = d[x][u]+l;
				H.push(ii(d[x][v], v));
			}
		}
	}
	while (!H.empty());
}

void quay(long long x, int t) {
	for (long long i=1; i<=t; i++) {
		if (!chosen[i] and cura>=d[curres[x-1]][p[i]]) {
			chosen[i] = true;
			curres[x] = i;
			cura -= d[curres[x-1]][p[i]];
			if (x > res) {
				if (cura >= d[curres[x]][1]) {
					res = x;
				}
			}
			if (x < t)
				quay(x+1, t);
			chosen[i] = false;
			cura += d[curres[x-1]][p[i]];
		}
	}
}

void solve() {
	cin >> n >> m;
	for (long long i=1; i<=n; i++)
		V[i].clear();
	for (long long i=1; i<=m; i++) {
		long long x,y,l;
		cin >> x >> y >> l;
		x++;
		y++;
		V[x].push_back(ii(y,l));
		V[y].push_back(ii(x,l));
	}
	int t;
	cin >> t;
	p[0] = 1;
	for (long long i=1; i<=t; i++) {
		cin >> p[i];
		p[i]++;
	}
	cin >> a;
	for (long long i=0; i<=t; i++)
		dijkstra(i);
	memset(chosen, false, sizeof(chosen));
	res = 0;
	curres[0] = 0;
	cura = a;
	quay(1, t);
	cout << res << '\n';
}

int main() {
	int tc;
	cin >> tc;
	while (tc--)
		solve();
	return 0;
}