#include "adjacency_list.h"

ostream &operator<<(ostream &out, const neighbor_list &neighbors)
{
    int idx = 1;
    for (auto neighbor : neighbors)
    {
        out << neighbor << '\n';
    }
    return out;
}

adjacency_list *create_adjacency_list(const vector<Face *> &faces)
{

    adjacency_list *adj_list = new adjacency_list();

    for (const Face *face : faces)
    {
        // for v1
        adj_list->operator[](*face->v1).insert(*face->v2);
        adj_list->operator[](*face->v1).insert(*face->v3);
        // for v2
        adj_list->operator[](*face->v2).insert(*face->v1);
        adj_list->operator[](*face->v2).insert(*face->v3);
        // for v3
        adj_list->operator[](*face->v3).insert(*face->v1);
        adj_list->operator[](*face->v3).insert(*face->v2);
    }

    return adj_list;
}

struct Node
{
    Vector3 vertex;
    size_t d;
};

neighbor_list *find_vertex_neighbors(const adjacency_list *adj_list, const Vector3 &vertex, int N)
{

    neighbor_list *neighbors = new neighbor_list();
    neighbor_list visited;
    vector<Node> queue;
    queue.push_back({vertex, 0});
    visited.insert(vertex);

    while (queue.size())
    {
        Vector3 v = queue.front().vertex;
        size_t d = queue.front().d;
        queue.erase(queue.begin());
        if (d >= N){
            break;
        }
        for (auto neighbor : adj_list->at(v))
        {
            if (neighbor == vertex)
                continue;
            neighbors->insert(neighbor); // if exist not insert new one
            if (visited.find(neighbor) == visited.end())
            {
                visited.insert(neighbor);
                queue.push_back({neighbor, (d + 1)});
            }
        }
    }

    return neighbors;

}
