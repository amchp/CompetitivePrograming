#include <algorithm>
#include <array>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <functional>
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

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;   // int vec
typedef vector<ll> vll;   // int vec
typedef vector<vi> vvi;   // int vec vec
typedef vector<vll> vvll; // int vec
typedef vector<pii> vpi;  // int int pair vec
typedef vector<pll> vpll; // int int pair vec
typedef complex<double> cd;

const double pi = 3.1415926535897932384626433832795;
const int maxn = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll INFLL = 1000000000000000005LL;
const ld EPS = 1e-9;
int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};

#define d(x) cout << #x << " = " << x << endl;
#define ios ios_base::sync_with_stdio(0), cin.tie(0);
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define forab(i, a, b) for (int i = a; i < (int)b; ++i)
#define foreach(a, b) for (auto &(a) : (b))
#define formap(map) for (const auto &[key, value] : map)
#define all(v) v.begin(), v.end()
#define allar(arr, sz) arr, arr + sz
#define ms(ar, val) memset(ar, val, size)
#define pq(type) priority_queue<type>
#define pqd(type) priority_queue<type, vector<type>, greater<type>>
#define umap unordered_map
#define uset unordered_set
#define imax INT_MAX
#define imin INT_MIN
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define nl "\n"
#define in(t) while (t--)

vi g[maxn], ts;
bool seen[maxn];
void dfs(int u) {
  seen[u] = true;
  for (int v : g[u])
    if (!seen[v])
      dfs(v);
  ts.pb(u);
}
void topo(int n) {
  forn(i, n) {
    int ind = n - i - 1;
    if (!seen[ind])
      dfs(ind);
  }
  reverse(all(ts));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(20);
  int n, m;
  cin >> n >> m;
  vi passed(n - 1, true);
  forn(i, m) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].pb(v);
    if (u + 1 == v) {
      passed[u] = false;
    }
  }
  forn(i, n - 1) {
    if (passed[i]) {
      g[i].pb(i + 1);
    }
  }
  forn(i, n) { sort(all(g[i])); }
  topo(n);
  vi ans(n);
  // forn(i, n) { cout << ts[i] << ' '; }
  // cout << nl;
  forn(i, n) { ans[ts[i]] = i + 1; }
  forn(i, n) { cout << ans[i] << ' '; }
  cout << nl;
}
