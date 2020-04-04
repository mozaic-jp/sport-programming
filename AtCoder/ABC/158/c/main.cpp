#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm> // sort
#include <unistd.h>
#include <map>
#include <cmath>

#define pii pair<int,int>
#define REP(i, n) for (long long i = 0; i < (n); i++) 
using namespace std;


typedef long long ll;
static const ll INF = 1000000000000000000LL;
static const ll MOD = 1000000007;


int main()
{
    double a,b;
    cin >> a >> b;
    int res = -1;

    for(int i = 1; i <= 20000; ++i)
    {
        double a8,a10;
        a8 = i * (0.08);
        a10 = i * (0.10);

        if(floor(a) == floor(a8) && floor(b) == floor(a10))
        {
            res = i;
            break;
        }
    }


    cout << res << endl;

    return 0;
}