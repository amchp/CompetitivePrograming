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
const int maxn = 201;
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

int n;
vector<string> words;
set<string> s;
vector<string> ans;

bool sol(int i);

bool aux(int i, string cur, int j, int d){
    if(d >= 4){
        return false;
    }
    forab(k, j, words[i].length()){
        cur.push_back(words[i][k]);
        if(!s.count(cur)){
            s.insert(cur);
            ans[i] = cur;
            if(sol(i + 1)){
                return true;
            }
            s.erase(cur);
        }
        aux(i, cur, k + 1, d+1);
        cur.pop_back();
    }
    return false;
}

bool sol(int i){
    if(i == n){
        return true;
    }
    if(words[i].length() < 5){
        if(s.count(words[i])){
            return false;
        }
        s.insert(words[i]);
        ans[i] = words[i];
        if(sol(i + 1)){
            return true;
        }
        s.erase(words[i]);
    }
    string cur = "";
    if(aux(i, cur, 0, 0)){
        return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    string word;
    ans.resize(n);
    forn(i, n){
        cin >> word;
        words.pb(word);
    }
    if(!sol(0)){
        cout << -1 << nl;
        return 0;
    }
    forn(i, n){
        cout << ans[i] << nl;
    }
}