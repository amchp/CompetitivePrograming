#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i,n) for(int i=0; i< (int)n; ++i)
#define for1(i,n) for(int i=1; i<= (int)n; ++i)
#define fore(i,l,r) for(int i=(int)l; i<= (int)r; ++i)
#define ford(i,n) for(int i=(int)(n) - 1; i>= 0; --i)
#define fored(i,l,r) for(int i=(int)r; i>= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cerr<< #x<< " " << x<<el
#define ri(n) scanf("%d",&n)
#define sz(v) int(v.size())
#define all(v) v.begin(),v.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<ld> vd;


const int inf = 1e9;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

vi g[nax], gr[nax], ts, gcc[nax], leaf;
vector<vi> roots;
int seen[nax];
int scc[nax], comp;
void dfs1(int u){
  seen[u] = 1;
  for(int v: g[u]) if(!seen[v]) dfs1(v);
  ts.pb(u);
}
void dfs2(int u){
  scc[u] = comp;
  for(int v : gr[u]) if(scc[v] == -1) dfs2(v);
}
int find_scc(int n){ //TENER CREADO EL GRAFO REVERSADO gr
  forn(i, n) if(!seen[i]) dfs1(i);
  reverse(all(ts));
  forn(i, n)scc[i] = -1;
  comp = 0;
  for(int u: ts) if(scc[u] == -1) dfs2(u), ++comp;
  return comp;
}

int dfs3(int u){
    for(int& v : gcc[u]){
        if(seen[v] == -1){
            return seen[u] = dfs3(v);
        }else{
            return seen[u] = seen[v];
        }
    }
    leaf.pb(u);
    return sz(leaf) - 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int n;
    cin >> n;
    forn(u, n){
        int v;
        cin >> v;
        --v;
        g[u].pb(v);
        gr[v].pb(u);
    }
    int sn = find_scc(n);
    if(sn == 1){
        cout << 0 << el;
        return 0;
    }
    vi in(sn);
    vi prt(sn, -1);
    forn(u, n){
        if(prt[scc[u]] == -1)prt[scc[u]] = u;
        for(int& v : g[u]){
            if(scc[u] == scc[v])continue;
            gcc[scc[u]].pb(scc[v]);
            ++in[scc[v]];
        }
    }
    forn(i, sn)seen[i] = -1;
    forn(u, sn){
        if(!in[u]){
            int cleaf = dfs3(u);
            // d(cleaf);
            if(cleaf == sz(roots)){
                roots.pb({u});
            }else{
                roots[cleaf].pb(u);
            }
        }
    }
    vector<ii> ans;
    forn(i, sz(leaf)){
        for(int& v : roots[(i + 1) % sz(leaf)]){
            ans.pb({leaf[i], v});
        }
    }
    cout << sz(ans) << el;
    for(auto& [u, v] : ans)cout << prt[u] + 1 << ' ' << prt[v] + 1<< el;
}