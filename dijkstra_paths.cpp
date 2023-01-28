#include <iostream> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <limits.h>


typedef long long int ll;
#define MOD 1e9 + 7
#define fi(a,b) for(ll i = a; i < b; i++)
#define fj(a,b) for(ll j = a; j < b; j++)
#define fk(a,b) for(ll k = a; k < b; k++)

using namespace std;

vector <vector <ll>> dijkstra(unordered_map <ll,vector <vector <ll>>> gal, ll n, ll start, ll* dist,vector <vector <ll>> final){ //dist = answer,final = paths
    ll index,length;
    ll visited[n+1] = {false};
    dist[start] = 0;
    priority_queue < pair <ll,ll>, vector<pair <ll,ll>>, greater<pair <ll,ll>>> pq;
    pq.push(make_pair(0,start));
    while(!(pq.empty())){
        index = (pq.top()).second;
        length = (pq.top()).first;
        pq.pop();
        if(visited[index]){
                continue;
            }
        visited[index] = true;
        for(auto m : gal[index]){
            if(visited[m[0]]){
                continue;
            }
            if(length+m[1] < dist[m[0]]){
                dist[m[0]] = length + m[1];
                final[m[0]] = final[index];
                final[m[0]].push_back(m[0]);
            }
            pq.push(make_pair(dist[m[0]],m[0]));
        }
    }
    return final;
}


void solve(){
    ll n,e,start;
    cin >> n >> e;
    vector <vector <ll>> final;
    fi(0,n+1){
        vector <ll> temp;
        final.push_back(temp);
    }
    unordered_map <ll,vector <vector <ll>>> gal;
    ll dist[n+1];
    fi(1,n+1){
        dist[i] = INT_MAX;
    }
    ll from,to,weight;
    fi(0,e){
        cin >> from >> to >> weight;
        vector <ll> temp1 = {to,weight};
        vector <ll> temp2 = {from,weight};
        gal[from].push_back(temp1);
        gal[to].push_back(temp2);
    }
    cin >> start;
    vector <ll> path;
    path.push_back(start);
    final[start] = path;
    final = dijkstra(gal,n,start,dist,final);
    cout << "distance : " ;
    fi(1,n+1){
        cout << dist[i] << " ";
    }
    cout << "\nPaths : " << endl;
    fi(1,n+1){
        for(auto m : final[i]){
            cout << m << " ";
        }
        cout << "\n";
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
// 4 5 4
// 4 6 5
// 4 7 2
// 5 8 9
// 6 8 1
// 7 8 2

// 4 6
// 1 2 3
// 2 3 1
// 2 4 2
// 3 4 3
// 1 4 9
// 1 3 4
// 1

int main(){
	// VarteMaameDurrr;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	// ll t; cin >> t;
	// while (t--) {
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	// }
	return 0;
}