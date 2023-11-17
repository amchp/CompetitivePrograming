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
    for(int i = 0; i < 6; ++i){
        if(a == 0 && b == 2){
            aux(x, y, 2, 24);
        }
        else if(a == 1 && b ==2){
            aux(x, y, 1, 34);
        }
        else if(a == 2 && b == 2){
            y -= (y / 44)*44;
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
        if(a == 0 && y < 24 && y >= 14)b = 1;
        else if(a == 0 && y < 14)b = 0;
        if(a == 1 && y < 34 && y >= 24)b = 1;
        else if(a == 1 && y < 24)b = 0;
    }
    bool winner;
    if( (a == 0 && x >= 2 && y >= 2) ||
        (a == 2 && x >= 0 && y >= 22) ||
        (a == 1 && x >= 1 && y >= 12))winner = true;
    if(winner)cout << "Ciel" << el;
    else cout << "Hanako" << el;
 }