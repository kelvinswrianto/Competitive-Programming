#include<stdio.h>
#include<string>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

char map[102][102];
int drr[] = {+0,+0,-1,+1,+1,+1,-1,-1};
int dcc[] = {-1,+1,+0,+0,-1,+1,+1,-1};
void bfs(int r, int c, int rMax, int cMax){
    if (map[r][c] == '*') {
		return;
	}
    queue<pair<int, int>> Q;
    Q.push(make_pair(r, c));

    while(!Q.empty()){
        pair<int, int> t = Q.front();

        Q.pop();
        for(int i=0; i<8; i++){
            int x = t.first + drr[i];
            int y = t.second + dcc[i];
            if(x < 0 || x > rMax || y < 0 || y > cMax || map[x][y] != '@') continue;
            
            Q.push(make_pair(x, y));
            map[x][y] = 0;
        }
    }
}


int main(){
    int m, n;
    string temp;
    int r[102], c[102], counter;
    int vis[102][102];

    while(cin >> m >> n){
        
        if(m == 0 || n == 0){
            break;
        }
        counter = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cin >> map[i][j];
            }
        }
        counter = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(map[i][j] == '@'){
                    bfs(i, j, m, n);
                    counter++;
                }
            }
        }

        printf("%d\n", counter);
    }



    return 0;
}