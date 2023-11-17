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
#define sz(v) ((intv.size())
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

ll n, m, r, k;

ll dist(ll x, ll y) {
  return min(r, min(min(n - x + 1, x), n - r + 1)) *
         min(r, min(min(m - y + 1, y), m - r + 1));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(20);
  cout << fixed;
  cin >> n >> m >> r >> k;
  vl iN;
  vl iM;
  iN.pb(n / 2 + 1);
  iM.pb(m / 2 + 1);
  if (n % 2 == 0)
    iN.pb(n / 2);
  if (m % 2 == 0)
    iM.pb(m / 2);
  priority_queue<vl> pq;
  set<pair<ll, ll>> visited;
  vl v(3);
  forn(i, iN.size()) {
    forn(j, iM.size()) {
      v[1] = iN[i];
      v[2] = iM[j];
      v[0] = dist(v[1], v[2]);
      pq.push(v);
      visited.insert(make_pair(v[1], v[2]));
    }
  }
  ll num = 0;
  while (k-- && !pq.empty()) {
    vl cur = pq.top();
    pq.pop();
    num += cur[0];
    // cout << cur[1] << ' ' << cur[2] << el;
    // cout << cur[0] << el;
    forn(k, 8) {
      int dx = cur[1] + dr[k];
      int dy = cur[2] + dc[k];
      if (dx > 0 && dx <= n && dy > 0 && dy <= m &&
          !visited.count(make_pair(dx, dy))) {
        v[1] = dx;
        v[2] = dy;
        v[0] = dist(v[1], v[2]);
        pq.push(v);
        visited.insert(make_pair(v[1], v[2]));
      }
    }
  }
  // cout << num << el;
  ll dem = (ll)(n - r + 1) * (ll)(m - r + 1);
  // cout << dem << el;
  ld ans = (ld)num / (ld)dem;
  cout << ans << el;
}
