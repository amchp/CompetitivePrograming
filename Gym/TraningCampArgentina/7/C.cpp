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


typedef long long ll;
typedef vector<int> vi;

typedef pair<ll,ll> ii;

const int nax = 2e6 +200;
vector<ii> g[nax], gr[nax], cond[nax];
ll val[nax];

int N;
int low[nax],num[nax],scc[nax];
vector<bool> truth;
int comp, timer;
stack<int> st;
void tjn(int u) {
  low[u] = num[u] = timer++; st.push(u); int v;
  for(ii v: g[u]) {
    if(num[v.fi]==-1) tjn(v.fi);
    if(scc[v.fi]==-1) low[u] = min(low[u], low[v.fi]);
  }
  if(low[u]==num[u]) {
    do{ v = st.top(); st.pop(); scc[v]=comp;
    }while(u != v);
    ++comp;
  }
}
ll tri[20001];
ll prefTri[20001];
ll f(ll w){
    if(w <= 1) return w;
    int raiz = 1;
    ll val = 1LL + w * 8LL;
    while((1LL*(raiz+1)) * (1LL*(raiz+1)) <=val){
        raiz++;
    }
    int ind = (raiz-1)/2;
    ll ret =  1LL*w * (1LL*(ind+1)) - prefTri[ind];
    return ret;
}

ll go(int u,int p, ll w){
    ll mx = 0;
    for(ii v : cond[u]){
        if(v.fi != p){
            mx = max(go(v.fi,u,v.se), mx);
        }
    }
    return w + mx + val[u];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cout << setprecision(20);

    memset(val,0,sizeof(val));
    memset(scc,-1,sizeof(scc));
    memset(num,-1,sizeof(num));
    tri[0] = 0;
    for1(i, 20000){
        tri[i] += i + tri[i - 1];
    }
    // d(tri.size());
    // forn(i,10)cout<<tri[i]<<" ";
    // cout<<el;
    forn(i,20001){
        prefTri[i]+= tri[i] + (i>0 ? prefTri[i-1] : 0);
    }
    // d(prefTri.size());
    // d(prefTri.back());
    // for1(i,10){
    //     d(f(i));
    // }
    int n,m;cin>>n>>m;
    forn(i,m){
        int x,y,w;
        cin>>x>>y>>w;
        x--,y--;
        g[x].pb({y,w}),gr[y].pb({x,w});
    }
    forn(i,n){
        if(num[i]==-1)
            tjn(i);
    }
    forn(i,n){
        for(ii v : g[i]){
            if(scc[i] == scc[v.fi])
                val[scc[i]] += 1LL*f(v.se);
        }
    }
    // fore(i,n,amount){
    //     d(val[i]);
    // }
    forn(i,n){
        for(ii v : g[i]){
            if(scc[v.fi] != scc[i]){
                cond[scc[i]].pb({scc[v.fi],v.se});
            }
        }
    }
    int szs;
    cin>>szs;
    szs--;
    szs = scc[szs];
    ll ans = go(szs,-1,0);
    cout<<ans<<el;
}