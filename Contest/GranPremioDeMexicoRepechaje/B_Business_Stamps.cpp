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

int N, M, eI, eJ, dI, dJ;
int dirI[4] = {-1, 0, 0, 1};
int dirJ[4] = {0, -1, 1, 0};
int g[100][100];
int dp[100][100][1024];
bool visited[100][100][1024];

int aux(int i, int j, int mask){
    if(eI == i && eJ == j){
        int ans = 0;
        forn(k, 10){
            ans += (bool)(mask & (1 << k));
        }
        return ans;
    }if(dp[i][j][mask] != 0){
        return dp[i][j][mask];
    }
    int ans = INF;
    visited[i][j][mask] = true;
    forn(k, 4){
        dI = i + dirI[k];
        dJ = j + dirJ[k];
        if(-1 < dI && dI < N && -1 < dJ && dJ < M && !visited[dI][dJ][mask]){
            ans = min(ans, aux(dI, dJ, mask | (1 << g[dI][dJ])));
        }
    }
    dp[i][j][mask] = ans;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(dp, 0, sizeof(dp));
    memset(visited, 0, sizeof(visited));
    memset(g, 0, sizeof(g));
    int sI, sJ;
    cin >> N >> M;
    cin >> sI >> sJ;
    cin >> eI >> eJ;
    sI--;
    sJ--;
    eI--;
    eJ--;
    forn(i, N){
        forn(j, M){
            cin >> g[i][j];
            g[i][j]--;
        }
    }
    int mask = 1 << g[sI][sJ];
    cout << aux(sI, sJ, mask) << nl;
}