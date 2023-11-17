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
#define ri(n) scanf("%d", &n)
#define sz(v) ((int)v.size())
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define RAYA cout << "#####" << el;

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

typedef pair<ll, vi> lv;

const int N = 41;

struct sstree{
  lv neutro = lv(0, vi(N));
  int n, l, r, pos, val, pval;  
  vector<lv> t;
  sstree(int n): n(n), t(n<<2, lv(0LL, vi(N))){}
  sstree(const vi& a): n(sz(a)), t(n<<2, lv(0LL, vi(N))){ build(1, 0, n-1, a); }
  lv oper(lv& a, lv& b){
    vi frec(N, 0);
    ll inv = 0;
    forn(i, N)frec[i] = a.se[i] + b.se[i];
    forn(i, N){
      forn(j, i){
        inv += ll(a.se[i])*b.se[j];
      }
    }
    return lv(a.fi + b.fi + inv, frec);
  }
  void build(int v, int tl, int tr, const vi& a){// solo para el 2. constructor
    if(tl == tr){ 
        t[v].fi = 0;  
        t[v].se[a[tl]]++;
        return; 
    }
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm, a), build((v << 1) | 1, tm+1, tr, a);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
    // d(tl);
    // d(tr);
    // d(t[v].fi);
    // RAYA;
  }
  lv query(int v, int tl, int tr){
    if(tl > r || tr < l) return neutro;  // estoy fuera
    if(l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) >> 1;
    lv lf = query(v << 1, tl, tm);
    lv rt = query((v << 1) | 1, tm+1, tr);
    return oper(lf, rt);
  }
  void upd2(int v, int tl, int tr){
    if(tl == tr){ 
        t[v].se[pval]--;
        t[v].fi = 0;
        t[v].se[val]++;
        return; 
    }
    int tm = (tl + tr) >> 1;
    if(pos <= tm) upd2(v << 1, tl, tm);
    else upd2((v << 1) | 1, tm+1, tr);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  void upd(int idx, int num, int pnum){ pos = idx, val = num, pval = pnum, upd2(1, 0, n-1);}
  ll query(int ql, int qr){ l = ql, r = qr;  return query(1, 0, n-1).fi;}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n, m;
    cin >> n >> m;
    vi a(n);
    forn(i, n){
        cin >> a[i];
        a[i]--;
    }
    // cout << "HI" << el;
    sstree st(a);
    while(m--){
        int op;
        cin >> op;
        // cout << op << el;
        if(op == 1){
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << st.query(l, r) << el;
        }else{
            int ind, x;
            cin >> ind >> x;
            ind--;
            x--;
            st.upd(ind, x, a[ind]);
            a[ind] = x;
        }
    }

}
