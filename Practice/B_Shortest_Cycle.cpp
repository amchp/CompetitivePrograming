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

int ans = inf;
vi g[200];
int depth[200];

void bfs(int ind){
    queue<ii> q, qq;
    q.push({ind, -1});
    int d = 1;
    while(!q.empty()){
        swap(q, qq);
        while(!qq.empty()){
            ii p = qq.front();
            int u = p.first;
            int pr = p.second;
            qq.pop();
            depth[u] = d;
            for(int v : g[u]){
                if(v == pr)continue;
                if(depth[v] != -1){
                    if(depth[v] == d)continue;
                    cout << depth[u] << ' ' << depth[v] << el;
                    ans = min(ans, abs(depth[u] - depth[v]) + 1);
                }else{
                    q.push({v, u});
                }
            }
        }
        d++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n;
    cin >> n;
    int a[63];
    memset(a, 0, sizeof(a));
    vl nodes;
    forn(i, n){
        ll v;
        cin >> v;
        if(v != 0)nodes.pb(v);
        forn(j, 63){
            if(v & (1LL << j)){
                a[j]++;
            }
        }
    }
    bool inner_loop = false;
    forn(i, 63){
        inner_loop = inner_loop || (a[i] >= 3);
    }
    if(inner_loop){
        cout << 3 << el;
        return 0;
    }
    // cout << sz(nodes) << el;
    forn(i, sz(nodes)){
        fore(j, i + 1, sz(nodes) - 1){
            if((nodes[i] & nodes[j]) != 0){
                g[i].pb(j);
                g[j].pb(i);
                // cout << i << ' ' << j << el;
            }
        }
    }
    // forn(i, sz(nodes)){
    //     d(i);
    //     for(int v : g[i]){
    //         cout << v << ' ';
    //     }
    //     cout << el;
    // }
    memset(depth, -1, sizeof(depth));
    forn(i, sz(nodes)){
        if(depth[i] == -1)bfs(i);
    }
    if(ans == inf)cout << -1 << el;
    else cout << ans << el;
}
