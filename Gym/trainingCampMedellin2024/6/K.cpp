#include <bits/stdc++.h>


#define pb push_back
#define sz(x) x.size()
#define forn(i, n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= n; ++i)
#define fore(i, l, r) for(int i = l; i <= r; ++i)
#define el '\n'
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define db(x) cerr << #x << ' ' << x << el;

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const ll inf = 1e18;
struct edge {
    int to, rev; ll cap, f{0};
    edge(int to, int rev, ll cap): to(to), rev(rev), cap(cap){}
};

struct Dinic{
    int n, s, t; ll max_flow = 0;
    vector<vector<edge>> g;
    vi q, dis, work;
    Dinic(int n, int s, int t): n(n), s(s), t(t), g(n), q(n){}
    void addEdge(int s, int t, ll cap){
        // db(s);
        // db(t);
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

    ll dfs(int u, ll cur){
        if(u == t) return cur;
        for(int& i = work[u]; i < sz(g[u]); ++i){
            auto& [v, rev, cap, f] = g[u][i];
            if(cap <= f)continue;
            if(dis[v] == dis[u] + 1){
                ll df = dfs(v, min(cur, cap - f));
                if(df > 0){
                    f += df, g[v][rev].f -= df;
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
            while(ll delta = dfs(s, inf))cur_flow += delta;
        }
        max_flow += cur_flow;
        return max_flow;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n), b(n);
    map<int, vi> mp;
    forn(i, n){
        cin >> a[i];
        mp[a[i]].pb(i);
    }
    forn(i, n)cin >> b[i];
    int mx = 100;
    vector<vi> fact(mx + 1);
    for1(i, mx){
        for(int j = 1; j*j <= i; ++j){
            if(i % j == 0){
                fact[i].pb(j);
                int k = i / j;
                if(j != k)fact[i].pb(k);
            }
        }
        sort(all(fact[i]));
    }

    int N = n + 2, s = N - 2, t = N - 1;
    Dinic dnc = Dinic(N, s, t);
    ll sm = 0;

    forn(i, n){
        if(b[i] > 0){
            dnc.addEdge(s, i, b[i]);
            sm += b[i];
        }
        if(b[i] < 0){
            dnc.addEdge(i, t, -b[i]);
        }
    }

    forn(i, n){
        for(int& f : fact[a[i]]){
            vi& vec = mp[f];
            auto it = lower_bound(all(mp[f]), i);
            if(it != vec.begin()){
                --it;
                dnc.addEdge(i, *it, inf);
            }
        }
    }

    // db(sm);
    // db(dnc.maxFlow());
    ll ans = sm - dnc.maxFlow();
    cout << ans << el;
}