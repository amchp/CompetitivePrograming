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
const ll MOD = 1e9 + 7;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int n;
ii g[nax];
int out[nax];
ll p2[nax];

vl dfs(int ind){
    if(ind == -1)return {1, 1, 1};
    vl left = dfs(g[ind].first);
    vl right = dfs(g[ind].second);
    ll zeros = left[1]*right[1] % MOD;
    ll bits = left[2] + right[2];
    ll ones = (p2[bits] - zeros + MOD) % MOD;
    return {zeros, ones, bits};
}

vl dfs2(int ind){
    if(ind == -1)return {1, 1, 1};
    vl left = dfs2(g[ind].first);
    vl right = dfs2(g[ind].second);
    if(out[ind] != -1){
        ll bits = left[2] + right[2];
        vl ans = {0, 0, bits};
        ans[out[ind]] = p2[bits];
        return ans;
    }
    ll zeros = left[1]*right[1] % MOD;
    ll bits = left[2] + right[2];
    ll ones = (p2[bits] - zeros + MOD) % MOD;
    return {zeros, ones, bits};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    cin >> n;
    forn(i, n){
        int u, v, o;
        cin >> u >> v >> o;
        u--;
        v--;
        g[i].first = u;
        g[i].second = v;
        out[i] = o;
    }
    p2[0] = 1;
    for1(i, n + 1){
        p2[i] = p2[i - 1] * 2;
        p2[i] %= MOD;
    }
    vl rAns = dfs(0);
    vl sAns = dfs2(0);
    // d(rAns[0]);
    // d(rAns[1]);
    // d(rAns[2]);
    // d(sAns[0]);
    // d(sAns[1]);
    // d(sAns[2]);
    ll tAns = sAns[1] - rAns[1];
    if(tAns < 0)tAns = sAns[0] - rAns[0];
    tAns += MOD;
    tAns %= MOD;
    cout << tAns << el;
}
