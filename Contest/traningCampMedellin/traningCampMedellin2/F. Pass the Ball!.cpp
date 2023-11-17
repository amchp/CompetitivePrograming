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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;   // int vec
typedef vector<ll> vll;   // int vec
typedef vector<vi> vvi;   // int vec vec
typedef vector<vll> vvll; // int vec
typedef vector<pii> vpi;  // int int pair vec
typedef vector<pll> vpll; // int int pair vec

const int MAXN = 131072;
const ll INF = 1e9;
const ll INFLL = 1000000000000000005LL;
int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};

#define d(x) cout << #x << " = " << x << endl;
#define ios ios_base::sync_with_stdio(0), cin.tie(0);
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define forab(i, a, b) for (int i = a; i < (int)b; ++i)
#define fore(i,l,r) for(int i=(int)l; i<= (int)r; ++i)
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
#define sz(x) x.size()

typedef double ld;
const ld PI = acos(-1.0L);
const ld one = 1;

typedef complex<ld> C;
typedef vector<ld> vd;

void fft(vector<C>& a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vector<complex<ld>> R(2, 1);
	static vector<C> rt(2, 1);  // (^ 10% faster if double)
	for (static int k = 2; k < n; k *= 2) {
		R.resize(n); rt.resize(n);
		auto x = polar(one, PI / k);
		fore(i,k,2*k-1) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
	}
	vi rev(n);
	forn(i,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	forn(i,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) forn(j,k) {
			// C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
			auto x = (ld *)&rt[j+k], y = (ld *)&a[i+j+k];        /// exclude-line
			C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
			a[i + j + k] = a[i + j] - z;
			a[i + j] += z;
		}
}

vll conv(const vll& a, const vll& b) {
	if (a.empty() || b.empty()) return {};
	vll res(sz(a) + sz(b) - 1);
	int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
	vector<C> in(n), out(n);
	copy(all(a), begin(in));
	forn(i,sz(b)) in[i].imag(b[i]);
	fft(in);
	for (C& x : in) x *= x;
	forn(i,n) out[i] = in[-i & (n - 1)] - conj(in[i]);
	fft(out);
	forn(i,sz(res)) res[i] = floor(imag(out[i]) / (4 * n) +0.5);
	return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(0) << fixed;
  int n, q;
  cin >> n >> q;
  vi a(n + 1);
  map<int, vll> ffts;
  vector<bool> visited(n + 1, false);
  forab(i, 1, n + 1) { cin >> a[i]; }
  forab(i, 1, n + 1) {
    if (visited[i]) {
      continue;
    }
    int ind = i;
    vll mA = vll();
    vll mB = vll();
    while (!visited[ind]) {
      visited[ind] = true;
      mA.pb((int)a[ind]);
      mB.pb(ind);
      ind = (int)a[ind];
    }
    int m = mA.size();
    forn(i, m) { mA.pb(mA[i]); }
    // forn(i, mA.size()){
    //   cout << mA[i] << ' ';
    // }
    // cout << nl;
    reverse(all(mB));
    // forn(i, m){
    //   cout << mB[i] << ' ';
    // }
    // cout << nl;
    vll ans = conv(mA, mB);
    // forn(i, ans.size()) { cout << ans[i] << ' '; }
    // cout << nl;
    reverse(ans.begin(), ans.begin() + mA.size() + mB.size() - 1);
    // forn(i, ans.size()) { cout << ans[i] << ' '; }
    // cout << nl;
    if (ffts.count(m)) {
      forn(i, ffts[m].size()) { ffts[m][i] += round(ans[i]); }
    } else {
      ffts[m] = ans;
    }
  }
  forn(i, q) {
    int k;
    cin >> k;
    ll sum = 0;
    for (map<int, vll>::iterator it = ffts.begin(); it != ffts.end(); it++) {
      int m = (*it).first;
      vll &ansM = (*it).second;
      int mInd = k % m;
      sum += round(ansM[mInd + m]);
    }
    cout << round(sum) << nl;
  }
}
