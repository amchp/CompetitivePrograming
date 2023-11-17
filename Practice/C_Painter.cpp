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
  int n, l, r, c, idx;
  vi neutro = {0, 0, 0, 0};
  ii neutrop = {0, -1};
  vector<vi> t;
  vector<ii> lazy;
  stree(int n): n(n), t(n << 2, vi(5, 0)), lazy(n << 2, neutrop){}
  inline vi oper(vi& a, vi& b, int tl, int tr){
    vi ans(4);
    ans[0] = a[0] + b[0];
    ans[1] = a[1] + b[1] - (a[3] == 1 && a[3] == b[2]);
    ans[2] = a[2];
    ans[3] = b[3];
    return ans;
  }
  inline void updNode(int v, int tl, int tr, ii op){
    int col = op.fi;
    if(lazy[v].se >= op.se)return;
    lazy[v] = op;
    t[v][0] = col ? (tr - tl + 1) : 0;
    t[v][1] = col;
    t[v][2] = col;
    t[v][3] = col;
    t[v][4] = col;
  }
  inline void push(int v, int tl, int tr){
    if(lazy[v] == neutrop)return;
    int tm = (tl + tr) >> 1;
    updNode(v << 1, tl, tm, lazy[v]);
    updNode((v << 1) | 1, tm + 1, tr, lazy[v]);
    lazy[v] = neutrop;
  }
  void upd(int v, int tl, int tr){
    if(tl > r || tr < l) return;
    if(l <= tl && tr <= r){
      updNode(v, tl, tr, {c, idx});
      return ;
    }
    push(v, tl, tr);  int tm = (tl + tr) >> 1;
    upd(v << 1, tl, tm);  upd((v << 1) | 1, tm+1, tr);
    t[v] = oper(t[v << 1], t[(v << 1) | 1], tl, tr);
  }
  void update(int ql, int qr, int qc, int qidx){  
    l = ql, r = qr, c = qc, idx = qidx, upd(1, 0, n-1); }
  vi query(){ l = 0, r = n - 1;  return t[1]; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n;
    cin >> n;
    stree st(1e6 + 200);
    forn(i, n){
        char c;
        cin >> c;
        int col;
        if(c == 'B')col = 1;
        else col = 0;
        int l, r;
        cin >> l >> r;
        l += 5e5;
        r = l + r - 1;
        st.update(l, r, col, i);
        vi ans = st.query();
        cout << ans[1] << ' ' << ans[0] << el;
    }
}
