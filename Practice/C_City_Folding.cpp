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

vector<ll> calculateLevels(ll folds, ll level){
    if(folds == 0){
        vector<ll> levels;
        levels.pb(1);
        return levels;
    }
    ll ans = level;
    ll halfLevel = (ll)pow(2, folds - 1);
    if(halfLevel < ans){
        ans = halfLevel - (level - halfLevel) + 1;
    }
    vector<ll> levels =  calculateLevels(folds - 1, ans);
    levels.pb(level);
    return levels;
}

vector<char> calculateFolds(vector<ll>& levels, ll i, ll position){
    vector<char> moves;
    if(i == levels.size() - 1){
        moves = vector<char>(levels.size() - 1);
        return moves;
    }
    char side;
    ll halfLength = (ll)pow(2, levels.size() - i - 2);
    if(position <= halfLength)side = 'L';
    else{
        side = 'R';
        position -= halfLength; 
    }
    char move;
    ll newPosition = position;
    if(levels[i] == levels[i + 1]){
        if(side == 'R')move = 'L';
        else move = 'R';
    }
    else{
        move = side;
        newPosition = halfLength - position + 1;
    }
    moves = calculateFolds(levels, i + 1, newPosition);
    moves[i] = move;
    return moves;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll folds, position, level;
    cin >> folds >> position >> level;
    vector<ll> levels = calculateLevels(folds, level);
    vector<char> moves = calculateFolds(levels, 0, position);
    forn(i, moves.size()){
        cout << moves[i];
    }
    cout << nl;
}