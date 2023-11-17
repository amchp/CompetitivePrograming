#include <algorithm>
#include <assert.h>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <string.h>
#include <unordered_map>
#include <vector>
//  #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl

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
#define count1s(v) __builtin_popcount(v)
#define count1sll(v) __builtin_popcountll(v)
#define countL0s(v) __builtin_clz(v)
#define countL0sll(v) __builtin_clzll(v)
#define vii(a, n)                                                              \
  vector<int> a(n);                                                            \
  forn(i, n) cin >> a[i];

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> ii;
typedef pair<pair<ll, ll>, ll> iii;

typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<char> vc;

const ll inf = 1e18;
const int MAXS = 1e5 + 2;
const int MAXT = 1e2 + 2;

int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};

void solve() {
  int n;
  cin >> n;

  vector<ll> a;
  vector<tuple<ll, ll, vector<ll>>> queries(n);

  bool tipo2 = true;
  forn(i, n) {
    ll type, m;
    cin >> type >> m;
    if (type == 1)
      tipo2 = false;
    vector<ll> c(m);
    forn(j, m) {
      cin >> c[j];
      if (c[j] - 1 >= 1)
        a.pb(c[j] - 1);
      if (c[j] + 1 <= inf)
        a.pb(c[j] + 1);
      a.pb(c[j]);
    }
    sort(all(c));
    queries[i] = {type, m, c};
  }
  a.pb(2);
  a.pb(inf + 1);
  a.pb(inf - 1);
  a.pb(inf), a.pb(1);
  sort(all(a));
  a.erase(unique(all(a)), a.end());
  vector<ll> pref(a.size() + 1);
  forn(i, n) {
    ll type = get<0>(queries[i]), m = get<1>(queries[i]);
    vector<ll> curr = get<2>(queries[i]);
    ll prev = 1;
    forn(j, curr.size()) {
      int idx = lower_bound(all(a), curr[j]) - a.begin() + 1;
      if (type == 1) {
        pref[idx]++;
        pref[idx + 1]--;
      } else {
        int idx2 = lower_bound(all(a), prev) - a.begin() + 1;
        pref[idx2]++;
        pref[idx]--;
        prev = curr[j] + 1;
      }
    }
    if (type == 2) {
      int idx = lower_bound(all(a), inf + 1) - a.begin() + 1;
      int idx2 = lower_bound(all(a), prev) - a.begin() + 1;
      pref[idx2]++;
      pref[idx]--;
    }
  }
  for1(i, pref.size() - 1) { pref[i] += pref[i - 1]; }
  ll ans = 0;
  // forn(i, a.size()) { cout << a[i] << ' '; }
  // cout << el;
  forn(i, pref.size()) {
    // cout << pref[i] << ' ';
    if (pref[i] == n) {
      if (i == pref.size() - 1)
        continue;
      else
        ans += a[i] - a[i - 1];
    }
  }
  // cout << el;
  cout << ans << el;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // cout.precision(5);
  int tt;
  tt = 1;
  // cin >> tt;
  while (tt--)
    solve();
  return 0;
}
// run g++ --std=c++17 A.cpp -o A
