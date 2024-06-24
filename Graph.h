//
//  Graphs.h
//  project 4
//
//  Created by Kc Ashiogwu on 12/11/22.
//
#include <iostream>
#include<list>
#include<queue>
#include<cstring>
#include<fstream>
#include "Edge.h"
#include "Vertex.h"
#include "PriorityQueue.h"



using namespace std;

class Graph{
public:
    int v; //the number of vertices
    
    Vertex * vHead;
    Edge * eHead;
    
    int** matrix;
    
    string origin;
    
    string destination;
    
    
    
    
public:
    Graph(int v); //constructor
    
    
    Graph();
    
    ~Graph();
    
    
    int getVertexIndex(string);
    
    string getVertexName(int);
    
    
    
    void readFile(string);
    
    void AddEdge( int u , int v, int w); // add egdes to a graph
    
    
    int AddVertex(string);
    
    //TODO: optional, print matrix
    
    //TODO remove parameters
    void ShortestPath(); // calculate the shortest path
    
    
};
Graph::Graph(){ //default constructor
    vHead = NULL;
    eHead = NULL;
    origin = "";
    destination = "";
    v = 0;
    
}

Graph::Graph(int Vertex){ //constrctor
    vHead = NULL;
    eHead = NULL;
    origin = "";
    destination = "";
    v = Vertex;
}

Graph::~Graph(){ //destructor
    //TODO: implement
}

int Graph::getVertexIndex(string name){
    int index = 0;
    Vertex * temp;
    temp = vHead;
    while(temp != NULL){
        if(temp->name == name){
            return index;
        }
        else{
            temp = temp->node;
            index++;
        }
    }
    return -1;
}

string Graph::getVertexName(int index){
    //TODO: implement
    Vertex * temp;
    temp = vHead;
    for(int i =0; i< index; i++ ){
        temp = temp->node;
    }
    return temp->name;
}

void Graph::AddEdge(int u, int v, int w){
    if(eHead == NULL){
        eHead = new Edge(u, v, w);
    }
    else{
        Edge * temp;
        temp = eHead;
        while(temp->node !=NULL){
            temp = temp->node;
        }
        temp->node = new Edge(u, v, w);
    }
    
}

void Graph::ShortestPath(){
    //create a distance array representing the distance from the start node to every other
    
    int distance[v];
    
    //create a "previous" array that is updated to hold path for shortest
    int previous[v]; //idk
    
    //initialize all values in distance to be infinity, previous to -1
    for(int i = 0; i < v; i++){
        distance[i] = 99999;
        previous[i] = -1;
    }
    
    
    //set the distance of the start index to 0
    
    int startIndex;
    int endIndex;
    
    startIndex = getVertexIndex(origin);
    endIndex = getVertexIndex(destination);
    
    distance[startIndex] = 0;
    
    //create the priority queue
    
    PriorityQueue PQ;
    
    //queue<int> PQ;
    
    
    //enqueue the index of the starting vertex on the PQ with priority zero
    
    PQ.addData(startIndex, 0);
    
    //while PQ is not empty
    while(!PQ.IsListEmpty()){
        //dequeue the next vertex index from the PQ (u)
        int u = PQ.Remove();
        
        //using the adjacency matrix, determine which nodes are adjacent to u
        
        for(int i = 0; i< v ; i++){
            //check if index in matrix is != 0
            if(matrix[u][i] != 0){
                //new distance  = value in matrix + distance array at u
                int newDistance = matrix[u][i] + distance[u];
                //if new distance is less than distance stored at array
                if(newDistance < distance[i]){
                    //distance at v on array is now the new distance
                    distance[i] = newDistance;
                    //update the previous matrix at v to u
                    previous[i] = u;
                    //enqueue v with priority distance v to pq
                    PQ.addData(i, distance[i]);
                }
                
            }
        }
       
    }
    
    //after this while loop completes, we've found the shortest path to the destination
    
    //first figure out the path
        //follow the previous array at u, adding the value to the path in reverse
    
    string path = "";
    int u = endIndex;
    while(u != -1){
        path = getVertexName(u) + " " + path;
        u = previous[u];
        
    }
    
    cout << "Path: " << path << endl;
    
    cout << "Cost: " << distance[endIndex] << endl;
    
    //then output the distance
        //distance array at destination index
    
    
    
    
    
    
    
    
    
    
}
int Graph::AddVertex(string name){
    int index = 0;
    
    if(vHead == NULL){
        vHead = new Vertex(name);
        v++;
    }
    else{
        index++;
        Vertex * temp;
        temp = vHead;
        while(temp->node!=NULL){
            if(temp->name == name){
                return --index;
            }
            else{
                index++;
                temp = temp->node;
            }
        }
        if(temp->name == name){
            return --index;
        }
        temp->node = new Vertex(name);
        v++;
    }
    return index;
    
}

void Graph::readFile(string pathName){
    //open file to pathname
    fstream file(pathName);
    //check to make sure the file opened
    if(!file){
        cout << "error ";
    }
    else{
        cout << "file opened";
        //read in the origin (string) and destination (string)
        file>> origin;
        file>> destination;
        
        //read in the $ separator
        
        char toLoad;
        file.clear();
        file >> toLoad;
        
        //while loop to read each line of the file (edge)
        string start, end;
        int weight;
        while(file){
            //read in start
            //read in end
            //read in weight
            file>> start;
            file>> end;
            file >> weight;
            int startIndex;
            int endIndex;
            //addVertex twice for start and end
            startIndex = AddVertex(start);
            endIndex = AddVertex(end);
            //addEdge using indices and weight
            AddEdge(startIndex, endIndex, weight);
        }
        
        //generate the adjacency matrix
        //create matrix
        
        matrix = new int*[v]; //creating matrix
        //loop through x axis and create more arrays
        for (int i = 0; i < v; i++){
            matrix[i] = new int[v]; //idk
        }
        
        
        //run through every index in the matrix and set to zero
        for(int i = 0; i <v; i++){
            for (int k = 0; k < v; k++){
                matrix[i][k] =0;
            }
        }
        
        //populate the matrix with the correct edge weights
        //run through the edge linked lists
        Edge * temp = eHead;
        while(temp != NULL){
            //matrix at edge origin, edge destination = edge weight
            //increment pointer
            matrix[temp->origin][temp->destination] = temp->weight;
            temp = temp->node;
        }
        
        
        
    }
    
}
