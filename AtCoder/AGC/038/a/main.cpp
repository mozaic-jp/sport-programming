#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm> // sort
#include <map>

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;
using namespace std;


int main(){
    int h,w,a,b;
    cin >> h >> w >> a >> b;

    for(int i = 0; i < h; ++i)
    {
        for(int j = 0; j < w; ++j)
        {
            int tmp;
            if(i < b)
            {
                if(j < a)tmp = 0;
                else tmp = 1;
            }
            else
            {
                if(j < a)tmp = 1;
                else tmp = 0;
            }
            cout << tmp;
        }
        cout << endl;
    }

    cout << endl;
    return 0;    
}

