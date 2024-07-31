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

int n, m;
int dp[nax];
int nxt[nax];
int cnt[nax];

int sol(int ind){
    // d(ind);
    if(ind == n + 1){
        return 0;
    }
    int& ans = dp[ind];
    if(ans != -1)return ans;
    ans = max(sol(ind + 1), sol(nxt[ind]) + cnt[ind]);
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
        cin >> n >> m;
        vector<ii> itr(m);
        forn(i, m){
            cin >> itr[i].fi >> itr[i].se;
        }
        sort(all(itr));
        for1(i, n){
            dp[i] = -1;
            cnt[i] = 0;
        }
        int mr = 0;
        int j = 0;
        map<int, int> mp;
        int cts = 0;
        for1(i, n){
            while(j < m && itr[j].fi == i){
                mr = max(mr, itr[j].se);
                mp[itr[j].se]++;
                cts++;
                ++j;
            }
            auto it = mp.begin();
            if(it != mp.end() && (*it).fi == (i - 1)){
                cts -= (*it).se;
                mp.erase(it);
            }
            nxt[i] = max(i + 1, mr + 1);
            cnt[i] = cts;
            // d(i);
            // d(nxt[i]);
            // d(cnt[i]);
        }
        cout << sol(1) << el;
    }
}
