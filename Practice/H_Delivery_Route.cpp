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
#define d(x) cout << #x << " " << x << el
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
typedef vector<ll> vl;
typedef tuple<int, int, ll> iil;

const ll inf = 1e18;
const int nax = 3e4 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

vector<pll> g[nax];
ll d[nax];
vector<vi> gc;
vector<vector<iil>> gcE;
vi ts;
int comp[nax];

void find_comp(int u){
    for(auto &[v, w] : g[u]){
        if(comp[v] == -1){
            comp[v] = comp[u];
            find_comp(v);
        }
    }
}
vector<bool> seen;
void dfst(int u){
  seen[u] = true;
  for(int v: gc[u])
    if (!seen[v])
      dfst(v);
  ts.pb(u);
}
void topo(int n){
  forn(i,n) if (!seen[i]) dfst(i);
  reverse(all(ts));
}

void dijkstra(int s){
    priority_queue<pll, vector<pll>, greater<pll>> q;
    d[s] = 0;
    q.push({0, s});
    ll dist, u, v, w;
    while (sz(q))
    {
        tie(dist, u) = q.top();
        q.pop();
        if (dist > d[u])
            continue;
        // cout << "HI" << el;
        for (pll e : g[u])
        {
            tie(v, w) = e;
            if (d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                q.push(pll(d[v], v));
            }
        }
    }
}

void dijkstra2(){
    priority_queue<pll, vector<pll>, greater<pll>> q;
    for(int cU : ts){
        // cout << cU + 1 << ' ';
        for(auto &[u, v, w] : gcE[cU]){
            if(d[u] == inf)continue;
            if(d[u] + w < d[v]){
                d[v] = d[u] + w;
                q.push(pll(d[v], v));
            }
        }
        ll dist, u, v, w;
        while (sz(q))
        {
            tie(dist, u) = q.top();
            q.pop();
            if (dist > d[u])
                continue;
            for (pll e : g[u])
            {
                tie(v, w) = e;
                if (d[u] + w < d[v])
                {
                    d[v] = d[u] + w;
                    q.push(pll(d[v], v));
                }
            }
        }
    }
    // cout << el;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    memset(comp, -1, sizeof(comp));
    int n, x, y, s;
    cin >> n >> x >> y >> s;
    forn(i, n) d[i] = inf;
    s--;
    forn(i, x){
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    forn(i, n){
        if(comp[i] == -1){
            comp[i] = sz(gc);
            gc.pb(vi());
            gcE.pb(vector<iil>());
            seen.pb(false);
            find_comp(i);
        }
    }
    forn(i, y){
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        gc[comp[u]].pb(comp[v]);
        gcE[comp[u]].pb({u, v, w});
    }
    topo(sz(gc));
    dijkstra(s);
    //  forn(i, n){
    //     if(d[i] == inf)cout << "NO PATH" << el;
    //     else cout << d[i] << el;
    // }
    // cout << el;
    dijkstra2();
    forn(i, n){
        if(d[i] == inf)cout << "NO PATH" << el;
        else cout << d[i] << el;
    }
}
