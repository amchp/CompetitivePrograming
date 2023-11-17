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

using namespace std;


typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi; // int vec
typedef vector<vi> vvi; // int vec vec
typedef vector<pii> vpi; // int int pair vec

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

string intToString(int n){
    string ans = to_string(n);
    if(n < 10)ans = '0' + ans;
    return ans;
}

bool palindrome(string s1, string s2){
    int s = s1.length();
    forn(i, s){
        if(s1.at(i) != s2.at(s - 1 - i))return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, h, m, x, ans;
    string s, hour, minute, sHour, sMinute;
    string::size_type sz;
    cin >> t;
    in(t){
        cin >> s;
        cin >> x;
        ans = 0;
        sHour = s.substr(0, 2);
        sMinute = s.substr(3, 2);
        ans += palindrome(sHour, sMinute);
        h = stoi(sHour);
        m = stoi(sMinute);
        hour = intToString((h + (m + x) / 60) % 24);
        minute = intToString((m + x) % 60);
        while(sHour != hour || sMinute != minute){
            ans += palindrome(hour, minute);
            h = stoi(hour);
            m = stoi(minute);
            hour = intToString((h + (m + x) / 60) % 24);
            minute = intToString((m + x) % 60);
        }
        cout << ans << nl;
    }
}