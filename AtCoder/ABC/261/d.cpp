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
#define dline(a) dline_internal(__LINE__, #a, a);

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
void dline_internal(int l, const char *context, const Class &a) {
    std::cerr << "[L" << l << "] " << context << ": ";
    int cnt = 0;
    for(const auto &elem : a) std::cerr << (cnt++ == 0 ? "" : " ") << elem;
    std::cerr << std::endl;
}

#else

#define debug(...) void(0)
#define dline(a) void(0)

#endif

template <typename Type>
std::vector<Type> table(size_t n, Type val) { return std::vector<Type>(n, val); }

template <class... Args>
auto table(size_t n, Args &&...args) {
    auto val = table(std::forward<Args>(args)...);
    return std::vector<decltype(val)>(n, std::move(val));
}

int main(){
    int n,m;
    cin>>n>>m;
    
    vector<ll> x(n+1), y(n+1,0);
    FOR(i,1,n+1) cin>>x[i];
    REP(i,m){
        int c;
        cin>>c;
        cin>>y[c];
    }
    
    auto &&dp=table(n+1,n+1,0LL);
    FOR(i,1,n+1){
        dp[i][0]=*max_element(ALL(dp[i-1]));
        FOR(j,1,i+1) dp[i][j]=dp[i-1][j-1]+x[i]+y[j];
        dline(dp[i]);
    }
    
    auto ans=*max_element(ALL(dp[n]));
    cout<<ans<<endl;
}
