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
  int neutro = -1, n, l, r, pos, val;  vi t;
  stree(int n): n(n), t(n << 2){}
  stree(const vi& a): n(sz(a)), t(n<<2){ build(1, 0, n-1, a); }
  inline int oper(int a, int b){ return max(a, b); }
  void build(int v, int tl, int tr, const vi& a){// solo para el 2. constructor
    if(tl == tr){ t[v] = a[tl];  return; }
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm, a), build((v << 1) | 1, tm+1, tr, a);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  int query(int v, int tl, int tr){
    if(tl > r || tr < l) return neutro;  // estoy fuera
    int tm = (tl + tr) >> 1;
    int cl = v << 1;
    int cr = (v << 1) | 1;
    if(l <= tl && tr <= r){
        if(tl == tr){
            if(t[v] < val)return -1;
            return tl;
        }
        // d(tl);
        // d(tr);
        // d(ind);
        // d(t[l]);
        if(val <= t[cl]){
            return query(cl, tl, tm);
        }
        if(val <= t[cr]){
            return query(cr, tm + 1, tr);
        }
        return -1;
    }
    int ql = query(cl, tl, tm);
    int qr = query(cr, tm + 1, tr);
    if(ql == -1)return qr;
    if(qr == -1)return ql;
    return min(ql, qr);
  }
  void upd(int v, int tl, int tr){
    if(tl == tr){ t[v] = val;  return; }
    int tm = (tl + tr) >> 1;
    if(pos <= tm) upd(v << 1, tl, tm);
    else upd((v << 1) | 1, tm+1, tr);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  void upd(int idx, int num){ pos = idx, val = num, upd(1, 0, n-1);}
  int query(int ql, int qval){val = qval; l = ql, r = n - 1; return query(1, 0, n-1);}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n, m;
    cin >> n >> m;
    vi a(n);
    forn(i, n)cin >> a[i];
    stree st(a);
    while(m--){
        int op;
        cin >> op;
        if(op == 1){
            int p, val;
            cin >> p >> val;
            st.upd(p, val);
        }else{
            int val, l;
            cin >> val >> l;
            cout << st.query(l, val) << el;
        }
    }
}