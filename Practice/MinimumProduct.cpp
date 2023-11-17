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
        int a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        if(a - x > n and b - y > n){
            if(a <= b) a -=n;
            else b -= n;
        }
        else if(a - x <= n and b - y <= n){
            if(x <= y){
                n -= a - x;
                a = x;
                if(b - y <= n) b = y;
                else b -= n;
            }else{
                n -= b - y;
                b = y;
                if(a - x <= n) a = x;
                else a -= n;
            }
        }else if(a - x <= n){
            if(x <= b - n){
                n -= a - x;
                a = x;
                b -= n;
            }else b -= n;
        }else{
            if(y <= a - n){
                n -= b - y;
                b = y;
                a -= n;
            }else a -= n;
        }
        cout << (long long)a * b << el;
    }
}