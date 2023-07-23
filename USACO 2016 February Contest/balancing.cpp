/* Trust The Process */
 
#include <bits/stdc++.h>
 
#define fr(i,be,en) for(int i = (be); i<=(en); ++i)
#define fd(i,be,en) for(int i = (be); i>=(en); --i)
#define each(x, a)   for(auto &x: a)
#define debug(x) cout << #x << ": " << x << endl
#define ull unsigned long long
#define ll long long
#define ld long double
#define fi first
#define se second
#define vt vector
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define len(x) (int)(x).size()
#define uni(a) ((a).erase(unique(all(a)),(a).end()))
#define reset(x,val) memset((x),(val),sizeof(x))
#define pii pair<int,int>
#define pll pair<ll, ll>
#define MP make_pair
#define file "balancing"
 
using namespace std;
 
template<class T> bool ckmax(T &a, T b) {if (a<b) return a=b,1; return 0;}
template<class T> bool ckmin(T &a, T b) {if (a>b) return a=b,1; return 0;}
 
const int mod = 998244353;
const int INF = 1e9+9;
 
int add(int a, int b) {
    a += b;
    if (a >= mod) a -= mod;
    return a;
}
 
int neg(int a, int b) {
	a -= b;
	if (a < 0) a += mod;
	return a;
}
 
int mul(int a, int b) {
    return (1LL * a * b) % mod;
}

int N, A[2001][2001], DP[2001][2001];
vt<int> cmp;

int get(int u, int v, int x, int y) {
	if (u>2000 || v>2000 || x>2000 || y>2000)
		return 0;
	return DP[x][y] - DP[x][v-1] - DP[u-1][y] + DP[u-1][v-1];
}

void solve() {
	cin >> N;

	vt<pii> cows;
	for(int i=0; i<N; ++i) {
		int x, y;
		cin >> x >> y;
		cows.push_back(MP(x, y));
		cmp.push_back(x);
		cmp.push_back(y);
	}

	sort(all(cmp));
	uni(cmp);

	for(int i=0; i<N; ++i) {
		cows[i].fi = (upper_bound(all(cmp), cows[i].fi) - cmp.begin());
		cows[i].se = (upper_bound(all(cmp), cows[i].se) - cmp.begin());
		A[cows[i].fi][cows[i].se]++;
	}

	for(int i=1; i<=2000; ++i) {
		for(int j=1; j<=2000; ++j) {
			DP[i][j] = A[i][j] + DP[i][j-1] + DP[i-1][j] - DP[i-1][j-1];
		}
	}

	int ret = 2e9;
	for(int i=1; i<=2000; ++i) {
		for(int j=1; j<=2000; ++j) {
			int a, b, c, d;

			a = get(1, 1, i, j);
			b = get(1, j+1, i, 2000);
			c = get(i+1, 1, 2000, j);
			d = get(i+1, j+1, 2000, 2000);

			ret = min(ret, max({a, b, c, d}));
		}
	}

	cout << ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    if (fopen(file".in", "r")) {
        freopen(file".in", "r", stdin);
        freopen(file".out", "w", stdout);
    }
 
    int t=1;
    // cin >> t;
    fr(tc, 1, t) {
        solve();
    }
}
 
 
