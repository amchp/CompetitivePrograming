#include <algorithm>
#include <array>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <exception>
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

const ll inf = 1e18;
const int nax = 1e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int n, m;
int a[nax], b[nax];

ll f(int mid) {
  ll ans = 0;
  forn(i, n) {
    if (a[i] < mid) {
      ans += mid - a[i];
    }
  }
  forn(i, m) {
    if (b[i] > mid) {
      ans += b[i] - mid;
    }
  }
  return ans;
}

ll ternary_search(int l, int r) {
  while (l + 20 < r) {
    // cout << l << ' ' << r << el;
    ll m1 = l + (r - l) / 3;
    ll m2 = r - (r - l) / 3;
    ll f1 = f(m1), f2 = f(m2);
    if (f1 > f2)
      l = m1;
    else
      r = m2;
  }
  ll ans = inf;
  fore(i, l, r) { ans = min(ans, f(i)); }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(20);
  cin >> n >> m;
  forn(i, n) { cin >> a[i]; }
  forn(i, m) { cin >> b[i]; }
  cout << ternary_search(0, 1e9) << el;
}
