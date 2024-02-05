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
typedef vector<ll> vll;

const int inf = 1e9;
const int nax = 5000 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int dp[nax][nax];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20);
    int n;
    cin >> n;
    vi ones;
    vi zeros;
    memset(dp, 0, sizeof(dp));
    forn(i, n){
      int v;
      cin >> v;
      if(v == 0)zeros.pb(i);
      else ones.pb(i);
    }
    int o = sz(ones);
    int z = sz(zeros);
    vi suf(sz(zeros));
    ford(i, o){
      suf[z - 1] = dp[i + 1][z] + abs(ones[i] - zeros[z - 1]);
      ford(j, z - 1){
        suf[j] = min(suf[j + 1], dp[i + 1][j + 1] + abs(ones[i] - zeros[j]));
      }
      int e = z - (o - i - 1);
      // forn(j, z){
      //   cout << suf[j] << ' ';
      // }
      // cout << el;
      forn(j, e){
        dp[i][j] = suf[j];
      }
      fore(j, e, z){
        dp[i][j] = inf;
      }
    }
    // cout << o << ' ' << z << el;
    // forn(i, o + 1){
    //   forn(j, z){
    //     cout << dp[i][j] << ' ';
    //   }
    //   cout << el;
    // }
    int ans = inf;
    forn(j, z){
      ans = min(dp[0][j], ans);
    }
    cout << ans << el;
}
