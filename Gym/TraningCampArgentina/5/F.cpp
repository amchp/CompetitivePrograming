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

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    forn(i, n)cin >> a[i];
    sort(all(a));
    int ind = upper_bound(all(a), n) - a.begin();
    int ans = n - ind;
    for1(i, ind){
        if(a[i] == a[i - 1])ans++;
    }
    cout << ans << el;
}