#include <iostream>

using namespace std;

int main(){
    int n, count;
    char c;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int u;
        string s;
        cin >> u >> s;
        count = 0;
        for(int i = 0 ; i < s.length(); ++i){
            c = s.at(i);
            if(c == '.'){
                count++;
                i += 2;
            }
        }
        cout << "Case " << i << ": " << count << endl;
    }
}