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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll fI = -1;
    ll fS = -1;
    forn(i, n){
        if(s[i] == '1'){
            fI = i;
            break;
        }
    }
    if(fI == -1){
        cout << 0 << nl;
        return 0;
    }
    vi ones, zeros;
    int lOnes = -1, lZeros = -1;
    int fZero = -1;
    forab(i, fI, n){
        if(s[i] == '1'){
            if(lOnes == -1){
                lOnes = i;
                continue;
            }
            ones.pb(i - lOnes);
            lOnes = i;
        }else{
            if(lZeros == -1){
                fZero = i;
                lZeros = i;
                continue;
            }
            zeros.pb(i - lZeros);
            lZeros = i;
        }
    }
    if(fZero == -1){
        cout << s.substr(fI, n - fI) << nl;
        return 0;
    }
    int ans = 1;
    int ansOne = 0;
    forn(i, ones.size()){
        if(ones[i] > fZero || zeros.size() == 0)break;
        if(ones[i] == zeros[0]){
            int curAns = 2;
            int j = 1;
            while(j < zeros.size() && i + j < ones.size() && ones[i + j] == zeros[j]){
                curAns++;
                j++;
            }
            if(ans < curAns){
                ansOne = i;
                ans = curAns;
            }
            if(j == zeros.size() || i + j == ones.size()){
                break;
            }
        }
    }
    int sOnes = -1;
    forab(i, fI, n){
        if(s[i] == '1'){
            ansOne--;
            if(ansOne == -1){
                sOnes = i;
                break;
            }
        }
    }
    string sAns = s;
    forn(i, n - fZero){
        if(s[fZero + i] == '0' && s[sOnes + i] == '1')sAns[fZero + i] = '1';
    }
    cout << sAns.substr(fI, n - fI) << nl;
}