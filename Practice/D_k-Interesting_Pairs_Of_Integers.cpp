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
const int nax = 1<<14;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n, k;
    cin >> n >> k;
    int a[nax];
    memset(a, 0, sizeof(a));
    forn(i, n){
        int v;
        cin >> v;
        a[v]++;
    }
    ll ans = 0;
    forn(i, nax){
        int cnt = 0;
        forn(j, 15){
            if(i & (1<< j))cnt++;
        }
        if(cnt != k)continue;
        forn(j, nax){
            int xo = i^j;
            if(j == xo){
                ans += (ll)(a[j]-1)*a[j];
            }else{
                ans += (ll)a[j]*a[xo];
            }
        }
    }
    ans /= 2;
    cout << ans << el;
}
