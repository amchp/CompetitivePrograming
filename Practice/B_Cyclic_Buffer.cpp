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
const int nax = 1e6 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int n, k;
ll dp[nax][2];
int pos[nax];

bool in_interval_left(int ind, int nxt){
    int r = pos[ind] + k - 1;
    if(r >= n){
        return ((pos[ind] <= pos[nxt] && pos[nxt] < n) || (0 <= pos[nxt] && pos[nxt] <= r - n));
    }else{
        return pos[ind] <= pos[nxt] && pos[nxt] <= r;
    }
}

bool in_interval_right(int ind, int nxt){
    int l = pos[ind] - k + 1;
    if(l < 0){
        return ((0 <= pos[nxt] && pos[nxt] <= pos[ind]) || (n - abs(l) <= pos[nxt] && pos[nxt] < n));
    }
    return l <= pos[nxt] && pos[nxt] <= pos[ind];
}

ll dist(int x, int y){
    return min((x - y + n) % n, (y - x + n) % n);
}

ll distL(int ind, int p, int nxt){
    if(p == 0){
        return dist(pos[nxt], pos[ind]);
    }
    int left = (pos[ind] - (k - 1) + n) % n;
    return dist(pos[nxt], left);
}

ll distR(int ind, int p, int nxt){
    if(p == 1){
        return dist(pos[nxt], pos[ind]);
    }
    int right = (pos[ind] + k - 1) % n;
    return dist(pos[nxt], right);
}


ll sol(int ind, int p){
    if(ind == n)return 0;
    ll& ans = dp[ind][p];
    if(ans != -1)return dp[ind][p];
    int nxt = ind + 1;
    if(p == 0){
        while(nxt < n && in_interval_left(ind, nxt))nxt++;
    }else{
        while(nxt < n && in_interval_right(ind, nxt))nxt++;
    }
    if(nxt == n)return 0;
    return ans = min(sol(nxt, 0) + distL(ind, p, nxt), sol(nxt, 1) + distR(ind, p, nxt));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        int f = -1;
        forn(i, n){
            int v;
            cin >> v;
            v--;
            if(f == -1)f = v;
            pos[v] = i;
            dp[i][0] = -1;
            dp[i][1] = -1;
        }
        int strt = 0;
        while(strt < n && in_interval_left(f, strt))strt++;
        if(strt == n){
            cout << 0 << el;
            continue;
        }
        // cout << strt << ' ' << f << el;
        cout << min(sol(strt, 0) + distL(f, 0, strt), sol(strt, 1) + distR(f, 0, strt)) << el;
        // d(f);
        // d(distL(f, 0, 0));
        // d(distR(f, 0, 0));
        // forn(i, n){
        //     cout << dp[i][0] << ' ' << dp[i][1] << el;
        // }
    }
}
