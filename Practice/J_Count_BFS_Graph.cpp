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
const int nax = 5e3 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;
const int mod = 998244353;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int addm(int a, int b){
    int ans = a + b;
    if(ans >= mod)ans -= mod;
    return ans;
}

int subm(int a, int b){
    int ans = a - b;
    if(ans < 0)ans += mod;
    return ans;
}

int mulm(int a, int b){
    return (1LL*a*b) % mod;
}

int n;
int a[nax];
int dp[nax][nax][2];
int p2[nax];

int sol(int i, int inQueue, int first){
    if(i > n)return 1;
    if(inQueue <= 0)return 0;
    int& ans = dp[i][inQueue][first];
    if(ans != -1)return ans;
    ans = 0;
    ans = addm(ans, sol(i, inQueue - 1, true));
    if(first || a[i - 1] < a[i]){
        ans = addm(ans, mulm(sol(i + 1, inQueue + 1, false), p2[inQueue]));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for1(i, n)cin >> a[i];
    p2[0] = 0;
    p2[1] = 1;
    fore(i, 2, nax - 1)p2[i] = mulm(p2[i - 1], 2);
    cout << sol(2, 1, true) << el;
    // for1(i, n){
    //     for1(j, n){
    //         cout << dp[i][j][0] << ' ';
    //     }
    //     cout << el;
    // }
    // cout << el;
    // for1(i, n){
    //     forn(j, n){
    //         cout << dp[i][j][1] << ' ';
    //     }
    //     cout << el;
    // }
}
