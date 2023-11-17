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
const int maxn = 7000 + 1;
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

int n;
int k[2];
int dp[maxn][2];
bool visited[maxn][2];
int moves[2][maxn];

int sol(int ind, int player){
    if(ind >= n){
        ind %=n;
        if(ind == 0)return 2;
        if(visited[ind][player]){
            return 1;
        }
    }
    if(dp[ind][player] != -1){
        if(dp[ind][player] == 0)return 2;
        else if(dp[ind][player] == 2)return 0;
        else if(visited[ind][player])return 1;
    }
    visited[ind][player] = true;
    int ans = 0;
    forn(i, k[player]){
        ans = max(ans, sol((ind + moves[player][i]), !player));
    }
    visited[ind][player] = false;
    dp[ind][player] = ans;
    if(dp[ind][player] == 0)return 2;
    else if(dp[ind][player] == 1){
        return 1;
    }
    else return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    cin >> n;
    cin >> k[0];
    forn(i, k[0])cin >> moves[0][i];
    cin >> k[1];
    forn(i, k[1])cin >> moves[1][i];
    memset(dp, -1, sizeof(dp));
    forab(i, 1, n){
        forn(j, 2){
            memset(visited, false, sizeof(visited));
            sol(i, j);
        }
    }
    forab(i, 1, n){
        if(dp[i][0] == 0){
            cout << "Lose ";
        }
        else if(dp[i][0] == 1){
            cout << "Loop ";
        }else{
            cout << "Win ";
        }
    }
    cout << nl;
    forab(i, 1, n){
        if(dp[i][1] == 0){
            cout << "Lose ";
        }
        else if(dp[i][1] == 1){
            cout << "Loop ";
        }else{
            cout << "Win ";
        }
    }
    cout << nl;
}