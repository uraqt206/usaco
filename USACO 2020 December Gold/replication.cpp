#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
#define vec vector
#define foru(i, l, r) for(int i=l; i<=r; ++i)
#define revu(i, r, l) for(int i=r; i>=l; --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()

const int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
const int lim = 2e9;
const int N = 1000+5;

int n, d, nearest[N][N], fst[N][N], dist[N][N];
bool block[N][N], mark[N][N];
vector<ii> tmp[N*2];

void solve() {
	memset(nearest, 0x3f, sizeof(nearest));
	memset(fst, 0x3f, sizeof(fst));
	memset(dist, 0x3f, sizeof(dist));

	cin >> n >> d;

	queue<ii> robot, cell;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j) {
			char ch;
			cin >> ch;

			if (ch == '#') {
				block[i][j] = 1;
				nearest[i][j] = -1;
				cell.push({i, j});
			} 
			else if (ch == 'S') {
				fst[i][j] = 0;
				robot.push({i, j});
			}
		}

	while (!cell.empty()) {
		ii cur = cell.front();
		cell.pop();

		for(int i=0; i<4; ++i) {
			int x = cur.fi + dx[i], y = cur.se + dy[i];
			if (x<1 || y<1 || x>n || y>n || block[x][y] || nearest[x][y] <= nearest[cur.fi][cur.se]+1) {
				continue;
			}
			nearest[x][y] = nearest[cur.fi][cur.se] + 1;
			cell.push({x, y});
		}
	}

	while (!robot.empty()) {
		ii cur = robot.front();
		robot.pop();

		int round = fst[cur.fi][cur.se];
		tmp[nearest[cur.fi][cur.se]].emplace_back(cur);

		int trans = round / d;
		if (trans > nearest[cur.fi][cur.se]) {
			continue;
		}

		for(int i=0; i<4; ++i) {
			int x = cur.fi + dx[i], y = cur.se + dy[i];
			if (x<1 || y<1 || x>n || y>n || block[x][y] || fst[x][y] <= round+1) {
				continue;
			}
			if (trans > nearest[x][y]) {
				continue;
			}
			fst[x][y] = round+1;
			robot.push({x, y});
		}
	}

	for(int i=n*2; i>=0; --i) {
		vector<ii> lst;

		for(int j=0; j<tmp[i].size(); ++j) {
			ii now = tmp[i][j];
			mark[now.fi][now.se] = 1;

			if (i == 0) continue;

			for(int z=0; z<4; ++z) {
				ii to(now.fi + dx[z], now.se + dy[z]);

				if (to.fi < 1 || to.se < 1 || to.fi > n || to.se > n) {
					continue;
				}  

				if (block[to.fi][to.se] || mark[to.fi][to.se]) {
					continue;
				}

				mark[to.fi][to.se] = 1;
				if (i>0) tmp[i-1].emplace_back(to);
			}
		}
	}

	int ans = 0;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			ans += mark[i][j];
			// cout << mark[i][j];
		}
		// cout << "\n";
	}
	
	// cout << mark[2][8] << "\n";
	cout << ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();
	return 0;
}