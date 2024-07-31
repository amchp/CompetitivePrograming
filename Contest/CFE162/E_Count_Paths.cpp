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
typedef vector<ll> vl;

const int inf = 1e9;
const int nax = 2e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int c[nax];
vi g[nax];
map<int, int> mps[nax];
ll ans = 0;

void dfs(int u, int p){
    // d(u);
    for(int& v: g[u]){
        if(v == p)continue;
        dfs(v, u);
        if(sz(mps[u]) < sz(mps[v])){
            swap(mps[u], mps[v]);
        }
        for(auto& [key, val] : mps[v]){
            if(key == c[u]){
                ans += val;
                continue;
            }
            if(mps[u].count(key)){
                ans += mps[u][key] * val;
            }
            mps[u][key] += val;
        }
    }
    ans += mps[u][c[u]];
    mps[u][c[u]] = 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ans = 0;
        forn(i, n)g[i].clear();
        forn(i, n)mps[i].clear();
        forn(i, n)cin >> c[i];
        forn(i, n - 1){
            int u, v;
            cin >> u >> v;
            --u, --v;
            g[u].pb(v);
            g[v].pb(u);
        }
        dfs(0, 0);
        cout << ans << el;
    }
}
