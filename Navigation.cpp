#include "Navigation.h"

using namespace std;

Navigation::Navigation(){}

Navigation::~Navigation(){}

bool Navigation::readNetwork(string _mapname){
    ifstream inFile(_mapname);
    inFile >> numNodes;

    if(!inFile){
        return false;
    } else{
        for(int i = 0; i < numNodes; i++){
            vector<int> icky;
            for(int j = 0; j < numNodes; j++){
                int vicky = 0;
                inFile >> vicky;
                icky.push_back(vicky);
            }
            costs.push_back(icky);
        } 
    } return true;
}

queue<int> Navigation::computeShortestPath(int _startInd, int _endInd){
    priority_queue<Node, vector<Node>, Node> queuePrivy;
    Node n;
    n.cost = 0;
    n.path.push(_startInd);
    queuePrivy.push(n);

    while(queuePrivy.top().path.back() != _endInd){
        Node gramps = queuePrivy.top();
        int worldsEnd = gramps.path.back();
        queuePrivy.pop();

        for(int neigh = 0; neigh < numNodes; neigh++){
            Node daBabyNode;
            if(costs[worldsEnd][neigh] > 0 && (neigh != gramps.path.back())){
                daBabyNode.cost = gramps.cost + costs[worldsEnd][neigh];
                daBabyNode.path = gramps.path;
                daBabyNode.path.push(neigh);
                queuePrivy.push(daBabyNode);
            }
        }
    }
    grandFinale = queuePrivy.top().path;
    
    return grandFinale;
}

void Navigation::printPath(queue<int> _path){
    cout<<"\nPRINTING THE PATH, START ";

    queue<int> printy = grandFinale;

    cout<<printy.front();
    printy.pop();
    while(!printy.empty()){
        cout<<"->"<<printy.front();
        printy.pop();

    }
    cout<<" END\n\n";

}