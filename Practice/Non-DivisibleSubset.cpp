#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
int divisable[100000][100000];

int search(vector<int> v,int i, int j){
    if(j >= n)return v.size();
    if(divisable[i][j] == 1){
        bool works = true;
        for(size_t k = 0; k < v.size(); ++k){
            if(divisable[v[k]][j] != 1) works = false;
        }
        if(works){
            vector<int> p = v;
            p.push_back(j);
            return max(search(v, i, j+1), search(p, i, j+1));
        }else{
            vector<int> p;
            p.push_back(v[0]);
            p.push_back(j);
            return max(search(v, i, j+1), search(p, i, j+1));
        }
    }else{
        vector<int> p;
        p.push_back(j);
        return max(search(v, i, j+1), search(p, j, j+1));
    }
}

int main(){
    int d;
    cin >> n >> d;
    int arr[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            if((arr[i] + arr[j]) % d != 0) divisable[i][j] = 1;
        }
    }
    int m = 0;
    vector<int> v;
    v.push_back(0);
    m = search(v, 0, 1);
    cout << m << endl;
}