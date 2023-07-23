#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define ins push_back
#define vec vector
#define C make_pair

const int N = 1e5+5;
int n;

// fenwick tree
int ft[N];

void upd(int i, int v) {
  for(; i<=n; i+=i&-i)
    ft[i] += v;
}

int query(int i) {
  int ans = 0;
  for(; i>=1; i-=i&-i)
    ans += ft[i];
  return ans;
}

// general
int a[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  if (fopen("sleepy.in", "r")) {
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
  }

  cin >> n;
  for(int i=1; i<=n; ++i)
    cin >> a[i];

  int len = 1;
  for(len=1; len<n && a[n-len]<a[n-len+1]; ++len);
  for(int i=n-len+1; i<=n; ++i) upd(a[i], 1);

  cout << n-len << "\n";
  for(int i=1; i<=n-len; ++i) {
    cout << n-len-i + query(a[i]);
    if (i < n-len) cout << " ";
    upd(a[i], 1); 
  }
  return 0;
}