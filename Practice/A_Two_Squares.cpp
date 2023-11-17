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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int u, v;
    vpi a(4);
    vpi b(4);
    forn(i, 4){
        cin >> u >> v;
        a[i] = mp(u, v);
    }
    forn(i, 4){
        cin >> u >> v;
        b[i] = mp(u, v);
    }
    sort(all(a));
    pii x = a[0];
    pii y;
    forab(i, 1, 4){
        if(x.first != a[i].first && x.second != a[i].second){
            y = a[i];
        }
    }
    pii xR = mp(INF, INF);
    pii yR;
    forn(i, 4){
        xR = min(b[i], xR);
    }
    xR = mp(xR.first + xR.second, xR.first - xR.second);
    forn(i, 4){
        if(b[i].first + b[i].second != xR.first && b[i].first - b[i].second != xR.second){
            yR = mp(b[i].first + b[i].second, b[i].first - b[i].second);
        }
    }
    bool pass = false;
    forn(i, 4){
        pass |= x.first <= b[i].first && b[i].first <= y.first &&
        x.second <= b[i].second && b[i].second <= y.second;
    }
    int xRr, yRr;
    forn(i, 4){
        xRr = a[i].first + a[i].second;
        yRr = a[i].first - a[i].second;
        pass |= xR.first <= xRr && xRr <= yR.first &&
        xR.second <= yRr && yRr <= yR.second;
    }
    double slope, intercept, x1, x2, y1, y2, yl, ym, xl, xm;
    forn(i, 4){
        slope = (b[(i + 1) % 4].second - b[i].second) / (b[(i + 1) % 4].first - b[i].first);
        intercept = b[i].second - b[i].first*slope;
        y1 = slope*x.first + intercept;
        y2  = slope*y.first + intercept;
        x1 = (x.second - intercept) / slope;
        x2 = (y.second - intercept) / slope;
        yl = min(b[(i + 1) % 4].second, b[i].second);
        ym = max(b[(i + 1) % 4].second, b[i].second);
        xl = min(b[(i + 1) % 4].first, b[i].first);
        xm = max(b[(i + 1) % 4].first, b[i].first);
        pass |= yl <= y1 && y1 <= ym && x.second <= y1 && y1 <= y.second;
        pass |= yl <= y2 && y2 <= ym && x.second <= y2 && y2 <= y.second;
        pass |= xl <= x1 && x1 <= xm && x.first <= x1 && x1 <= y.first;
        pass |= xl <= x2 && x2 <= xm && x.first <= x2 && x2 <= y.first;
    }
    if(pass)cout << "YES" << nl;
    else cout << "NO" << nl;
}