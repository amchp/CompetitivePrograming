#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i,n) for(int i=0; i< (int)n; ++i)
#define for1(i,n) for(int i=1; i<= (int)n; ++i)
#define fore(i,l,r) for(int i=(int)l; i<= (int)r; ++i)
#define ford(i,n) for(int i=(int)(n) - 1; i>= 0; --i)
#define fored(i,l,r) for(int i=(int)r; i>= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout<< #x<< " " << x<<el
#define ri(n) scanf("%d",&n)
#define sz(v) int(v.size())
#define all(v) v.begin(),v.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<ld> vd;


const int inf = 1e9;
const int nax = 30;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

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

typedef vector<ll> vl;

vl conv(const vl& a, const vl& b) {
	if (a.empty() || b.empty()) return {};
	vl res(sz(a) + sz(b) - 1);
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

vl convMod(const vl &a, const vl &b, const int &M) {
	if (a.empty() || b.empty()) return {};
	vl res(sz(a) + sz(b) - 1);
	int B=32-__builtin_clz(sz(res)), n=1<<B, cut=int(sqrt(M));
	vector<C> L(n), R(n), outs(n), outl(n);
	forn(i,sz(a)) L[i] = C((int)a[i] / cut, (int)a[i] % cut);
	forn(i,sz(b)) R[i] = C((int)b[i] / cut, (int)b[i] % cut);
	fft(L), fft(R);
	forn(i,n) {
		int j = -i & (n - 1);
		outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
		outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / 1i;
	}
	fft(outl), fft(outs);
	forn(i,sz(res)) {
		ll av = ll(real(outl[i])+.5), cv = ll(imag(outs[i])+.5);
		ll bv = ll(imag(outl[i])+.5) + ll(real(outs[i])+.5);
		res[i] = ((av % M * cut + bv) % M * cut + cv) % M;
	}
	return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout << setprecision(20)<< fixed;
  int n, p;
  cin >> n >> p;
  vl b(n), r(n), y(n);
  forn(i, n){
    char c;
    cin >> c;
    if(c == 'B')b[i] = 1;
    if(c == 'Y')y[i] = 1;
    if(c == 'R')r[i] = 1;
  }
  vl db = b, dr = r, dy = y;
  db.insert(db.end(), all(b));
  dr.insert(dr.end(), all(r));
  dy.insert(dy.end(), all(y));
  reverse(all(b));
  reverse(all(r));
  reverse(all(y));
  vl ba = conv(b, db);
  vl ra = conv(r, dr);
  vl ya = conv(y, dy);
  vector<pll> ans(n);
  fore(i, n - 1, 2*n - 2){
    ans[i - (n - 1)].fi = n - ba[i] - ra[i] - ya[i];
    ans[i - (n - 1)].se = i - (n - 1);
  }
  map<int, int> chk;
  vector<vi> lvl(n + 1);
  for(auto& [dif, ind] : ans){
    if(ind == 0)continue;
    chk[ind] = dif;
    lvl[dif].pb(ind);
  }
  int sm = 0;
  for1(i, n - 1){
    assert(chk[i] == chk[(-i + n) % n]);
  }
  forn(i, n + 1){
    if(sm + sz(lvl[i]) < p){
      sm += sz(lvl[i]);
      continue;
    }
    cout << lvl[i][0] << el;
    break;
  }
}