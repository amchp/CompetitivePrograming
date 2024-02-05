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

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> ii;
typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int inf = 1e9;
const int nax = 800;
const int kax = 1e4 + 200;
const int ansax = 700*700+200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int n, m, k, nm;
int grid[nax][nax];
ii prsn[kax];
int tgrid[nax][nax];

int t[ansax << 2];
int lazy[ansax << 2];
int op = 0;
struct stree{
  int n, l, r, val, neutro = -1;
  stree(){}
  stree(int n): n(n){ forn(i, n << 2) t[i] = lazy[i] = -1; }
  inline int oper(int a, int b){ return a > b ? a : b; }
  inline void push(int v){
    if(lazy[v] != -1){
      t[v << 1] = max(t[v << 1], lazy[v]);  lazy[v << 1] = max(lazy[v << 1], lazy[v]);
      t[(v << 1) | 1] = max(t[(v << 1) | 1], lazy[v]);  lazy[(v << 1) | 1] = max(lazy[(v << 1) | 1], lazy[v]);
      lazy[v] = -1;
    }
  }
  void build(int v, int tl, int tr, vi& a){
    if(tl == tr){
      t[v] = a[tl]; return;
    }
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm, a), build((v << 1) | 1, tm+1, tr, a);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  void upd(int v, int tl, int tr){
    if(tl > r || tr < l) return;
    if(l <= tl && tr <= r){
      t[v] = max(t[v], val);  lazy[v] = max(lazy[v], val);
      return ;
    }
    push(v);  int tm = (tl + tr) >> 1;
    upd(v << 1, tl, tm);  upd((v << 1) | 1, tm+1, tr);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  int query(int v, int tl, int tr){
    if(tl > r || tr < l) return neutro;
    if(l <= tl && tr <= r) return t[v];
    push(v);  int tm = (tl + tr) >> 1;
    return oper(query(v << 1, tl, tm), query((v << 1) | 1, tm + 1, tr));
  }
  void update(int ql, int qr, int qval){  
    l = ql, r = qr, val = qval, upd(1, 0, n-1); }
  int query(int ql, int qr){ l = ql, r = qr;  return query(1, 0, n-1); }
};

void rotate(){
    forn(i, n){
        forn(j, m)tgrid[j][n - i - 1] = grid[i][j];
    }
    forn(i, k){
        prsn[i] = {prsn[i].se, n - 1- prsn[i].fi};
    }
    swap(n, m);
    swap(tgrid, grid);
}

struct RMQ{
  int n, K;
  ll neutro = inf;
  vector<vi> st;
  inline ll oper(ll a, ll b){ return a > b ? a : b; }
  RMQ(){}
  RMQ(vi& a){
    n = sz(a);
    K = ceil(log2(n)) + 3;
    st = vector<vi>(n, vi(K));
    forn(i, n) st[i][0] = a[i];
    for1(j, K-1)
      forn(i, n - (1 << j) + 1)
        st[i][j] = oper(st[i][j-1], st[i + (1 << (j-1))][j-1]);
  }
  ll query(int l, int r){
    if(l > r) return neutro;
    int j = 31 - __builtin_clz(r-l+1);
    return oper(st[l][j], st[r - (1 << j) + 1][j]);
  }
};

vector<ii> cprsn[kax];

vector<ii> merge(vector<ii>& a, vector<ii>& b){
    int i = 0;
    int j = 0;
    int mx = 0;
    vector<ii> c;
    while(i < sz(a) && j < sz(b)){
        if(a[i].se < b[j].se){
            if(a[i].fi <= mx){
                ++i;
                continue;
            }
            if(sz(c) && c.back().se == a[i].se)c.pop_back();
            c.pb(a[i]);
            mx = a[i].fi;
            ++i;
            continue;
        }
        if(b[j].fi <= mx){
            ++j;
            continue;
        }
        if(sz(c) && c.back().se == b[j].se)c.pop_back();
        c.pb(b[j]);
        mx = b[j].fi;
        ++j;
    }
    while(i < sz(a)){
        if(a[i].fi <= mx){
                ++i;
                continue;
        }
        if(sz(c) && c.back().se == a[i].se)c.pop_back();
        c.pb(a[i]);
        mx = a[i].fi;
        ++i;
    }
    while(j < sz(b)){
        if(b[j].fi <= mx){
            ++j;
            continue;
        }
        if(sz(c) && c.back().se == b[j].se)c.pop_back();
        c.pb(b[j]);
        mx = b[j].fi;
        ++j;
    }
    return c;
}

void sol(){
    vector<vi> dig(nm);
    forn(j, m){
        forn(i, n){
            dig[i + j].pb(grid[i][j]);
        }
    }
    vector<RMQ> digRMQ(nm);
    forn(i, nm){
        digRMQ[i] = RMQ(dig[i]);
    }
    forn(i, k){
        auto& [x, y] = prsn[i];
        vector<ii> mxs;
        mxs.pb({grid[x][y], 0});
        // d(x);
        // d(y);
        grid[x][y];
        int dig = x + y;
        int tm = 1;
        fore(cdig, dig + 1, nm - 1){
            int ni = x + tm;
            int nj = y + tm;
            int l = y - max(0, cdig - (n - 1));
            int r = nj - max(0, cdig - (n - 1));
            l = max(l, 0);
            r = min(r, digRMQ[cdig].n - 1);
            int nmx = digRMQ[cdig].query(l, r);
            if(mxs.back().fi < nmx){
                mxs.pb({nmx, tm});
            }
            ++tm;
        }
        // cout << "mxs : ";
        // for(ii& v : mxs)cout << v.fi << ' ' << v.se << el;
        // cout << el;
        cprsn[i] = merge(cprsn[i], mxs);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    cin >> n >> m >> k;
    int X = 0, Y = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            grid[i + j][i - j + m] = x;
            X = max(X, i + j);
            Y = max(Y, i - j + m);
        }
    }
    sol();
    rotate();
    // forn(i, n){
    //     forn(j, m)cout << grid[i][j] << ' ';
    //     cout << el;
    // }
    // cout << el;
    sol();
    rotate();
    // forn(i, n){
    //     forn(j, m)cout << grid[i][j] << ' ';
    //     cout << el;
    // }
    // cout << el;
    sol();
    rotate();
    // forn(i, n){
    //     forn(j, m)cout << grid[i][j] << ' ';
    //     cout << el;
    // }
    sol();
    // forn(i, k){
    //     d(i);
    //     forn(j, sz(cprsn[i])){
    //         cout << cprsn[i][j].fi << ' ' << cprsn[i][j].se << el;
    //     }
    //     cout << el;
    // }
    stree ans = stree(n*m + 1);
    forn(i, k){
        forn(j, sz(cprsn[i])){
            if(j == 0){
                ans.update(0, cprsn[i][j].fi, cprsn[i][j].se);
                continue;
            }
            ans.update(cprsn[i][j - 1].fi + 1, cprsn[i][j].fi, cprsn[i][j].se);
        }
    }
    for1(i, n*m){
        cout << ans.query(i, i) << ' ';
    }
    cout << el;
}