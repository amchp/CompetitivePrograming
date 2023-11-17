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
    int t;
    cin >> t;
    in(t){
        int n;
        cin >> n;
        string s;
        cin >> s;
        if(n % 2){
            cout << -1 << nl;
            continue;
        }
        vvi m(26, vi(26, 0));
        vi mm(26, 0);
        int sum = 0;
        forn(i, n / 2){
            if(s[i] == s[n - i - 1]){
                mm[s[i] - 'a']++;
                sum++;
            }else{
                m[s[i] - 'a'][s[n - i - 1] - 'a']++;
            }
        }
        int mmx = mm[0], mInd = 0;
        forn(i, 26){
            // cout << (char)('a' + i) << ' ' << m[i] << nl;
            if(mmx < mm[i]){
                mmx = mm[i];
                mInd = i;
            }
        }
        int remainder = max(0, mmx - (sum - mmx));
        if(remainder == 0){
            cout << (int)ceil((double)sum / 2) << nl;
            continue;
        }
        // cout << mmx << ' ' << mInd << ' ' << remainder << nl;
        int ans = mmx - remainder;
        forn(i, 26){
            if(mInd == i)continue;
            // cout << i << nl;
            forn(j, 26){
                if(mInd == j)continue;
                // cout << j << ":" << m[i][j] << ' ';
                int diff = min(remainder, m[i][j]);
                remainder -= diff;
                ans += diff;
            }
            // cout << nl;
        }
        // cout << remainder << nl;
        if(remainder == 0)cout << ans << nl;
        else cout << -1 << nl;
    }
}