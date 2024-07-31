#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define fored(i, l, r) for (int i = (int)r; i >= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cerr << #x << " " << x << el
#define ri(n) scanf("%d", &n)
#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef ll ld;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<ld> vd;

const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

const int nax = 25000 + 100;

// Complexity O(V^2*E)
const ll inf = 1e18;
struct edge
{
    int to, rev;
    ll cap, f{0};
    edge(int to, int rev, ll cap) : to(to), rev(rev), cap(cap) {}
};
struct Dinic
{
    int n, s, t;
    ll max_flow = 0;
    vector<vector<edge>> g;
    vi q, dis, work;
    Dinic(int n, int s, int t) : n(n), s(s), t(t), g(n), q(n) {}
    void addEdge(int s, int t, ll cap)
    {
        g[s].pb(edge(t, sz(g[t]), cap));
        g[t].pb(edge(s, sz(g[s]) - 1, 0));
    }

    bool bfs()
    {
        dis.assign(n, -1), dis[s] = 0;
        int qt = 0;
        q[qt++] = s;
        forn(qh, qt)
        {
            int u = q[qh];
            for (auto &[v, _, cap, f] : g[u])
                if (dis[v] < 0 && f < cap)
                    dis[v] = dis[u] + 1, q[qt++] = v;
        }
        return dis[t] >= 0;
    }
    ll dfs(int u, ll cur)
    {
        if (u == t)
            return cur;
        for (int &i = work[u]; i < sz(g[u]); ++i)
        {
            auto &[v, rev, cap, f] = g[u][i];
            if (cap <= f)
                continue;
            if (dis[v] == dis[u] + 1)
            {
                ll df = dfs(v, min(cur, cap - f));
                if (df > 0)
                {
                    f += df, g[v][rev].f -= df;
                    return df;
                }
            }
        }
        return 0;
    }
    ll maxFlow()
    {
        ll cur_flow = 0;
        while (bfs())
        {
            work.assign(n, 0);
            while (ll delta = dfs(s, inf))
                cur_flow += delta;
        }
        max_flow += cur_flow;
        // todos los nodos con dis[u]!=-1 vs los que tienen dis[v]==-1 forman el min-cut, (u,v)
        return max_flow;
    }
    vii min_cut()
    {
        maxFlow();
        vii cut;
        forn(u, n)
        {
            if (dis[u] == -1)
                continue;
            for (auto &e : g[u])
                if (dis[e.to] == -1)
                    cut.pb({u, e.to});
        }
        sort(all(cut)), cut.resize(unique(all(cut)) - cut.begin());
        return cut;
    }
};

vector<ii> g[nax];
ll d[nax];
vi p[nax];
void dijkstra(int s, int n){
    forn(i, n) d[i] = inf, p[i].clear();
    d[s] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({0, s});
    while (sz(q))
    {
        auto [dist, u] = q.top();
        q.pop();
        if (dist > d[u])
            continue;
        for (auto &[v, w] : g[u])
        {
            if (d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                p[v].clear();
                p[v].pb(u);
                q.push(pll(d[v], v));
            }
            else if (d[u] + w == d[v])
                p[v].pb(u);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(20) << fixed;
    int n, m, c;
    cin >> n >> m >> c;
    forn(i, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    dijkstra(0, n);
    int ans = 0;
    vi cars(n);
    forn(i, c){
        int u;
        cin >> u;
        --u;
        ++cars[u];
        if(u == 0)++ans;
    }
    vector<pll> dst(n);
    forn(u, n){
        dst[u] = {d[u], u};
    }
    sort(all(dst));
    Dinic base = Dinic(n + 1, n, 0);
    forn(u, n){
        for(int& v : p[u]){
            base.addEdge(u, v, 1);
        }
    }
    int ind = 0;
    while(ind < n){
        ll& nd = dst[ind].se;
        if(nd == 0 || cars[nd] == 0){
            ++ind;
            continue;
        }
        Dinic tmp = base;
        tmp.addEdge(n, nd, cars[nd]);
        ++ind;
        while(ind < n && dst[ind - 1].fi == dst[ind].fi){
            ll& nd2 = dst[ind].se;
            if(cars[nd2] > 0)tmp.addEdge(n, nd2, cars[nd2]);
            ++ind;
        }
        ans += tmp.maxFlow();
    }
    cout << ans << el;
}