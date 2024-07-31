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
        ll x, m;
        cin >> x >> m;
        vi xones;
        vi mones;
        // ford(i, 63)cout << bool(x & (1LL << i));
        // cout << el;
        // ford(i, 63)cout << bool(m & (1LL << i));
        // cout << el;
        ford(i, 63){
            int ind = 62 - i;
            if(x & (1LL << i))xones.pb(ind);
            if(m & (1LL << i))mones.pb(ind);
        }
        // for(int& v : xones)cout << v << ' ';
        // cout << el;
        // for(int& v : mones)cout << v << ' ';
        // cout << el;
        if(sz(xones) == 1){
            cout << -1 << el;
            continue;
        }
        if(mones[0] == xones[0]){
            cout << 1 << el;
            cout << x << ' ' << m << el;
            continue;
        }
        if(xones[1] <= mones[0]){
            ll aux = m | (1LL << (62 - xones[1]));
            assert(aux < x);
            assert((aux ^ x) < x);
            // ford(i, 63)cout << bool(x & (1LL << i));
            // cout << el;
            // ford(i, 63)cout << bool(aux & (1LL << i));
            // cout << el;
            // ford(i, 63)cout << bool(m & (1LL << i));
            // cout << el;
            if(aux == m){
                cout << 1 << el;
                cout << x << ' ' << m << el;
                continue;
            }
            assert(m < aux);
            assert((aux ^ m) < aux);
            cout << 2 << el;
            cout << x << ' ' << aux << ' ' << m << el;
        }else{
            cout << -1 << el;
        }
    }
}
