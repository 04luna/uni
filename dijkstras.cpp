// Dijkstra's algorithm - Shortest Path Algorithm
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

    void addEdge(int node1,int node2, int weight){
        A[node1-1][node2-1] = weight;
    }

    bool isAdjacent(int node1,int node2){
        return A[node1-1][node2 - 1] != 0;
    }

    bool allNodesVisited(bool* array){
        for(int i=1;i<=nodes;++i)
            if(array[i] == false)
                return false;
        return true;
    }

    //is node1 reachable from node 2, ie. is there a edge from node2 to node1
    bool isReachableFrom(int node1,int node2){
        return A[node2-1][node1-1] != 0;
    }

    int getWeight(int node1,int node2){
        return A[node1-1][node2-1];
    }

    int getMinimumUnvisitedNode(bool* visited, int* costArray){
    	int minIndex = 1;
    	for(int i=1;i<=nodes;++i){
    		if(visited[i] == false && costArray[i] <= costArray[minIndex]){
	    		minIndex = i;
    		}
    	}
	    return minIndex;
    }

    void getMinimumNode(bool* visited,int& startNode, int* costArray,int& weightSoFar){
        for(int i=1;i<=nodes;++i){
            if(isReachableFrom(i,startNode)){
            	if(getWeight(startNode,i) + weightSoFar < costArray[i] && visited[i] == false)
            	costArray[i] = getWeight(startNode,i) + weightSoFar;
            }
		}
		int minNode = getMinimumUnvisitedNode(visited,costArray);
        //cout<<"Minimum Node: "<<minNode<<endl;
        //cout<<"Minimum Weight: "<<costArray[minNode]<<endl;
        visited[minNode] = true;
        weightSoFar = costArray[minNode];
        startNode = minNode;
        if(weightSoFar != 10000)
        	cout<<"Cost to reach: "<<startNode<<" ("<<weightSoFar<<") "<<endl;
        else
        	cout<<"Cannot reach: "<<startNode<<endl;
    }

    void printArrayContents(int* array){
    	for(int i=1;i<nodes+1;++i){
	        cout<<array[i]<<" | ";
	    }
	    cout<<endl;
    }

    void getShortestPath(int startNode){
        bool* visited = new bool[nodes+1];
	    for(int i=0;i<nodes+1;++i){
	        visited[i] = false;
	    }

	    int* costArray = new int[nodes+1];
	    for(int i=0;i<nodes+1;++i){
	        costArray[i] = 10000;
	    }
	    int weightSoFar = 0;

	    cout<<"Starting from node: "<<startNode<<endl;
	    visited[startNode] = true;
        for(int i=1;i<=nodes-1;++i){
        	getMinimumNode(visited,startNode,costArray,weightSoFar);
        	// printArrayContents(costArray);
        	// cout<<"Start Node: "<<startNode<<endl;
        }
        cout<<endl;
        
    }

    ~Graph(){
        for (int i = 0; i < nodes; ++i)
        delete [] A[i];
        delete [] A;
    }
};

int main(){
	Graph g(8);
    g.addEdge(1,2,20);
    g.addEdge(1,7,90);
    g.addEdge(7,1,20);
    g.addEdge(1,4,80);
    g.addEdge(2,6,10);
    g.addEdge(5,2,50);
    g.addEdge(3,4,10);
    g.addEdge(4,3,10);
    g.addEdge(3,8,20);
    g.addEdge(3,6,50);
    g.addEdge(6,3,10);
    g.addEdge(6,4,40);
    g.addEdge(4,7,20);
    g.addEdge(5,7,30);
    //g.printAdjacencyMatrix();
    
    g.getShortestPath(1);
    return 0;
}