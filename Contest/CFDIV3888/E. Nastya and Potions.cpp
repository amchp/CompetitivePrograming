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
const int nax = 1e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;
const int maxn = 2e5 + 1;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int n;
vi topo;
bool visited[maxn];
vi g[maxn];
vi gI[maxn];

void dfs(int ind) {
  visited[ind] = true;
  forn(i, g[ind].size()) {
    if (!visited[g[ind][i]])
      dfs(g[ind][i]);
  }
  topo.pb(ind);
}

void topo_sort() {
  topo.clear();
  forn(i, n) { visited[i] = false; }
  forn(i, n) {
    if (!visited[i])
      dfs(i);
  }
  reverse(all(topo));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(20);
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> n >> k;
    vi cost(n);
    forn(i, n) {
      g[i].clear();
      gI[i].clear();
      cin >> cost[i];
    }
    forn(i, k) {
      int v;
      cin >> v;
      v--;
      cost[v] = 0;
    }
    forn(i, n) {
      int m;
      cin >> m;
      forn(j, m) {
        int v;
        cin >> v;
        v--;
        gI[i].pb(v);
        g[v].pb(i);
      }
    }
    // forn(i, n) {
    //   cout << i << " : ";
    //   forn(j, g[i].size()) { cout << g[i][j] << ' '; }
    //   cout << el;
    // }
    topo_sort();
    forn(i, topo.size()) {
      int ind = topo[i];
      // cout << ind << ' ';
      if (gI[ind].size() == 0)
        continue;
      ll sum = 0;
      forn(j, gI[ind].size()) { sum += cost[gI[ind][j]]; }
      cost[ind] = min(sum, (ll)cost[ind]);
    }
    // cout << el;
    forn(i, n) { cout << cost[i] << ' '; }
    cout << el;
  }
}
