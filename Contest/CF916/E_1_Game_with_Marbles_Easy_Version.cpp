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

const ll inf = 1e16;
const int nax = 100;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int n;
int a[nax];
int b[nax];

ll min_max(int msk, int turn){
    // d(msk);
    // d(turn);
    if(msk == (1 << n) - 1)return 0;
    if(turn == 0){
        ll ans = -inf;
        forn(i, n){
            if(!(msk & (1 << i))){
                ans = max(ans, min_max(msk | (1 << i), !turn) + a[i] - 1);
            }
        }
        return ans;
    }
    ll ans = inf;
    forn(i, n){
        if(!(msk & (1 << i))){
            ans = min(ans, min_max(msk | (1 << i), !turn) - (b[i] - 1));
        }
    }
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
        cin >> n;
        forn(i, n)cin >> a[i];
        forn(i, n)cin >> b[i];
        cout << min_max(0, 0) << el;
    }
}
