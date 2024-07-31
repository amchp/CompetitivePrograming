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
        vi a(n);
        vector<vi> mp(n);
        forn(i, n){
            cin >> a[i];
            mp[a[i]].pb(i);
        }
        int zeros = sz(mp[0]);
        if(zeros == 0){
            cout << 2 << el;
            cout << 1 << ' ' << 1 << el;
            cout << 2 << ' ' << n << el;
            continue;
        }
        if(zeros == 1){
            cout << -1 << el;
            continue;
        }
        int num = 1;
        while(sz(mp[num]) && 2 <= sz(mp[num])){
            ++num;
        }
        if(sz(mp[num]) && 2 > sz(mp[num])){
            cout << -1 << el;
            continue;
        }
        vector<ii> ans(2);
        int r = 0;
        forn(i, num){
            r = max(r, mp[i][0]);
        }
        bool pass = true;
        forn(i, num){
            auto it = upper_bound(all(mp[i]), r);
            pass &= it != mp[i].end();
        }
        if(pass){
            cout << 2 << el;
            cout << 1 << ' ' << r + 1 << el;
            assert(r + 2 <= n);
            cout << r + 2 << ' ' << n << el;
        }else{
            cout << -1 << el;
        }
    }
}
