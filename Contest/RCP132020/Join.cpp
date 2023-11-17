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

map<pii, int> dp;

int aux(vector<pii>& games, int B, int g){
    if(B == 0 || g == games.size()){
        return 0;
    }
    if(dp.count(make_pair(B, g))){
        return dp[make_pair(B, g)];
    }
    int nt = aux(games, B, g + 1);
    if(B - games[g].fi >= 0){
        int t = aux(games, B - games[g].fi, g + 1);
        dp[make_pair(B, g)] = max(nt,  t + games[g].se);
        return dp[make_pair(B, g)];
    }
    dp[make_pair(B, g)] = nt;
    return dp[make_pair(B, g)];
}

int main(){
    ios
    int G, B;
    cin >> G >> B;
    vector<pii> games(G);
    int g, b;
    forn(i, G){
        cin >> b >> g;
        games[i] = make_pair(b, g);
    }
    cout << aux(games, B, 0) << endl;
}