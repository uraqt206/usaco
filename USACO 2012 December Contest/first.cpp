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
#define file "first"
#define tail "in"

using namespace std;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<class T> bool maximize(T &a, T b) {if (a<b) return a=b,1; return 0;}
template<class T> bool minimize(T &a, T b) {if (a>b) return a=b,1; return 0;}

const int mod = 1e9 + 7;
const int mxn = 1e6 + 5;

struct node {
    int child[26];
    int cnt;
    node() {
        memset(child, -1, sizeof(child));
        cnt = 0;
    }
};

vt<node> trie;
int n, used[26];
bool edge[26][26];
string s[40001];

bool dfs(int u) {
    used[u] = 1;
    for(int v=0; v<26; ++v) if (edge[u][v]) {
        if (used[v] == 2) continue;
        if (used[v] == 1) return 1;
        if (used[v] == 0) if (dfs(v)) return 1;
    }
    used[u] = 2;
    return 0;
}

bool check() {
    memset(used, 0, sizeof(used));
    for(int i=0; i<26; ++i) if (used[i] == 0)
        if (dfs(i)) return 1;
    return 0;
}

void add(string s) {
    int cur = 0;
    for(int i=0; i<s.size(); ++i) {
        int ch = s[i] - 'a';
        if (trie[cur].child[ch] == -1) {
            trie[cur].child[ch] = trie.size();
            trie.push_back(node());
        }
        cur = trie[cur].child[ch];
    }
    ++trie[cur].cnt;
}

bool query(string s) {
    memset(edge, 0, sizeof(edge));
    int cur = 0;
    for(int i=0; i<s.size(); ++i) {
        if (trie[cur].cnt) return 0;
        int ch = s[i] - 'a';
        for(int j=0; j<26; ++j) if (j != ch && trie[cur].child[j] != -1)
            edge[ch][j] = 1;
        cur = trie[cur].child[ch];
    }
    return (!check());
}

void uraqt() {
    trie.push_back(node());
    cin >> n;
    for(int i=1; i<=n; ++i) {
        cin >> s[i];
        add(s[i]);
    }

    vt<string> ret;
    for(int i=1; i<=n; ++i) if (query(s[i]))
        ret.emplace_back(s[i]);
    cout << ret.size() << endl;
    for(string s: ret) cout << s << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    if (fopen(file"."tail, "r")) {
        freopen(file"."tail, "r", stdin);
        freopen(file".out", "w", stdout);
    }

    int t=1;
//    cin >> t;
    for(int i=1; i<=t; ++i)
        uraqt();
}
