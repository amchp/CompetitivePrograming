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

vi g[nax];
char st[nax];
int dp[nax][2];

int sol(int u, int p, int l){
    int& ans = dp[u][l];
    if(ans != -1)return ans;
    ans = 0;
    for(int& v : g[u]){
        if(v == p)continue;
        ans += min((sol(v, u, 0) + (l != 0)), sol(v, u, 1) + (l != 1));
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
        int n;
        cin >> n;
        forn(i, n){
            g[i].clear();
            dp[i][0] = -1;
            dp[i][1] = -1;
        }
        forn(i, n - 1){
            int u = i + 1, v;
            cin >> v;
            --v;
            g[u].pb(v);
            g[v].pb(u);
        }
        queue<int> q;
        vector<bool> vis(n);
        forn(i, n){
            cin >> st[i];
            if(st[i] == 'S'){
                dp[i][1] = inf;
            }
            if(st[i] == 'P'){
                dp[i][0] = inf;
            }
        }
        int ans = min(sol(0, -1, 0), sol(0, -1, 1));
        cout << ans << el;
    }
}
