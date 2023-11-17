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
const int maxn = 2e5 + 5;
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

string s;
int n;
int letters[maxn][5];

int greaterLetter(int i, int c){
    forn(j, 4 - c){
        int ind = 4 - j;
        if((letters[n][ind] - letters[i][ind]) > 0)return -1;
    }
    return 1;
}

ll getAns(){
    forn(i, n + 1){
        forn(j, 5){
            letters[i][j] = 0;
        }
    }
    forab(i, 1, n + 1){
        letters[i][s[i - 1] - 'A']++;
    }
    forab(i, 1, n + 1){
        forn(j, 5){
            letters[i][j] += letters[i - 1][j];
        }
    }
    ll sumT = 0;
    forab(i, 1, n + 1){
        sumT += greaterLetter(i, s[i - 1] - 'A')*(ll)pow(10, s[i - 1]-'A');
    }
    return sumT;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    in(t){
        cin >> s;
        n = s.size();
        vector<bool> seen(5, false);
        ll ans = -INFLL;
        forn(i, s.size()){
            if(!seen[s[i] - 'A']){
                char o = s[i];
                seen[s[i] - 'A'] = true;
                // cout << i << " : ";
                forn(j, 5){
                    s[i] = (char)('A' + j);
                    ans = max(ans, getAns());
                    // cout << getAns() << ' ';
                }
                s[i] = o;
                // cout << nl;
            }
        }
        forn(i, 5)seen[i] = false;
        forn(i, s.size()){
            int ind = n - i - 1;
            if(!seen[s[ind] - 'A']){
                char o = s[ind];
                seen[s[ind] - 'A'] = true;
                // cout << ind << " : ";
                forn(j, 5){
                    s[ind] = (char)('A' + j);
                    ans = max(ans, getAns());
                    // cout << getAns() << ' ';
                }
                s[ind] = o;
                // cout << nl;
            }
        }
        cout << ans << nl;
        
    }
}