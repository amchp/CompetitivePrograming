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
#define sz(v) ((int)v.size())
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> ii;
typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

string convert(int jind)
{
    char cur = 'a' + jind;
    string curs(1, cur);
    return curs;
}

const ll inf = 1e9;
struct edge
{
    int to, rev;
    ll cap, cos, f{0};
    edge(int to, int rev, ll cap, ll cos) : to(to), rev(rev), cap(cap), cos(cos) {}
};
struct MCMF{
    int n, s, t;
    vector<vector<edge>> g;
    vi p;
    vll dis;
    MCMF(){}
    MCMF(int n, int s, int t) : n(n), g(n), s(s), t(t) {}
    void addEdge(int s, int t, ll cap, ll cos){
        g[s].pb(edge(t, sz(g[t]), cap, cos));
        g[t].pb(edge(s, sz(g[s]) - 1, 0, -cos));
    }
    void spfa(int v0){
        dis.assign(n, inf);
        dis[v0] = 0;
        p.assign(n, -1);
        vector<bool> inq(n);
        queue<int> q({v0});
        while (sz(q))
        {
            int u = q.front();
            q.pop();
            inq[u] = 0;
            for (auto &[v, rev, cap, cos, f] : g[u])
            {
                if (cap - f > 0 && dis[v] > dis[u] + cos)
                {
                    dis[v] = dis[u] + cos, p[v] = rev;
                    if (!inq[v])
                        inq[v] = 1, q.push(v);
                }
            }
        }
    }
    ll min_cos_flow(ll K){
        ll flow = 0, cost = 0;
        while (flow < K)
        {
            spfa(s);
            if (dis[t] == inf)
                break;
            ll f = K - flow;
            int cur = t; // Find flow
            while (cur != s)
            {
                int u = g[cur][p[cur]].to, rev = g[cur][p[cur]].rev;
                f = min(f, g[u][rev].cap - g[u][rev].f);
                cur = u;
            }
            flow += f, cost += f * dis[t], cur = t; // Apply flow
            while (cur != s)
            {
                int u = g[cur][p[cur]].to, rev = g[cur][p[cur]].rev;
                g[u][rev].f += f, g[cur][p[cur]].f -= f;
                cur = u;
            }
        }
        if (flow < K)
            assert(0);
        return cost;
    }
};

MCMF mcmf;

const int nax = 300;

int ans[nax];
int s;
int ps;
int t;

void sol(int u, int& ind){
    int in = -1;
    for(edge& v : mcmf.g[u]){
        if(v.f <= 0)continue;
        in = v.to;
        break;
    }
    // d(u);
    assert(in != -1);
    ans[in / 2] = ind;
    int out = -1;
    for(edge& v : mcmf.g[in]){
        if(v.f <= 0)continue;
        out = v.to;
    }
    if(out == t)return;
    sol(out, ind);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n, m;
    cin >> n >> m;
    vi a(n);
    forn(i, n){
        cin >> a[i];
    }
    s = 2 * n;
    ps = 2 * n + 1;
    t = 2 * n + 2;
    mcmf = MCMF(2 * n + 3, s, t);
    mcmf.addEdge(s, ps, m, 0);
    mcmf.addEdge(ps, t, inf, 0);
    forn(i, n){
        mcmf.addEdge(ps, 2 * i, 1, __popcount(a[i]));
        mcmf.addEdge(2 * i, 2 * i + 1, 1, -inf);
        mcmf.addEdge(2 * i + 1, t, 1, 0);
    }
    forn(i, n){
        fore(j, i + 1, n - 1){
            mcmf.addEdge(2 * i + 1, 2 * j, inf, a[i] == a[j] ? 0 : __popcount(a[j]));
        }
    }
    ll mncst = mcmf.min_cos_flow(m) + inf * n;
    int var = 0;
    for(edge& e : mcmf.g[ps]){
        if(e.f <= 0)continue;
        if(e.to == t)continue;
        sol(e.to, var);
        ++var;
    }
    // d(var);
    assert(var <= m + 1);
    vi vars(m, 0);
    vector<string> fans;
    forn(i, n){
        int ind = ans[i];
        if(a[i] != vars[ind]){
            vars[ind] = a[i];
            fans.pb(convert(ind) + "=" + to_string(a[i]));
        }
        fans.pb("print(" + convert(ind) + ")");
    }
    cout << sz(fans) << ' ' << mncst << el;
    for(string& s : fans)cout << s << el;
}
