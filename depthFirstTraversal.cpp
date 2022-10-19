// Graph - Depth First Traversal
#include<iostream>
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

    bool isConnected(int node1,int node2){
        return A[node1-1][node2 - 1] == 1;
    }
    
    void addEdge(int node1,int node2){
        A[node1-1][node2 - 1] = A[node2-1][node1-1] = 1;
    }

    void depthFirstTraversal(int node){
        stack<int> s;
        bool hasAdjacent = false;
        bool *visited = new bool[nodes+1];
        for(int i=0;i<=nodes;++i)
            visited[i] = false;
        s.push(node);
        visited[node] = true;
        cout<<"Depth first traversal from node "<<node<<" : "<<node<<" ";
        while(!s.empty()){
            int topNode = s.top();
            hasAdjacent = false;
            for(int i=1;i<=nodes;++i){
                if(isConnected(topNode,i) && visited[i] == false){
                    hasAdjacent = true;
                    s.push(i);
                    visited[i]= true;
                    cout<<i<<" ";
                    break;
                }
            }
            if(!hasAdjacent)
                s.pop();

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
    g.depthFirstTraversal(1);
    return 0;
}