#include<bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>
#define F first
#define S second
#define ld long double
#define rep(i,a,n) for (ll i= (a) ; i < (n); ++i)
#define vi vector<ll>
#define all(v) (v).begin(),(v).end()
#define M_PI 3.14159265358979323846
const ll MOD = 1e9 + 7;

vector<int> used;
vector<vector<int>> g;

void dfs( int u ) {
	used[u] = 1;
	//cout<<u<<endl;
	for ( auto v : g[u]) {
		if ( !used[v] )
            dfs(v);
	}

}

void solve() {
	int n, m;
	cin >> n >> m;
	//cout << n << m << endl;
	g = vector<vector<int>>(n);

	for ( int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		--x, --y;

		g[x].pb(y);
		g[y].pb(x);

	}

	used = vector<int>(n,0);
	int res = 0;
	for ( int i = 0; i < n; i++) {
        //cout<<used[i]<<" ";
		if ( !used[i]) {
			res++;
			dfs(i);
		}
	}
	cout << res << endl;
}


int main() {

	int t = 1;

	//cin >> t;
	ll k = 1;
	while (t--) {
		//cout << "Case #" << k++ << ": ";
		solve();
	}
	return 0;
}
