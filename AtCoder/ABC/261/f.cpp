#include <bits/stdc++.h>
#define REP(i,n)   for(int i=0;i<(int)(n);++i)
#define FOR(i,l,r) for(int i=(int)(l);i<(int)(r);++i)
#define ALL(v)     (v).begin(),(v).end()
using ll  = long long;
using vi  = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int,int>;
using namespace std;
constexpr int       INF  = 1e9;
constexpr long long LINF = 1e18;
constexpr double    EPS  = 1e-10;
constexpr int       MOD  = 1e9+7;

// Binary Indexed Tree.
template <typename T>
class BIT {
    int sz;               // sz:=(要素数).
    std::vector<T> tree;  // 1-based index.

    void build() {
        for(int i = 1; i < sz; ++i) {
            int j = i + (i & -i);
            if(j <= sz) tree[j] += tree[i];
        }
    }

public:
    // constructor. O(N).
    BIT() : BIT(0){};
    explicit BIT(size_t sz_) : sz(sz_), tree(sz_ + 1, 0) {}
    explicit BIT(const std::vector<T> &v) : sz(v.size()), tree(v.size() + 1) {
        std::copy(v.begin(), v.end(), tree.begin() + 1);
        build();
    }

    int size() const { return sz; }
    void fill(T a = 0) {  // 全要素をaで埋める．O(N).
        std::fill(tree.begin() + 1, tree.end(), a);
        if(a == 0) return;
        build();
    }
    void add(int k, T a) {  // k番目の要素にaを足す．O(logN).
        assert(1 <= k and k <= sz);
        for(; k <= sz; k += (k & -k)) tree[k] += a;
    }
    T sum(int r) const {  // 区間[1,r]の総和を求める．O(logN).
        assert(0 <= r and r <= sz);
        T res = 0;
        for(; r > 0; r -= (r & -r)) res += tree[r];
        return res;
    }
    T sum(int l, int r) const {  // 区間[l,r]の総和を求める．O(logN).
        assert(1 <= l and l <= r and r <= sz);
        return sum(r) - sum(l - 1);
    }
};

int main(){
    int n;
    cin>>n;
    
    vi c(n);
    vi x(n);
    vvi y(n+1); // y[c][]:=(色cの値のリスト).
    for(auto &in:c) cin>>in;
    for(auto &in:x) cin>>in;
    REP(i,n) y[c[i]].push_back(x[i]);
    
    BIT<int> tree(n);
    ll ans=0;
    for(int i=n-1;i>=0;--i){
        ans+=tree.sum(x[i]-1);
        tree.add(x[i],1);
    }
    for(auto elem:x) tree.add(elem,-1);
    FOR(i,1,n+1){
        const auto &v=y[i];
        for(auto itr=v.rbegin();itr<v.rend();++itr){
            ans-=tree.sum(*itr-1);
            tree.add(*itr,1);
        }
        for(auto elem:v) tree.add(elem,-1);
    }
    
    cout<<ans<<endl;    
}

// I refered explanations.
