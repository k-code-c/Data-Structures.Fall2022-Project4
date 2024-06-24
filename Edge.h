//
//  Edge.h
//  project 4
//
//  Created by Kc Ashiogwu on 12/12/22.
//

#ifndef Edge_h
#define Edge_h
using namespace std;
class Edge{
public:
    int origin; //start
    int destination; //end
    int weight; //size
    
    Edge* node;
    
    Edge();
    Edge(int origin, int destination, int weight);
};

Edge::Edge(){
    origin = 0;
    destination = 0;
    weight = 0;
    node = NULL;
    
}

Edge::Edge(int origin, int destination, int weight){
    this->origin = origin;
    this->destination = destination;
    this->weight = weight;
    this->node = NULL;
}



#endif /* Edge_h */
