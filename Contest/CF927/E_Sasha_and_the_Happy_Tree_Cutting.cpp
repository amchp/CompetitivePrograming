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

int timer;
ii up[nax];
int n;
int in[nax], out[nax];
vector<ii> g[nax];
void dfs(int u, int p){
  in[u] = ++timer;
  for(auto [v, ind]: g[u]){
    if(v==p) continue;
    up[v] = {u, ind};
    dfs(v,u);
  }
  out[u] = ++timer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        timer = 0;
        forn(i, n){
            g[i].clear();
        }
        forn(i, n - 1){
            int u, v;
            cin >> u >> v;
            --u, --v;
            g[u].pb({v, i});
            g[v].pb({u, i});
        }
        int k;
        cin >> k;
        vector<ii> prs(k);
        forn(i, k){
            cin >> prs[i].fi >> prs[i].se;
            --prs[i].fi, --prs[i].se;
        }
        dfs(0, 0);
        vi edgs(n - 1);
        forn(i, k){
            int u = prs[i].fi;
            int v = prs[i].se;
            while(u != v){
                if(in[v] < in[u]){
                    edgs[up[u].se] |= 1 << i;
                    u = up[u].fi;
                }else{
                    edgs[up[v].se] |= 1 << i;
                    v = up[v].fi;
                }
            }
        }
        sort(all(edgs));
        edgs.erase(unique(all(edgs)), edgs.end());
        int ks = 1 << k;
        vi dp(ks, k);
        dp[0] = 0;
        forn(i, ks){
            for(int& msk : edgs){
                dp[i | msk] = min(dp[i | msk], dp[i] + 1);
            }
        }
        cout << dp[ks - 1] << el;
    }
}
