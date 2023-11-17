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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    map<int, int> trf;
    vector<vpi> a;
    int n, c, s;
    cin >> n;
    forn(i, n){
        cin >> c >> s;
        if(!trf.count(c)){
            trf[c] = a.size();
            a.pb(vpi());
        }
        a[trf[c]].pb(mp(s, i + 1));
    }


    int mx = 0;
    forn(i, a.size()){
        sort(all(a[i]), greater<pii>());
        mx = max(mx, (int)a[i].size());
    }

    // cout << mx << nl;
    vector<vpll> cmb(mx);
    forn(i, a.size()){
        ll p = 0;
        forn(j, a[i].size()){
            p += a[i][j].first;
            if(j != 0)cmb[j  - 1].pb(mp(p, i));
            cmb[j].pb(mp(p, i));
        }
    }
    forn(i, cmb.size()){
        sort(all(cmb[i]), greater<pll>());
    }

    
    ll sum = 0;
    int ind1, ind2;
    forn(i, cmb.size()){
        pll m1 = cmb[i][0];
        pll m2 = mp(-1, -1);
        forn(j, cmb[i].size()){
            if(m1.second != cmb[i][j].second){
                m2 = cmb[i][j];
                break;
            }
        }
        if(m2.second == -1)continue;
        // cout << m1.first +  m2.first << nl;
        if(sum < m1.first + m2.first){
            sum = m1.first + m2.first;
            ind1 = m1.second;
            ind2 = m2.second;
        }
    }


    cout << sum << nl;
    // cout << ind1 << ' ' << ind2 << nl;
    if(a[ind1].size() > a[ind2].size()){
        swap(ind1, ind2);
    }
    int sz = a[ind1].size() + min(a[ind2].size(), a[ind1].size() + 1);
    cout << sz << nl;
    forn(i, sz){
        if(i % 2)cout << a[ind1][i / 2].second << ' ';
        else cout << a[ind2][i / 2].second << ' ';
    }
    cout << nl;
}