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
        vector<vi> bits(32);
        vector<vi> nBits(32);
        forn(i, n){
            cin >> a[i];
            forn(j, 32){
                if(a[i] & (1 << j)){
                    bits[j].pb(i);
                }else{
                    nBits[j].pb(i);
                }
            }
        }
        forn(i, 32){
            nBits[i].pb(n);
        }
        vector<vector<ii>> cBits(n);
        forn(i, n){
            set<int> cNI;
            forn(j, 32){
                if(a[i] & (1 << j)){
                    int nNI = (*upper_bound(all(nBits[j]), i));
                    cNI.insert(nNI);
                }
            }
            int x = a[i];
            cBits[i].pb({x, i});
            for(int nNI : cNI){
                x &= a[nNI];
                cBits[i].pb({x, nNI});
            }
        }
        // forn(i, n){
        //     d(i);
        //     forn(j, sz(cBits[i])){
        //         d(cBits[i][j].first);
        //         d(cBits[i][j].second);
        //     }
        // }
        int q;
        cin >> q;
        forn(i, q){
            int l, k;
            cin >> l >> k;
            l--;
            if(k > a[l]){
                cout << -1 << ' ';
                continue;
            }
            int ans = n - 1;
            forn(j, sz(cBits[l])){
                ans = cBits[l][j].second - 1;
                if(cBits[l][j].first < k)break;
            }
            ans++;
            cout << ans << ' ';
        }
        cout << el;
    }
}