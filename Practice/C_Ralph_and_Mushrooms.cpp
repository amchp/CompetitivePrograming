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
#define d(x) cout<< #x<< " " << x<<el
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
const int nax = 1e6+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

vector<ii> g[nax], gr[nax], gcc[nax];
vi ts;
bool seen[nax];
int scc[nax], comp;
ll sa[nax];

ll smr(ll n){
    return n*(n + 1)/2;
}

ll smr2(ll n){
    return n*(n + 1)*(2*n + 1)/6;
}

ll score(ll x){
    ll n = (-1 + floor(sqrt(1+4*2*x)))/2 + 1;
    return x*n - (n*smr(n - 1) - smr2(n - 1));
}

void dfs1(int u){
  seen[u] = 1;
  for(auto& [v, w]: g[u]) if(!seen[v]) dfs1(v);
  ts.pb(u);
}
void dfs2(int u){
  scc[u] = comp;
  for(auto& [v, w] : gr[u]){
    if(scc[v] == -1){
        dfs2(v);
    }
  }
}
int find_scc(int n){ //TENER CREADO EL GRAFO REVERSADO gr
  forn(i, n) if(!seen[i]) dfs1(i);
  reverse(all(ts));
  memset(scc, -1, sizeof scc);
  comp = 0;
  for(int u: ts){
    if(scc[u] == -1){
        dfs2(u), ++comp;
    }
  }
  return comp;
}

ll dp[nax];

ll sol(int u){
    ll& ans = dp[u];
    if(ans != -1)return ans;
    ans = 0;
    for(auto& [v, w] : gcc[u]){
        ans = max(ans, sol(v) + w);
    }
    ans += sa[u];
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int n, m;
    cin >> n >> m;
    forn(i, m){
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        g[u].pb({v, w});
        gr[v].pb({u, w});
    }
    int sn = find_scc(n);
    forn(u, n){
        for(auto& [v, w] : g[u]){
            if(scc[u] == scc[v]){
                sa[scc[u]] += score(w);
                continue;
            }
            gcc[scc[u]].pb({scc[v], w});
        }
    }
    forn(u, sn){
        dp[u] = -1;
    }
    int st;
    cin >> st;
    --st;
    st = scc[st];
    // d(score(1));
    cout << sol(st) << el;
}