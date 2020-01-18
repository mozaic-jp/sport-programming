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

string seki[] = {"Vacant", "Male", "Female"};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // Maleだったら、半分で

    ll N;
    cin >> N;
    ll res;
    ll t;
    string zero = "";
    string a;
    int l,r,m;
    l = 0;
    r = N;
    m = (N-1) / 2;

    //1回目
    cout << 0 << endl;
    cout.flush();

    cin >> zero;
    if(zero == seki[0])
    {
        return 0;
    }

    //N-1回目
    cout << N-1 << endl;
    cout.flush();

    cin >> a;
    if(a == seki[0])
    {
        return 0;
    }

    while(true)
    {
        cout << m << endl;
        cout.flush();
        string s;
        cin >> s;

        if(s == seki[0])
        {
            return 0;
        }
        //0との位置を判定
        else if(s == zero)
        {
            //区間が偶数であれば間にない
            if(m % 2 == 0)
            {
                l = m+1;
            }
            else
            {
                r = m-1;
            }
        }
        else
        {
            //区間が偶数であれば間にない
            if(m % 2 == 0)
            {
                r = m-1;
            }
            else
            {
                l = m+1;
            }
        }

        m = (l + r) / 2;
    }

    return 0;    
}
