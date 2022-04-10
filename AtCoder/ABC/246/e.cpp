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

template<typename Type> inline bool chmax(Type &a,const Type &b){if(a<b){a=b;return true;}return false;}
template<typename Type> inline bool chmin(Type &a,const Type &b){if(a>b){a=b;return true;}return false;}

int main(){
    int n;
    cin>>n;
    
    int ay,ax,by,bx;
    cin>>ay>>ax>>by>>bx;
    ay--, ax--, by--, bx--;
    
    vector<string> vs(n);
    for(auto &in:vs) cin>>in;
    
    auto &&dp=table(n,n,5,INF);
    dp[ay][ax][4]=0;
    deque<tuple<int,int,int> > dque;
    dque.emplace_back(ay,ax,4);
    bool seen[n][n][5]={{{}}};
    const int dy[] = {-1, -1, 1, 1};
    const int dx[] = {-1, 1, -1, 1};
    auto jud=[&n](int y,int x)->bool{
        return (0<=y and y<n and 0<=x and x<n);
    };
    while(!dque.empty()){ // 0-1 BFS.
        auto [y,x,dir]=dque.front();
        dque.pop_front();
        
        if(y==by and x==bx){
            cout<<dp[y][x][dir]<<endl;
            return 0;
        }
        
        if(seen[y][x][dir]) continue;
        seen[y][x][dir]=true;
        
        REP(i,4){
            int ny=y+dy[i], nx=x+dx[i];
            if(jud(ny,nx) and vs[ny][nx]=='.'){
                if(chmin(dp[ny][nx][i], dp[y][x][dir]+(i==dir?0:1))){
                    if(i==dir) dque.emplace_front(ny,nx,i);
                    else dque.emplace_back(ny,nx,i);
                }
            }
        }
    }
    
    cout<<-1<<endl;
}
