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
#define MAXA                         (int)1e9

using namespace std;

int main(){
    double H, U, D, F, CH;
    int day;
    cin >> H >> U >> D >> F;
    while(H != 0){
        F *= U * 0.01;
        day = 0;
        CH = 0;
        while(H >= 0){
            day++;
            CH += U;
            if(CH > H)break;
            U -= F;
            
            CH -= D;
        }
        if(CH >= H)cout << "success on day " << day << el;
        else cout << "failure on day " << day << el;
        cin >> H >> U >> D >> F;
    }
}