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
const int nax = 5e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int szs;
ii vals[nax];
int dp[nax];

int sol(int mex){
    if(mex == 0){
        return 0;
    }
    if(dp[mex] != -1){
        return dp[mex];
    }
    int& ans = dp[mex] = inf;
    forn(i, szs){
        int v = vals[i].first;
        int o = vals[i].second;
        // cout << v << el;
        if(mex < v)break;
        ans = min(ans, sol(v) + (o - 1)*mex + v);
    }
    // cout << mex << ' ' << ans << el;
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
        int n;
        cin >> n;
        map<int, int> mVals;
        forn(i, n){
            int v;
            cin >> v;
            mVals[v]++;
        }
        szs = 0;
        for(auto &[v, o] : mVals){
            vals[szs] = {v, o};
            dp[szs] = -1;
            szs++;
        }
        int mex = 0;
        for(auto &[v, o] : mVals){
            if(v != mex)break;
            mex++;
        }
        dp[mex] = -1;
        cout << sol(mex) << el;
        // forn(i, szs){
        //     cout << i << ' ' << dp[i] << el;
        // }
    }
}
