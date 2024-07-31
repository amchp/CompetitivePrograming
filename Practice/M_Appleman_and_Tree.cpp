#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i,n) for(int i=0; i< (int)n; ++i)
#define for1(i,n) for(int i=1; i<= (int)n; ++i)
#define fore(i,l,r) for(int i=(int)l; i<= (int)r; ++i)
#define ford(i,n) for(int i=(int)(n) - 1; i>= 0; --i)
#define fored(i,l,r) for(int i=(int)r; i>= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout<< #x<< " " << x<<el
#define ri(n) scanf("%d",&n)
#define sz(v) int(v.size())
#define all(v) v.begin(),v.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<ld> vd;


const int inf = 1e9;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;
const int mod = 1e9 + 7;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

struct mint{
    int x;
    mint(): x(0){}
    mint(ll x): x(x % mod){}
    mint operator+(mint b){
        int ans = x + b.x;
        if(ans >= mod) ans -= mod;
        return ans;
    }
    mint operator*(mint b){
        return 1LL*x*b.x%mod;
    }
};

vi g[nax];
int x[nax];
mint dp[nax][2];

void dfs(int v, int p){
    // d(v);
    dp[v][0] = 1;
    dp[v][1] = 0;
    for(int& u : g[v]){
        if(u == p)continue;
        // d(u);
        dfs(u, v);
        dp[v][1] = dp[v][1] * dp[u][0];
        dp[v][1] = dp[v][1] + dp[v][0]*dp[u][1];
        dp[v][0] = dp[v][0] * dp[u][0];
    }
    if(x[v] == 1){
        dp[v][1] = dp[v][0];
    }else{
        dp[v][0] = dp[v][0] + dp[v][1];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int n;
    cin >> n;
    for1(u, n - 1){
        int v;
        cin >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    forn(i, n){
        cin >> x[i];
        // cout << x[i] << ' ';
    }
    // cout << el;
    dfs(0, 0);
    // forn(i, n)cout << dp[0][0].x << ' ' << dp[0][1].x << el;
    cout << dp[0][1].x << el;
}