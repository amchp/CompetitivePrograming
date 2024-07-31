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

int cnt[nax], depth[nax], f[nax], dist[25][nax];

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


int decompose( int u, int d = 0){
    int centroid = get_centroid(u,dfs(u) >> 1);
    depth[centroid] = d;
    dfs(centroid, d);
    for(int v : g[centroid]){
        if(!depth[v])
            f[decompose(v,d+1)] = centroid;
    }
    return centroid;
}

void sol(){
    int n;
    cin>>n;
    forn(i,n-1){
        int u,v;
        cin>>u>>v;
        --u,--v;
        g[u].pb(v);
        g[v].pb(u);
    }

    decompose(0);
    // forn(i,n)db(depth[i]);
    forn(i,n)cout<<char('A' + depth[i]-1)<<" ";
    cout<<el;
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