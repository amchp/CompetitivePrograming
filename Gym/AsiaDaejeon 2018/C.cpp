#include<bits/stdc++.h>

#define el '\n'
#define db(x) cerr << #x << ' ' << x << el
#define forn(i,n) for(int i= 0; i < (int)n;++i)
#define pb push_back
#define sz(a) (int) a.size()
#define all(a) a.begin(), a.end()
using namespace std;
typedef vector<int> vi;

const int nax = 2e5;
vi g[nax];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    forn(i,m){
        int u,v;
        cin>>u>>v;
        g[u].pb(v), g[v].pb(u);
    }
    vector<vi> pot(n);
    vi dp(n, 1);
    forn(i,n){
        pot[sz(g[i])].pb(i);
    }

    forn(i, n){
        if(pot[i].empty())continue;
        for(int u : pot[i]){
            for(int v : g[u]){
                if(sz(g[v]) > sz(g[u])){
                    dp[v] = max(dp[u] + 1, dp[v]);
                }
            }
        }
    }
    cout<<*max_element(all(dp))<<el;

}