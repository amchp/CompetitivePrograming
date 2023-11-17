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
const int maxn = 5005;
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

int dp[maxn][maxn];

bool sol(int ind, int turn){
    if(ind <= 0){
        return !(turn % 2);
    }
    int& v = dp[ind][turn];
    if(v != -1)return v;
    v = !(turn % 2);
    forab(i, 1, min(turn + 1, ind + 1)){
        int ind2 = min(turn + 1, ind + 1) - i;
        if(turn % 2){
            v |= sol(ind - ind2, turn + 1);
            if(v)break;
        }else{
            v &= sol(ind - ind2, turn + 1);
            if(!v)break;
        }
    }
    // cout << ind << ' ' << turn << ' ' << v << nl;
    return v;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    bool ans = sol(n, 1);
    // forn(i, n + 1){
    //     forn(j, n + 1){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << nl;
    // }
    if(ans){
        cout << "Jane" << nl;
    }else{
        cout << "John" << nl;
    }
}