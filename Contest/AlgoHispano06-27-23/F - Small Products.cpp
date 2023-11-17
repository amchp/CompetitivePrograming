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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(20);
  int n;
  cin >> n;
  int k;
  cin >> k;
  int sq = sqrt(n);
  vvll s(k + 1, vll(sq + 1));
  vvll b(k + 1, vll(sq + 1));
  vvll sp(k + 1, vll(sq + 1, 0));
  vvll bp(k + 1, vll(sq + 1, 0));
  s[0][1] = 1;
  forab(i, 1, sq + 1) { sp[0][i] = 1; }
  forab(i, 1, k + 1) {
    forab(j, 1, sq + 1) {
      s[i][j] =
          (sp[i - 1][sq] + (bp[i - 1][sq] - bp[i - 1][j - 1] + MOD) % MOD) %
          MOD;
      b[i][j] = (ll)(n / j - n / (j + 1)) * sp[i - 1][j] % MOD;
      if (j == n / j)
        b[i][j] = 0;
      sp[i][j] = (s[i][j] + sp[i][j - 1]) % MOD;
      bp[i][j] = (b[i][j] + bp[i][j - 1]) % MOD;
    }
  }
  // forab(i, 1, k + 1) {
  //   forab(j, 1, sq + 1) { cout << s[i][j] << ' '; }
  //   cout << nl;
  // }
  // cout << nl;
  // forab(i, 1, k + 1) {
  //   forab(j, 1, sq + 1) { cout << b[i][j] << ' '; }
  //   cout << nl;
  // }
  // cout << nl;
  ll ans = (bp[k][sq] + sp[k][sq]) % MOD;
  cout << ans << nl;
}
