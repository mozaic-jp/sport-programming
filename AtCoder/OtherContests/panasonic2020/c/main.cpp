#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm> // sort
#include <unistd.h>
#include <map>
#include <set> 
#include <math.h> 

#define pii pair<int,int>
#define REP(i, n) for (long long i = 0; i < (n); i++) 
using namespace std;


typedef long long ll;
static const ll INF = 1000000000000000000LL;
static const ll MOD = 1000000007;


int main()
{
    long double a,b,c;
    cin >> a >> b >> c;
    string res;

    //if(pow(a,0.5) + pow(b,0.5) < pow(c,0.5))
    if(sqrtl(a * b) < (c-a-b) / (2.0))
    //if(sqrt(a) + sqrt(b) < sqrt(c))
    {
        res = "Yes";
    }
    else res = "No";

    //cout << pow(a,0.5) << endl;

    cout << res << endl;


    return 0;
}