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
int ans = 0;
void dfs(int u, int &a, int p = -1, int h = 0){
    if(h > ans) a = u, ans = h;

    for(int v : g[u]) if(v!=p)dfs(v, a, u, h+1);

}

vi path;

bool dfs3(int u,int &b, int p = -1){
    db(u);
    bool cur = u == b;
    for(int v: g[u]){
        if(v != p) {
            bool szs = dfs3(v, b, u);
            if(szs) path.pb(v);
            cur |= szs;
        }
    }
    return cur;
}

char c[nax];
void dfs2(int u, int p = -1, int h =0){
    c[u] = 'A' + h;
    for(int v : g[u]) if(v!=p)dfs2(v, u, h+1);

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
    int start = 0;
    dfs(start, start);
    int a = start;
    dfs(start, start);
    int b = start;
    if((ans + 2) / 2 > 26){
        cout<<"Impossible"<<el;
        return;
    }

    int p = a;
    path = vi();
    db(a),db(b);
    dfs3(a, b);
    path.pb(a);
    dfs2(path[sz(path) / 2]);

    forn(i,n)cout<<c[i]<<" ";cout<<el;
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