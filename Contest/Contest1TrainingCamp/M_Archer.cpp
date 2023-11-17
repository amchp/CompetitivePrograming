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
#include <tuple>


// Useful constants 
#define INF                         (int)2e9 
#define EPS                         1e-9

#define el '\n'

#define MAXN                         (int)2e5

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    double a, b, c, d, ans;
    cin >> a >> b >> c >> d;
    ans = (a)/(a+((c*b)/d)-((a*c)/d));
    cout << setprecision(12) << ans << el;
}