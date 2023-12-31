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
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi; // int vec
typedef vector<vi> vvi; // int vec vec
typedef vector<pii> vpi; // int int pair vec

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
    // Abrir archivos
    // freopen("A.in", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios

    ll n;
    cin >> n;

    vector<ll> arr(n, 0);
    forn(i, n){
        ll temp;
        cin >> temp;
        arr[i] = temp;
    }
    vector<vector<ll> > dp(n, vector<ll>(n));
    forn(i, n){
        dp[n - 1][i] = -INFLL;
        dp[i][n - 1] = arr[n - 1];
    }
    for(int i = 1; i <= n - 1; ++i){
        int l = 0;
        for(int j = n - 2; j > -1; ++j){
            if(j % i  == 0){
                l = j;
                dp[i][j] = max(dp[i][j + i] + arr[j], (dp[i - 1][n - 1] - dp[i - 1][j]));
            }else{
                dp[i][j] = max(dp[i][l] + arr[j],  + dp[i - 1][n - 1] - dp[i - 1][j]); 
            }
        }
    }
    forn(i, n){
        forn(j, n){
            cout << dp[i][j] << " ";
        }
        cout << nl;
    }
    cout << dp[n - 1][n - 1] << nl;
}