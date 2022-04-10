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

// 素集合データ構造.
class UnionFind {
    int vn, gn;            // vn:=(ノード数), gn:=(グループ数).
    std::vector<int> par;  // par[v]:=(ノードvの親番号). 0未満の場合，vが親で，絶対値がグループサイズを表す．

public:
    // constructor.
    UnionFind() : UnionFind(0) {}
    explicit UnionFind(size_t vn_) : vn(vn_), gn(vn_), par(vn_, -1) {}

    int get_vn() const { return vn; };  // ノード数を返す．
    int get_gn() const { return gn; };  // グループ数を返す．
    int root(int v) {                   // ノードvの親番号を返す．
        assert(0 <= v and v < vn);
        if(par[v] < 0) return v;
        return par[v] = root(par[v]);
    }
    int size(int v) {  // ノードvが属するグループのサイズを返す．
        assert(0 <= v and v < vn);
        return -par[root(v)];
    }
    bool same(int u, int v) {  // ノードuとvが同じグループか判定する．
        assert(0 <= u and u < vn);
        assert(0 <= v and v < vn);
        return root(u) == root(v);
    }
    bool unite(int u, int v) {  // ノードu, vが属するそれぞれのグループを結合する．
        assert(0 <= u and u < vn);
        assert(0 <= v and v < vn);
        u = root(u), v = root(v);
        if(u == v) return false;                // Do nothing.
        if(size(u) < size(v)) std::swap(u, v);  // Merge technique.
        par[u] += par[v];
        par[v] = u;
        gn--;
        return true;
    }
    void reset() {
        gn = vn;
        std::fill(par.begin(), par.end(), -1);
    }
};

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
    cin>>n;
    
    vi p(n),q(n);
    for(auto &in:p) cin>>in;
    for(auto &in:q) cin>>in;
    
    UnionFind uf(n+1);
    REP(i,n) uf.unite(p[i],q[i]);
    
    mint998244353 ans=1;
    bool seen[n+1]={};
    FOR(i,1,n+1){
        int par=uf.root(i);
        if(seen[par]) continue;
        seen[par]=true;
        
        int tmp=uf.size(par);
        if(tmp==1){}
        else{
            ans*=tmp+1;
        }
    }
    
    cout<<ans<<endl;
}
