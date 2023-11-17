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
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vi a(n);
    vector<vi> m(n + 1);
    forn(i, n) {
      cin >> a[i];
      m[a[i]].pb(i);
    }
    int ls = m[a[n - 1]].size();
    // cout << ls << ' ' << k << el;
    if (ls < k) {
      cout << "NO" << el;
      continue;
    }
    if (a[0] == a[n - 1]) {
      cout << "YES" << el;
      continue;
    }
    int pos = m[a[n - 1]][ls - k];
    // cout << pos << el;
    int i = 0;
    while (i < k && i < m[a[0]].size() && m[a[0]][i] < pos) {
      i++;
    }
    if (i == k) {
      cout << "YES" << el;
    } else {
      cout << "NO" << el;
    }
  }
}
