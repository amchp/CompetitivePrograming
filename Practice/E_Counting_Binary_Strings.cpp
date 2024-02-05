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
const int nax = 2500 + 10;
const ld pi = acos(-1);
const ld eps = 1e-9;
const int mod = 998244353;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};


void solve(){
    int n, k;
    cin >> n >> k;
    int dp[n + 1][k + 1] = {};
    int ans = 0;
    fill(dp[0] + 1, dp[0] + k + 1, 1);
    for (int sum = 1; sum <= n; sum++){
        for (int cur = 1; cur <= k; cur++){
            for (int prv = 1; cur * prv <= sum and cur + prv - 1 <= k; prv++)
                dp[sum][cur] = (dp[sum][cur] + dp[sum - cur * prv][prv]) % mod;
            if (sum == n)
                ans = (ans + dp[sum][cur]) % mod;
        }
    }
    cout<<ans<<"\n";
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); 
    int tc; 
    cin >> tc;
 
    while (tc--)
        solve();
}
