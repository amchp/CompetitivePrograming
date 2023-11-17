#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int grade;
        cin >> grade;
        if(grade >= 38 && grade % 5 >= 3)grade = grade + (5 - grade % 5);
        cout << grade << endl;
    }
}