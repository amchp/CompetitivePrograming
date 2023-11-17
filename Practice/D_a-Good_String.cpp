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

int n, depth;
string s;
vi preffix[26];

int sol(int c, int l, int r){
    if(l + 1 == r){
        return s[l] != (char)('a' + c);
    }
    int m = l + (r - l) / 2;
    int distL = (m - l) - (preffix[c][m] - preffix[c][l]) + sol(c + 1, m, r);
    int distR = (m - l) - (preffix[c][r] - preffix[c][m]) + sol(c + 1, l, m);
    // cout << (char)('a' + c) << ' ' <<  l << ' ' << r << ' ' << distL << ' ' << distR << nl;
    return min(distL, distR);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    in(t){
        cin >> n;
        forn(i, 26){
            preffix[i].resize(n + 1);
            preffix[i][0] = 0;
        }
        cin >> s;
        forn(j, n){
            forn(i, 26){
                preffix[i][j + 1] = preffix[i][j] + (s[j] == (char)('a' + i));
            }
        }
        // forn(i, 26){
        //     cout << preffix[i][0] << ' ';
        //     forn(j, n){
        //         cout << preffix[i][j + 1] << ' ';
        //     }
        //     cout << nl;
        // }
        depth = log2(n) + 1;
        cout << sol(0, 0, n) << nl;
    }
}