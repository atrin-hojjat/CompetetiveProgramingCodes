#include <iostream>

using namespace std;

typedef vector<int> vi;

void solve(bool* maze,int n,int m,bool*sol,int sx,int sy,int ex,int ey){
    map<int,vector<int>> graph;

    for(int i=0;i<n;i++){
        int prev = 1;
        for(int j=1;j<m-1;j++){
            if(!maze[i*n+j]) continue;
            else if(!maze[i*n+j-1]){
                if(!graph[i*n+j])graph[i*n+j] = vi();
                prev = j;
                if(maze[(i+1)*n+j]){
                    graph[i*n+j].push_back((i+1+*n)+j);
                    graph[(i+1)*n+j] = vi(1,i*n+j);
                }
            } else if(!maze[i*n+j+1]){
                if(!graph[i*n+j])graph[i*n+j] = vi();
                if(maze[i*n+j-1])graph[i*n+j].push_back(prev);
                if(maze[(i+1)*n+j]){
                    graph[i*n+j].push_back((i+1+*n)+j);
                    graph[(i+1)*n+j] = vi(1,i*n+j);
                }
            } else if(graph[i*n+j]){
                graph[i*n+j].push_back(i*n + prev);
                graph[i*n+prev].push_back(i*n+j);
                prev = i;
                if(maze[(i+1)*n+j]){
                    graph[i*n+j].push_back((i+1+*n)+j);
                    graph[(i+1)*n+j] = vi(1,i*n+j);
                }
            } else {
                 if(maze[(i+1)*n+j]){
                    graph[i*n+j] = vi(1,i*n+prev);
                    prev = j;
                    graph[i*n+j].push_back((i+1+*n)+j);
                    graph[(i+1)*n+j] = vi(1,i*n+j);
                } else if((i==sx&&j==sy) || (i==ex&&j==ey)){
                    graph[i*n+j] = vi();
                    if(maze[i*n+j-1])graph[i*n+j].push_back(prev);

                    if(maze[(i+1)*n+j]){
                        graph[i*n+j].push_back((i+1+*n)+j);
                        graph[(i+1)*n+j] = vi(1,i*n+j);
                    }
                }
            }
        }
    }
    
}

