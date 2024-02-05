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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n;
    cin >> n;
    vi a(n);
    forn(i, n)cin >> a[i];
    int q;
    cin >> q;
    vi ls(n, 0);
    vi mxs(q, -1);
    forn(i, q){
        int o, f;
        cin >> o >> f;
        if(o == 1){
            int x;
            cin >> x;
            --f;
            ls[f] = i;
            a[f] = x;
        }else{
            mxs[i] = f;
        }
    }
    vi smxs(q);
    smxs[q - 1] = mxs[q - 1];
    ford(i, q - 1){
        smxs[i] = max(smxs[i + 1], mxs[i]);
    }
    // forn(i, n){
    //     cout << ls[i] << ' ';
    // }
    // cout << el;
    // forn(i, q){
    //     cout << mxs[i] << ' ';
    // }
    // cout << el;
    // forn(i, q){
    //     cout << smxs[i] << ' ';
    // }
    // cout << el;
    forn(i, n){
        cout << max(a[i], smxs[ls[i]]) << ' ';
    }
    cout << el;
}
