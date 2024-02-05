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

int n, a, b, da, db;
vi g[nax];

ii dfs(int u, int p, int d){
    ii ans = {d, u};
    for(int& v : g[u]){
        if(v == p)continue;
        ans = max(ans, dfs(v, u, d + 1));
    }
    return ans;
}

int dfsd(int u, int p, int d){
    if(u == b)return d;
    int ans = 0;
    for(int& v : g[u]){
        if(v == p)continue;
        ans = max(ans, dfsd(v, u, d + 1));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> a >> b >> da >> db;
        --a;
        --b;
        forn(i, n)g[i].clear();
        forn(i, n - 1){
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            g[u].pb(v);
            g[v].pb(u);
        }
        // d(db);
        // d(da);
        // d((db < da * 2 + 1));
        // d((dfsd(a, -1, 0)));
        // d((dfsd(a, -1, 0) <= da));
        if(db < da * 2 + 1 || dfsd(a, -1, 0) <= da){
            cout << "Alice" << el;
            continue;
        }
        ii ans = dfs(0, -1, 1);
        ii sans = dfs(ans.se, -1, 1);
        // d((sans.fi / 2 <= da));
        if(sans.fi / 2 <= da){
            cout << "Alice" << el;
        }else{
            cout << "Bob" << el;
        }
    }

}
