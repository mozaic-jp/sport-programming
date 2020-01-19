#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <math.h>
#include <algorithm> // sort

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll INF = 1000000000000000000LL;
using namespace std;

const int MOD = 1000000007;

int main(){
    ll N;
    cin >> N;
    vector <pair<int, int> > v(N);

    REP(i,N)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(),v.end());

    if(N==1)
    {
        cout << 1 << endl;
        return 0;
    }

    int cnt = 0;
    int cur = 0;
    for(int i = 0; i < N-1; ++i)
    {
        //1個
        if(v[i].first + v[i].second <= v[i+1].first - v[i+1].second)
        {
            ++cnt;
            if(i == N-2)++cnt;
            continue;
        }
        else
        {
            if(i == N-2)++cnt;
            //v[i]のほうが短いか
            if(v[i].first + v[i].second <= v[i+1].first + v[i+1].second)
            {
                v[i+1].first = v[i].first;
                v[i+1].second = v[i].second;
            }
        }
    }


    cout << cnt << endl;

    return 0;    
}
