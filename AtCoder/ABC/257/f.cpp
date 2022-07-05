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

vi bfs(int s,int n,const vvi &g){
    vi d(n,INF);
    d[s]=0;
    queue<int> que;
    que.push(s);
    while(!que.empty()){
        int u=que.front();
        que.pop();
        for(int v:g[u]){
            if(d[v]==INF){
                d[v]=d[u]+1;
                que.push(v);
            }
        }
    }
    
    return d;
}

int main(){
    int n,m;
    cin>>n>>m;
    
    vvi g(n+1);
    REP(i,m){
        int u,v;
        cin>>u>>v;
        
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    vi &&d_one=bfs(1,n+1,g);
    vi &&d_n=bfs(n,n+1,g);
    
    int direct=d_one[n];
    FOR(v,1,n+1){
        int tmp=min(d_one[0]+d_n[v],d_one[v]+d_n[0]);
        int ans=min(direct,tmp);
        
        cout<<(ans==INF?-1:ans)<<endl;
    }
}
