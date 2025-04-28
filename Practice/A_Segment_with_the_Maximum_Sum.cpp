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
const int nax = 1e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

struct node{
  ll mxs, mxpre, mxsuf, ttl;
  node(){}
  node(ll mxs, ll mxpre, ll mxsuf, ll ttl): mxs(mxs), mxpre(mxpre), mxsuf(mxsuf), ttl(ttl){}
};

struct stree{
  node neutro = {0, 0, 0, 0}; 
  int n, l, r, pos; 
  ll val;  
  vector<node> t;
  stree(int n): n(n), t(n << 2){}
  stree(const vl& a): n(sz(a)), t(n<<2){ build(1, 0, n-1, a); }
  node oper(node a, node b){ 
    node ans = neutro;
    ans.mxs = max({a.mxs, b.mxs, a.mxsuf + b.mxpre});
    ans.mxpre = max(a.mxpre, a.ttl + b.mxpre);
    ans.mxsuf = max(b.mxsuf, b.ttl + a.mxsuf);
    ans.ttl = a.ttl + b.ttl;
    return ans;
  }
  void build(int v, int tl, int tr, const vl& a){// solo para el 2. constructor
    if(tl == tr){ t[v] = node(a[tl], a[tl], a[tl], a[tl]);  return; }
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm, a), build((v << 1) | 1, tm+1, tr, a);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  node query(int v, int tl, int tr){
    if(tl > r || tr < l) return neutro;  // estoy fuera
    if(l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) >> 1;
    return oper(query(v << 1, tl, tm), query((v << 1) | 1, tm+1, tr));
  }
  void upd(int v, int tl, int tr){
    if(tl == tr){ t[v] = node(val, val, val, val);  return; }
    int tm = (tl + tr) >> 1;
    if(pos <= tm) upd(v << 1, tl, tm);
    else upd((v << 1) | 1, tm+1, tr);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  void upd(int idx, ll num){ pos = idx, val = num, upd(1, 0, n-1);}
  node query(){ l = 0, r = n - 1;  return oper(neutro, query(1, 0, n-1));}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n, m;
    cin >> n >> m;
    vl a(n);
    forn(i, n)cin >> a[i];
    stree st(a);
    // forn(i, 4*n)cout << st.t[i] << ' ';
    // cout << el;
    cout << st.query().mxs << el;
    while(m--){
        int p, x;
        cin >> p >> x;
        st.upd(p, x);
        cout << st.query().mxs << el;
    }
}
