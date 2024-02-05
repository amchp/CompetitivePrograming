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
int p[nax];
vi nds[nax];
ll cmp[nax];
ll dif[nax];

int find(int x){
    if(x == p[x])return x;
    return p[x] = find(p[x]);
}

void merge(int u, int v, int edg){
    u = find(u);
    v = find(v);
    if(u == v)return;
    if(sz(nds[u]) < sz(nds[v]))swap(u, v);
    cmp[u] += 1LL*sz(nds[v])*edg;
    cmp[v] += 1LL*sz(nds[u])*edg;
    cmp[v] -= cmp[u];
    for(int& nv :nds[v]){
        dif[nv] += cmp[v];
        nds[u].pb(nv);
    }
    p[v] = u;
}

struct edge{
    int u, v, w;
    edge(){};
    edge(int u, int v, int w): u(u), v(v), w(w){}
    bool operator<(edge e){
        return w < e.w;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    freopen("road.in", "r", stdin);
    int t;
    cin >> t;
    forn(c, t){
        int n, m;
        cin >> n >> m;
        vector<edge> vec;
        forn(i, n){
            p[i] = i;
            nds[i].pb(i);
            cmp[i] = 0;
            dif[i] = 0;
        }
        forn(i, m){
            int u, v, w;
            cin >> u >> v >> w;
            --u;
            --v;
            vec.pb(edge(u, v, w));
        }
        sort(all(vec));
        for(edge& e : vec){
            merge(e.u, e.v, e.w);
        }
        cout << "Case " << c + 1 << ':' << el;
        forn(i, n){
            ll ans = cmp[find(i)];
            ans += dif[i];
            cout << ans << el;
        }
        forn(i, n){
            nds[i].clear();
        }
    }
}
