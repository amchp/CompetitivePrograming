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
  int n, l, r, neutro = 0, idx;
  vi t;
  vi lazy;
  stree(int n): n(n), t(n << 2), lazy(n << 2){}
  inline int oper(int a, int b){ return a + b; }
  inline void updNode(int v, int tl, int tr, int nval){
    if(nval){
        t[v] = (tr - tl + 1) - t[v];
        lazy[v] ^= 1;
    }
  }
  inline void push(int v, int tl, int tr){
    int tm = (tl + tr) >> 1;
    if(lazy[v]){
      updNode(v << 1, tl, tm, lazy[v]);
      updNode((v << 1) | 1, tm + 1, tr, lazy[v]);
      lazy[v] = 0;
    }
  }
  void upd(int v, int tl, int tr){
    if(tl > r || tr < l) return;
    if(l <= tl && tr <= r){
      updNode(v, tl, tr, 1);
      return ;
    }
    push(v, tl, tr);  int tm = (tl + tr) >> 1;
    upd(v << 1, tl, tm);  upd((v << 1) | 1, tm+1, tr);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  int query(int v, int tl, int tr){
    if(tl == tr)return tl;
    push(v, tl, tr);  int tm = (tl + tr) >> 1;
    if(idx < t[v << 1]){
        return query(v << 1, tl, tm);
    }else{
        idx -= t[v << 1];
        return query((v << 1) | 1, tm + 1, tr);
    }
  }
  void update(int ql, int qr){  
    l = ql, r = qr, upd(1, 0, n-1); }
  int query(int qidx){ idx = qidx; return query(1, 0, n-1); }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n, m;
    cin >> n >> m;
    stree st(n);
    while(m--){
        int op, l;
        cin >> op >> l;
        if(op == 1){
            int r;
            cin >> r;
            r--;
            st.update(l, r);
        }else{
            cout << st.query(l) << el;
        }
    }
}
