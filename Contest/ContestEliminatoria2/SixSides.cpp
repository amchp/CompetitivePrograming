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



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> dice1(6);
    vector<int> dice2(6);
    for(int i = 0; i < 6; i++)cin >> dice1[i];
    for(int i = 0; i < 6; i++)cin >> dice2[i];
    int w = 0;
    int l = 0;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(dice1[i] > dice2[j])w++;
            if(dice1[i] < dice2[j])l++;
        }
    }
    cout.precision(5);
    cout << fixed << ((double)w / (w+l)) << endl;
}