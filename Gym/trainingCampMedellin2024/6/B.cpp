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

const int nax = 110;

vi primes;

void sieve(){
    int mx = 1e5;
    vector<bool> sv(mx);
    fore(i, 2, mx - 1){
        if(sv[i])continue;
        primes.pb(i);
        for(int j = i + i; j < mx; j += i){
            sv[j] = true;
        }
    }
}

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

int a[nax];
map<int, int> pf[nax];

void pfact(int ind){
    int x = a[ind];
    map<int, int>& cpf = pf[ind];
    for(int& p : primes){
        while(x % p == 0){
            x /= p;
            ++cpf[p];
        }
    }
    if(x != 1)++cpf[x];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int n, m;
    cin >> n >> m;
    forn(i, n)cin >> a[i];
    forn(i, n){
        pfact(i);
    }
    vector<vi> gprimes(n);
    vector<vi> idxs(n);
    vector<ii> prs(m);
    forn(i, m){
        int u, v;
        cin >> u >> v;
        --u, --v;
        if(u&1)swap(u, v);
        prs[i] = {u, v};
        map<int, int>& pfu = pf[u];
        map<int, int>& pfv = pf[v];
        for(auto& [p, pw] : pfu){
            if(pfv.count(p)){
                gprimes[u].pb(p);
                gprimes[v].pb(p);
            }
        }
    }

    int N = 0;
    forn(u, n){
        if(!sz(gprimes))continue;
        sort(all(gprimes[u]));
        gprimes[u].erase(unique(all(gprimes[u])), gprimes[u].end());
        for(auto& p : gprimes[u]){
            idxs[u].pb(N++);
        }
        assert(sz(gprimes[u]) == sz(idxs[u]));
    }

    N += 2;
    int s = N - 2, t = N - 1;
    Dinic dnc = Dinic(N, s, t);

    forn(u, n){
        vi& vecu = gprimes[u];
        if(u&1){
            forn(i, sz(vecu)){
                int& p = vecu[i];
                int ind = idxs[u][i];
                dnc.addEdge(ind, t, pf[u][p]);
            }
        }else{
            forn(i, sz(vecu)){
                int& p = vecu[i];
                int ind = idxs[u][i];
                dnc.addEdge(s, ind, pf[u][p]);
            }
        }
    }

    for(auto [u, v] : prs){
        vi& vecu = gprimes[u];
        vi& vecv = gprimes[v];
        forn(i, sz(vecu)){
            int& p = vecu[i];
            int ind = idxs[u][i];
            int j = lower_bound(all(vecv), p) - vecv.begin();
            if(j < sz(vecv) && p == vecv[j]){
                int jnd = idxs[v][j];
                dnc.addEdge(ind, jnd, inf);
            }
        }
    }

    ll ans = dnc.maxFlow();
    cout << ans << el;
}