
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

#define el '\n'

using namespace std;

int main(){
    int n, w = 0, m = 0;
    int a[3], b[3];
    cin >> n;
    for(int i = 0; i < 3; ++i)cin >> a[i];
    for(int i = 0; i < 3; ++i)cin >> b[i];
    //Win
    //Rock scissors paper
    if(a[0] < b[1]){
        w += a[0];
    }else{
        w += b[1];
    }if(a[1] < b[2]){
        w += a[1];
    }else{
        w += b[2];
    }if(a[2] < b[0]){
        w += a[2];
    }else{
        w += b[0];
    }

    if(a[0] < b[0]){
        b[0] -= a[0];
        a[0] = 0;
    }else{
        a[0] -= b[0];
        b[0] = 0;
    }
    if(a[1] < b[1]){
        b[1] -= a[1];
        a[1] = 0;
    }else{
        a[1] -= b[1];
        b[1] = 0;
    }if(a[2] < b[2]){
        b[2] -= a[2];
        a[2] = 0;
    }else{
        a[2] -= b[2];
        b[2] = 0;
    }

    if(a[1] < b[0]){
        b[0] -= a[1];
        a[1] = 0;
    }else{
        a[1] -= b[0];
        b[0] = 0;
    }if(a[2] < b[1]){
        b[1] -= a[2];
        a[2] = 0;
    }else{
        a[2] -= b[1];
        b[1] = 0;
    }if(a[0] < b[2]){
        b[2] -= a[0];
        a[0] = 0;
    }else{
        a[0] -= b[2];
        b[2] = 0;
    }

    

    cout << a[0] << " " << a[1] << " " << a[2] << endl;

    cout << b[0] << " " << b[1] << " " << b[2] << endl;

    m = a[0] + a[1] + a[2];

    cout << m << " " << w << endl;
}