8 5 6#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

#define lc (id<<1)
#define rc (id<<1)+1
#define fi first
#define se second
#define debug(x) cout << #x << ": " << x << "\n"
#define all(x) x.begin(), x.end()

template<class T> bool umax(T &a, T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool umin(T &a, T b) { if (a>b) { a=b; return 1; } return 0; }

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

const int mod=1e9+7;
const int MAX=1000000;
const int N=5000010;

int T, A, B;
bool dp[2][N];

int main() {
    setIO("feast");
    cin >> T >> A >> B;

    dp[0][0]=1;
    for(int i=1; i<=T; ++i) {
        if (i>=A) dp[0][i] |= dp[0][i-A];
        if (i>=B) dp[0][i] |= dp[0][i-B];
        dp[1][i/2] |= dp[0][i];
    }

    for(int i=1; i<=T; ++i) {
        if (i>=A) dp[1][i] |= dp[1][i-A];
        if (i>=B) dp[1][i] |= dp[1][i-B];
    }

    int a1, a2;
    for(a1=T; a1>=0 && !dp[0][a1]; --a1);
    for(a2=T; a2>=0 && !dp[1][a2]; --a2);
    cout << max(a1, a2);
}