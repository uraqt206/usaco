#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define vec vector
#define foru(i, l, r) for(int i=l; i<=r; ++i)
#define revu(i, r, l) for(int i=r; i>=l; --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()

struct incident {
		ll x, y, t;
		incident(ll _x=0, ll _y=0, ll _t=0) : x(_x), y(_y), t(_t) {}

		bool operator < (const incident &a) {
				return t < a.t;
		}
};

bool can(incident a, incident b) {
		return (a.x-b.x) * (a.x-b.x) + (a.y-b.y) * (a.y-b.y) <= (b.t-a.t)*(b.t-a.t);
}

int n, g;
vector<incident> cows;

void solve() {
		cin >> g >> n;

		for(int i=0; i<g; ++i) {
				int x, y, t;
				cin >> x >> y >> t;
				cows.emplace_back(x, y, t);
		}

		sort(all(cows));
		
		int ans=0;
		for(int i=0; i<n; ++i) {
				int x, y, t;
				cin >> x >> y >> t;
				incident cur = incident(x, y, t);
				
				int lb=0, rb=g, mb;
				while (lb<rb) {
						mb = (lb+rb)>>1;
						if (cows[mb].t>=t)
								rb=mb;
						else 
								lb=mb+1;
				}

				if (lb==0 && can(cur, cows[0])) ++ans;
				else if (lb==g && can(cows[g-1], cur)) ++ans;
				else if (lb>0 && lb<g && can(cows[lb-1], cur) && can(cur, cows[lb])) ++ans;
		}

		cout << n-ans;
}

int main() {
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);


		//freopen(".in", "r", stdin);
		//freopen(".out", "w", stdout);

		solve();
		return 0;
}
