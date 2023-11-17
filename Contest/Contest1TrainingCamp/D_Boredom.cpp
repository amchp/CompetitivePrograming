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


void aux(int &x, int &y, int c, int d){
    int rOff = min(x/c, y/d);
    x -= rOff*c;
    y -= rOff*d;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, y;
    cin >> x >> y;
    int a, b;
    a = 0;
    b = 2;
    for(int i = 0; i < 3; ++i){
        if(a == 0 && b == 2){
            aux(x, y, 2, 24);
        }
        else if(a == 1 && b ==2){
            aux(x, y, 1, 34);
        }
        else if(a == 2 && b == 2){
            aux(x, y, 0, 44);
        }
        else if(a == 0 && b == 1){
            aux(x, y, 3, 14);
        }
        else if(a == 0 && b == 0){
            aux(x, y, 4, 4);
        }
        else if(a == 1 && b == 1){
            aux(x, y, 2, 24);
        }
        if(x == 1)a = 1;
        else if(x == 0)a = 2;
        if(y < 22 && y >= 12)b = 1;
        else if(y < 12)b = 0;
    }
    
}