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

typedef long double ll;
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

vl sol(vl &a, vl &b) {
  vl c(a.size() + b.size());
  forn(i, a.size()) {
    forn(j, b.size()) { c[i + j] += a[i] * b[j]; }
  }
  return c;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(20);
  vector<vl> a;
  ll nth[] = {4, 6, 8, 12, 20};
  forn(i, 5) {
    ll num;
    cin >> num;
    vl curr;
    curr.pb(0);
    for1(j, nth[i]) { curr.pb(1); }
    forn(j, num) a.pb(curr);
  }
  vl prev = a.front();
  for1(i, a.size() - 1) { prev = sol(prev, a[i]); }
  vector<pll> ans;
  forn(i, prev.size()) {
    if (prev[i] != 0)
      ans.pb(make_pair(prev[i], i));
  }
  sort(all(ans), greater<pll>());
  forn(i, ans.size()) { cout << ans[i].second << ' '; }
  cout << el;
}
