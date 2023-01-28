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
queue <ll> que,new_que;
ll shortest = 100;
ll num;
char* game = (char*)malloc(num*sizeof(char));

int bfs(ll count, ll row, ll col,ll endp){
    ll incr[4] = {-col, -1, col, 1};

    while(!(que.empty())){
    ll vertice = que.front();
    if(visited[vertice]){
        que.pop();
        continue;
    }

    if(vertice == endp){
        shortest = min(count,shortest);
        return 0;
    }
    visited[vertice] = true;
    fi(0,4){
        ll newnum = vertice + incr[i];
        if(newnum <= row*col && newnum >= 0 && (vertice/col == newnum/col || i%2==0) && (game[newnum] == '.' || game[newnum] == 'e') && !(visited[newnum])){
            new_que.push(newnum);
        }
        
    }
    que.pop();
    }
    que.swap(new_que);
    if(que.empty()){
        return 0;
    }
    bfs(count+1,row,col,endp);
    
}

void solve(){
    ll r,c;
    ll start,end;
    num = r*c;
    cin >> r >> c;
    fi(0,r*c){
        cin >> game[i];
        if(game[i] == 's'){
            start = i;
        }
        else if(game[i]== 'e'){
           end = i;
        }   
    }
    que.push(start);
    bfs(1,r,c,end);
    cout << shortest-1 << endl;


}

//examples

// 5 7                 
// s . . # . . . 
// . # . . . # .   
// . # . . . . .
// . . # # . . . 
// # . # e . # .

// 3 3
// s . .
// . # .
// . # e
int main()
{   
    solve();
    return 0;
}