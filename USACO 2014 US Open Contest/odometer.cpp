/* Trust The Process */

#include <bits/stdc++.h>

#define debug(x) cout << #x << ": " << x << endl
#define ll long long
#define fi first
#define se second
#define vt vector
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define len(x) (int)(x).size()
#define uni(a) ((a).erase(unique(all(a)),(a).end()))
#define mp make_pair
#define file "odometer"

using namespace std;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using db =  double;

template<class T> bool ckmax(T &a, T b) {if(a<b) return a=b,1; return 0;}
template<class T> bool ckmin(T &a, T b) {if(a>b) return a=b,1; return 0;}

void read() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  if (fopen(file".in", "r")) {
      freopen(file".in", "r", stdin);
      freopen(file".out", "w", stdout);
  }
}

ll L, R, F[20][2][2][39], s1, s2;
vt<int> num;

ll DP1(int tar, int i, bool und, bool pl, int k) {
	if (i == num.size()) {
		return pl && k >= 0;
	}

	ll &ret = F[i][und][pl][k + 19];
	if (ret != -1)
		return ret;
	ret = 0;
	
	for(int j=0; j<=9; ++j) if (und || (j <= num[i])) {
		if (j==0 && pl==0) {
			ret += DP1(tar, i+1, 1, 0, 0);
			continue;
		}

		bool nund = und | (j < num[i]);
		bool npl = pl | (j != 0);
		int nk = k;
		if (j != tar) --nk;
		else ++nk;

		ret += DP1(tar, i+1, nund, npl, nk);
	}

	return ret;
}

ll DP2(int tar1, int tar2, int i, bool und, bool pl, int k) {
	if (i == num.size()) {
		return pl && k == 0;
	}

	ll &ret = F[i][und][pl][k+19];
	if (ret != -1)
		return ret;
	ret = 0;
	
	if (!pl)
		ret += DP2(tar1, tar2, i+1, 1, 0, k);

	if (pl || tar1!=0) {
		if (und || tar1<=num[i])
			ret += DP2(tar1, tar2, i+1, und || (tar1 < num[i]), pl || (tar1!=0), k+1);
	}

	if (und || tar2<=num[i])
		ret += DP2(tar1, tar2, i+1, und || (tar2 < num[i]), pl || (tar2!=0), k-1);
	
	return ret;
}

ll solve(ll n) {
	num.clear();
	while (n != 0) {
		num.push_back(n % 10);
		n /= 10;
	}
	reverse(all(num));

	//for(int x: num) cout << x << ' ';
	//cout << endl;
	
	ll ret = 0;
	for(int i=0; i<=9; ++i) {
		memset(F, -1, sizeof(F));
		ret += DP1(i, 0, 0, 0, 0);
	}

	for(int i=0; i<=9; ++i)
		for(int j=i+1; j<=9; ++j) {
			memset(F, -1, sizeof(F));
			ret -= DP2(i, j, 0, 0, 0, 0);
		}

	return ret;
}

void mgl_diamond() {
	cin >> L >> R;
	cout << solve(R) - solve(L - 1) << endl;
}

int main() {
	read();
	int t = 1;
	// cin >> t;
	for(int i=1; i<=t; ++i)
		mgl_diamond();
}

