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

// #define DEBUG

#ifdef DEBUG

#define debug(...) debug_internal(__LINE__, #__VA_ARGS__, __VA_ARGS__)
#define line(a) line_internal(__LINE__, #a, a);

template <typename T, class... Args>
void debug_internal(int l, const char *context, T &&first, Args &&...args) {
    constexpr const char *open_brankets = (sizeof...(args) == 0 ? "" : "(");
    constexpr const char *close_brankets = (sizeof...(args) == 0 ? "" : ")");
    std::cerr << "[L" << l << "] " << open_brankets << context << close_brankets << ": "
              << open_brankets << std::forward<T>(first);
    ((std::cerr << ", " << std::forward<Args>(args)), ...);
    std::cerr << close_brankets << std::endl;
}

template <class Class>
void line_internal(int l, const char *context, const Class &a) {
    std::cerr << "[L" << l << "] " << context << ": ";
    int cnt = 0;
    for(const auto &elem : a) std::cerr << (cnt++ == 0 ? "" : " ") << elem;
    std::cerr << std::endl;
}

#else

#define debug(...) void(0)
#define line(a) void(0)

#endif

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

template <typename Type>
Type euclidean_distance(Type dy, Type dx) { return dy * dy + dx * dx; }

int main(){
    int n;
    ll sx,sy,tx,ty;
    cin>>n>>sx>>sy>>tx>>ty;
    
    vector<tuple<ll,ll,ll> > vt(n);
    for(auto &[x,y,r]:vt) cin>>x>>y>>r;
    
    int s,t;
    REP(v,n){
        const auto &[x,y,r]=vt[v];
        if(euclidean_distance(abs(sy-y),abs(sx-x))==r*r) s=v;
        if(euclidean_distance(abs(ty-y),abs(tx-x))==r*r) t=v;
    }
    debug(s,t);
    
    UnionFind uf(n);
    REP(u,n){
        const auto &[ux,uy,ur]=vt[u];
        
        REP(v,n){
            if(u==v) continue;
            
            const auto &[vx,vy,vr]=vt[v];
            auto dist=euclidean_distance(abs(uy-vy),abs(ux-vx));
            if(abs(ur-vr)*abs(ur-vr)<=dist and dist<=(ur+vr)*(ur+vr)) uf.unite(u,v);
        }
    }
    
    bool ans=uf.same(s,t);
    cout<<(ans?"Yes":"No")<<endl;
}
