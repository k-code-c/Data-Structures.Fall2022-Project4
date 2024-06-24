//
//  main.cpp
//  project 4
//
//  Created by Kc Ashiogwu on 12/11/22.
//

#include <iostream>
#include "Graph.h"
#include <chrono>

int main(int argc, const char * argv[]) {
    Graph graph;
    graph.readFile("/Users/kcashiogwu/Downloads/p4_test1.txt");
    chrono::steady_clock::time_point t3 = chrono::steady_clock::now();
    graph.ShortestPath();
    chrono::steady_clock::time_point t4 = chrono::steady_clock::now();
    
    unsigned long Graph_insertTime = chrono::duration_cast<chrono::nanoseconds>(t4-t3).count();
    
    cout<< "Traversal time: " << Graph_insertTime << endl;
    
    return 0;
}
