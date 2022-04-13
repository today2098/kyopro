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

int main(){
    int n;
    cin>>n;
    
    vi p(n),q(n);
    for(auto &in:p) cin>>in;
    for(auto &in:q) cin>>in;
    
    UnionFind uf(n+1);
    REP(i,n) uf.unite(p[i],q[i]);
    
    ll ans=1;
    bool seen[n+1]={};
    FOR(i,1,n+1){
        int par=uf.root(i);
        if(seen[par]) continue;
        seen[par]=true;
        
        int sz=uf.size(par);
        if(sz%2==0){
            ll tmp=(ll)(sz/2)*(2+sz)/2+1;
            ans*=tmp;
        }else{
            ll tmp=(ll)(sz/2)*(3+sz)/2+1;
            ans*=tmp;
        }
        debug(ans);
    }
    
    cout<<ans<<endl;  
}
