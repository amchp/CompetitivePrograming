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
bool mrk[nax];
vi dp[nax];
int ans[nax];

int dfs(int ind, int p){
    int mx = 0;
    for(int v : g[ind]){
        if(v == p)continue;
        dp[ind].pb(dfs(v, ind));
        mx = max(dp[ind].back(), mx);
    }
    if(mx == 0)return mx + mrk[ind];
    return mx + 1;
}

ii get_top2(int ind){
    int mx = 0;
    int mx2 = 0;
    for(int v : dp[ind]){
        if(mx < v){
            mx2 = mx;
            mx = v;
        }else if(mx2 < v){
            mx2 = v;
        }
    }
    return {mx, mx2};
}

void dfs2(int ind, int p, int val){
    if(p != -1)dp[ind].pb(val);
    ii top2 = get_top2(ind);
    ans[ind] = top2.first;
    int i = 0;
    for(int v : g[ind]){
        if(v == p)continue;
        if(dp[ind][i] == top2.first){
            dfs2(v, ind, top2.second + (top2.second != 0 || mrk[ind]));
        }else{
            dfs2(v, ind, top2.first +  (top2.first != 0 || mrk[ind]));
        }
        i++;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        forn(i, n){
            mrk[i] = false;
            g[i].clear();
            dp[i].clear();
            ans[i] = inf;
        }
        forn(i, m){
            int v;
            cin >> v;
            v--;
            mrk[v] = true;
        }
        forn(i, n - 1){
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            g[u].pb(v);
            g[v].pb(u);
        }
        dfs(0, -1);
        dfs2(0, -1, inf);
        int fAns = inf;
        forn(i, n){
            fAns = min(ans[i], fAns);
        }
        cout << fAns << el;
    }
}
