// Prim's Algorithm - Minimum Spanning Tree
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
        return A[node1-1][node2 - 1] != 0;
    }

    int getWeight(int node1,int node2){
        return A[node1-1][node2 - 1];
    }
    
    void addEdge(int node1,int node2,int weight){
        A[node1-1][node2 - 1] = A[node2-1][node1-1] = weight;
    }

    int findMinimumEdgeFromVisitedVertices(bool* visited){
        int minWeight = 100;
    	int minNode = 100;
        int workingNode = 100;
    	for(int i=1;i<=nodes;++i){
    		if(visited[i] == true){
    			for (int j=1; j<=nodes; ++j){
    				if(visited[j] == false && isConnected(j,i)){
    					if(getWeight(j,i) < minWeight){
    						minWeight = getWeight(j,i); 
                            workingNode = i;
    						minNode = j;
    					}
    				}
    			}
    		}
    	}
        visited[minNode] = true;
        cout<<minNode<<" <--> "<<workingNode<<" ("<<minWeight<<") "<<endl;
    }

    //Without loss of generality, lets start with the first node
    void findMinimumSpanningTree(int node){
        bool *visited = new bool[nodes+1];
        for(int i=0;i<=nodes;++i)
            visited[i] = false;
        visited[node] = true;
        int n = nodes;
        cout<<"Minimum spanning tree:"<<endl;
        while(--n){
            findMinimumEdgeFromVisitedVertices(visited);   
        }

    }

    ~Graph(){
        for (int i = 0; i < nodes; ++i)
        delete [] A[i];
        delete [] A;
    }
};

int main(){
	Graph g(6);
    g.addEdge(1,2,6);
    g.addEdge(1,4,5);
    g.addEdge(1,3,1);
    g.addEdge(2,3,5);
    g.addEdge(3,4,5);
    g.addEdge(2,5,3);
    g.addEdge(4,6,2);
    g.addEdge(3,5,6);
    g.addEdge(3,6,4);
    g.addEdge(5,6,6);
    g.findMinimumSpanningTree(1);
    return 0;
}

