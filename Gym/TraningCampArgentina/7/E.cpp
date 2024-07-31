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


using namespace std;

#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define el '\n'
#define pb push_back

typedef long long ll;
typedef vector<int> vi;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        ll m = 0;
        vi a;
        forn(i, n){
            if(s[i] == '*'){
                m++;
                a.pb(i);
            }
        }
        ll ans = 0;
        forn(i, m){
            ans += abs(a[m / 2] - a[i]);
        }
        // cout << ans << el;
        if(m == 0 || m == 1);
        else if(m % 2)ans -= ((m-1)/2)*((m-1)/2+1);
        else ans -= (((m/2)*(m/2+1))/2+((m/2-1)*(m/2))/2);
        cout << ans << el;
    }
}