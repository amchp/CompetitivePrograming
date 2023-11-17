#include <iostream>

using namespace std;

int main(){
    string s;
    getline (cin, s);
    int n = stoi(s);
    string st = "";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j + i < n){
                st = st + " ";
            }else{
                st = st + "#";
            }
        }
        st = st + "\n";
    }
    cout << st;
}