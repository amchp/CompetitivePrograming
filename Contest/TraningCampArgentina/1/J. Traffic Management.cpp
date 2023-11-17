#include <algorithm>
#include <array>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <ios>
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

pair<ll, ll> lines[nax];

double intersetion(int i, int j) {
  if ((lines[i].se - lines[j].se) == 0)
    return -1;
  return (double)(lines[j].fi - lines[i].fi) / (lines[i].se - lines[j].se);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(20);
  cout << fixed;
  int n;
  cin >> n;
  forn(i, n) { cin >> lines[i].fi >> lines[i].se; }
  sort(lines, lines + n);
  vector<pair<double, int>> st;
  st.push_back(make_pair(inf, n - 1));
  double ans = 0;
  ford(i, n - 1) {
    double inter = intersetion(st.back().se, i);
    while (st.size() > 0 && (inter <= 0 || st.back().fi < inter)) {
      st.pop_back();
      if (st.size())
        inter = intersetion(st.back().se, i);
    }
    ans = max(ans, inter);
    if (st.size() == 0)
      st.push_back(make_pair(inf, i));
    else
      st.push_back(make_pair(inter, i));
  }
  cout << ans << el;
}
