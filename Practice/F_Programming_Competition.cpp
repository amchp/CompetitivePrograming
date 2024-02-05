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

vi g[nax];
int prt[nax], in[nax], out[nax];
int timer = 0;
ii nspr[nax];

void dfs(int u, int& anc){
    in[u] = ++timer;
    nspr[u] = {anc++, u};
    for(int& v : g[u]){
        dfs(v, anc);
    }
    --anc;
    out[u] = ++timer;
}

bool spr(int u, int v){
    return in[u] <= in[v] && out[u] >= out[v];
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
        prt[0] = -1;
        timer = 0;
        for1(i, n - 1){
            cin >> prt[i];
            --prt[i];
            g[prt[i]].pb(i);
        }
        int anc = 0;
        dfs(0, anc);
        sort(nspr, nspr + n, greater<ii>());
        queue<int> left;
        int ans = 0;
        forn(i, n){
            int& u = nspr[i].se;
            // d(u);
            if(!left.empty() && !spr(u, left.front())){
                // cout << u << ' ' << left.front() << el;
                left.pop();
                ++ans;
            }else{
                left.push(u);
            }
        }
        cout << ans << el;
        forn(i, n){
            g[i].clear();
        }
    }
}
