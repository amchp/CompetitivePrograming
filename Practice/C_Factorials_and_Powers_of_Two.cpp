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

vector<ll> fac;
int ans;


void sol(ll val, int bm){
    int cAns = 0;
    forn(i, fac.size()){
        int bit = 1 << i;
        if(bm & bit){
            cAns++;
            val -= fac[i];
        }
    }
    if(val < 0)return;
    forn(i, 63){
        if(1LL << i & val)cAns++;
    }
    // cout << cAns << el;
    ans = min(cAns, ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    ll i = 1;
    fac.pb(1);
    while(fac.back()*(ll)(fac.size()+1) <= 1e12){
        fac.pb(fac.back()*(ll)(fac.size()+1));
    }
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ans = inf;
        int end = 1 <<fac.size();
        forn(i, end){
            sol(n, i);
        }
        cout << ans << el;
    }
}
