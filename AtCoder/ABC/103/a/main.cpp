#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

#define REP(i, n) for (long long i = 0; i < (n); i++) 
#define ll long long

using namespace std;
//        tmp = stoi(S.substr(i,3));
int main(){
//    std::ifstream in("input.txt");
//    std::cin.rdbuf(in.rdbuf());
    ll A,B;
    ll res;

    cin >> A >> B;

    res = (A-1)*(B-1);

    cout << res << endl;

    return 0;
}
