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
#define file "btree"

using namespace std;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<class T> bool maximize(T &a, T b) {if (a<b) return a=b,1; return 0;}
template<class T> bool minimize(T &a, T b) {if (a>b) return a=b,1; return 0;}

const int mod = 1e9 + 7;
const int mxn = 40040;

int n, ret;
vt<int> tree[mxn], tmp{-1, 1};
int a[mxn], f[mxn][2];

void dfs(int u, int p) {
    for(int v: tree[u]) if (v != p) {
        dfs(v, u);
        maximize(f[u][0], f[v][0]);
        maximize(f[u][1], f[v][1]);
    }

    for(int j: tmp)
        f[u][j == 1] = max(0, f[u][j == 1] + a[u] * j);
}

void change(vt<int> &t, int i) {
    if (i > t[0]) {
        t[1] = t[0];
        t[0] = i;
    } else if (i > t[1]) {
        t[1] = i;
    }
}

void calc(int u, int p, vt<int> up) {
    ret = max(ret, min(up[0], f[u][1]));
    ret = max(ret, min(up[1], f[u][0]));

    vt<vt<int>> top(2, vt<int>(2, 0));

    for(int v: tree[u]) if (v != p) {
        for(int j=0; j<=1; ++j) {
            change(top[j], f[v][j]);
        }
    }

    for(int v: tree[u]) if (v != p) {
        vt<int> nxt(2);

        for(int j: tmp) {
            int cand = (f[v][j == 1] == top[j == 1][0]) ? top[j == 1][1] : top[j == 1][0];
            nxt[j == 1] = max(up[j == 1], cand);
            nxt[j == 1] = max(0, nxt[j == 1] + a[u] * j);
        }

        calc(v, u, nxt);
    }
}

void uraqt() {
    cin >> n;

    for(int i=2; i<=n; ++i) {
        int x; cin >> x;
        tree[x].push_back(i);
        tree[i].push_back(x);

//        cout << x << ' ' << i << endl;
    }

    for(int i=1; i<=n; ++i) {
        char ch; cin >> ch;
        if (ch == '(') a[i] = +1;
        else           a[i] = -1;
    }

    dfs(1, 1);
//    for(int i=1; i<=n; ++i)
//        cout << f[i][1] << endl;

    calc(1, 1, {0, 0});

    cout << ret << endl;
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
