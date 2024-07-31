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
const int nax = 3e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;
const int mod = 998244353;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int n;
vi g[nax];
int dp[nax];
int ans = 0;

int add(int a, int b){
    int x = a + b;
    if(x >= mod)x -= mod;
    return x;
}

int sbt(int a, int b){
    int x = a - b;
    if(x < 0)x += mod;
    return x;
}

int mlt(int a, int b){
    return 1LL*a*b%mod;
}

void dfs(int u, int p){
    int prd = 1;
    for(int& v : g[u]){
        if(v == p)continue;
        dfs(v, u);
        prd = mlt(prd, add(dp[v], 1));
    }
    dp[u] = prd;
    ans = add(ans, dp[u]);
    return ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        ans = 0;
        cin >> n;
        forn(i, n - 1){
            int u, v;
            cin >> u >> v;
            --u, --v;
            g[u].pb(v);
            g[v].pb(u);
        }
        dfs(0, -1);
        ans = add(ans, 1);
        cout << ans << el;
        forn(i, n)g[i].clear();
    }
}
