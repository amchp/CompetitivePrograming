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

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(20);
  int n, m;
  cin >> n >> m;
  // vector<vector<bool>> g(n, vector<bool>(n, 0));
  vector<vector<bool>> gI(n, vector<bool>(n, 1));
  forn(i, m) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    // g[u][v] = 1;
    // g[v][u] = 1;
    gI[u][v] = 0;
    gI[v][u] = 0;
  }
  vi connection(n, 0);
  int mn = 100;
  int mnInd = -1;
  forn(i, n) {
    forn(j, n) { connection[i] += gI[i][j]; }
    if (connection[i] < mn) {
      mnInd = i;
      mn = connection[i];
    }
  }
  vi ans;
  int total = 2 * m;
  int complete = n * (n - 1);
  while (total < complete) {
    ans.pb(mnInd);
    vi a, b;
    forn(i, n) {
      if (i == mnInd) {
        a.pb(i);
        continue;
      }
      if (gI[mnInd][i])
        a.pb(i);
      else
        b.pb(i);
    }
    int k = 0;
    mn = 1e9;
    mnInd = -1;
    forn(i, n) {
      if (k < a.size() && a[k] == i) {
        k++;
        if (connection[i] < mn) {
          mnInd = i;
          mn = connection[i];
        }
        continue;
      }
      forn(j, b.size()) {
        if (i == b[j])
          continue;
        total += gI[i][b[j]];
        connection[i] -= gI[i][b[j]];
        gI[i][b[j]] = 0;
      }
      if (connection[i] < mn) {
        mnInd = i;
        mn = connection[i];
      }
    }
  }
  cout << ans.size() << el;
  forn(i, ans.size()) { cout << ans[i] + 1 << ' '; }
  cout << el;
}