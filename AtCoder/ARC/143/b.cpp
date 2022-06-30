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

template <int mod>
class Modint {
    long long val;

public:
    // constructor.
    Modint() : Modint(0) {}
    Modint(long long val_) : val(val_) {
        static_assert(mod >= 1);
        val %= mod;
        if(val < 0) val += mod;
    }

    Modint operator+() const { return Modint(*this); }
    Modint operator-() const { return Modint() - (*this); }
    Modint &operator++() {
        val++;
        if(val == mod) val = 0;
        return *this;
    }
    Modint &operator--() {
        if(val == 0) val = mod;
        val--;
        return *this;
    }
    Modint operator++(int) {
        Modint res = *this;
        ++(*this);
        return res;
    }
    Modint operator--(int) {
        Modint res = *this;
        --(*this);
        return res;
    }
    friend Modint operator*(const Modint &x, const Modint &y) { return Modint(x) *= y; }
    friend Modint operator/(const Modint &x, const Modint &y) { return Modint(x) /= y; }
    friend Modint operator+(const Modint &x, const Modint &y) { return Modint(x) += y; }
    friend Modint operator-(const Modint &x, const Modint &y) { return Modint(x) -= y; }
    Modint &operator*=(const Modint &a) {
        val = val * a.val % mod;
        return *this;
    }
    Modint &operator/=(const Modint &a) { return (*this) *= a.inv(); }
    Modint &operator+=(const Modint &a) {
        val += a.val;
        if(val >= mod) val -= mod;
        return *this;
    }
    Modint &operator-=(const Modint &a) {
        val -= a.val;
        if(val < 0) val += mod;
        return *this;
    }
    friend bool operator==(const Modint &x, const Modint &y) { return x.val == y.val; }
    friend bool operator!=(const Modint &x, const Modint &y) { return x.val != y.val; }
    friend std::istream &operator>>(std::istream &is, Modint &x) {
        is >> x.val;
        x.val %= mod;
        if(x.val < 0) x.val += mod;
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Modint &x) { return os << x.val; }

    int modulus() const { return mod; }
    long long value() const { return val; }
    Modint inv() const {
        long long a = val, b = mod, u = 1, v = 0;
        while(b) {
            long long t = a / b;
            a -= t * b, u -= t * v;
            std::swap(a, b), std::swap(u, v);
        }
        return Modint(u);
    }

    friend Modint mod_pow(const Modint &x, long long k) {
        if(k < 0) return mod_pow(x.inv(), -k);
        Modint res = 1, tmp = x;
        while(k > 0) {
            if(k & 1LL) res *= tmp;
            tmp = tmp * tmp, k >>= 1;
        }
        return res;
    }
};

using mint998244353  = Modint<998'244'353>;
using mint1000000007 = Modint<1'000'000'007>;

// 二項係数（mod付き）．
template <int mod>
class Combination {
    int sz;                                  // sz:=(要素数). ただし，sz<mod．
    std::vector<long long> fact, inv, finv;  // fact[n]:=(nの階乗), inv[n]:=(nの逆元), finv[n]:=(nの階乗の逆元).

    void build() {
        fact[0] = fact[1] = 1;
        inv[1] = 1;
        finv[0] = finv[1] = 1;
        for(int a = 2; a < sz; ++a) {
            fact[a] = fact[a - 1] * a % mod;
            inv[a] = mod - inv[mod % a] * (mod / a) % mod;
            finv[a] = finv[a - 1] * inv[a] % mod;
        }
    }

public:
    // constructor. O(N).
    Combination() : Combination(51e4) {}
    explicit Combination(size_t sz_) : sz(sz_), fact(sz_), inv(sz_), finv(sz_) {
        static_assert(mod >= 1);
        assert(2 <= sz and sz < mod);
        build();
    }

    int modulus() const { return mod; }
    long long factorial(int n) const {  // 階乗.
        assert(0 <= n and n < sz);
        return fact[n];
    }
    long long inverse(int n) const {  // 逆元.
        assert(1 <= n and n < sz);
        return inv[n];
    }
    long long inverse_fact(int n) const {  // 階乗の逆元.
        assert(0 <= n and n < sz);
        return finv[n];
    }
    long long nPk(int n, int k) const {  // 順列．
        assert(0 <= k and k <= n and n < sz);
        return fact[n] * finv[n - k] % mod;
    }
    long long nCk(int n, int k) const {  // 組み合わせ．
        assert(0 <= k and k <= n and n < sz);
        return fact[n] * finv[n - k] % mod * finv[k] % mod;
    }
    long long nHk(int n, int k) const { return nCk(k + n - 1, n - 1); }  // 重複組み合わせ．
};

using Combination998244353  = Combination<998'244'353>;
using Combination1000000007 = Combination<1'000'000'007>;

int main(){
    int n;
    cin>>n;
    
    using mint=mint998244353;
    Combination998244353 comb;
    
    mint ans=comb.factorial(n*n);
    mint tmp=mint(comb.nCk(n*n,2*n-1))*(n*n)*comb.factorial(n-1)*comb.factorial(n-1)*comb.factorial((n-1)*(n-1));
    ans-=tmp;
    
    cout<<ans<<endl;
}

// I refered explanations.
