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

template <typename T>
class SegmentTree {
    using F = std::function<T(T, T)>;

    F f;                  // T f(T,T):=(二項演算関数).
    T e;                  // e:=(単位元).
    int sz, n;            // sz:=(要素数), n:=(葉の数).
    std::vector<T> tree;  // tree[]:=(完全二分木). 1-based index.

    void build() {
        n = 1;
        while(n < sz) n <<= 1;
        tree.assign(2 * n, e);
    }

public:
    // constructor. O(N).
    SegmentTree(){};
    explicit SegmentTree(const F &f_, const T &e_, size_t sz_) : f(f_), e(e_), sz(sz_) {
        build();
    }
    explicit SegmentTree(const F &f_, const T &e_, std::vector<T> &v) : f(f_), e(e_), sz(v.size()) {
        build();
        std::copy(v.begin(), v.end(), tree.begin() + n);
        for(int i = n - 1; i >= 1; --i) tree[i] = f(tree[i << 1], tree[(i << 1) | 1]);
    }

    int size() const { return sz; }   // 要素数を返す．
    T identity() const { return e; }  // 単位元を返す．
    void set(int k, const T &a) {     // k番目の要素をaに置き換える．O(logN).
        assert(0 <= k and k < sz);
        k = k + n;
        tree[k] = a;
        while(k >>= 1) tree[k] = f(tree[k << 1], tree[(k << 1) | 1]);
    }
    T prod(int k) const {  // 一点取得．O(1).
        assert(0 <= k and k < sz);
        return tree[k + n];
    }
    T prod(int l, int r) const {  // 区間[l,r)の総積（v[l]•v[l+1]•....•v[r-1]）を求める．O(logN).
        assert(0 <= l and l <= r and r <= sz);
        T lv = e, rv = e;
        l = l + n, r = r + n;
        while(l < r) {
            if(l & 1) lv = f(lv, tree[l++]);
            if(r & 1) rv = f(tree[--r], rv);
            l >>= 1, r >>= 1;
        }
        return f(lv, rv);
    }
    T all_prod() const { return tree[1]; }  // 区間全体の総積を返す．O(1).
    // jud(prod(l,-))=trueとなる区間の最右位値を二分探索する．ただし要素列には単調性があり，またjud(e)=true．O(logN).
    int most_right(const std::function<bool(T)> &jud, int l) const {
        assert(jud(e) == true);
        assert(0 <= l and l <= sz);
        if(l == sz) return sz;
        T val = e;
        l += n;
        do {
            while(!(l & 1)) l >>= 1;
            T &&tmp = f(val, tree[l]);
            if(!jud(tmp)) {
                while(l < n) {
                    l <<= 1;
                    T &&tmp2 = f(val, tree[l]);
                    if(jud(tmp2)) val = tmp2, l++;
                }
                return l - n;
            }
            val = tmp, l++;
        } while((l & -l) != l);  // (x&-x)==xのとき，xは2の階乗数．
        return sz;
    }
    // jud(prod(-,r))=trueとなる区間の最左位値を二分探索する．ただし要素列には単調性があり，またjud(e)=true．O(logN).
    int most_left(const std::function<bool(T)> &jud, int r) const {
        assert(jud(e) == true);
        assert(0 <= r and r <= sz);
        if(r == 0) return 0;
        T val = e;
        r += n;
        do {
            r--;
            while(r > 1 and r & 1) r >>= 1;
            T &&tmp = f(tree[r], val);
            if(!jud(tmp)) {
                while(r < n) {
                    r = (r << 1) | 1;
                    T &&tmp2 = f(tree[r], val);
                    if(jud(tmp2)) val = tmp2, r--;
                }
                return r - n + 1;
            }
            val = tmp;
        } while((r & -r) != r);  // (x&-x)==xのとき，xは2の階乗数．
        return 0;
    }
    void reset() { std::fill(tree.begin(), tree.end(), e); }
};

int main(){
    int n;
    int x,y;
    cin>>n>>x>>y;
    
    vi a(n);
    for(auto &in:a) cin>>in;
    
    using T=int;
    const auto f=[](T a,T b)->T{return max(a,b);};
    const T e=-INF;
    SegmentTree<T> tree(f,e,a);
    
    const auto jf=[&x](T a)->bool{return a<=x;};
    const auto jff=[&x](T a)->bool{return a<=x-1;};
    
    const auto f2=[](T a,T b)->T{return min(a,b);};
    const T e2=INF;
    SegmentTree<T> tree2(f2,e2,a);
    
    const auto jf2=[&y](T a)->bool{return y<=a;};
    const auto jff2=[&y](T a)->bool{return y+1<=a;};
    
    ll ans=0;
    FOR(i,1,n+1){
        int l=tree.most_left(jf,i);
        int r=tree.most_left(jff,i);
        int l2=tree2.most_left(jf2,i);
        int r2=tree2.most_left(jff2,i);
        
        assert(l<=r);
        assert(l2<=r2);
        
        // debug(i);
        // fprintf(stderr, "%d %d\n", l,r);
        // fprintf(stderr, "%d %d\n", l2,r2);
        
        ll tmp=0;
        if(l<=l2){
            if(r<=l2){}
            else if(r2<=r) tmp=r2-l2;
            else tmp=r-l2;
        }else{
            if(r2<=l){}
            else if(r<=r2) tmp=r-l;
            else tmp=r2-l;
        }
        // debug(tmp);
        ans+=tmp;
    }
    
    cout<<ans<<endl;
}