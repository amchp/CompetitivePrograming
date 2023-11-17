#include <algorithm>
#include <array>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream> // istringstream buffer(myString);
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>


using namespace std;

#define for1(i, n) for(int i = 1; i <= (int)n; ++i)
#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define fore(i,l,r) for(int i = (int)l; i <= (int)r; ++i)
#define sz(a) (int) a.size()
#define el '\n'
#define pb push_back
#define fi first
#define se second

#define all(a) a.begin(),a.end()
#define RAYA cerr << "===============\n";
#define d(x) cerr<< #x << "  "<<x<<el;
#define neutro 0
typedef long long ll;
typedef vector<int> vi;

typedef pair<ll,ll> ii;

struct node{
  int sum, l, r;
}; 
const int nax = 2e5+100;
struct stree{
  vector<int> rts;
  vector<node> t;
  int n, idx;
  inline int oper(int a, int b){ return min(a,b); }
  int build(int tl, int tr, vector<int> &a){
    int v = idx++;
    if(tl==tr){
      t[v].sum = a[tl]; return v;
    }
    int tm = (tl+tr)/2;
    t[v].l = build(tl, tm, a);
    t[v].r = build(tm+1, tr, a);
    t[v].sum = t[t[v].l].sum + t[t[v].r].sum;
    return v;
  }
  stree(vector<int> &a){
    n = sz(a);
    t.resize(nax);
    idx = 0;
    rts.pb(0);
    build(0, n-1, a);
  }
  int query(int v, int tl, int tr, int l, int r){
    if(tl>r || tr<l) return neutro;
    if(l<=tl && tr<= r){
      return t[v].sum;
    }
    int tm = (tl+tr)/2;
    return oper(query(t[v].l, tl, tm, l, r), query(t[v].r, tm+1, tr, l, r));
  }
  int query(int a, int b, int tl, int tr, int l, int r){
    if(tl>r || tr<l) return neutro;
    if(l<=tl && tr<= r){
      return t[v].sum;
    }
    int tm = (tl+tr)/2;
    return oper(query(t[v].l, tl, tm, l, r), query(t[v].r, tm+1, tr, l, r));
  }
  int upd(int prev, int tl, int tr, int pos, int val){
    int v = idx++; t[v] = t[prev];
    if(tl==tr){
      t[v].sum = val; return v;
    }
    int tm = (tl+tr)/2;
    if(pos<=tm) t[v].l = upd(t[v].l, tl, tm, pos, val);
    else t[v].r = upd(t[v].r, tm+1, tr, pos, val);

    t[v].sum = t[t[v].l].sum + t[t[v].r].sum;
    return v;
  }
  int upd2(int v, int tl, int tr, int pos, int val){
    if(tl==tr){
      t[v].sum = val; return v;
    }
    int tm = (tl+tr)/2;
    if(pos<=tm) t[v].l = upd2(t[v].l, tl, tm, pos, val);
    else t[v].r = upd2(t[v].r, tm+1, tr, pos, val);

    t[v].sum = t[t[v].l].sum + t[t[v].r].sum;
    return v;
  }
  int query(int v, int l, int r){
    return query(v, 0, n-1, l, r);
  }
  int query(int a, int b, int l, int r){
    return query(rtsa,b, 0, n-1, l, r);
  }

  void upd(int pos, int val, int version){
    if(version == rts.size()){
        upd(pos,val);
    }
    else{
        int id = upd2(rts[version], 0, n-1, pos, val);
    }
  }
  void upd(int pos, int val){
    int id = upd(rts.back(), 0, n-1, pos, val);
    rts.pb(id);
  }
};
vi g[nax];
int in[nax],out[nax];
int height[nax];
int timer = 0;
void dfs(int u, int p){
    in[u] = timer++;

    for(int v : g[u]){
        if(v != p){
            dfs(v,u);
        }
    }
    out[u] = timer;
}
int main(){
    memset(height,0,sizeof(height));
    int n,r;
    cin>>n>>r;
    r--;
    vi val(n);
    forn(i,n){
        cin>>val[i];
    }
    vi frec(n);

    frec[0] = val[0];

    forn(i,n-1){
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v),g[v].pb(u);
    }
    dfs(r,-1);
    vi a;
    queue<ii> q;
    int altura = 1;
    q.push({r,-1});
    stree st(frec);
    while(!q.empty()){
        int w = q.size();
        while(w--){
            ii curr =q.front();q.pop();
            for(int v : g[curr.fi]){
                if(v != curr.se){
                    height[v] = altura;
                    st.upd(curr.fi,val[curr.fi],altura);//pos,val,version
                    q.push({v,curr.fi});
                }
            }
        }
        altura++;
    }
    int m;
    cin>>m;
    forn(i,m){
        int x,di;
        cin>>x>>di;
        x--;
        int l = in[x], r = out[x];
        int li = height[x], ri  = li + di -1;
        if(li == 0){
            int ans = st.query(ri,l,r);
            cout<<ans<<el;
        }else{
            int ans = st.query(li,ri,l,r);
            cout<<ans<<el;

        }

    }
}