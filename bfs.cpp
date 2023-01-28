#include <iostream> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>


typedef long long int ll;
#define MOD 1e9 + 7
#define fi(a,b) for(ll i = a; i < b; i++)
#define fj(a,b) for(ll j = a; j < b; j++)
#define fk(a,b) for(ll k = a; k < b; k++)

using namespace std;

unordered_map <ll,bool> visited;
unordered_map <ll,vector <ll>> gal;
queue <ll> que;

int bfs(ll vertice){
    if(visited[vertice]){
        return 0;
    }
    visited[vertice] = true;
    for(auto m : gal[vertice]){
            que.push(m);
    }
    que.pop();
    if(que.empty()){
        return 0;
    }
    bfs(que.front());
}

void solve(){
    ll from = 1,to;
    do{
        cin >> from >> to;
        gal[from].push_back(to);
        visited[from] = false;
        visited[to] = false;
    }while(from > 0);

    for(auto m : gal){
        if(!visited[m.first]){
            que.push(m.first);
            bfs(m.first);
        }
    }
}

int main()
{   
    solve();
    return 0;
}