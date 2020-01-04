//オイラーの公式

//三角関数 -> 指数関数
//三角関数は直交している(内積が0)

//高速フーリエ変換
//https://atc001.contest.atcoder.jp/tasks/fft_c


//https://www.yukisako.xyz/entry/fourier-transform

//なんとなく、よくわからん関数を三角関数の和に変換するということはわかった
#include <bits/stdc++.h>
#define DEBUG 1

using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define sz(x) ((ll)(x).size())
#define pll pair<ll,ll>
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;i++)
//複素数
#define  Complex complex<double>

const double PI = acos(-1);
vector<Complex> fft(vector<Complex> A, int n, int sgn)
{
    if(n==1)return A;
    vector <Complex> f0,f1;
    REP(i, n/2)
    {
        f0.push_back(A[i*2+0]);
        f1.push_back(A[i*2+1]);
    }
    f0 = fft(f0,n/2, sgn);
    f1 = fft(f1,n/2, sgn);
    Complex zeta = Complex(cos(2.0 * PI/n), sin(2.0 * PI/n) * sgn);
    Complex pow_zeta = 1;
    REP(i, n)
    {
        A[i] = f0[i % (n / 2)] + pow_zeta * f1[i % (n/ 2)];
        pow_zeta *= zeta;
    }
    return A;
}

vector <Complex> inv_fft(vector <Complex> A, int n)
{
    auto res = fft(A, n, -1);
    REP(i, n)
    {
        res[i] /= n;
    }
    return res;
}


vector <Complex> multiply(vector <Complex> &X, vector <Complex> &Y)
{
    int n = 1;
    while(n < (sz(X) + sz(Y) + 1))n *= 2;
    vector <Complex> ret;
    X.resize(n);
    Y.resize(n);
    X = fft(X, n, 1);
    Y = fft(Y, n, 1);

    REP(i,n)ret.push_back(X[i] * Y[i]);

    return(inv_fft(ret, n));
}

int main()
{
#if DEBUG
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    int N;
    cin >> N;
    vector <Complex> x(N+1);
    vector <Complex> y(N+1);

    x[0] = 0;
    y[0] = 0;
    //点の登録
    REP(i, N)
    {
        double a, b;
        cin >> a >> b;
        x[i+1] = a;
        y[i+1] = b;
    }
    //i円の組み合わせ数
    vector <Complex> res = multiply(x, y);
    REP(i, 2 * N)
    {
        cout << (int)(res[i+1].real() + 0.5) << endl;
    }

}