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

struct stree{
  vl neutro = {0, 0, 0, 0}; 
  int n, l, r, pos; 
  ll val;  
  vector<vl> t;
  stree(int n): n(n), t(n << 2){}
  stree(const vl& a): n(sz(a)), t(n<<2){ build(1, 0, n-1, a); }
  vl oper(vl a, vl b){ 
    vl ans = neutro;
    ans[0] = max({a[0], b[0], a[2] + b[1]});
    ans[1] = max(a[1], a[3] + b[1]);
    ans[2] = max(b[2], b[3] + a[2]);
    ans[3] = a[3] + b[3];
    return ans;
  }
  void build(int v, int tl, int tr, const vl& a){// solo para el 2. constructor
    if(tl == tr){ t[v] = {a[tl], a[tl], a[tl], a[tl]};  return; }
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm, a), build((v << 1) | 1, tm+1, tr, a);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  vl query(int v, int tl, int tr){
    if(tl > r || tr < l) return neutro;  // estoy fuera
    if(l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) >> 1;
    return oper(query(v << 1, tl, tm), query((v << 1) | 1, tm+1, tr));
  }
  void upd(int v, int tl, int tr){
    if(tl == tr){ t[v] = {val, val, val, val};  return; }
    int tm = (tl + tr) >> 1;
    if(pos <= tm) upd(v << 1, tl, tm);
    else upd((v << 1) | 1, tm+1, tr);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  void upd(int idx, ll num){ pos = idx, val = num, upd(1, 0, n-1);}
  vl query(){ l = 0, r = n - 1;  return oper(neutro, query(1, 0, n-1));}
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
    cout << st.query()[0] << el;
    while(m--){
        int p, x;
        cin >> p >> x;
        st.upd(p, x);
        cout << st.query()[0] << el;
    }
}
