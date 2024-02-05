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
int p[nax][32];
int in[nax];
int out[nax];

void dfs(int i, int& v){
    in[i] = v;
    for(int& nxt : g[i]){
        dfs(nxt, v);
    }
    out[i] = v;
    ++v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n;
    cin >> n;
    for1(i, n){
        cin >> p[i][0];
        g[p[i][0]].pb(i);
    }
    int val = 0;
    dfs(0, val);
    p[0][0] = 0;
    forn(i, n + 1){
        for1(j, 31){
            p[i][j] = p[p[i][j - 1]][j - 1];
            assert(p[i][j] >= 0 && p[i][j] <= n);
        }
    }
    int m;
    cin >> m;
    vector<vector<ii>> queries(n + 1);
    forn(i, m){
        int u, h;
        cin >> u >> h;
        queries[u].pb({h, i});
    }
    queue<int> q, qq;
    q.push(0);
    vi oin;
    vi oout;
    vi lq;
    vi ans(m, 0);
    // forn(i, n + 1){
    //     d(i);
    //     cout << in[i] << ' ' << out[i] << el;
    // }
    while(!q.empty()){
        swap(q, qq);
        while(!qq.empty()){
            int u = qq.front();
            qq.pop();
            lq.pb(u);
            oin.pb(in[u]);
            oout.pb(out[u]);
            for(int& v : g[u]){
                q.push(v);
            }
        }
        // cout << "IN" << el;
        // for(int& u : oin){
        //     cout << u << ' ';
        // }
        // cout << el;
        // cout << "OUT" << el;
        // for(int& u : oout){
        //     cout << u << ' ';
        // }
        // cout << el;
        sort(all(oin));
        sort(all(oout));
        for(int& u : lq){
            for(auto &[h, i] : queries[u]){
                int cur = u;
                ford(j, 32){
                    if(h & (1 << j)){
                        cur = p[cur][j];
                    }
                }
                // d(i);
                if(cur == 0){
                    ans[i] = 0;
                    // d(cur);
                    continue;
                }
                int l = lower_bound(all(oin), in[cur]) - oin.begin();
                int r = upper_bound(all(oout), out[cur]) - oout.begin() - 1;
                // d(l);
                // d(r);
                assert(r != -1);
                assert(r - l >= 0);
                ans[i] = r - l;
            }
        }
        lq.clear();
        oin.clear();
        oout.clear();
    }
    forn(i, m)cout << ans[i] << ' ';
    cout << el;
}
