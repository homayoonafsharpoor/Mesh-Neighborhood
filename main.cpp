#include <iostream>
#include <fstream>
#include <sstream>
#include "obj_loader.h"
#include "adjacency_list.h"

using namespace std;

struct Argument
{
    string input_file;
    string output_file;
    Vector3 vertex;
    int N;
};


ostream & operator <<(ostream & out,const Argument& arguments)
{
    out<<"Arguments:"<<"{"<<endl;
    out<<"\tinput_file : "<<arguments.input_file<<","<<endl;
    out<<"\toutput_file : "<<arguments.output_file<<","<<endl;
    out<<"\tvertex : "<<arguments.vertex<<","<<endl;
    out<<"\tN : "<<arguments.N<<endl;
    out<<"}"<<endl;
    out<<" Nachbar-Eckpunkte gespeichert"<<endl;
    return out;
}


void parse_arguments(Argument& arguments,int argc,char **argv)
{


    arguments.input_file = string(argv[1]);
    for (int i = 2; i < argc;)
    {
        string option(argv[i]);
        if (option == "-v")
        {
            float x, y, z;
            istringstream iss(string(argv[i + 1]) + " " + string(argv[i + 2]) + " " + string(argv[i + 3]) + "\n");
            iss >> x >> y >> z;

            arguments.vertex = Vector3(x,y,z);
            i += 4;
        }
        else if (option == "-N")
        {
            arguments.N = atoi(argv[i+1]);
            i+=2;
        }
        else if (option == "-o")
        {
            arguments.output_file = string(argv[i+1]);
            i+=2;
        }
    }
}


int main(int argc, char **argv)
{

    if (argc < 9)
    {
        cerr << "Usage: program_name input.obj -v vertex -N n -o output.obj" << endl;
        exit(1);
    }

    Argument arguments={"","",{0,0,0},0};

    parse_arguments(arguments,argc,argv);

    cout << arguments;
    ofstream output(arguments.output_file);
    OBJ obj(arguments.input_file);
    adjacency_list *adj_list = create_adjacency_list(obj.__getFaces());
    neighbor_list *neighbors = find_vertex_neighbors(adj_list,arguments.vertex,arguments.N);


    //write to the output file
    //find the faces
    vector <Face *> faces;

    neighbors->insert(arguments.vertex);
    for(auto face:obj.__getFaces())
    {

        auto haveV1 = neighbors->find((const Vector3 &)*face->v1);
        auto haveV2 = neighbors->find((const Vector3 &)*face->v2);
        auto haveV3 = neighbors->find((const Vector3 &)*face->v3);

        if(haveV1 != neighbors->end() &&
           haveV2 != neighbors->end() &&
           haveV3 != neighbors->end())
        {
            faces.push_back(face);
        }
    }

    //write to the output
    OBJ::write(output,faces);

}

