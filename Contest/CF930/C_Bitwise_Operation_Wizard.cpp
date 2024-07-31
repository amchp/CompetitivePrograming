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

int qstn(int a, int b, int c, int d){
    cout << "? " << a << ' ' << b << ' ' << c << ' ' << d << endl;
    char ch;
    cin >> ch;
    if(ch == '>')return -1;
    if(ch == '=')return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int mx = 0;
        for1(i, n - 1){
            int res = qstn(mx, mx, i, i);
            if(res == 1){
                mx = i;
            }
        }
        vi candidates;
        if(mx == 0)candidates.pb(1);
        else candidates.pb(0);
        forn(i, n){
            if(mx == i || candidates[0] == i)continue;
            int res = qstn(mx, candidates[0], mx, i);
            if(res == 1){
                candidates.clear();
                candidates.pb(i);
            }
            if(res == 0)candidates.pb(i);
        }
        int mn = candidates[0];
        for1(i, sz(candidates) - 1){
            int res = qstn(mn, mn, candidates[i], candidates[i]);
            if(res == -1){
                mn = candidates[i];
            }
        }
        cout << "! " << mn << ' ' << mx << el;
    }
}
