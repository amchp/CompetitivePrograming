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
const int nax = 710;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int n;
int a[nax];
short dp[nax][nax][2];
bool trans[nax][nax];

bool sol(int l, int r, bool rgt){
    if(r < l)return true;
    short& ans = dp[l][r][rgt];
    if(ans != -1)return ans;
    ans = false;
    if(!rgt){
        fore(i, l, r){
            if(trans[l - 1][i]){
                ans |= sol(l, i - 1, 1) && sol(i + 1, r, 0);
            }
        }
    }else{
        fore(i, l, r){
            if(trans[i][r + 1]){
                ans |= sol(l, i - 1, 1) && sol(i + 1, r, 0);
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    forn(i, n)cin >> a[i];
    forn(i, n){
        forn(j, n){
            trans[i][j] = __gcd(a[i], a[j]) > 1;
        }
    }
    bool ans = false;
    forn(i, n){
        ans |= sol(0, i - 1, 1) && sol(i + 1, n - 1, 0);
    }
    // forn(l, n){
    //     forn(r, n)cout << dp[l][r][0] << ' ';
    //     cout << el;
    // }
    // cout << el;
    // forn(l, n){
    //     forn(r, n)cout << dp[l][r][1] << ' ';
    //     cout << el;
    // }
    if(ans)cout << "Yes" << el;
    else cout << "No" << el;
}
