#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define ll long long
#define heap priority_queue
#define ii pair<ll,ll>
#define X first
#define Y second
using namespace std;
const ll maxn = 10000;
const ll maxt = 8;
const ll oo = (ll) 4e18;
ll n,m,t,a;
vector<ii> V[maxn+1];
ll p[maxt+1];

heap<ii,vector<ii>,greater<ii> > H;
ll d[maxt+1][maxn+1];

bool fre[maxn+1];
ll res,curres[maxt+1],cura;
bool chosen[maxt+1];

void dijkstra(ll x)
{
	while (!H.empty()) H.pop();
	for (ll i=1; i<=n; i++)
		d[x][i]=oo;
	d[x][p[x]]=0;
	H.push(ii(0,p[x]));
	memset(fre,true,sizeof(fre));
	do
	{
		ll u=H.top().Y;
		H.pop();
		if (!fre[u]) continue;
		//cout << u << '\n';
		fre[u]=false;
		//H.pop();
		for (auto it=V[u].begin(); it!=V[u].end(); it++)
		{
			ll v=(*it).X;
			ll l=(*it).Y;
			if (d[x][v]>d[x][u]+l)
			{
				d[x][v]=d[x][u]+l;
				H.push(ii(d[x][v],v));
			}
		}
	}
	while (!H.empty());
}

void quay(ll x)
{
	for (ll i=1; i<=t; i++)
		if (!chosen[i] and cura>=d[curres[x-1]][p[i]])
		{
			chosen[i]=true;
			curres[x]=i;
			cura-=d[curres[x-1]][p[i]];
			//cout << curres[x-1] << ' ' << p[i] << ' ' << d[curres[x-1]][p[i]] << '\n';

			if (x>res)
			{
				if (cura>=d[curres[x]][1]) 
				{
					res=x;
					//for (ll i=1; i<=x; i++)
						//cout << p[curres[i]] << ' ';
					//cout << ' ' << a << ' ' << cura << ' ' << cura-d[curres[x]][1] << '\n';
				}
			}

			if (x<t)
				quay(x+1);
			
			chosen[i]=false;
			cura+=d[curres[x-1]][p[i]];
		}
}

void solve()
{
	cin >> n >> m;

	for (ll i=1; i<=n; i++)
		V[i].clear();
	
	for (ll i=1; i<=m; i++)
	{
		ll x,y,l;
		cin >> x >> y >> l;
		x++;
		y++;
		V[x].push_back(ii(y,l));
		V[y].push_back(ii(x,l));
	}

	cin >> t;
	p[0]=1;
	for (ll i=1; i<=t; i++)
	{
		cin >> p[i];
		p[i]++;
	}

	cin >> a;

	//dijkstra(0);
	//dijkstra(1);
	for (ll i=0; i<=t; i++)
		dijkstra(i);

	/*for (ll i=0; i<=t; i++)
	{
		for (ll j=1; j<=n; j++)
			cout << d[i][j] << ' ';
		cout << '\n';
	}*/

	memset(chosen,false,sizeof(chosen));
	res=0;
	curres[0]=0;
	cura=a;
	quay(1);

	cout << res << '\n';
}
main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ll t;
	cin >> t;
	for (ll i=1; i<=t; i++)
		solve();
	return 0;
}