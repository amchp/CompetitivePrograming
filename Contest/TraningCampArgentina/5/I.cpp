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

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define all(v) v.begin(), v.end()
#define el '\n'

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;


int main(){
    int n;
    cin >> n;
    vi a(3);
    forn(i, 3){
        cin >> a[i];
    }
    sort(all(a));
    vi ans(n + 1, 0);
    forn(i, 3){
        if(a[i] > n)continue;
        ans[a[i]] = 1;
        // cout << a[i] << ' ';
    }
    // cout << el;
    forn(i, 3){
        if(a[i] > n)continue;
        forn(j, n + 1){
            if(ans[j] == 0 || n < a[i] + j){
                continue;
            }
            ans[a[i] + j] = max(ans[j] + 1, ans[a[i] + j]);
        }
    }
    cout << ans[n] << el;
}