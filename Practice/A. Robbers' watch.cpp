#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
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
const int maxn = 1e5 + 5;
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

int n, m;
int nP, mP;

int sol(int pos, ll &hours, ll &minutes, int &bitSet) {
  if (pos - nP >= mP)
    return 1;
  if (bitSet == 0)
    return 0;
  int ans = 0;
  forn(i, 7) {
    int ind = 6 - i;
    if (!(bitSet & (1 << ind)))
      continue;
    if (pos < nP) {
      hours += ind * (ll)pow(7, nP - (pos + 1));
      if (hours > n - 1) {
        hours -= ind * (ll)pow(7, nP - (pos + 1));
        continue;
      }
    } else {
      minutes += ind * (ll)pow(7, mP - (pos + 1 - nP));
      if (minutes > m - 1) {
        minutes -= ind * (ll)pow(7, mP - (pos + 1 - nP));
        continue;
      }
    }
    bitSet ^= (1 << ind);
    ans += sol(pos + 1, hours, minutes, bitSet);
    bitSet |= (1 << ind);
    if (pos < nP) {
      hours -= ind * (ll)pow(7, nP - pos);
    } else {
      minutes -= ind * (ll)pow(7, mP - (pos + 1 - nP));
    }
  }
  return ans;
}

int findBase7(int num) {
  int l = 0;
  int r = 12;
  while (l + 1 < r) {
    int mid = l + (r - l) / 2;
    if ((ll)pow(7, mid) <= num - 1) {
      l = mid;
    } else {
      r = mid;
    }
  }
  return l;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(20);
  cin >> n >> m;
  nP = findBase7(n) + 1;
  mP = findBase7(m) + 1;
  int bitSet = (1 << 7) - 1;
  ll hours = 0;
  ll minutes = 0;
  cout << sol(0, hours, minutes, bitSet) << nl;
}
