#include<bits/stdc++.h>

#define el '\n'
#define db(x) cerr << #x << ' ' << x << el
#define forn(i,n) for(int i= 0; i < (int)n;++i)
#define pb push_back
#define sz(a) (int) a.size()
#define all(a) a.begin(), a.end()
using namespace std;
typedef vector<int> vi;
typedef long long ll;
const int nax = 2e5;

const ll inf = 1e18;

struct edge{
    int to, rev; ll cap, f{0};
    edge(int to, int rev, ll cap):to(to), rev(rev), cap(cap){}

};
struct Dinic{
    int n,s,t;ll max_flow = 0;
    vector<vector<edge>> g;
    vi q, dis, work;

    Dinic(int n):n(n),g(n), q(n){}
    Dinic(int n, int s, int t):n(n), s(s), t(t), g(n), q(n){}

    void addEdge(int s,int t, ll cap){
        g[s].pb(edge(t,sz(g[t]), cap));
        g[t].pb(edge(s,sz(g[s])-1, 0));
    }

    bool bfs(){
        dis.assign(n, -1), dis[s] = 0;
        int qt=  0;
        q[qt++] = s;
        forn(qh, qt){
            int u = q[qh];
            for(auto &[v, _, cap, f]: g[u])
                if(dis[v] < 0 && f<cap) dis[v] = dis[u]+1, q[qt++]=v;
            
        }
        return dis[t]>=0;
    }

    ll dfs(int u, ll cur){
        if(u==t)return cur;
        for(int &i = work[u]; i<sz(g[u]);++i){
            auto &[v, rev, cap, f] = g[u][i];
            if(cap<=f)continue;
            if(dis[v] == dis[u]+1){
                ll df = dfs(v,min(cur,cap-f));
                if(df>0){
                    f+=df, g[v][rev].f-=df;
                    return df;
                }
            }
        }
        return 0;
    }
    ll maxFlow(){
        ll cur_flow = 0;
        while(bfs()){
            work.assign(n, 0);
            while(ll delta = dfs(s, inf)) cur_flow += delta;

        }
        max_flow += cur_flow;
        return max_flow;
    }


};
typedef pair<int,int> ii;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    map<ll,vector<ii>> edges;
    forn(i,m){
        int u,v, w;
        cin>>u>>v>>w;
        --u,--v;
        edges[w].pb({u,v});
    }
    Dinic prevfl(n+1);
    int ans = 0;
    for(auto [_, li] : edges){
        for(auto [a,b] : li){
            Dinic fl = prevfl;
            fl.s = a, fl.t = b;
            ans += fl.maxFlow();
        }
        for(auto [a,b] : li){
            prevfl.addEdge(a,b, 1);
            prevfl.addEdge(b,a, 1);
        }
    }
    cout<<ans<<el;
}