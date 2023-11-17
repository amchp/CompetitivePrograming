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

vector<vi> perms[8];
vi perm;

void sums(int ini, int a){
    if(a == 0){
        perms[ini].pb(perm);
    }
    forn(i, a){
        perm.pb(a - i);
        if(perm.size() > 1 && perm[perm.size() - 1] < perm[perm.size() - 2]){
            perm.pop_back();
            continue;
        }
        sums(ini, a - (a - i));
        perm.pop_back();
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n, k, v;
    cin >> n >> k;
    int ans = 0;
    int sum = 0;
    vi a(k);
    forn(i, n){
        cin >> v;
        a[v % k]++;
        ans += v / k;
        sum += v % k;
    }
    forab(i, 1, k){
        sums(i, k - i);
    }
    vector<vpi> permus[8];
    pair<int, int> p;
    forab(i, 1, k){
        forn(j, perms[i].size()){
            reverse(all(perms[i][j]));
        }
        sort(all(perms[i]));
        reverse(all(perms[i]));
        forn(j, perms[i].size()){
            permus[i].pb(vpi());
            p = mp(perms[i][j][0], 1);
            forn(l, perms[i][j].size() - 1){
                if(perms[i][j][l] != perms[i][j][l + 1]){
                    permus[i][permus[i].size() - 1].pb(p);
                    p = mp(perms[i][j][l + 1], 1);
                }else{
                    p.second++;
                }
            }
            permus[i][permus[i].size() - 1].pb(p);
        }
    }
    while(sum > 0){
        forab(i, 1, k){
            int ind = k - i - 1;
            forn(j, permus[ind].size()){
                bool pass = a[ind] != 0;
                forn(l, permus[ind][j].size()){
                    pass &= permus[ind][j][l].second <= a[permus[ind][j][l].first];
                }
                if(pass){
                    forn(l, permus[ind][j].size()){
                        a[permus[ind][j][l].first] -= permus[ind][j][l].second;
                        sum -= permus[ind][j][l].first;
                    }
                }
            }
        }
        forab(i, 1, k){
            int ind = k - i - 1;
            if(a[ind] != 0){
                cout << ind << nl;
                forab(j, 1, k){
                    if(a[j] == 0)continue;
                    a[ind]--;
                    a[j]--;
                    a[ind - (k - j)]++;
                    ans++;
                    break;
                }
                break;
            }
        }
    }
    cout << ans << nl;
}