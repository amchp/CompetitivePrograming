#include <bits/stdc++.h>
#define el '\n'
#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define for1(i, n) for(int i = 1; i <= (int)n; ++i)
#define fore(i, l, r)for(int i = l; i <= (int)r; ++i)
#define ford(i, n)for(int i = (int)n - 1; i >= 0; --i)
#define all(a) a.begin(), a.end()
#define d(x) cerr<<#x<<" "<<x<<el
#define sz(x) x.size()
#define pb push_back
#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef array<int, 4> a4;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;

const int nax = 1e4 + 100;
const ll inf = 1e18;

int B, N, n;
vector<a4> recipies[nax];
vi g[nax];
pll vals[nax];
map<string, int> nds;
ll dp[nax][nax];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> B >> N;
    vi in(nax);
    forn(i, N){
        string name, base, add;
        cin >> name >> base >> add;
        int cst, prt;
        cin >> cst >> prt;
        if(!nds.count(name)){
            nds[name] = sz(nds);
        }
        if(!nds.count(base)){
            nds[base] = sz(nds);
        }
        if(!nds.count(add)){
            nds[add] = sz(nds);
        }
        int ind = nds[name], ib = nds[base], ia = nds[add];
        recipies[ind].pb({ib, ia, cst, prt});
        in[ind] += 2;
        g[ib].pb(ind);
        g[ia].pb(ind);
    }
    n = sz(nds);
    queue<int> q;
    forn(i, n){
        if(!in[i])q.push(i);
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vals[u] = {inf, 0};
        for(auto& [ib, ia, cst, prt] : recipies[u]){
            vals[u] = min(vals[u], {
                vals[ib].fi + vals[ia].fi + cst,
                vals[ib].se + vals[ia].se + (-prt)
            });
        }
        if(!sz(recipies[u]))vals[u].fi = 0;
        for(int& v : g[u]){
            --in[v];
            if(!in[v])q.push(v);
        }
    }
    forn(i, B + 1)dp[n][B] = 0;
    ford(i, n){
        forn(b, B + 1){
            dp[i][b] = dp[i + 1][b];
            if(vals[i].fi <= b){
                dp[i][b] = max(dp[i][b], dp[i + 1][b - vals[i].fi] + (-vals[i].se));
            }
        }
    }
    ll ans = dp[0][B];
    int cst = B;
    ford(i, B){
        if(dp[0][i] == ans){
            cst = i;
        }
    }
    cout << ans << el << cst << el;
}