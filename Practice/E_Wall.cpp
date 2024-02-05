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
const int nax = (int(2e6) << 2);
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

struct node{
  int time, x, change;
  node(): time(0), x(0), change(0){}
  node(int t, int xi, int c): time(t), x(xi), change(c){}
  bool operator<(node other){
    return time < other.time;
  }
  bool operator==(node other){
    return time == other.time;
  }
};

ii t[nax];
node lazyu[nax];
node lazyd[nax];

struct stree{
  int n, l, r, val, opr, idx, pos;
  ii neutro = {0, 0};
  node neutrou = node(-1, 0, 1);
  node neutrod = node(-1, inf, -1);
  stree(int n): n(n){
    forn(i, n << 2){
      t[i] = neutro;
      lazyu[i] = neutrou;
      lazyd[i] = neutrod;
    }
  }
  inline ii oper(ii& a, ii& b){
    ii ans;
    ans.fi = min(a.fi, b.fi);
    ans.se = max(a.se, b.se);
    return ans;
  }
  inline void updNode(int v, node& op, node& op2){
    int& mn = t[v].fi;
    int& mx = t[v].se;
    vector<node> vec = {lazyu[v], lazyd[v], op, op2};
    sort(all(vec));
    forn(i, sz(vec)){
      if(vec[i].change == 1){
        if(mn < vec[i].x){
          mn = vec[i].x;
          mx = max(mx, mn);
          lazyu[v] = vec[i]; 
        }
      }
      else{
        if(mx > vec[i].x){
          mx = vec[i].x;
          mn = min(mn, mx);
          lazyd[v] = vec[i];
        }
      }
    }
  }
  inline void push(int v){
    if(lazyu[v] == neutrou && lazyd[v] == neutrod)return;
    updNode(v << 1, lazyu[v], lazyd[v]);
    updNode((v << 1) | 1, lazyu[v], lazyd[v]);
    lazyu[v] = neutrou;
    lazyd[v] = neutrod;
  }
  void upd(int v, int tl, int tr){
    if(tl > r || tr < l) return;
    if(l <= tl && tr <= r){
      node vec = node(idx, val, opr);
      if(opr == 1)updNode(v, vec, neutrod);
      else updNode(v, neutrou, vec);
      return ;
    }
    push(v);  int tm = (tl + tr) >> 1;
    upd(v << 1, tl, tm);  upd((v << 1) | 1, tm+1, tr);
    t[v] = oper(t[v << 1], t[(v << 1) | 1]);
  }
  int query(int v, int tl, int tr){
    if(tl == tr){
      return t[v].fi;
    }
    push(v);  int tm = (tl + tr) >> 1;
    if(pos <= tm)return query(v << 1, tl, tm);
    else return query((v << 1) | 1, tm + 1, tr);
  }
  void update(int ql, int qr, int qop, int qval, int qidx){  
    l = ql, r = qr, opr = qop, val = qval, idx = qidx, upd(1, 0, n-1); }
  int query(int qpos){ pos = qpos; return query(1, 0, n-1); }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n, m;
    cin >> n >> m;
    stree st(n);
    forn(i, m){
      int op, l, r, val;
      cin >> op >> l >> r >> val;
      if(op == 1){
        st.update(l, r, op, val, i);
      }else{
        op = -1;
        st.update(l, r, op, val, i);
      }
    }
    forn(i, n){
      cout << st.query(i) << el;
    }
}
