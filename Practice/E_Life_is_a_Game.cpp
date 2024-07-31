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
typedef array<ll, 3> a3;


const int inf = 1e9;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int p[nax];
set<pll> svs[nax];
ll ans[nax];
ll sm[nax];

int find(int u){
    if(u == p[u])return u;
    return p[u] = find(p[u]);
}

void merge(int u, int v, ll w){
    u = find(u);
    v = find(v);
    if(u == v)return;
    if(sz(svs[u]) < sz(svs[v]))swap(u, v);
    auto it = svs[u].begin();
    vector<pll> ers;
    while(it != svs[u].end() && (*it).fi + sm[u] < w){
        auto& [exp, ind] = (*it);
        ans[ind] = exp + sm[u];
        ers.pb((*it));
        ++it;
    }
    for(pll pr : ers){
        svs[u].erase(pr);
    }
    for(auto& [exp, ind] : svs[v]){
        if(exp + sm[v] < w){
            ans[ind] = exp + sm[v];
            continue;
        }
        svs[u].insert({exp, ind});
    }
    p[v] = u;
    sm[u] += sm[v];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int n, m, q;
    cin >> n >> m >> q;
    forn(i, n){
        p[i] = i;
        cin >> sm[i];
    }
    vector<a3> edgs(m);
    forn(i, m){
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        edgs[i] = {w, u, v};
    }
    forn(i, q){
        int u, x;
        cin >> u >> x;
        --u;
        svs[u].insert({x, i});
    }
    sort(all(edgs));
    for(auto& [w, u, v] : edgs){
        merge(u, v, w);
    }
    vector<bool> vis(n, false);
    forn(i, n){
        int u = find(i);
        if(vis[u])continue;
        vis[u] = true;
        for(auto& [exp, ind] : svs[u]){
            ans[ind] = exp + sm[u];
        }
    }
    forn(i, q){
        assert(ans[i]);
        cout << ans[i] << el;
    }
    cout << el;
}