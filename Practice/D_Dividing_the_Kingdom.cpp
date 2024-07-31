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
typedef array<int, 3> a3;

const int inf = 1e9;
const int nax = 5e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int n, m;
vector<ii> g[nax];
int color[nax];

bool dfs(int u, int c, int& mid){
    color[u] = c;
    for(auto& [w, v] : g[u]){
        if(w < mid)break;
        if(color[v] == -1){
            if(!dfs(v, !c, mid))return false;
            continue;
        }
        if(color[u] == color[v])return false;
    }
    return true;
}

bool bipartite(int mid){
    forn(i, n)color[i] = -1;
    forn(i, n){
        if(color[i] == -1){
            if(!dfs(i, 0, mid))return false;
        }
    }
    return true;
}

bool different(vector<ii>& vec){
    int n = sz(vec);
    // d(n);
    for1(i, n - 1){
        if(!(
                vec[0].fi == vec[i].fi || vec[0].fi == vec[i].se ||
                vec[0].se == vec[i].fi || vec[0].se == vec[i].se
        )){
            return true;
        }
    }
    fore(i, 2, n - 1){
        if(!(
                vec[1].fi == vec[i].fi || vec[1].fi == vec[i].se ||
                vec[1].se == vec[i].fi || vec[1].se == vec[i].se
        )){
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    cin >> n >> m;
    map<int, vector<ii>> edges;
    forn(i, m){
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        edges[w].pb({min(u, v), max(u, v)});
        g[u].pb({w, v});
        g[v].pb({w, u});
    }
    forn(u, n)sort(all(g[u]), greater<ii>());
    int l = -1, r = 1e9 + 1;
    while(l + 1 < r){
        int mid = l + (r - l) / 2;
        if(bipartite(mid)){
            r = mid;
        }else{
            l = mid;
        }
    }
    int mn = l;
    auto it = edges.lower_bound(mn);
    vi ans;
    if(mn <= 0)ans.pb(0);
    for(; it != edges.end(); it++){
        auto& [key, vec] = (*it);
        if(key == 0)continue;
        if(different(vec))ans.pb(key);
    }
    if(sz(ans) == 0){
        cout << "IMPOSSIBLE" << el;
        return 0;
    }
    for(int& v : ans)cout << v << el;

}