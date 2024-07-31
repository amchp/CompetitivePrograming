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
const int nax = 2e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int n, k;
ii g[nax];
string cs, word;
vi flat_word;
bool dup[nax];
bool win[nax];

void get_word(int ind) {
  if (g[ind].fi != -1)
    get_word(g[ind].fi);
  word.pb(cs[ind]);
  flat_word.pb(ind);
  if (dup[ind])
    word.pb(cs[ind]);
  if (g[ind].se != -1)
    get_word(g[ind].se);
}

bool sol(int ind, int depth) {
  if (k - depth < 0)
    return false;
  bool lower = false;
  if (g[ind].fi != -1)
    lower = sol(g[ind].fi, depth + 1);
  if (lower || win[ind]) {
    if (!lower)
      k -= depth;
    dup[ind] = true;
    if (g[ind].se != -1)
      sol(g[ind].se, 1);
    return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(20);
  cin >> n >> k;
  cin >> cs;
  forn(i, n) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[i] = make_pair(u, v);
    dup[i] = 0;
    win[i] = 0;
  }
  word.clear();
  flat_word.clear();
  get_word(0);
  stack<int> st;
  forn(i, n) {
    while (st.size() > 0 && word[st.top()] != word[i]) {
      win[flat_word[st.top()]] = word[st.top()] < word[i];
      st.pop();
    }
    st.push(i);
  }
  while (st.size() > 0) {
    win[flat_word[st.top()]] = false;
    st.pop();
  }
  // forn(i, n) { cout << win[i] << ' '; }
  // cout << el;
  sol(0, 1);
  word.clear();
  flat_word.clear();
  get_word(0);
  cout << word << el;
}
