#include<bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= n; ++i)
#define pb push_back
#define sz(x) x.size()
#define el '\n'
#define d(x) cerr<<#x<<" "<<x<<el
#define all(x) x.begin(), x.end()
using namespace std;

typedef vector<int> vi;
typedef double ld;
typedef pair<int, int> ii;
typedef vector<ii> vdd;
typedef long long ll;
typedef vector<char> vc;

const ld eps = 1e-9;
const ld pi = acos(-1);
typedef tuple <ld, int,int,int> iii;
const int nax = 2e5 + 200;
// const int nax = 2e3 + 200;
const int inf = 1e9;
int dir[]={0, 1, 2, 3};
vi g[nax];
int dp[nax];

int mnh;

int dfs(int u, int p, int d){
    vi hgts;
    for(int& v : g[u]){
        if(v == p)continue;
        hgts.pb(dfs(v, u, d + 1));
    }
    // d(u);
    if(sz(hgts) == 0){
        // d(d);
        return d;
    }
    if(sz(hgts) == 1){
        dp[u] = d + 1;
        mnh = min(mnh, d + 2);
        return d + 1;
    }
    assert(sz(hgts) == 2);
    sort(all(hgts));
    if(abs(hgts[1] - hgts[0]) > 1){
        dp[u] = hgts[0] + 1;
        mnh = min(mnh, hgts[0] + 2);
        return hgts[0] + 1;
    }
    return hgts[1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.precision(20);
    int n;
    cin >> n;
    forn(i, n - 1){
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    forn(i, n)dp[i] = inf;
    mnh = inf;
    dfs(0, 0, 0);
    // d(mnh);
    int lvl = 0;
    queue<ii> q;
    q.push({0, mnh});
    int ans = 0;
    vector<bool> vis(n, false);
    vis[0] = true;
    while(!q.empty()){
        int end = sz(q);
        forn(_, end){
            auto& [u, h] = q.front();
            q.pop();
            if(lvl > h){
                ++ans;
            }
            for(int& v : g[u]){
                if(!vis[v]){
                    vis[v] = true;
                    int nh = min(h, dp[u]);
                    q.push({v, nh});
                }
            }
        }
        ++lvl;
    }
    cout << ans << el;
}