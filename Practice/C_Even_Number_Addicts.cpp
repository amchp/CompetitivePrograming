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

bool dp[101][101][2][2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    in(t){
        ll n, v;
        cin >> n;
        ll even = 0, odd = 0;
        forn(i, n){
            cin >> v;
            if(v % 2 == 0){
                even++;
            }else{
                odd++;
            }
        }
        forn(i, even + 1){
            dp[i][0][0][0] = false;
            dp[i][0][0][1] = false;
            dp[i][0][1][0] = true;
            dp[i][0][1][1] = true;
        }
        forab(j, 1,odd + 1){
            dp[0][j][0][0] = dp[0][j - 1][1][1];
            dp[0][j][0][1] = dp[0][j - 1][0][0];
            dp[0][j][1][0] = dp[0][j - 1][0][1];
            dp[0][j][1][1] = dp[0][j - 1][1][0];
        }
        forab(i, 1, even + 1){
            forab(j, 1, odd + 1){
                forn(k, 2){
                    forn(l, 2){
                        if(l == 0){
                            dp[i][j][k][l] = dp[i - 1][j][k][1] && dp[i][j - 1][(k + 1) % 2][1];
                        }else{
                            dp[i][j][k][l] = dp[i - 1][j][k][0] || dp[i][j - 1][k][0];
                        }
                    }
                }
            }
        }
        bool ans = dp[even][odd][0][0];
        if(ans)cout << "Bob" << nl;
        else cout << "Alice" << nl;
    }
}