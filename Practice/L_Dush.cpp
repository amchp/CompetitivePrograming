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

const int inf = 2e9 + 100;
const int nax = 1e5 + 200;
const int ndp = 2e6;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n, m;
    cin >> n >> m;
    vector<ii> prsn(n);
    forn(i, n){
        int ty, dur;
        cin >> ty >> dur;
        ty++;
        prsn[i] = {dur, ty};
    }
    vector<vector<ii>> shower(3);
    forn(i, m){
        int si, dur, ty;
        cin >> si >> dur >> ty;
        ++ty;
        shower[ty].pb({si, dur});
    }
    forn(i, 3)sort(all(shower[i]));
    vector<vector<ii>> trans(n);
    forn(i, n){
        forn(j, sz(shower[prsn[i].se])){
            auto& [si, dur] = shower[prsn[i].se][j];
            if(dur < prsn[i].fi)continue;
            trans[i].pb({si + dur - prsn[i].fi, j});
        }
    }
    queue<int> q;
    vector<bool> vis(ndp, false);
    vector<int> dp(ndp, inf);
    q.push(0);
    dp[0] = 0;
    while(!q.empty()){
        int msk = q.front();
        q.pop();
        // d(msk);
        forn(i, n){
            if(!(msk & (1 << i))){
                int nmsk = msk | (1 << i);
                vector<ii>& vec = trans[i];
                // for(auto& [si, dur] : vec){
                //     cout << si << ' ' << dur << el;
                // }
                // cout << "######" << el;
                auto it = lower_bound(all(vec), ii{dp[msk], -1});
                if(it == vec.end())continue;
                ii nxt = (*it);
                int ans = max(dp[msk], shower[prsn[i].se][nxt.se].fi) + prsn[i].fi;
                dp[nmsk] = min(dp[nmsk], ans);
                if(!vis[nmsk]){
                    // d(nmsk);
                    q.push(nmsk);
                    vis[nmsk] = true;
                }
            }
        }
    }
    cout << dp[(1 << n) - 1] << el;
}
