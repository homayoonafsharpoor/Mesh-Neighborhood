#ifndef ADJACENCY_LIST_H_INCLUDED
#define ADJACENCY_LIST_H_INCLUDED
#include "types.h"
#include <unordered_map>
#include <ostream>
#include <vector>
#include <unordered_set>

typedef unordered_map<Vector3,unordered_set<Vector3,VerticesHash>,VerticesHash> adjacency_list;

typedef unordered_set<Vector3,VerticesHash> neighbor_list;

ostream & operator<< (ostream & out,const neighbor_list & neighbors);

adjacency_list * create_adjacency_list(const vector<Face* > & faces);

neighbor_list * find_vertex_neighbors(const adjacency_list* adj_list,const Vector3& vertex,int N=1);


#endif // ADJACENCY_LIST_H_INCLUDED
