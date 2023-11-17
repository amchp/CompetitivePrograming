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
  int n, l, r, pos, idx, val, neutro = 0; vector<ii> t;
  stree(int n): n(n), t(n << 2, {0, 0}){}
  inline void push(int v){
    if(t[v].fi > t[v << 1].fi)t[v << 1] = t[v];
    if(t[v].fi > t[(v << 1) | 1].fi)t[(v << 1) | 1] = t[v];
  }
  void upd(int v, int tl, int tr){
    if(tl > r || tr < l) return;
    if(l <= tl && tr <= r){
      t[v] = {idx, val};
      return ;
    }
    push(v);  int tm = (tl + tr) >> 1;
    upd(v << 1, tl, tm);  upd((v << 1) | 1, tm+1, tr);
  }
  int query(int v, int tl, int tr){
    if(tl == tr) return t[v].se;
    push(v);  int tm = (tl + tr) >> 1;
    if(pos <= tm)return query(v << 1, tl, tm);
    else return query((v << 1) | 1, tm + 1, tr);
  }
  void update(int ql, int qr, int qval, int qidx){  
    l = ql, r = qr, val = qval, idx = qidx, upd(1, 0, n-1); }
  int query(int qpos){ pos = qpos;  return query(1, 0, n-1); }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n, m;
    cin >> n >> m;
    stree st(n);
    for1(i, m){
        int op;
        cin >> op;
        if(op == 1){
            int l, r, val;
            cin >> l >> r >> val;
            r--;
            st.update(l, r, val, i);
        }else{
            int pos;
            cin >> pos;
            cout << st.query(pos) << el;
        }
    }
}
