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
typedef vector<vector<vi>> vvvi;
typedef vector<vi> vvi;

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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi a(n);
        forn(i, n)cin >> a[i];
        vvvi dp = vvvi(n + 1, vvi(n + 1, vi(n + 1, inf)));
        dp[0][0][0] = 0;
        forn(i, n){
            forn(j, n){
                forn(k, n + 1){
                    if(dp[i][j][k] < inf){
                        // Z
                        {
                            int ni = i + 1;
                            int nj = j > 0 ? j + 1 : (k == 0) ? 1 : 0;
                            int nk = max(0, k - 1);
                            dp[ni][nj][nk] = min(dp[ni][nj][nk], dp[i][j][k]);
                        }
                        // L
                        {
                            int ni = i + 1;
                            int nj = j > 0 ? j + 1 : 0;
                            if (nj <= a[i])
                                nj = 0;
                            int nk = max(0, k - 1);
                            dp[ni][nj][nk] = min(dp[ni][nj][nk], dp[i][j][k] + 1);
                        }
                        // R
                        {
                            int ni = i + 1;
                            int nj = j > 0 ? j + 1 : 0;
                            int nk = max(a[i] - 1, k - 1);
                            dp[ni][nj][nk] = min(dp[ni][nj][nk], dp[i][j][k] + 1);
                        }
                    }
                }
            }
        }
        int ans = inf;
        forn(i, n + 1)ans = min(ans, dp[n][0][i]);
        cout << ans << el;
    }
}
