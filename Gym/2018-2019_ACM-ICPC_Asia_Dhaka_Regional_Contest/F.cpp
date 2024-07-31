#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < n; ++i)
#define fored(i, l, r) for(int i = r; i >= l; --i)
#define for1(i, n) for(int i = 1; i <= n; ++i)
#define el '\n'
#define pb push_back
#define sz(a) (int) a.size()
#define all(x) x.begin(), x.end()
#define db(x) cerr<<#x<<" "<<x<<el
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef array<int,2> v2;

const int mod = 1e9 + 7;
const int nax = 1e6, L = 21;

vi g[nax];
int out[nax], in[nax], up[nax][L+1], d[nax], t = 0;

void dfs(int u, int p, int h = 0){
    up[u][0] = p;
    d[u] = h;
    for1(i, L) up[u][i] = up[up[u][i-1]][i-1];
    in[u] = t++;
    for(int v : g[u]) if(v != p) dfs(v, u, h+1);
    out[u] = t;
}
bool isanc(int a,int b){
    return in[a] <= in[b] && out[a] >= out[b];
}
int lca(int a, int b){
    if(isanc(b,a))return b;
    if(isanc(a,b))return a;
    fored(i,0, L){
        if(!isanc(up[a][i], b)){
            a = up[a][i];
        }
    }
    return up[a][0];
}
int dist(v2 x){
    int a = x[0], b = x[1];
    if(isanc(b,a))swap(a,b);
    if(isanc(a,b)){
        return d[b] - d[a] + 1;
    }
    int lc = lca(a,b);
    return d[a] - 2*d[lc] + d[b] + 1;// agregar el lca
}

v2 inter(v2 a, v2 b){
    vi inters;
    if(d[lca(a[0], a[1])] < d[lca(b[0], b[1])]) swap(a,b);
    int lc = lca(a[0], a[1]);
    bool can = 0;
    int node = -1;
    forn(i,2){
        bool cur = 0;
        forn(j,2){
            int curlc = lca(a[i], b[j]);
            if(d[curlc] > d[lc]) inters.pb(curlc);
            cur = cur || (curlc == lc);
            if(curlc == lc) node = lc;
        }
        can = cur || can;
    }
    if(sz(inters) == 1){
        inters.pb(lc);
    }else if(inters.empty()){
        if(can) return {node, node};
        return {-1,-1};
    }
    return {inters[0], inters[1]};
}
void solve(int cas){
    int n;
    cin>>n;
    forn(i,n) g[i].clear();t = 0;
    forn(i,n-1){
        int u,v;
        cin>>u>>v;
        --u,--v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0, 0);
    int q;cin>>q;
    cout<<"Case "<<cas<<": "<<el;
    while(q--){
        int k;cin>>k;
        v2 pa;
        cin>>pa[0]>>pa[1];
        --pa[0], --pa[1];
        forn(_, k-1){
            v2 pv;
            cin>>pv[0]>>pv[1];
            --pv[0], --pv[1];
            if(pa != v2{-1,-1})
                pa = inter(pa, pv);
        }
        if(pa == v2{-1,-1}){
            cout<<0<<el;
        }else{
            cout<<dist(pa)<<el;
        }
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int id = 1;
    int tt;cin>>tt;
    while(tt--){
        solve(id++);
    }
}