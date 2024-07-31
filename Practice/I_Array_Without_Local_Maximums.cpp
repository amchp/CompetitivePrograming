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

const int nax = 1e5 + 200;
const int inf = 1e9;
const ld pi = acos(-1);
const ld eps = 1e-9;
const int mod = 998244353;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int dp[nax][201][3];
int pre[201][3];

int add(int a, int b){
    int ans = a + b;
    if(ans >= mod)ans -= mod;
    return ans;
}

int sbt(int a, int b){
    int ans = a - b;
    if(ans < 0)ans += mod;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n;
    cin >> n;
    vi a(n);
    forn(i, n)cin >> a[i];
    if(a[0] == -1){
        for1(i, 200){
            dp[0][i][0] = 1;
        }
    }else{
        dp[0][a[0]][0] = 1;
    }
    
    for1(ind, n - 1){
        for1(val, 200){
            pre[val][0] = add(dp[ind - 1][val][0], pre[val - 1][0]);
            pre[val][1] = add(dp[ind - 1][val][1], pre[val - 1][1]);
            pre[val][2] = add(dp[ind - 1][val][2], pre[val - 1][2]);
        }
        for1(val, 200){
            if(a[ind] != -1 && a[ind] != val)continue;
            dp[ind][val][0] =  add(
                add(
                    pre[val - 1][0], 
                    pre[val - 1][1]
                ), 
                pre[val - 1][2]
            );
            dp[ind][val][1] = add(
                add(
                    sbt(pre[val][0], pre[val - 1][0]),
                    sbt(pre[val][1], pre[val - 1][1])
                ),
                sbt(pre[val][2], pre[val - 1][2])
            );
            dp[ind][val][2] = add(
                sbt(pre[200][2], pre[val][2]),
                sbt(pre[200][1], pre[val][1])
            );
        }
    }
    int ans = 0;
    for1(val, 200){
        ans = add(ans, add(dp[n - 1][val][1], dp[n - 1][val][2]));
    }
    cout << ans << el;
}
