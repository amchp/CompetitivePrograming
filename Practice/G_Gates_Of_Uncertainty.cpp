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

struct mint{
    int x;
    mint(){}
    mint(ll x): x(x % MOD){}
    mint operator+(mint b){
        int ans = x + b.x;
        if(ans > MOD)ans -= MOD;
        return ans;
    }
    mint operator-(mint b){
        int ans = x - b.x;
        if(ans < 0)ans += MOD;
        return ans;
    }
    mint operator*(mint b){
        return 1LL*x*b.x%MOD;
    }
};

typedef array<mint, 4> mint4;
typedef array<int, 4> a4;
typedef array<a4, 4> mtx4;

int n;
ii g[nax];
int out[nax];
mint p2[nax];

mtx4 zrs = {
    a4{1, 1, 1, 1},
    a4{1, 0, 0, 1},
    a4{1, 0, 0, 1},
    a4{1, 1, 1, 1},
};

mtx4 ons = {
    a4{2, 2, 2, 2},
    a4{2, 3, 3, 2},
    a4{2, 3, 3, 2},
    a4{2, 2, 2, 2}
};

mtx4 nrm = {
    a4{2, 2, 2, 2},
    a4{2, 3, 3, 2},
    a4{2, 3, 0, 1},
    a4{2, 2, 1, 1}
};

vector<mtx4> mtx = {nrm, zrs, ons};

mint4 dfs(int ind){
    if(ind == -1)return {1, 0, 1, 0};
    mint4 left = dfs(g[ind].first);
    mint4 right = dfs(g[ind].second);
    mint4 ans = {0, 0, 0, 0};
    mtx4& cmtx = mtx[out[ind] + 1];
    forn(i, 4){
        forn(j, 4){
            int idx = cmtx[i][j];
            ans[idx] = ans[idx] + left[i]*right[j];
        }
    }
    return ans;
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
        p2[i] = p2[i - 1] * mint(2);
    }
    mint4 rAns = dfs(0);
    mint fAns = rAns[1] + rAns[3];
    cout << fAns.x << el;
}
