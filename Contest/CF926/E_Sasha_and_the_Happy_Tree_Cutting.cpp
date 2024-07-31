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
vector<vector<ii>> gcc(20);
vector<int> cegd;
map<int, int> gtgc;
vector<ii> prs;
set<int> icg;



bool dfs2(int u, int p, int& dst, int& msk){
    if(u == dst)return true;
    for(auto& [v, ind] : gcc[u]){
        if(v == p)continue;
        if(dfs2(v, u, dst, msk)){
            cegd[ind] |= msk;
            return true;
        }
    }
    return false;
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
        forn(i, n - 1){
            int u, v;
            cin >> u >> v;
            --u, --v;
            gcc[u].pb({v,i});
            gcc[v].pb({u,i});
            cegd.pb(0);
        }
        int k;
        cin >> k;
        forn(i, k){
            int a, b;
            cin >> a >> b;
            --a, --b;
            prs.pb({a, b});
            icg.insert(a);
            icg.insert(b);
            
        }
        
        forn(i, k){
            auto& [a, b] = prs[i];
            int msk = 1 << i;
            dfs2(a, -1, b, msk);
        }
        // for(int& x : cegd)cout << x << ' ';
        // cout << el;
        int sbt = 1 << k;
        vi dp(sbt, inf);
        dp[0] = 0;
        forn(i, k)dp[1 << i] = 1;
        for(int& smsk : cegd){
            forn(i, sbt){
                dp[i | smsk] = min(dp[i | smsk], dp[i] + 1);
            }
        }
        cout << dp[sbt - 1] << el;
        forn(i, n)g[i].clear();
        prs.clear();
        gcc.clear();
        icg.clear();
        gtgc.clear();
        cegd.clear();
    }
}
