#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for(int i = (int)l; i <= (int)r; ++i)
#define all(x) x.begin(), x.end()
#define el '\n'
#define sz(x) x.size()
#define fi first
#define se second
#define pb push_back
#define d(x) cerr << #x << ' ' << x << el;

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;

const int nax = 2e5 + 100;

struct node{
    int u, v, f;
    node(){}
    node(int u, int v, int f): u(u), v(v), f(f){}
};

vi g[nax];
vector<bool> vis(nax, false);
vector<node> ans;

bool dfs(int u){
    vis[u] = true;
    vi mc;
    for(int v: g[u]){
        if(vis[v])continue;
        if(!dfs(v))mc.pb(v);
    }
    int e = sz(mc) - (sz(mc)&1);
    for(int i = 0; i < e; i += 2){
        ans.pb(node(mc[i], mc[i + 1], u));
    }
    if(sz(mc) & 1)ans.pb(node(u, mc[sz(mc) - 1], -1));
    return sz(mc)&1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    n *=2;
    forn(i, m){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    bool pass = true;
    forn(i, n){
        if(vis[i])continue;
        bool cp = dfs(i);
        // d(i);
        // d(cp);
        pass &= cp;
    }
    if(pass){
        cout << "POSSIBLE" << el;
        for(node& nd : ans){
            cout << nd.u << ' ' << nd.v << ' ' << nd.f << el;
        }
        return 0;
    }
    cout << "IMPOSSIBLE" << el;
    return 0;
}