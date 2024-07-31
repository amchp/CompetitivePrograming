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

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define ford(i, n) for (int i = (int)n-1; i >=0; --i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define all(v) v.begin(), v.end()
#define pb push_back
#define sz(a) (int) a.size()
#define mp make_pair
#define el "\n"

typedef pair<int, int> ii;
typedef vector<int> vi;
const int nax = 1e5 +10;
#define neutro 0
struct stree{
  int n;  vector<int> t;
  stree(int m){
    n = m;   t.resize(n<<2);
  }
  inline int oper(int a, int b){  return a+b; }
  int query(int v, int tl, int tr, int l, int r){
    if(tl>r || tr<l) return neutro;
    if(l<=tl && tr<=r) return t[v];
    int tm = (tl+tr)/2;
    return oper(query(v*2, tl, tm, l, r),
           query(v*2+1, tm+1, tr, l, r));
  }
  void upd(int v, int tl, int tr, int pos, int val){
    if(tl==tr){
      t[v] += val;  return ;
    }
    int tm = (tr+tl)/ 2;
    if(pos<= tm)  upd(v*2, tl, tm, pos, val);
    else  upd(v*2+1, tm+1, tr, pos, val);
    t[v] = oper(t[v*2], t[v*2+1]);
  }
  void upd(int pos, int val){ upd(1,0,n-1,pos,val); }
  int query(int l, int r){ return query(1,0,n-1,l,r); }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // cout << setprecision(20);
    int y,n;
    cin>>y>>n;
    vi v(y);
    forn(i,y){
        cin>>v[i];
    }
    vector<vector<ii>> queries(y);
    vi ans(n);
    forn(i,n){
        int ai,pi,fi;
        cin>>ai>>pi>>fi;
        ai--;
        if(!fi || v[ai] >= pi){
            ans[i] = 0;
        }else{
            queries[ai].pb(ii{pi,i});
            queries[ai+fi].pb(ii{pi,i});
        }
    }
    stree st(nax);
    vi dp(n,-1);
    ford(i,y){
        if(sz(queries[i])){
            for(ii ele: queries[i]){
                if(dp[ele.second] == -1){
                    dp[ele.second] = st.query(ele.first,nax-1);
                }else{
                    int curr = st.query(ele.first,nax-1) - dp[ele.second];
                    ans[ele.second] = curr;
                }
            }
        }
        st.upd(v[i],1);
    }
    forn(i,n)
    {
        cout<<ans[i]<<el;
    }
}