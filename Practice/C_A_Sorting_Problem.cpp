#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string.h>
#include <math.h>
#include <queue>
#include <set>
#include <assert.h>
#include <map>
#include <numeric>
#include <climits>
#include <cstring>
#include <tuple>

#define forn(i,n) for(int i = 0; i < (int)n;++i)
#define for1(i,n) for(int i = 1; i <= (int)n;++i)
#define fore(i, l, r) for(int i = (int)l; i <= (int)r;++i)
#define all(a) a.begin(),a.end()
#define el '\n'
#define sz(a) (int)a.size()
#define d(x) cout << #x << ' ' << x << el

using namespace std;

typedef vector<int> vi;
typedef long double ld;
typedef long long  ll;

struct stree{
  int n, neutro = 0;  vi t;
  stree(int n): n(n), t(n<<2){}
  stree(vi a): n(sz(a)), t(n<<2){ build(1, 0, n-1, a); }
  inline int oper(int a, int b){ return a + b; }
  void build(int v, int tl, int tr, vi& a){// solo para el 2. constructor
    if(tl == tr){ t[v]= a[tl];  return; }
    int tm = (tr+tl)/ 2;
    build(v*2, tl, tm, a);
    build(v*2+1, tm+1, tr, a);
    t[v] = oper(t[v*2], t[v*2+1]);
  }
  int query(int v, int tl, int tr, int l, int r){
    if(tl > r || tr < l) return neutro;  // estoy fuera
    if(l <= tl && tr <= r) return t[v];
    int tm = (tl+tr)/2;
    return oper(query(v*2, tl, tm, l, r), query(v*2+1, tm+1, tr, l, r));
  }
  void upd(int v, int tl, int tr, int pos, int val){
    if(tl==tr){ t[v] = val;  return; }
    int tm = (tr+tl)/ 2;
    if(pos<= tm) upd(v*2, tl, tm, pos, val);
    else upd(v*2+1, tm+1, tr, pos, val);
    t[v] = oper(t[v*2], t[v*2+1]);
  }
  void upd(int pos, int val){ upd(1, 0, n-1, pos, val);}
  int query(int l, int r){ return query(1, 0, n-1, l, r);}
};
int main(){
    int n;
    cin>>n;
    vi p(n);
    forn(i, n){
        p[i] = i + 1;
    }
    do{
        vi v(n + 1, 1);
        vi inv(n + 1);
        stree st(v);
        for1(i,n){
            v[i] = p[i - 1];
            inv[v[i]] = i;
        }
        // for1(i, n){
        //     cout << inv[i] << ' ';
        // }
        // cout << el;
        ll ans = 0;
        for1(i,n-1){
            int op = st.query(1, inv[i] - 1);
            // d(inv[i]);
            // d(op);
            ans += (ll)op;
            st.upd(inv[i], 0);
        }
        cout<<ans<<el;
    }while(next_permutation(all(p)));
}