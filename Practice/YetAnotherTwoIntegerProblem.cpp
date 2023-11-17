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

// Useful constants 
#define INF                         (int)1e9 
#define EPS                         1e-9 

#define el '\n'

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, ans;
        cin >> a >> b;
        if(a == b){
            cout << 0 << el;
        }else{
            ans = ceil((double)abs(b - a) / 10);
            cout << ans << el;
        }
    }
    
}