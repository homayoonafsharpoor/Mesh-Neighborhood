#ifndef OBJ_LOADER_H_INCLUDED
#define OBJ_LOADER_H_INCLUDED
#include <fstream>
#include <vector>
#include "types.h"

using namespace std;
class OBJ
{
public:
        OBJ(const string& path);


        const vector<Vector3*> & __getVertices();
        const vector<Face*>& __getFaces();

        static void write(ostream& out,const vector<Face *>& faces);


private:
        void readObjFile();

        ifstream file;
        vector<Vector3*> vertxes;

        vector<Face*> faces;

};
#endif  // OBJ_LOADER_H_INCLUDED
