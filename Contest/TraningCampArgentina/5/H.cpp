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

typedef long long ll;

int main(){
    ll k, n, w;
    cin >> k >> n >> w;
    ll ans = (w*(w + 1) / 2) * k - n;
    if(ans < 0)cout << 0 << '\n';
    else cout << ans << '\n';
}