#include <algorithm>
#include <array>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream> // istringstream buffer(myString);
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define ford(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define all(v) v.begin(), v.end()
#define el '\n'
#define pb push_back

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

const int inf = 1e9;
const ll MOD = (ll)1e9 + 7;

int main(){
    int n;
    cin >> n;
    int l = 0, r = inf;
    ll ans = 1;
    ll tAns = 1;
    set<int> st;
    string s;
    int num;
    forn(i, n){
        cin >> s;
        cin >> num;
        if(s == "ADD"){
            if(l < num && num < r){
                tAns += 1;
                tAns %= MOD;
            }
            st.insert(num);
        }else{
            tAns = 1;
            if(num < l || num > r){
                cout << 0 << el;
                return 0;
            }if(!(num == l || num == r)){
                ans *= 2;
                ans %= MOD;
            }
            auto it = st.lower_bound(num);
            auto it2 = st.upper_bound(num);
            if(it == st.begin()){
                l = 0;
            }else{
                it--;
                l = *it;
                it++;
            }
            if(it2 == st.end()){
                r = inf;
            }else{
                r = *it2;
            }
            st.erase(it);
        }
    }
    ans *= tAns;
    ans %= MOD;
    cout << ans << el;
}