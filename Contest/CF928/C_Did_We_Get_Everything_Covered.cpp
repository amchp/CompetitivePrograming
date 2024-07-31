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
#define d(x) cerr << #x << " " << x << el
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        int n, k, m;
        cin >> n >> k >> m;
        string s;
        cin >> s;
        vi dp(k, 0);
        vector<vi> mp(26);
        forn(i, m){
            int c = s[i] - 'a';
            mp[c].pb(i);
        }
        forn(i, k){
            mp[i].pb(m);
        }
        ford(i, m){
            int mn = inf;
            forn(j, k){
                mn = min(mn, dp[j]);
            }
            int c = s[i] - 'a';
            if(dp[c] == mn)++dp[c];
        }
        int mn = inf;
        int mind = 0;
        forn(i, k){
            // cout << dp[i] << ' ';
            if(dp[i] < mn){
                mn = dp[i];
                mind = i;
            }
        }
        // cout << el;
        if(mn >= n)cout << "YES" << el;
        else{
            cout << "NO" << el;
            string ans;
            ans.pb('a' + mind);
            int ind = mp[mind][0];
            // d(mind);
            while(ind < m){
                int sind = 0;
                int mxnxt = ind;
                forn(i, k){
                    int nxt = *upper_bound(all(mp[i]), ind);
                    if(mxnxt < nxt){
                        mxnxt = nxt;
                        sind = i;
                    }
                }
                ans.pb('a' + sind);
                ind = mxnxt;
                // d(ind);
            }
            while(sz(ans) < n){
                ans.pb('a');
            }
            cout << ans << el;
        }
    }
}
