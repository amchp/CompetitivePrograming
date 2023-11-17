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

// Useful constants 
#define INF                         (int)2e9 
#define EPS                         1e-9

#define el '\n'

#define MAXN                         (int)2e5

using namespace std;

typedef long long ll;
typedef long double ld;
 
using namespace std;

int main()
{
    int i = 3, a, b;
    vector<pair<int, int> > squares;
    while (i--)
    {
        cin >> a >> b;
        if(a > b)squares.push_back(make_pair(a, b));
        else squares.push_back(make_pair(b, a));
    }
    int x0, y0, x1, y1, x2, y2;
    bool pass = false;
    x0 = squares[0].first;
    y0 = squares[0].second;
    x1 = squares[1].first;
    y1 = squares[1].second;
    x2 = squares[2].first;
    y2 = squares[2].second;
    if(x0 > x1 && y0 > y1)pass = false;
    if(x1 > x0 )
    string out = pass ? "YES" : "NO";

}