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

const int inf = 1e6;
const int nax = 20;
const ld pi = acos(-1);
const ld eps = 1e-9;

const int mod = 1e9 + 7;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int n, m, c;
int alln;
int fact[1001];

int add(int a, int b){
    int ans = a + b;
    if(ans >= mod)ans -= mod;
    return ans;
}

int mlt(int a, int b){
    return 1LL*a*b%mod;
}

int dist[nax][nax];
void floyd(){
  // Hay que saber inicializar el array d.
    forn(k,n){
        forn(u,n){
            forn(v,n){
                dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
            }
        }
    }
}

int binpow(int b, int e) {
	int ans = 1;
	for (; e; b = 1LL*b*b%mod, e /= 2)
		if (e&1) ans = 1LL*ans*b%mod;
	return ans;
}

int inv(int x){
    return binpow(x, mod - 2);
}

int C(int n, int r){
    return mlt(fact[n], inv(mlt(fact[n - r], fact[r])));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20);
    cin >> n >> m >> c;
    fact[0] = 1;
    for1(i, 1000)fact[i] = mlt(fact[i - 1], i);
    forn(i, n){
        forn(j, n){
            if(i == j)continue;
            dist[i][j] = inf;
        }
    }
    forn(i, m){
        int u, v;
        cin >> u >> v;
        dist[u][v] = 1;
        dist[v][u] = 1;
    }
    floyd();
    int sn = (1 << n);
    alln = sn - 1;
    int nc = min(n, c);
    vector<vi> dp(sn, vi(nc + 1, 0));
    vi lst;
    forn(i, sn){
        lst.clear();
        forn(j, n){
            if(!(i & (1 << j)))lst.pb(j);
        }
        dp[i][1] = 1;
        forn(j, sz(lst)){
            fore(k, j + 1, sz(lst) - 1){
                if(dist[lst[j]][lst[k]] <= 2){
                    dp[i][1] = 0;
                }
            }
        }
    }
    dp[alln][1] = 0;
    fore(col, 1, nc - 1){
        forn(msk, sn){
            if(!dp[msk][col])continue;
            for(int subset= msk; subset; subset= (subset-1) & msk){
                int sb = (subset ^ alln);
                if(!dp[sb][1])continue;
                int nxt = sb & msk;
                dp[nxt][col + 1] = add(dp[nxt][col + 1], dp[msk][col]);
            }
        }
    }
    int ans = 0;
    for1(i, nc){
        ans = add(ans, mlt(dp[0][i], C(c, i)));
    }
    cout << ans << el;
}
