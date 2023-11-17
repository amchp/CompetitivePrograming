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
const int nax = 2e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int n;
vi g[nax];
bool vis[nax];

int dfs(int u){
    vis[u] = true;
    int ans = 0;
    for(int& v : g[u]){
        if(vis[v])return inf;
        ans = max(ans, dfs(v) + 1);
    }
    return ans;
}

bool sol(){
    int k;
    cin >> n >> k;
    vi a(n);
    forn(i, n){
        vis[i] = false;
        g[i].clear();
        cin >> a[i];
        a[i]--;
    }
    forn(i, n){
        if(a[i] >= n)continue;
        int u = (i - a[i] + n) % n;
        int v = (u + (a[i] + 1)) % n;
        // cout << i << el;
        // cout << a[i] << el;
        g[v].pb(u);
        // cout << v << ' ' << u << el;
    }
    int ans = dfs(0);
    // cout << ans << el;
    if(k <= ans)return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        if(sol()){
            cout << "Yes" << el;
        }else{
            cout << "No" << el;
        }
    }
}
