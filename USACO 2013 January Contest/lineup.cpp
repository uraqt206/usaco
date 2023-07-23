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
#define C make_pair
#define file "lineup"

using namespace std;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<class T> bool maximize(T &a, T b) {if (a<b) return a=b,1; return 0;}
template<class T> bool minimize(T &a, T b) {if (a>b) return a=b,1; return 0;}

const int mod = 1e9 + 7;
const int mxn = 2e5 + 5;

int n, k, a[mxn], ret;
int cnt[mxn];

void uraqt() {
    int ret = 0;
    cin >> n >> k;

    map<int, int> mp;
    for(int i=1; i<=n; ++i) {
        cin >> a[i];
        mp[a[i]];
    }

    int cord=0;
    for(auto &x: mp) x.se = ++cord;
    for(int i=1; i<=n; ++i) a[i] = mp[a[i]];

    for(int i=1, j=1, num=0; i<=n; ++i) {
        if (++cnt[a[i]] == 1) ++num;
        while (num > k+1)
            if (--cnt[a[j++]] == 0)
                --num;
        ret = max(ret, cnt[a[i]]);
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
//    cin >> t;
    for(int i=1; i<=t; ++i)
        uraqt();
}
