
#include <cmath>
#include <climits>
#include <queue>
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

// Useful constants 
#define INF                         (int)1e9 
#define EPS                         1e-9 

using namespace std;

int main(){
    int t, n, x, a;
    cin >> t;
    while(t--){
        cin >> n >> x;
        if(n < 3){
            cout << 1 << endl;
        }else{
            a = (n - 3) / x + 2;
            cout << a << endl;
        }
    }
}