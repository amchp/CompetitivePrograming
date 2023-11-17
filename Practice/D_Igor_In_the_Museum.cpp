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
const int maxn = 1e6 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll INFLL = 1000000000000000005LL;
const ld EPS = 1e-9;
int dirx[4] = { -1, 0, 0, 1};
int diry[4] = { 0, 1, -1, 0};

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


int n, m;
char matrix[(int)1e3 + 1][(int)1e3 + 1];
int parent[maxn];
int walls[maxn];

void make_set(int ind){
    parent[ind] = ind;
    int i = ind / m;
    int j = ind % m;
    if(matrix[i][j] == '*'){
        walls[ind] = 0;
        return;
    }
    forn(k, 4){
        int di = i + dirx[k];
        int dj = j + diry[k];
        if(matrix[di][dj] == '*')walls[ind]++;
    }
}

int find(int u){
    return parent[u] == u ? u : parent[u] = find(parent[u]);
}

void combine(int u, int v){
    int pu = find(u);
    int pv = find(v);
    if(pu == pv)return;
    // cout << pu << ' ' << pv << nl;
    parent[pv] = pu;
    walls[pu] += walls[pv];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int k;
    cin >> n >> m >> k;
    forn(i, n){
        forn(j, m){
            cin >> matrix[i][j];
        }
    }
    forn(i, n){
        forn(j, m){
            make_set(i*m + j);
            // if(matrix[i][j] == '.'){
            //     cout << i*m + j << nl;
            //     cout << parent[i*m + j] << ' ' << walls[i*m + j] << nl;
            // }
        }
    }
    forn(i, n){
        forn(j, m){
            if(matrix[i][j] == '.'){
                forn(k, 4){
                    int di = i + dirx[k];
                    int dj = j + diry[k];
                    if(matrix[di][dj] == '.'){
                        combine(i*m + j, di*m + dj);
                    }
                }
            }
        }
    }
    int u, v;
    forn(i, k){
        cin >> u >> v;
        u--;
        v--;
        cout << walls[find(u*m + v)] << nl;
    }
}