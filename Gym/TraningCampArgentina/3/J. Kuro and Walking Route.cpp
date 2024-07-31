#include <algorithm>
#include <array>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream> // istringstream buffer(myString);
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>

#define fi first
#define se second
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define fored(i, l, r) for (int i = (int)r; i >= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout << #x << " " << x << el
#define ri(n) scanf("%d", &n)
#define sz(v) ((int)v.size())
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> ii;
typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int inf = 1e9;
const int nax = 3e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

vi g[nax];
int indX, indY;

bool search(int ind, int p, int &d) {
  if (ind == d) {
    forn(i, g[ind].size()) {
      if (g[ind][i] == p) {
        indY = i;
        return true;
      }
    }
  }
  forn(i, g[ind].size()) {
    if (g[ind][i] == p)
      continue;
    if (search(g[ind][i], ind, d)) {
      indX = i;
      return true;
    }
  }
  return false;
}

ll dfs(int ind, int p) {
  ll sum = 1;
  forn(i, g[ind].size()) {
    if (g[ind][i] == p)
      continue;
    sum += dfs(g[ind][i], ind);
  }
  return sum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(20);
  int n, x, y;
  cin >> n >> x >> y;
  x--;
  y--;
  forn(i, n - 1) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  search(x, -1, y);
  ll tX = dfs(x, g[x][indX]);
  ll tY = dfs(y, g[y][indY]);
  ll ans = (ll)n * (n - 1);
  ans = ans - (tX * tY);
  cout << ans << el;
}
