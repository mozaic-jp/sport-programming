#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i, n) for (long long i = 0; i < (n); i++) 
#define ll long long

using namespace std;
//        tmp = stoi(S.substr(i,3));
int main(){
    ll X,Y;

    cin >> X >> Y;

    cout << (X + Y/2) << endl;

    return 0;
}
