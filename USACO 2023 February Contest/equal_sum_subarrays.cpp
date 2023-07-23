#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define fi first
#define se second
#define ins push_back
#define vec vector
#define foru(i, l, r) for(int i=(l); i<=(r); ++i)
#define ford(i, l, r) for(int i=(l); i>=(r); --i)
#define fore(i, v) for(auto &i : v)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()

const ll lim = 1e18;
const int nx = 505;
int n;
ll a[nx];

void solve() {
	cin >> n;	

	vec<pair<ll, pii>> sum;
	foru(i, 1, n) {
		cin >> a[i];
		ll total = 0;
		ford(j, i, 1) {
			total += a[j];
			sum.ins({total, {j, i}});
		} 
	}

	sort(all(sum));
	for(int i=1; i<=n; ++i) {
		vec<ll> A, B;

		fore(range, sum) 
			if (range.se.fi <= i && range.se.se >= i)
				A.ins(range.fi);
			else
				B.ins(range.fi);

		ll ans = lim;
		int j=0, k=0;
		for(int i=0; i<sz(A); ++i) {
			while (j < sz(B)-1 && B[j+1] <= A[i])
				++j;
			while (k < sz(B) && B[k] < A[i]) 
				++k;
			
			if (B[j] <= A[i]) ans = min(ans, A[i] - B[j]);
			if (k < sz(B)) ans = min(ans, B[k] - A[i]);
		}

		cout << ans << "\n";
	}
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();
}
