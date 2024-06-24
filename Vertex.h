//
//  Vertex.h
//  project 4
//
//  Created by Kc Ashiogwu on 12/12/22.
//

#ifndef Vertex_h
#define Vertex_h
class Vertex{
public:
    string name;
    Vertex* node;
    
    Vertex();
    Vertex(string name);
};

Vertex::Vertex(){
    name = "";
    node = NULL;
}
Vertex::Vertex(string name){
    this->name = name;
    this->node = NULL;
}


#endif /* Vertex_h */
