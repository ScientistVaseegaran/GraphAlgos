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
unordered_map <ll,vector <ll>> gal;
bool* visited = (bool*)malloc(n*sizeof(bool));
ll* top_order = (ll*)malloc((n+1)*sizeof(ll));

int top_sort(ll vertice){
    if(visited[vertice]){
        return 0;
    }
    visited[vertice] = true;
    for(auto m : gal[vertice]){
        top_sort(m);
    }
    top_order[ind] = vertice;
    ind--;
    return 0;
}

void solve(){
    ll e;
    cin >> n >> e;
    ind = n;
    ll from,to;
    fi(0,e){
        cin >> from >> to;
        gal[from].push_back(to);
        visited[from] = false;
        visited[to] = false;
    }
    for(auto m : gal){
        if(!(visited[m.first])){
            top_sort(m.first);
        }
    }
    fi(1,n+1){
        cout << top_order[i] << " ";
    }


}
//example
// 13 18
// 3 1
// 3 2
// 5 1
// 1 4
// 3 4
// 5 4
// 5 6
// 4 8
// 4 7
// 6 11
// 6 10
// 8 10
// 8 9
// 7 9
// 11 10
// 9 12
// 10 12
// 10 13

int main()
{   
    solve();
    return 0;
}