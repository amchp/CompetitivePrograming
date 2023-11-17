#include <bits/stdc++.h>

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
#define RAYA cout << "########" << el;
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
const ll mod = 1e9 + 7;


int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

const int N = 2e5 + 10;
ll t[N << 2], lazy[N << 2];
struct stree{
  int n, l, r, val;
  ll neutro = 0;
  stree(int n): n(n){ forn(i, n << 2) t[i] = lazy[i] = 0; }
  inline int oper(int a, int b){ return (a + b) % mod; }
  inline void push(int v, int tl, int tr){
    if(lazy[v]){
      int tm = (tl + tr) >> 1;
      t[v << 1] += ll(tm - tl + 1)*lazy[v]%mod;  
      t[(v << 1)] %= mod;
      lazy[v << 1] += lazy[v];
      lazy[v << 1] %= mod;
      t[(v << 1) | 1] += ll(tr - (tm + 1) + 1)*lazy[v]%mod;  
      t[(v << 1) | 1] %= mod;
      lazy[(v << 1) | 1] += lazy[v];
      lazy[(v << 1) | 1] %= mod;
      lazy[v] = 0;
    }
  }
  void upd(int v, int tl, int tr){
    if(tl > r || tr < l) return;
    if(l <= tl && tr <= r){
      t[v] += ll(tr - tl + 1)*val%mod;  
      t[v] %= mod;
      lazy[v] += val;
      lazy[v] %= mod;
      return ;
    }
    push(v, tl, tr);  int tm = (tl + tr) >> 1;
    upd(v << 1, tl, tm);  upd((v << 1) | 1, tm+1, tr);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  ll query(int v, int tl, int tr){
    if(tl > r || tr < l) return neutro;
    if(l <= tl && tr <= r) return t[v];
    push(v, tl, tr);  int tm = (tl + tr) >> 1;
    return oper(query(v << 1, tl, tm), query((v << 1) | 1, tm + 1, tr));
  }
  void update(int ql, int qr, ll qval){  
    l = ql, r = qr, val = qval, upd(1, 0, n-1); }
  ll query(int ql, int qr){ l = ql, r = qr;  return query(1, 0, n-1); }
};

vector<ii> segmentedSieve(int L, long long R) {
    // generate all primes up to sqrt(R)
    int lim = sqrt(R);
    vector<bool> marked(lim, false);
    vector<int> primes;
    fore(i, 2, lim){
      if(marked[i])continue;
      primes.pb(i);
      for(int j = i + i; j <= lim; j += i){
        marked[j] = true;
      }
    }
    vector<ii> pD(R - L + 1, {-1, -1});
    fore(i, L, R){
      for(int& p : primes){
        if(i % p == 0){
          pD[i - L].fi = p;
          pD[i - L].se = i / p;
          break;
        }
      }
    }
    return pD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    int n = b - a + 1;
    vector<ii> pD = segmentedSieve(a, b);
    stree bl = stree(n);
    vl w(n, 0);
    w[0] = 1;
    fore(i, a, b){
        int ind = i - a;
        if(pD[ind] == ii{-1, -1})continue;
        int ll = ind - pD[ind].second;
        int lr = ind - pD[ind].first;
        int rl = ind + pD[ind].first;
        int rr = ind + pD[ind].second;
        if(lr >= 0){
            ll = max(0, ll);
            w[ind] += bl.query(ll, lr);
            w[ind] %= mod;
        }
        if(rl < n){
            rr = min(rr, n - 1);
            bl.update(rl, rr, w[ind]);
        }
    }
    ll ans = w[n - 1] + bl.query(n - 1, n - 1);
    ans %= mod;
    cout << ans << el;
}
// 0 0 1 1 0 0 1 1 3 3 5 