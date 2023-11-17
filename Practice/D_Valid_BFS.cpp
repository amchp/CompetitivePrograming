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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n;
    cin >> n;
    vector<set<int>> g(n);
    forn(i, n - 1){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].insert(v);
        g[v].insert(u);
    }
    queue<int> q, qq;
    vector<set<int>> levels;
    vector<bool> visited(n, false);
    q.push(0);
    visited[0] = true;
    vi lst(n);
    forn(i, n){
        cin >> lst[i];
        lst[i]--;
    }
    int ind = 1;
    while(!q.empty()){
        swap(q, qq);
        levels.pb(set<int>());
        while(!qq.empty()){
            int u = qq.front();
            levels.back().insert(u);
            qq.pop();
            forn(i, sz(g[u]) - (u != 0)){
                if(!g[u].count(lst[ind])){
                    cout << "No" << el;
                    return 0;
                }
                q.push(lst[ind]);
                ind++;
            }
        }
    }
    cout << "Yes" << el;
}
