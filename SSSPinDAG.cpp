#include <iostream> 
#include <vector>
#include <algorithm>
#include <unordered_map>

typedef long long int ll;
#define MOD 1e9 + 7
#define fi(a,b) for(ll i = a; i < b; i++)
#define fj(a,b) for(ll j = a; j < b; j++)
#define fk(a,b) for(ll k = a; k < b; k++)

using namespace std;

ll n,ind;
unordered_map <ll,vector <vector <ll>>> gal;
bool* visited = (bool*)malloc(n*sizeof(bool));
ll* top_order = (ll*)malloc((n+1)*sizeof(ll));
ll* path = (ll*)malloc((n+1)*sizeof(ll));

void SSSP(ll vertice,ll weight){
    path[vertice] = min(weight,path[vertice]);
    for(auto m:gal[vertice]){
        SSSP(m[0],weight+m[1]);
    }
}

int top_sort(ll vertice){
    if(visited[vertice]){
        return 0;
    }
    visited[vertice] = true;
    for(auto m : gal[vertice]){
        top_sort(m[0]);
    }
    top_order[ind] = vertice;
    ind--;
    return 0;
}

void solve(){
    ll e;
    cin >> n >> e;
    ind = n;
    ll from,to,weight;
    fi(0,e){
        cin >> from >> to >> weight;
        vector <ll> temp = {to,weight};
        gal[from].push_back(temp);
        visited[from] = false;
        visited[to] = false;
    }
    for(auto m : gal){
        if(!(visited[m.first])){
            top_sort(m.first);
        }
    }
    fi(1,n+1){
        path[i] = INT32_MAX;
    }
    SSSP(top_order[1],0);
    fi(1,n+1){
        cout << top_order[i] << " ";
    }
    cout << "\n";
    fi(1,n+1){
        cout << path[i] << " ";
    }

}
//example
// 8 13 
// 1 2 3
// 1 3 6
// 2 3 4
// 2 5 11
// 2 4 4
// 3 4 8
// 3 7 11
// 4 5 -4
// 4 6 5
// 4 7 2
// 5 8 9
// 6 8 1
// 7 8 2

int main()
{   
    solve();
    return 0;
}