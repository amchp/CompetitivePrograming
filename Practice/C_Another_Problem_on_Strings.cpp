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
    int k;
    cin >> k;
    string s;
    cin >> s;
    int ones = s[0] == '1';
    int l = 0;
    int r = 1;
    while(r < s.size() && ones < k){
        if(s[r] == '1')ones++;
        r++;
    }
    if(k == 0){
        while(r < s.size() && ones > k){
            if(s[l] == '1')ones--;
            if(s[r] == '1')ones++;
            l++;
            r++;
        }
    }
    if(ones != k){
        cout << 0 << nl;
        return 0;
    }
    ll ans = 0;
    int sL, sR;
    while(r <= s.size()){
        sR = r;
        while(r < s.size() && s[r] != '1'){
            r++;
        }
        sL = l;
        while(l < s.size() && s[l] != '1'){
            l++;
        }
        // cout << sL << ' ' << l << ' ' << sR << ' ' << r << nl;
        if(k != 0){
            // cout << ((ll)l - (ll)sL + 1LL)*((ll)r - (ll)sR + 1LL) << nl; 
            ans += ((ll)l - (ll)sL + 1LL)*((ll)r - (ll)sR + 1LL);
        }
        else ans += ((ll)r - (ll)sL)*((ll)r- (ll)sL + 1LL) / 2LL;
        l++;
        r++;
    }
    cout << ans << nl;

}