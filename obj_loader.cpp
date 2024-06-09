#include "obj_loader.h"
#include <sstream>
#include <string>
#include <iostream>
#include <unordered_map>
#include <set>

OBJ::OBJ(const string& path)
{
    file.open(path);
    readObjFile();
}

const vector<Vector3*> & OBJ::__getVertices()
{
    return vertxes;
}
const vector<Face*>& OBJ::__getFaces()
{
    return faces;
}


void OBJ::readObjFile()
{

    //temp
    unordered_map <Vector3,string,VerticesHash> vr_table;
    unordered_map <string,int> tr_table;

    string line;
    size_t vertex_counter=1;
    size_t vertex_indx =0;
    while(getline(file,line))
    {
        istringstream iss(line);
        float a,b,c;
        string vertex_name;

        if(line[0] == 'v')
        {
            // vertex_name = "v"+to_string(vertex_counter++);
            iss >> vertex_name >> a >> b >> c;
            vertex_name+=to_string(vertex_counter++);

            Vector3 *vertex = new Vector3(a,b,c);

          /* if(vr_table.find(*vertex) == vr_table.end())*/ // aufgrund des Hinweises von Herrn Kern während der Präsentation kommentiert bzw. entfernt
            {
                vr_table[*vertex] = vertex_name;
                vertxes.push_back(vertex);
                tr_table[vertex_name] = vertex_indx++;
            }

         /*   else     // aufgrund des Hinweises von Herrn Kern während der Präsentation kommentiert bzw. entfernt
            {
                // get the vertex name of the vertex
                string v_name = vr_table.at(*vertex);
                int idx = tr_table.at(v_name);
                tr_table[vertex_name] = idx;
                delete vertex; // relse memory
            }*/
        }
        else if(line[0] == 'f')
        {
            string v1,v2,v3;
            iss >> v1 >> v1 >> v2 >> v3;
            // create the face

            int v1Idx = tr_table.at("v"+v1);
            int v2Idx = tr_table.at("v"+v2);
            int v3Idx = tr_table.at("v"+v3);

            Face *face= new Face(
                vertxes[v1Idx],
                vertxes[v2Idx],
                vertxes[v3Idx]
            );
            faces.push_back(face);
        }
    }
}


void OBJ::write( ostream& out ,const vector<Face *>& faces)
{

    //simple way to write the obj file
    int32_t indx = 0;
    for(auto face:faces)
    {
        out << *face->v1 << endl;
        out << *face->v2 << endl;
        out << *face->v3 << endl;
        out << 'f' <<" " <<++indx <<" "<<++indx <<" " <<++indx<<endl;
    }
}

