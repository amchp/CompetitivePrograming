#include <bits/stdc++.h>

#define pb push_back
#define sz(x) x.size()
#define forn(i, n) for(int i = 0; i < n; ++i)
#define fore(i, l, r) for(int i = l; i <= r; ++i)
#define all(x) x.begin(), x.end()
#define el '\n'
#define db(x) cerr<<#x<<" "<<x<<el

using namespace std;

typedef long long ll;
typedef vector<int> vi;


const int inf = 1e9;
struct edge {
    int to, rev; int cap, f{0};
    edge(int to, int rev, int cap): to(to), rev(rev), cap(cap){}
};

struct Dinic{
    int n, s, t; int max_flow = 0;
    vector<vector<edge>> g;
    vi q, dis, work;
    Dinic(int n, int s, int t): n(n), s(s), t(t), g(n), q(n){}
    void addEdge(int s, int t, int cap){
        g[s].pb(edge(t, sz(g[t]), cap));
        g[t].pb(edge(s, sz(g[s]) - 1, 0));
    }

    bool bfs(){
        dis.assign(n, -1), dis[s] = 0;
        int qt = 0;
        q[qt++] = s;
        forn(qh, qt){
            int u = q[qh];
            for(auto& [v, _, cap, f] : g[u])
                if(dis[v] < 0 && f < cap) dis[v] = dis[u] + 1, q[qt++] = v;
        }
        return dis[t] >= 0;
    }

    int dfs(int u, int cur){
        if(u == t) return cur;
        for(int& i = work[u]; i < sz(g[u]); ++i){
            auto& [v, rev, cap, f] = g[u][i];
            if(cap <= f)continue;
            if(dis[v] == dis[u] + 1){
                int df = dfs(v, min(cur, cap - f));
                if(df > 0){
                    f += df, g[v][rev].f -= df;
                    return df;
                }
            }
        }
        return 0;
    }

    int maxFlow(){
        int cur_flow = 0;
        while(bfs()){
            work.assign(n, 0);
            while(int delta = dfs(s, inf))cur_flow += delta;
        }
        max_flow += cur_flow;
        return max_flow;
    }
};
typedef array<int, 3> v3;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<v3> edges(m);
    int s = n+n, t = s+1;
    for(auto &[w, u, v] : edges){
        cin>>u>>v>>w;
        --u,--v;
    }

    sort(all(edges));
    ll imp = edges.back()[0] + 1;
    ll l = -1, r = imp;
    while(l + 1 < r){
        ll mid = l + (r - l) / 2;
        Dinic flow(n+n+2, s, t);
        forn(i,n) flow.addEdge(s, i, 1);
        forn(i,n) flow.addEdge(i+n, t,  1);
        for(auto &[w, u, v] : edges){
            if(w > mid)break;
            flow.addEdge(u,v+n,1);
        }
        if(flow.maxFlow() >= n){
            r = mid;
        }else{
            l = mid;
        }
    }
    if(r == imp)cout << -1 << el;
    else cout << r << el;
}