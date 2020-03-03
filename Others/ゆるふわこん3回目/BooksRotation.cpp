#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm> // sort
#include <unistd.h>
#include <map>

#define pii pair<int,int>
#define REP(i, n) for (long long i = 0; i < (n); i++) 
using namespace std;


typedef long long ll;
static const ll INF = 1000000000000000000LL;
static const ll MOD = 1000000007;

int H,W;

//https://www.hackerrank.com/contests/yfkpo3-2/challenges
bool cmp(vector<int> b, vector <int> a)
{

    bool flg;
    for(int i = 0; i < H; ++i)
    {
        //cout << i << endl;
        flg = true;
        for(int j = 0; j < H; ++j)
        {
            if(a[j] != b[j])
            {
                flg = false;
                break;
            }
        }
        if(flg)break;

        //irekae
        int tmp = a[H-1];
        for(int j = H-1; j >= 1; --j)
        {
            a[j] = a[j-1];
        }
        a[0] = tmp;
    }


    return flg;
}

int main()
{
    cin >> H >> W;
    vector <vector<int>> a(W,vector<int>(H));

    REP(i,H)
    {
        REP(j,W)
        {
            cin >> a[j][i];
        }
    }
    string res = "Yes";

    //1列目の1番目に全部合わせる
    vector <int> tar = a[0];

    for(int x = 1; x < W; ++x)
    {
        //cout << x << ":" << endl;

        bool flg = false;
        for(int y = 0; y < H; ++y)
        {
            if(cmp(tar,a[x]))
            {
                flg = true;
                break;
            }
        }
        if(!flg)
        {
            res = "No";
            break;
        }
    }

    cout << res << endl;


    return 0;
}