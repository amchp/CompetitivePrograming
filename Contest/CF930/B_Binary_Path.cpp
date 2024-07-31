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
const int nax = 2e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int n;
int a[2][nax];
ll dp[2][nax];

string fans;

void construct(int i, int j){
    fans.pb(a[i][j] + '0');
    if(j == n - 1){
        if(i == 0)construct(i + 1, j);
        return;
    }
    if(i == 1){
        construct(i, j + 1);
        return;
    }
    if(a[i][j + 1] <= a[i + 1][j]){
        construct(i, j + 1);
    }else{
        construct(i + 1, j);
    }
}

ll cnt(int i, int j){
    // d(i);
    // d(j);
    ll& ans = dp[i][j];
    if(ans != -1)return dp[i][j];
    ans = 0;
    if(i == 1){
        if(a[i][j + 1] == (fans[i + j + 1] - '0'))ans = cnt(i, j + 1);
    }
    else{
        if(a[i][j + 1] == (fans[i + j + 1] - '0'))ans = cnt(i, j + 1);
        if(a[i + 1][j] == (fans[i + j + 1] - '0'))ans += cnt(i + 1, j);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        fans.clear();
        forn(i, 2){
            forn(j, n){
                char c;
                cin >> c;
                a[i][j] = c - '0';
                dp[i][j] = -1;
            }
        }
        construct(0, 0);
        cout << fans << el;
        dp[1][n - 1] = 1;
        dp[0][n] = 0;
        cout << cnt(0, 0) << el;
    }
}
