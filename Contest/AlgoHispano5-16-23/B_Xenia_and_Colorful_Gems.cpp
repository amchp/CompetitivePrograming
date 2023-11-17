#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <sstream>  // istringstream buffer(myString);
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <math.h>
#include <unordered_map>
#include <queue>
#include <array>
#include <set>
#include <numeric>

using namespace std;


typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi; // int vec
typedef vector<ll> vll; // int vec
typedef vector<vi> vvi; // int vec vec
typedef vector<vll> vvll; // int vec
typedef vector<pii> vpi; // int int pair vec
typedef vector<pll> vpll; // int int pair vec

const double pi = 3.1415926535897932384626433832795;
const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll INFLL = 1000000000000000005LL;
const ld EPS = 1e-9;
int dirx[8] = { -1, 0, 0, 1, -1, -1, 1, 1 };
int diry[8] = { 0, 1, -1, 0, -1, 1, -1, 1 };

#define d(x) cout << #x << " = " << x << endl;
#define ios ios_base::sync_with_stdio(0), cin.tie(0);
#define forn(i, n) for (int i=0; i< (int)n; ++i) 
#define forab(i, a, b) for (int i=a; i< (int)b; ++i) 
#define foreach(a, b) for (auto&(a) : (b))
#define formap(map) for (const auto &[key, value] : map)
#define all(v) v.begin(), v.end()
#define allar(arr, sz) arr, arr + sz
#define ms(ar, val) memset(ar, val, size)
#define pq(type) priority_queue<type> 
#define pqd(type) priority_queue<type,vector<type>,greater<type> >
#define umap unordered_map
#define uset unordered_set
#define imax INT_MAX
#define imin INT_MIN
#define pb push_back
#define mp make_pair
#define fi first 
#define se second 
#define nl "\n"
#define in(t) while (t--)

ll calc(ll x, ll y, ll z){
    ll dist1 = x - y;
    ll dist2 = y - z;
    ll dist3 = x - z;
    return dist1*dist1 + dist2*dist2 + dist3*dist3;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    in(t){
        int n[3], v;
        forn(i, 3){
            cin >> n[i];
        }
        vvi a(3);
        forn(i, 3){
            forn(j, n[i]){
                cin >> v;
                a[i].pb(v);
            }
        }
        forn(i, 3){
            sort(all(a[i]));
        }
        forn(i, 3){
            forn(j, n[i]){
                cout << a[i][j] << ' ';
            }
            cout << nl;
        }
        int it[3] = {0, 0, 0};
        ll ans = __LONG_LONG_MAX__;
        bool inc = true; 
        while(inc){
            cout << a[0][it[0]] << ' ' << a[1][it[1]] << ' ' << a[2][it[2]] << nl;
            vpi so(3);
            // cout << calc(a[0][it[0]], a[1][it[1]], a[2][it[2]]) << nl;
            ans = min(ans, calc(a[0][it[0]], a[1][it[1]], a[2][it[2]]));
            so[0] = mp(a[0][it[0]], 0);
            so[1] = mp(a[1][it[1]], 1);
            so[2] = mp(a[2][it[2]], 2);
            sort(all(so));
            inc = false;
            forn(i, 3){
                // cout << so[i].first << ' ' << so[i].second << nl;
                if(it[so[i].second] != n[so[i].second] - 1){
                    // cout << "HI" << nl;
                    inc = true;
                    it[so[i].second]++;
                    break;
                }
            }
        }
        cout << ans << nl;
    }
}