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

ll val[nax];
int in[nax],out[nax];
int tim = 0;
const int L = 24;
int up[nax][L+1];
vector<int> g[nax],tr[nax];
int n,lw[nax],idx[nax],qidx,cmp[nax],qcmp;
stack<int> st;
void tjn(int u){
	lw[u]=idx[u]=++qidx;
	st.push(u);cmp[u]=-2;
	forn(i,g[u].size()){
		int v=g[u][i];
		if(!idx[v]||cmp[v]==-2){
			if(!idx[v]) tjn(v);
			lw[u]=min(lw[u],lw[v]);
		}
	}
	if(lw[u]==idx[u]){
		int x;
		do{x=st.top();st.pop();cmp[x]=qcmp;}while(x!=u);
//		truth[qcmp]=(cmp[neg(u)]<0); // (2SAT)
		qcmp++;
	}
}
void scc(){
	memset(idx,0,sizeof(idx));qidx=0;
	memset(cmp,-1,sizeof(cmp));qcmp=0;
	forn(i,n)if(!idx[i])tjn(i);
}


void dfs(int u,int p){
    in[u] = tim++;
    up[u][0] = p;
    for1(i,L) up[u][i] = up[up[u][i-1]][i-1];
    for(int v: tr[u]){
        if(v != p){
            val[v] += val[u];
            dfs(v,u);
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
    int m;
    cin>>n>>m;
    forn(i,m){
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v),g[v].pb(u);
    }
    scc();
    int idx = n;
    unordered_map<int,int> cond;

    unordered_map<int,int> tam;
    forn(i,n){
        cout<<"csdfasdfs: "<<cmp[i]<<el;
        for(int v : g[i]){
            if(cmp[v] != cmp[i])
            {
                tr[v].pb(i);
            }else{
                tam[cmp[i]]++;
            }
        }
        if(cond.find(cmp[i]) == cond.end()){
            cond[cmp[i]] = idx++;
        }
        tr[i].pb(cond[cmp[i]]);
        tr[cond[cmp[i]]].pb(i);
        show(i+1,cond[cmp[i]]+1);
    }
    forn(i,n){
        val[cond[cmp[i]]] = tam[cmp[i]]/2;
    }
    int root = 0;

    dfs(root, root);
    int q;
    cin>>q;
    forn(i,q)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        int lc = lca(u,v);
        lc = up[lc][0];
        cout<<lc<<el;
        int ans = val[u] + val[v] - val[lc] - 1;
        cout<<ans<<el;
    }
}