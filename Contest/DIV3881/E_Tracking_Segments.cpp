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
#include <complex>

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
typedef complex<double> cd;

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

int main() {
    int T;
    cin >> T;
    in(T){
        int n, m;
        cin >> n >> m;
        vi arr(n + 1);
        vpi intervals(m);
        forn(i, m){
            int l, r;
            cin >> l >> r;
            intervals[i] = mp(l, r);
        }
        int q;
        cin >> q;
        vi moves(q);
        forn(i, q)cin >> moves[i];
        int l = -1, r = q + 1;
        while(l + 1 < r){
            int md = l + (r - l) / 2;
            // cout << md << nl;
            forn(i, n + 1){
                arr[i] = 0;
            }
            forn(i, md){
                arr[moves[i]] = 1;
            }
            forab(i, 1, n + 1){
                arr[i] += arr[i - 1];
            }
            bool pass = false;
            forn(i, m){
                int iL = intervals[i].first;
                int iR = intervals[i].second;
                int iS = (iR - iL + 1);
                // cout << iL << ' ' << iR << ' ' << iS << nl;
                // cout << (arr[iR] - arr[iL - 1]) << ' ' << (iS / 2) << nl;
                pass |= (arr[iR] - arr[iL - 1]) > (iS / 2);
                if(pass)break;
            }
            // d(pass)
            if(pass){
                r = md;
            }
            else{
                l = md;
            }
        }
        if(r == q + 1)cout << -1 << nl;
        else cout << r << nl;
    }
}