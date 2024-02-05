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
const int mod = 998244353;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int add(int a, int b){
    int ans = a + b;
    if(ans >= mod)ans -= mod;
    return ans;
}

int n;
int dp[nax][210][4];
int a[nax];

int sol(int ind, int x, int st){
    // d(ind);
    // d(x);
    // d(st);
    if(ind == n)return 1;
    int& ans = dp[ind][x][st];
    // d(ans);
    if(ans != -1)return ans;
    ans = 0;
    // d(ans);
    if(ind == n - 1){
        if(a[ind] != -1){
            if(st == 2){
                ans = x == a[ind];
                return ans;
            }
            if(a[ind] <= x)ans = 1;
            return ans;
        }
        if(st == 2){
            ans = add(ans, sol(ind + 1, x, 1));
            return ans;
        }
        if(x > 1)ans = add(ans, sol(ind, x - 1, 0));
        ans = add(ans, sol(ind + 1, x, 1));
        return ans;
    }
    if(st == 0){
        ans = add(ans, sol(ind + 1, x, 1));
        if(x > 1)ans = add(ans, sol(ind, x - 1, 0));
    }else if(st == 1){
        if(a[ind] != -1){
            if(a[ind] <= x)ans = sol(ind + 1, a[ind], 1);
            else ans = sol(ind + 1, a[ind], 2);
            return ans;
        }
        if(x < 200)ans = add(ans, sol(ind, x + 1, 3));
        ans = add(ans, sol(ind + 1, x, 1));
        if(x > 1)ans = add(ans, sol(ind, x - 1, 0));
    }else if(st == 2){
        if(a[ind] != -1){
            if(a[ind] > x){
                // d(x);
                ans = sol(ind + 1,  a[ind], 2);
            }
            if(a[ind] == x){
                // d(x);
                ans = sol(ind + 1, a[ind], 1);
            }
            return ans;
        }
        ans = add(ans, sol(ind + 1, x, 1));
        if(x < 200)ans = add(ans, sol(ind, x + 1, 3));
    }else if(st == 3){
        ans = add(ans, sol(ind + 1, x, 2));
        if(x < 200)ans = add(ans, sol(ind, x + 1, 3));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    cin >> n;
    forn(i, n)cin >> a[i];
    if(n == 2){
        if(a[0] == -1 && a[1] == -1)cout << 200 << el;
        else if(a[0] == a[1])cout << 1 << el;
        else cout << 0 << el;
        return 0;
    }
    memset(dp, -1, sizeof(dp));
    int ans = sol(1, max(a[0], 1), 2);
    cout << ans << el;
}
