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
    int a, b ,c, x, y, z;
    vi aV(6);
    cin >> a >> b >> c >> x >> y >> z;
    for(int i = 0; i < 6; ++i)cin >> aV[i];
    vector<vi > p(6, vi(3));
    p[0][0] = x / 2;
    p[0][1] = 0;
    p[0][2] = z / 2;
    p[1][0] = x / 2;
    p[1][1] = y;
    p[1][2] = z / 2;
    p[2][0] = x / 2;
    p[2][1] = y / 2;
    p[2][2] = 0;
    p[3][0] = x / 2;
    p[3][1] = y / 2;
    p[3][2] = z;
    p[4][0] = 0;
    p[4][1] = y / 2;
    p[4][2] = z / 2;
    p[5][0] = x;
    p[5][1] = y / 2;
    p[5][2] = z / 2;
    
}