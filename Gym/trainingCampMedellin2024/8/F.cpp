#include <bits/stdc++.h>

#define el '\n'
#define forn(i, n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= n; ++i)
#define fore(i, l, r) for(int i = (int)l; i <= (int)r; ++i)
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define pb push_back
#define sz(x)(int) x.size()
#define fi first
#define se second
#define db(x) cerr << #x << ' ' << x << el

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int nax = 1e5 + 100;
const int mod = 998244353;

struct mint{
    int x;
    mint(){}
    mint(ll x): x(x % mod){}
    mint operator+(mint b){
        int ans = x + b.x;
        if(ans >= mod)ans -= mod;
        return ans;
    }
    mint operator-(mint b){
        int ans = x - b.x;
        if(ans < 0)ans += mod;
        return ans;
    }
    mint operator*(mint b){
        return 1LL*x*b.x%mod;
    }
};

mint binpow(mint b, int e){
    mint ans = 1;
    for(; e; b = b*b, e /= 2){
        if(e&1)ans = ans*b;
    }
    return ans;
}

mint inv(mint x){
    return binpow(x, mod - 2);
}

struct frac{
    mint num, dem;
    frac(): num(0), dem(1){}
    frac(ll x, ll y): num(x), dem(y) {}
    frac(mint x, mint y): num(x), dem(y) {}
    frac operator+(frac b){
        return frac(num*b.dem + b.num*dem, dem*b.dem);
    }
    frac operator-(frac b){
        return frac(num*b.dem - b.num*dem, dem*b.dem);
    }
    frac operator*(frac b){
        return frac(num * b.num, dem*b.dem);
    }
    frac operator/(frac b){
        return frac(num * b.dem, dem*b.num);
    }
};

frac dp[nax], dep[nax];
vector<pair<int, frac>> g[nax];
int vis[nax];

void dfs(int u){
    if(vis[u])return;
    vis[u] = 1;
    for(auto& [v, w]: g[u]){
        if(vis[v] != 1){
            dp[v] = dp[v] + dep[v]*dp[u]*w;
            dep[v] = dep[v]*(frac(1, 1) - w);
        }
        dfs(v);
    }
    for(auto& [v, w] : g[u]){
        dep[v] = dep[v] / (frac(1, 1) - w); 
    }
    vis[u] = 2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    forn(i, m){
        int u, v, p, q;
        cin >> u >> v >> p >> q;
        --u, --v;
        g[u].pb({v, frac(p, q)});
    }
    forn(i, n){
        dp[i] = frac(0, 1);
        dep[i] = frac(1, 1);
        vis[i] = false;
    }
    dp[0] = frac(1, 1);
    dfs(0);
    forn(i, n){
        auto& [p, q] = dp[i];
        // cout << p.x << ' ' << q.x << el;
        cout << (p*inv(q)).x << el;
    }
}
