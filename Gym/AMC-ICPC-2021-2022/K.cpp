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
#define pb push_back
#define mp make_pair
#define el "\n"

typedef pair<int, int> ii;
typedef vector<int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int T, D, M;
    cin >> T >> D >> M;
    vi y(M + 2);
    y[0] = 0;
    for1(i, M)cin >> y[i];
    y[M + 1] = D;
    int mx = 0;
    for1(i, M + 1){
        mx = max(mx, y[i] - y[i - 1]);
    }
    if(mx >= T){
        cout << "Y" << el;
    }else{
        cout << "N" << el;
    }
}