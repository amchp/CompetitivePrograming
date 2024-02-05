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
        string s;
        cin >> s;
        vector<vi> mp(26);
        forn(i, n){
            char& c = s[i];
            mp[c - 'a'].pb(i);
        }
        vi idx;
        int ans = 0;
        ford(i, 26){
            int st;
            if(idx.empty()){
                st = 0;
            }else{
                st = upper_bound(all(mp[i]), idx.back()) - mp[i].begin();
            }
            if(!idx.empty())ans += sz(mp[i]) - st;
            fore(j, st, sz(mp[i]) - 1){
                idx.pb(mp[i][j]);
            }
        }
        // forn(i, sz(idx)){
        //     cout << idx[i] << ' ';
        // }
        // cout << el;
        forn(i, sz(idx) / 2){
            int ind = sz(idx) - i  - 1;
            swap(s[idx[i]], s[idx[ind]]);
        }
        // d(s);
        // d(ans);
        for1(i, n - 1){
            if(s[i - 1] > s[i])ans = -1;
        }
        cout << ans << el;
    }
}
