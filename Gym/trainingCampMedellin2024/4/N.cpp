#include<bits/stdc++.h>


using namespace std;

#define forn(i,n) for(int i = 0; i< n;++i)
#define fore(i,l, r) for(int i = l ; i<= r;++i)
#define for1(i,n) for(int i = 1; i <= n;++i)
#define all(a) a.begin(), a.end()
#define db(x) cerr<<#x<<" "<<x<<el
#define pb push_back
#define el '\n'
typedef double ld;
typedef long long ll;
typedef array<int,2> v2;
typedef array<int,27> v27;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
const int nax = 152;


vector<ii> g[nax];
ll dist[nax][nax];
const ll inf = 1e17;
vi nodes[nax];
void bellman_ford(int s, int n){
    forn(i,n) dist[s][i] = inf;
    dist[s][s] = 0;
    forn(_,n-1){
        forn(u,n){
            for(auto& [w, v]:g[u]){
                if(dist[s][u] + w < dist[s][v] ) dist[s][v] = dist[s][u] + w;
            }
        }
    }
    forn(u,n) {
        if(dist[s][u] == inf) continue;
        for(auto& [w, v]:g[u]){
            if(dist[s][u] + w < dist[s][v]) nodes[s].pb(v);
        }
    }
}
// Complejidad O(n^
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.precision(20);
    int n,m,q;
    cin>>n>>m>>q;
    while(n && m && q){
        forn(i,m){
            int u,v,w;
            cin>>u>>v>>w;
            g[u].pb({w,v});
        }
        forn(i,n) bellman_ford(i,n);
        forn(i,q){
            int u,v;cin>>u>>v;

            ll ans = dist[u][v];
            // db(ans);
            bool cycle = 0;
            for(int node : nodes[u]){
                if(dist[node][v] < inf) cycle = 1;
            }
            if(cycle){
                cout<<"-Infinity"<<el;
            }else if(ans == inf){
                cout<<"Impossible"<<el;
            }else{
                cout<<ans<<el;
            }
        }

        forn(i,n) {
            g[i].clear(), nodes[i].clear();

        }
        cout<<el;
        cin>>n>>m>>q;
    }
}