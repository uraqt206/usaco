#include <bits/stdc++.h>

#define conqueror_of_uraqt int main()
#define xuong cout << "\n"
#define debug(x) cout << #x << ": " << x << "\n"
#define go(i,l,r) for(int i=(l); i<=(r); ++i)
#define rev(i,l,r) for(int i=(r); i>=(l); --i)
#define fi first
#define se second
#define vec vectoriIi bq
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define uni(a) ((a).erase(unique(all(a)),(a).end()))
#define C make_pair

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int mod = 1e9+7;
const int N1 = 1001, N2 = 100010;
const pii range[] = {{0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}, {1, 4}}; 
int id[256];
int n;
string s;

int mul(int a, int b) { return 1LL * a * b % mod; }
void add(int &a, int b) { if ((a += b) >= mod) a -= mod; }

// sub1
int cnt[N1][N1][5][5], dp1[N1][5];

void sub1() {
	for(int i=n; i>=1; --i) {
		go(c, range[s[i]].fi, range[s[i]].se)
			cnt[i][i][c][c] = 1;

		for(int j=i+1; j<=n; ++j)
			go(cl, range[s[i]].fi, range[s[i]].se)
				go(cr, range[s[j]].fi, range[s[j]].se) {
					int &val = cnt[i][j][cl][cr];
					if (i < j-1) {
						go(t1, 1, 4) if (t1 ^ cl)
							go(t2, 1, 4) if (t2 ^ cr)
								add(val, cnt[i+1][j-1][t1][t2]);
					} else val = cl != cr;
				}
	}

	for(int i=1; i<=n; ++i) {
		for(int j=i; j>=1; --j)
			go(ci, range[s[i]].fi, range[s[i]].se)
				go(cj, range[s[j]].fi, range[s[j]].se) if (cnt[j][i][cj][ci] > 0) {
					int &val = dp1[i][cj];
					int added;
					if (j == 1) added = cnt[j][i][cj][ci];
					else added = mul(dp1[j-1][ci], cnt[j][i][cj][ci]);
					add(val, added);
				}
	}

	int ans = 0;
	go(i, 1, 4) add(ans, dp1[n][i]);
	cout << ans;
}

int dp2[N2][5][5][5];

void sub2() {
	go(c, range[s[1]].fi, range[s[1]].se)
		dp2[1][c][c][0] = 1;

	for(int i=1; i<n; ++i)
		go(cl, 1, 4)
			go(cr, 1, 4)
				go(lst, 0, 4) if (dp2[i][cl][cr][lst] > 0) {
					int &val = dp2[i][cl][cr][lst];
					go(nxt, range[s[i+1]].fi, range[s[i+1]].se) {
						if (nxt != cr) 
							add(dp2[i+1][cl][nxt][lst], val);

						if (lst == 0 || cr == lst) 
							add(dp2[i+1][nxt][nxt][cl], val);
					}
				}

	int ans = 0;
	go(cl, 1, 4)
		go(cr, 1, 4)
			go(lst, 0, 4) if (cr == lst || lst == 0)
				add(ans, dp2[n][cl][cr][lst]);
	
	cout << ans;
}

void solve() {
	cin >> s;
	n = s.size();
	for(char &c: s) c = id[c];
	s = "@" + s;

	// sub1(); cout << "\n";
	// sub2();
	if (n <= 1000) sub1();
	else sub2();
}

conqueror_of_uraqt {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	id['A'] = 1; id['C'] = 2; id['G'] = 3; id['T'] = 4; id['?'] = 5;
	solve();
	return 0;
}