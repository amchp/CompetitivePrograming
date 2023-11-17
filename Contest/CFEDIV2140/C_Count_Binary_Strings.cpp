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

bool aux(vvi& input, vi& visited, vi& bits, vi& twos, int& i, int j){
    if(visited[j] != -1)return true;
    visited[j] = i;
    forab(k, j, input.size()){
        if(input[j][k] == 1){
                forab(l, j + 1, k + 1){
                    if(visited[j] == visited[l]){
                        return false;
                    }
                    if(!aux(input, visited, bits, twos, i, l)){
                    return false;
                }
            }
        }
        if(input[j][k] == 2){
            if(visited[j] == visited[k]){
                return false;
            }
            twos[i] = max(twos[i], k);
        }
    }
    return true;
}

int sol(){
    int n;
    cin >> n;
    vvi input(n, vi(n));
    for(int i = 0; i < n; ++i){
        for(int j = i; j < n; ++j){
            cin >> input[i][j];
        }
    }
    vi visited(n, -1);
    vi twos(n);
    vi bits;
    forn(i, n){
        if(visited[i] != -1)continue;
        bits.pb(0);
        twos.pb(-1);
        if(!aux(input, visited, bits, twos, i, i)){
            return 0;
        }
    }
    ll ans = 2;
    int two = 0;
    for(int i = 1; i < bits.size(); ++i){
        two = max(twos[i], two);
        ans *= 2;
        if(two){
            ans -= 2;
            two--;
        }
        ans %= 998244353;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << sol() << nl;
}