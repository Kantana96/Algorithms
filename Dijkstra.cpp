#include <iostream>
#define INF 999
using namespace std;
int dist[100], V, cost[100][100], src;
bool visited[100]={0};
void init(){
    for(int i=0; i<V; i++){
        dist[i]=INF;
    }
    dist[src]=0;
}
int getNearest(){
    int minValue = INF;
    int minNode = 0;
    for(int i=1; i<V; i++){
        if(!visited[i] && dist[i]<minValue){
            minValue=dist[i];
            minNode=i;
        }
    }
    return minNode;
}
void display(){
    cout<<"The resulting table\nIndex\t\tWeight\n";
    for(int i=0; i<V; i++){
        cout<<i<<"\t\t"<<dist[i]<<endl;
    }
}
void dijkstra(){
    for(int i=0; i<V;i++){
        int nearest = getNearest();
        visited[nearest]=true;
        for(int j=0; j<V; j++){
            if(cost[nearest][j]!=INF && dist[j]>dist[nearest]+cost[nearest][j]){
                dist[j]=dist[nearest]+cost[nearest][j];
            }
        }
    }
}
int main(){
    cout<<"Enter number of vertices of graph: ";
    cin>>V;
    cout<<"Enter graph in matrix form:\n";
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            cin>>cost[i][j];
        }
    }
    init();
    dijkstra();
    display();
    return 0;
}