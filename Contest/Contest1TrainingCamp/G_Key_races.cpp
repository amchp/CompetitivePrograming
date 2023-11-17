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
    double s, v1, v2, t1, t2, tt1, tt2;
    cin >> s >> v1 >> v2 >> t1 >> t2;
    tt1 = (s * v1) + 2 * t1;
    tt2 = (s * v2) + 2 * t2;
    if(tt1 == tt2)cout << "Friendship" << el;
    else if(tt1 > tt2)cout << "Second" << el;
    else cout << "First" << el;
}