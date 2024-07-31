#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < n; ++i)
#define el '\n'
#define db(x) cerr<<#x<<" "<<x<<el
#define pb push_back
#define sz(a) (int) a.size()
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
const int nax =2e5;
vi g[nax];

int cnt[nax], depth[nax], f[nax], dist[19][nax], closest[nax];

int dfs(int u, int dep= -1, bool flag = 0, int dis = 0, int p =-1){
    cnt[u] = 1;
    if(flag) dist[dep][u]=dis;
    for(int v : g[u]){
        if(!depth[v] && v!=p) cnt[u] += dfs(v, dep, flag, dis+1, u);
    }
    return cnt[u];
}

int get_centroid(int u, int r, int p = -1){
    for(int  v: g[u]){
        if(!depth[v] && v!=p && cnt[v] > r) return get_centroid(v, r, u);
    }
    return u;
}


int decompose( int u, int d = 1){
    int centroid = get_centroid(u,dfs(u) >> 1);
    depth[centroid] = d;
    // db(u);
    dfs(centroid, d, true);
    // db(u), db(centroid);

    for(int v : g[centroid]){
        if(!depth[v])
            f[decompose(v,d+1)] = centroid;
    }
    // db(u);
    // cout<<"==="<<el;
    return centroid;
}


int n, m;
int calc(int u){
    int ans = n, v;
    for(v = u; v != f[v]; v = f[v]){
        ans = min(ans, dist[depth[v]][u] + closest[v]);
    }
    ans = min(ans, dist[depth[v]][u] + closest[v]);
    return ans;
}
void paint(int u){
    int v;
    for(v = u; v != f[v]; v = f[v]){
        closest[v] = min(closest[v], dist[depth[v]][u]);
    }
    closest[v] = min(closest[v], dist[depth[v]][u]);
}
void sol(){
    cin>>n>>m;
    forn(i,n)closest[i] = n, g[i].clear();

    forn(i,n-1){
        int u,v;
        cin>>u>>v;
        --u,--v;
        g[u].pb(v);
        g[v].pb(u);
    }

    int centroid = decompose(0);
    f[centroid] = centroid;
    // forn(i,n) db(depth[i]), db(f[i]);
    paint(0);
    forn(_,m){
        int t,v;
        cin>>t>>v;
        --v;
        if(t == 1){
            paint(v);
        }else{
            cout<<calc(v)<<el;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        sol();
    }
}