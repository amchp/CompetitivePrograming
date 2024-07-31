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

const int inf = 1e9;
const int nax = 1e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int n, m, H;
vector <int> g[nax];
int d[nax], l[nax], s[nax];

ll sol(int u, int v, ll cur){
    ll cu = cur*u % H;
    ll cv = cur*v % H;
    
}

void dijkstra(int s, int n){
    forn(i, n) d[i] = inf;
    d[s] = 0;
    priority_queue <pll, vector <pll>,greater<pll> > q;
    q.push({0, s});
    while(sz(q)){
        auto [dist, u] = q.top();  q.pop();
        if(dist > d[u]) continue;
        for(auto& v: g[u]){
            ll nxt = sol(u, v, dist);
            if (d[u] + w < d[v]){
                d[v] = d[u] + w;
                q.push(ii(d[v], v));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m >> H;
        forn(i, m){
            int u, v;
            cin >> u >> v;
            --u, --v;
            g[u].pb(v);
            g[v].pb(u);
        }

    }
}
