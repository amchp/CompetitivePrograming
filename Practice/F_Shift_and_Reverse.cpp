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

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int n, n2;
int dp[nax][2];

bool check_rot(vi& a, int rev){
    int i = 0;
    bool pass = true;
    while(i < n){
        int j = i + 1;
        while(j < i + n && a[j - 1] <= a[j])++j;
        if(j == i + n){
            pass = true;
            dp[i][rev] = 0;
            return true;
        }
        i = j;
    }
    return false;
}

int solve(int i, int rev){
    int& ans = dp[i][rev];
    if(ans != -1)return ans;
    ans = inf;
    ans = min(ans, solve((i - 1 + n) % n, rev) + 1);
    ans = min(ans, solve((n - i) % n, !rev) + 1);
    return ans;
}

int sol(){
    cin >> n;
    n2 = 2*n;
    vi a(n2);
    vi ra(n2);
    forn(i, n){
        forn(j, 2)dp[i][j] = -1;
        cin >> a[i];
        ra[n - i - 1] = a[i];
    }
    fore(i, n, n2 - 1){
        a[i] = a[i - n];
        ra[i] = ra[i - n];
    }
    bool pass = check_rot(a, 0);
    pass = check_rot(ra, 1) | pass;
    if(!pass)return -1;
    return solve(0, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        cout << sol() << el;
    }
}
