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

int n;
int even = 0;
int odds = 1;

void incEven() {
  even += 2;
  if (n % 2 == 0) {
    if (even % n == 1)
      even--;
    else if (even % n == 0)
      even++;
  }
}

void incOdd() {
  odds += 2;
  if (n % 2 == 0) {
    if (odds % n == 1)
      odds--;
    else if (odds % n == 0)
      odds++;
  }
}

int main() {
  cin >> n;
  int n2 = n * n;
  int a;
  while (even < n2 || odds < n2) {
    cin >> a;
    int color;
    int x, y;
    if (a == 1) {
      if (odds >= n2) {
        color = 3;
        x = even / n + 1;
        y = even % n + 1;
        incEven();
      } else {
        color = 2;
        x = odds / n + 1;
        y = odds % n + 1;
        incOdd();
      }
    }
    if (a == 2) {
      if (even >= n2) {
        color = 3;
        x = odds / n + 1;
        y = odds % n + 1;
        incOdd();
      } else {
        color = 1;
        x = even / n + 1;
        y = even % n + 1;
        incEven();
      }
    }
    if (a == 3) {
      if (even >= n2) {
        color = 2;
        x = odds / n + 1;
        y = odds % n + 1;
        incOdd();
      } else {
        color = 1;
        x = even / n + 1;
        y = even % n + 1;
        incEven();
      }
    }
    cout << color << ' ' << x << ' ' << y << nl;
    cout << nl;
    cout.flush();
  }
}
