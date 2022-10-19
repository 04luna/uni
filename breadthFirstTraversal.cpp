// Graph - Breadth First Traversal
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Graph{
	int nodes; //No of nodes in the graph
	int **A; //A is the adjacency matrix => the graph datastructure
public:
	Graph(int nodes){
		this->nodes = nodes;
		A = new int*[nodes];
		for(int i=0;i<nodes;++i){
			A[i] = new int[nodes];
		}
		for(int i=0;i<nodes;++i)
			for(int j=0;j<nodes;++j){
				A[i][j] = 0;
			}
	}

	void printAdjacencyMatrix(){
		for(int i=0;i<nodes;++i){
			for(int j=0;j<nodes;++j){
				cout<<A[i][j]<<" ";
			}
			cout<<endl;
		}
	}

    void addEdge(int node1,int node2){
        A[node1-1][node2 - 1] = A[node2-1][node1-1] = 1;
    }

    bool isConnected(int node1,int node2){
        return A[node1-1][node2 - 1] == 1;
    }

    bool allNodesVisited(bool* array){
        for(int i=1;i<=nodes;++i)
            if(array[i] == false)
                return false;
        return true;
    }

    void depthFirstTraversal(int node){
        queue<int> q;
        bool *visited = new bool[nodes+1];
        for(int i=0;i<=nodes;++i)
            visited[i] = false;
        int workingOn = node;
        visited[node] = true;
        q.push(node);
        cout<<"Depth first traversal from node "<<node<<" : "<<node<<" ";
        while(!q.empty() || !allNodesVisited(visited)){
            //cout<<"working with: "<<workingOn<<endl;
            for(int i=1;i<=nodes;++i){
                if(isConnected(workingOn,i) && visited[i] == false){
                    //cout<<i<<" is connected to "<<workingOn<<endl;
                    q.push(i);
                    visited[i]= true;
                    cout<<i<<" ";
                }
            }
            workingOn = q.front();
            q.pop();
        }
        cout<<endl;
        delete [] visited;
    }

    ~Graph(){
        for (int i = 0; i < nodes; ++i)
        delete [] A[i];
        delete [] A;
    }
};

int main(){
	Graph g(8);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(1,7);
    g.addEdge(2,5);
    g.addEdge(2,6);
    g.addEdge(3,6);
    g.addEdge(3,8);
    g.addEdge(4,6);
    g.addEdge(5,7);
    //g.printAdjacencyMatrix();
    g.depthFirstTraversal(1);
    return 0;
}