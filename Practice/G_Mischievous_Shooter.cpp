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

int n, m, k, nm;
vector<vi> a;

void rotate(){
    vector<vi> ra(m, vi(n));
    forn(i, n){
        forn(j, m)ra[j][n - i - 1] = a[i][j];
    }
    a = ra;
    swap(n, m);
}

int solve(){
    vector<vi> pred(nm);
    vector<vi> prer(n, vi(m));
    vector<vi> prec(n, vi(m));
    forn(i, n){
        forn(j, m){
            prer[i][j] = a[i][j] + (j != 0 ? prer[i][j - 1] : 0);
        }
    }
    forn(j, m){
        forn(i, n){
            prec[i][j] = a[i][j] + (i != 0 ? prec[i - 1][j] : 0);
        }
    }
    forn(j, m){
        forn(i, n){
            pred[i + j].pb(a[i][j]);
        }
    }
    forn(i, nm){
        for1(j, sz(pred[i]) - 1){
            pred[i][j] += pred[i][j - 1];
        }
        // forn(j, sz(pred[i]))cout << pred[i][j] << ' ';
        // cout << el;
    }
    int fans = 0;
    int knm = min(k + 1, nm);
    forn(i, knm){
        fans += pred[i][min(i, sz(pred[i]) - 1)];
    }
    // d(fans);
    int ans = fans;
    forn(i, n){
        int cans = fans;
        for1(j, m - 1){
            int sbt = prec[min(i + k, n - 1)][j - 1] - (i != 0 ? prec[i - 1][j - 1] : 0);
            cans -= sbt;
            int ni = i + k;
            int dig = ni + j;
            // d(i);
            // d(j);
            // d(dig);
            if(dig < nm){
                int nj = j + k;
                int edig = min(nj - (dig >= n ? dig - (n - 1) : 0), sz(pred[dig]) - 1);
                int idig = max(j - (dig >= n ? dig - (n - 1): 0), 0);
                int add = pred[dig][edig] - (idig != 0 ? pred[dig][idig - 1] : 0);
                cans += add;
                // d(idig);
                // d(edig);
                // d(add);
            }
            // d(min(i + k, n - 1));
            // d(sbt);
            // d(cans);
            // cout << "####" << el;
            ans = max(ans, cans);
        }
        if(i == n - 1)break;
        fans -= prer[i][min(k, m - 1)];
        int ni = i + 1;
        int dig = ni + k;
        if(dig < nm){
            int edig = min(k - (dig >= n ? (dig - (n - 1)) : 0), sz(pred[dig]) - 1);
            // if(edig < 0){
            //     d(ni);
            //     d(k);
            //     d(dig);
            //     d(edig);
            // }
            fans += pred[dig][edig];
        }
        ans = max(ans, fans);
    }
    return ans;
}

void sol(){
    cin >> n >> m >> k;
    nm = n+m-1;
    a.resize(n);
    forn(i, n){
        a[i].resize(m);
        forn(j, m){
            char c;
            cin >> c;
            a[i][j] = c == '#';
        }
    }
    // forn(i, n){
    //     forn(j, m)cout << a[i][j] << ' ';
    //     cout << el;
    // }
    // cout << el;
    int ans = solve();
    rotate();
    // forn(i, n){
    //     forn(j, m)cout << a[i][j] << ' ';
    //     cout << el;
    // }
    // cout << el;
    ans = max(ans, solve());
    rotate();
    // forn(i, n){
    //     forn(j, m)cout << a[i][j] << ' ';
    //     cout << el;
    // }
    // cout << el;
    ans = max(ans, solve());
    rotate();
    // forn(i, n){
    //     forn(j, m)cout << a[i][j] << ' ';
    //     cout << el;
    // }
    // cout << el;
    ans = max(ans, solve());
    cout << ans << el;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        sol();
    }
}
