/* conqueror_of_uraqt */
#include <bits/stdc++.h>

#define conqueror_of_uraqt int main()
#define xuong cout << "\n"
#define debug(x) cout << #x << ": " << x << endl
#define go(i,l,r) for(int i=(l); i<=(r); ++i)
#define x first
#define y second
#define C make_pair
#define vec vector
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define uni(a) ((a).erase(unique(all(a)),(a).end()))
#define file "dishes"

template<class T> bool ckmax(T &a, const T b) {if (a<b) return a=b,1; return 0;}
template<class T> bool ckmin(T &a, const T b) {if (a>b) return a=b,1; return 0;}

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int B = 256, M[2] = {(int)1e9+5277, (int)1e9+9277};
const int mod = 1e9+7;
const int mxN = 1e5+5;

int n, dish[mxN];

bool f(int pre) {
	vec<int> have;
	go(i, 1, pre) have.push_back(dish[i]);
	sort(all(have));
	deque<vec<int>> st;
	int j=0;
	go(i, 1, pre) {
		int lb = 0, rb = sz(st), mb;
		while (lb < rb) {
			mb = (lb + rb) >> 1;
			if (st[mb].back() > dish[i]) rb = mb;
			else lb = mb+1;
		}
		// cout << lb << "\n";
		if (lb == st.size()) st.push_back({dish[i]});
		else st[lb].push_back(dish[i]);
		// clear 
		while (!st.empty() && st.front().back() == have[j]) {
			st.front().pop_back();
			if (st.front().empty()) st.pop_front();
			++j;
		}
	}
	return j == have.size();
}

void URAQT() {
	cin >> n;
	go(i, 1, n) {
		cin >> dish[i];
	}
	int lb = -1, rb = n, mb;
	while (lb < rb) {
		mb = (lb + rb + 1) >> 1;
		if (f(mb)) lb = mb;
		else rb = mb-1;
	}
	cout << lb;
}

conqueror_of_uraqt {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	if (fopen(file".in", "r")) {
		freopen(file".in", "r", stdin);
		freopen(file".out", "w", stdout);
	}
	URAQT();
	return 0;
}