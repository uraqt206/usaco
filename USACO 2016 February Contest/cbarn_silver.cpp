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
#define file "cbarn"
 
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

int N, A[100100];
ll ret = 1e18;

int get(int i, set<int> &s) {
	auto it = s.lower_bound(i);
	if (it != s.end()) {
		int nxt = *it;
		s.erase(it);
		return nxt - i;
	} else {
		int nxt = *s.begin();
		s.erase(s.begin());
		return nxt + N - i;
	}
}

ll go(int x) {
	ll d = 0;
	set<int> s;

	for(int i=1; i<=N; ++i)
		s.insert(i);

	for(int i=x; i<=N; ++i) {
		for(int j=1; j<=A[i]; ++j) {
			ll dist = get(i, s);
			d += dist * dist;
			// cout << nxt << endl;
		}
	}

	for(int i=1; i<x; ++i) {
		for(int j=1; j<=A[i]; ++j) {
			ll dist = get(i, s);
			d += dist * dist;
			// cout << nxt << endl;
		}
	}

	return d;
}

void solve() {
	cin >> N;

	int pos = -1;
	for(int i=1; i<=N; ++i) {
		cin >> A[i];
	}

	// go(1);
	for(int i=1; i<=N; ++i) if (A[i])
		if (ckmin(ret, go(i))) pos = i;
	cout << pos << "\n";

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
 
 
