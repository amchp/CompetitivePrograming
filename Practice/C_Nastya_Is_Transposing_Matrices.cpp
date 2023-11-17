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

bool sol(){
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int>(m));
    vector<vector<int> > b(n, vector<int>(m));
    forn(i, n){
        forn(j, m){
            cin >> a[i][j];
        }
    }
    forn(i, n){
        forn(j, m){
            cin >> b[i][j];
        }
    }

    int i = 0, j = 0, cur = 0;
    map<int, int> mp;
    while(i < n){
        mp.clear();
        while(i > -1 && j < m){
            mp[a[i][j]]++;
            i--;
            j++;
        }
        i = cur;
        j = 0;
        while(i > -1 && j < m){
            if(!mp.count(b[i][j]) || mp[b[i][j]] < 1){
                return false;
            }
            mp[b[i][j]]--;
            i--;
            j++;
        }
        cur++;
        i = cur;
        j = 0;
    }
    i = n - 1;
    j = 1;
    cur = 1;
    while(j < m){
        mp.clear();
        while(i > -1 && j < m){
            mp[a[i][j]]++;
            i--;
            j++;
        }
        i = n - 1;
        j = cur;
        while(i > -1 && j < m){
            if(!mp.count(b[i][j]) || mp[b[i][j]] < 1){
                return false;
            }
            mp[b[i][j]]--;
            i--;
            j++;
        }
        cur++;
        i = n - 1;
        j = cur;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if(sol())cout << "YES" << nl;
    else cout << "NO" << nl;
}