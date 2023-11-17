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
const int maxn = 1e4 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll INFLL = 1000000000000000005LL;
const ld EPS = 1e-9;
int dirx[3] = { 0, 1, 0};
int diry[3] = { 0, 0, 1};

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

int n, m, r;
vector<vector<vector<bool> > > dp;
set<vi> lazers;

void sol(int i, int j, int t){
    if(i == n && j == m){
        dp[i][j][t] = true;
        return;
    }
    if(dp[i][j][t])return;
    dp[i][j][t] = true;
    int time = i + j + t;
    if(i < n && !lazers.count({time + 1, 1, i + 1}) && !lazers.count({time + 1, 2, j}))sol(i + 1, j, t);
    if(j < m && !lazers.count({time + 1, 1, i}) && !lazers.count({time + 1, 2, j + 1}))sol(i, j + 1, t);
    if(t < r && !lazers.count({time + 1, 1, i}) && !lazers.count({time + 1, 2, j}))sol(i, j, t + 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int T;
    cin >> T;
    in(T){
        cin >> n >> m;
        cin >> r;
        dp = vector<vector<vector<bool> > >(n + 1, vector<vector<bool> >(m + 1, vector<bool>(r + 1, false)));
        vi v(3);
        lazers.clear();
        forn(i, r){
            cin >> v[0] >> v[1] >> v[2];
            lazers.insert(v);
        }
        sol(0, 0, 0);
        int ans = -1;
        forn(i, r + 1){
            if(dp[n][m][i]){
                ans = n + m + i;
                break;
            }
        }
        cout << ans << nl;
    }
}