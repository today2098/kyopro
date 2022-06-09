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

template <typename Type>
std::vector<Type> table(size_t n, Type val) { return std::vector<Type>(n, val); }

template <class... Args>
auto table(size_t n, Args... args) {
    auto val = table(args...);
    return std::vector<decltype(val)>(n, std::move(val));
}

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

int main(){
    int n;
    string s;
    cin>>n>>s;
    
    int m=7;
    string t="atcoder";
    auto &&dp=table(n+1,m+1,mint1000000007(0));
    REP(i,n+1) dp[i][0]=1;
    FOR(i,1,n+1)FOR(j,1,m+1){
        dp[i][j]+=dp[i-1][j];
        if(s[i-1]==t[j-1]) dp[i][j]+=dp[i-1][j-1];
    }
    
    // REP(i,n+1) line(dp[i]);
    
    cout<<dp[n][m]<<endl;
}
