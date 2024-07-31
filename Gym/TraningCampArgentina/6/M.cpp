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

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define ford(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define all(v) v.begin(), v.end()
#define el '\n'

using namespace std;

typedef vector<int> vi;
typedef long long ll;


typedef pair<int, int> ii;

#define pb push_back
const int nax = 5e5;
int N;


vi g[nax], gr[nax], tr[nax], ts;
int scc[nax];
bool seen[nax];
void dfs1(int u){
  seen[u] = true;
  for (int v: g[u])
    if (!seen[v])
      dfs1(v);
  ts.pb(u);
}
void dfs(int u, int comp){
  scc[u] = comp;
  for (int v : gr[u])
    if (scc[v] == -1)
      dfs(v, comp);
}
// Retorna la cantidad de componentes
int find_scc(int n){
  //TENER CREADO EL GRAFO REVERSADO gr
  forn(i,n) if(!seen[i]) dfs1(i);
  reverse(all(ts));
  int comp = 0;
  for(int u: ts)
    if (scc[u] == -1) dfs(u, comp++);
  return comp;
}

ll val[nax];
int in[nax],out[nax];
int tim = 0;
const int L = 24;
int up[nax][L+1];
void dfs2(int u,int p){
    in[u] = tim++;
    up[u][0] = p;
    for1(i,L) up[u][i] = up[up[u][i-1]][i-1];
    for(int v: tr[u]){
        if(v != p){
            val[v] += val[u];
            dfs2(v,u);
        }
    }
    out[u] = tim;
}
bool anc(int u, int v){
  return in[u]<= in[v] && out[u]>= out[v];
}


int lca(int u, int v){
  if(anc(u,v)) return u;
  if(anc(v,u)) return v;
  for(int i= L; i>=0; --i){
    if(!anc(up[u][i],v))
      u = up[u][i];
  }
  return up[u][0];
}
void show(int u,int v){
    cout<<"( "<<u<<" -> "<<v<<")";
}
int main(){ 
    memset(seen,0,sizeof(seen));
    memset(scc,-1,sizeof(scc));
    
    int n,m;
    cin>>n>>m;
    forn(i,m){
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v),g[v].pb(u);
    }
    int amount = find_scc(n);
    int idx = n;
    unordered_map<int,int> cond;

    unordered_map<int,int> tam;
    forn(i,n){
        cout<<"csdfasdfs: "<<scc[i]<<el;
        // cout<<num[i]<<el;
        for(int v : g[i]){
            if(scc[v] != scc[i])
            {
                tr[v].pb(i);
            }else{
                tam[scc[i]]++;
            }
        }
        if(cond.find(scc[i]) == cond.end()){
            cond[scc[i]] = idx++;
        }
        tr[i].pb(cond[scc[i]]);
        tr[cond[scc[i]]].pb(i);
        show(i+1,cond[scc[i]]+1);
    }
    forn(i,n){
        val[cond[scc[i]]] = tam[scc[i]]/2;
    }
    int root = 0;

    // dfs2(root, root);
    // int q;
    // cin>>q;
    // forn(i,q)
    // {
    //     int u,v;
    //     cin>>u>>v;
    //     u--,v--;
    //     int lc = lca(u,v);
    //     lc = up[lc][0];
    //     cout<<lc<<el;
    //     int ans = val[u] + val[v] - val[lc] - 1;
    //     cout<<ans<<el;
    // }
}