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
    vector<vector<ii>> same;
    vector<ii> a(n);
    forn(i, n) {
      int v;
      cin >> v;
      a[i] = make_pair(v, i);
    }
    same.pb(a);
    queue<ii> q;
    q.push(make_pair(0, k - 1));
    int aI = 0;
    int aJ = 1;
    int x = (a[aI].first | a[aJ].first) ^ ((1 << k) - 1);
    int ans = (a[aI].first ^ x) & (a[aJ].first ^ x);
    while (!q.empty()) {
      ii p = q.front();
      int ind = p.first;
      int kI = p.second;
      q.pop();
      if (same[ind].size() == 2 || kI == -1) {
        int tAI = same[ind][0].second;
        int tAJ = same[ind][1].second;
        int tX = (a[tAI].first & a[tAJ].first) ^ ((1 << k) - 1);
        int tAns = ((a[tAI].first ^ tX) & (a[tAJ].first ^ tX));
        if (ans < tAns) {
          aI = tAI;
          aJ = tAJ;
          x = tX;
          ans = tAns;
        }
        continue;
      }
      vector<ii> zeros, ones;
      forn(i, same[ind].size()) {
        if (same[ind][i].first & (1 << kI)) {
          ones.pb(same[ind][i]);
        } else {
          zeros.pb(same[ind][i]);
        }
      }
      if (ones.size() > 1 && kI >= 0) {
        same.pb(ones);
        q.push(make_pair(same.size() - 1, kI - 1));
      }
      if (zeros.size() > 1 && kI >= 0) {
        same.pb(zeros);
        q.push(make_pair(same.size() - 1, kI - 1));
      }
    }
    // cout << ans << el;
    // forn(i, same.size()) {
    //   forn(j, same[i].size()) { cout << same[i][j].first << ' '; }
    //   cout << el;
    // }
    cout << aI + 1 << ' ' << aJ + 1 << ' ' << x << el;
  }
}
