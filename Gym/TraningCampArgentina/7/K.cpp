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

#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define sz(a) (int) a.size()
#define el '\n'
#define pb push_back
#define all(a) a.begin(),a.end()
#define RAYA cerr << "===============\n";
#define d(x) cerr<< #x << "  "<<x<<el;

typedef unsigned long long ll;
typedef vector<ll> vi;

#define neutro 0
struct stree{
  int n;  vector<ll> t;
  stree(int m){
    n = m;   t.resize(n<<2);
  }

  inline ll oper(ll a, ll b){  return a+b; }
  ll query(int v, int tl, int tr, int l, int r){
    if(tl>r || tr<l) return neutro;
    if(l<=tl && tr<=r) return t[v];
    int tm = (tl+tr)/2;
    return oper(query(v*2, tl, tm, l, r),
           query(v*2+1, tm+1, tr, l, r));
  }
  void upd(int v, int tl, int tr, int pos, ll val){
    if(tl==tr){
      t[v] += val;  return ;
    }
    int tm = (tr+tl)/ 2;
    if(pos<= tm)  upd(v*2, tl, tm, pos, val);
    else  upd(v*2+1, tm+1, tr, pos, val);
    t[v] = oper(t[v*2], t[v*2+1]);
  }
  void upd(int pos, ll val){ upd(1,0,n-1,pos,val); }
  ll query(int l, int r){ return query(1,0,n-1,l,r); }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n,k;
    cin>>n>>k;
    vi v(n);
    forn(i,n)cin>>v[i];
    if(k == 0){
        cout<<n<<el;
    }else{
        vector<stree> st(k+1,stree(n+2));
        ll ans = 0;
        forn(i,n){
            ll szs = st[k].query(0,v[i]-1);
            ans = ans + szs;
            for (int j = 2; j <= k; j++)
            {
                ll lessthan = st[j-1].query(0,v[i]-1);
                st[j].upd(v[i],lessthan);
            }
            st[1].upd(v[i], 1LL);
            }
            cout<<ans<<el;

    }
    }

