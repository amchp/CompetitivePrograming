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

struct pt{
    ll x, y;
    pt(){}
    pt(ll x, ll y): x(x), y(y){}
    ll hm(pt p){
        return abs(x - p.x) + abs(y - p.y);
    }
};

pt neurons[nax][8];
ll dp[nax][8];
int s[nax];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n;
    cin >> n;
    vector<bool> vis(nax, false);
    forn(i, n){
        ll x, y, col;
        cin >> x >> y >> col;
        --col;
        pt p = pt(x, y);
        if(vis[col]){
            pt cur = neurons[col][0];
            if(cur.x < p.x)neurons[col][0] = p;
            cur = neurons[col][1];
            if(cur.x + cur.y < p.x + p.y)neurons[col][1] = p;
            cur = neurons[col][2];
            if(cur.y < p.y)neurons[col][2] = p;
            cur = neurons[col][3];
            if(-cur.x + cur.y < -p.x + p.y)neurons[col][3] = p;
            cur = neurons[col][4];
            if(-cur.x < -p.x)neurons[col][4] = p;
            cur = neurons[col][5];
            if(-cur.x - cur.y < -p.x - p.y)neurons[col][5] = p;
            cur = neurons[col][6];
            if(-cur.y < -p.y)neurons[col][6] = p;
            cur = neurons[col][7];
            if(cur.x - cur.y < p.x - p.y)neurons[col][7] = p;
            continue;
        }
        forn(j, 8){
            neurons[col][j] = p;
        }
        vis[col] = true;
    }
    int t;
    cin >> t;
    while(t--){
        int m;
        cin >> m;
        forn(i, m){
            cin >> s[i];
            --s[i];
        }
        forn(j, 8){
            dp[m - 1][j] = 0;
        }
        ll ans = 0;
        ford(i, m - 1){
            forn(j, 8){
                dp[i][j] = 0;
                forn(k, 8){
                    dp[i][j] = max(dp[i][j], dp[i + 1][k] + neurons[s[i]][j].hm(neurons[s[i + 1]][k]));
                }
            }
        }
        forn(j, 8){
            ans = max(ans, dp[0][j]);
        }
        // forn(i, m){
        //     forn(j, 8){
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << el;
        // }
        cout << ans << el;
        // cout << el;
    }
}
