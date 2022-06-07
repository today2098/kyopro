#include <bits/stdc++.h>
#define REP(i,n)   for(int i=0;i<(int)(n);++i)
#define FOR(i,l,r) for(int i=(int)(l);i<(int)(r);++i)
#define ALL(v)     (v).begin(),(v).end()
#define debug(x)   std::cerr<<"(L"<<__LINE__<<") "<<#x<<": "<<(x)<<std::endl
using ll  = long long;
using vi  = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int,int>;
using namespace std;
constexpr int       INF  = 1e9;
constexpr long long LINF = 1e18;
constexpr double    EPS  = 1e-10;
constexpr int       MOD  = 1e9+7;
template<class Class> void line(const Class &a,std::ostream &os=std::cerr){int cnt=0;for(const auto &elem:a)os<<(cnt++==0?"":" ")<<elem;os<<std::endl;}

// エラトステネスの篩．
class Sieve {
    int mx;                // mx:=(篩にかける最大の自然数).
    std::vector<int> lpf;  // lpf[n]:=(自然数nの最小の素因数). Least prime factor. lpf[n]=nのとき，nは素数．

public:
    // constructor.
    Sieve() : Sieve(51e4) {}
    explicit Sieve(int n) : mx(n), lpf(n + 1, -1) {  // n以下の自然数を篩にかける．O(N loglogN).
        assert(n >= 0);
        for(int p = 2; p <= mx; ++p) lpf[p] = p;
        for(int p = 2; p * p <= mx; ++p) {
            if(lpf[p] == p) {
                for(int m = p * p; m <= mx; m += p) {
                    if(lpf[m] == m) lpf[m] = p;
                }
            }
        }
    }

    bool is_prime(int n) const {  // 素数判定．O(1).
        assert(0 <= n and n <= mx);
        return lpf[n] == n;
    }
    std::map<int, int> prime_factorize(int n) const {  // 高速素因数分解．O(logN).
        assert(1 <= n and n <= mx);
        std::map<int, int> res;
        while(n > 1) {
            res[lpf[n]]++;
            n /= lpf[n];
        }
        return res;
    }
    std::vector<int> divisors(int n) const {  // 高速約数列挙．
        assert(1 <= n and n <= mx);
        std::vector<int> res({1});
        const auto &&pf = prime_factorize(n);
        for(const auto &[p, cnt] : pf) {
            int sz = res.size();
            int v = 1;
            for(int i = 0; i < cnt; ++i) {
                v *= p;
                for(int j = 0; j < sz; ++j) res.push_back(res[i] * v);
            }
        }
        std::sort(res.begin(), res.end());
        return res;
    }
};

int main(){
    int n;
    cin>>n;
    
    Sieve ob(2e5+10);
    vector<int> squares;
    for(int i=1;i*i<=n;++i) squares.push_back(i*i);
    ll ans=squares.size();
    for(int i=2;i<=n;++i){
        const auto &&pf=ob.prime_factorize(i);
        
        int tmp=1;
        for(const auto &[p,cnt]:pf){
            if(cnt%2==1) tmp*=p;
        }
        
        ans+=upper_bound(ALL(squares),n/tmp)-squares.begin();
    }
    
    cout<<ans<<endl;
}
