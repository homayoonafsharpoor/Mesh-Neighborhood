#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED
#include <iostream>
#include<string>

using namespace std;

struct Vector3
{
    Vector3(float x,float y,float z);
    float x;
    float y;
    float z;
    bool operator ==(const Vector3& v) const;
    bool operator < (const Vector3& v) const;
};

ostream & operator << (ostream &out,const Vector3 &vector);


struct Face
{
    Face(Vector3 * const v1,Vector3 * const v2,Vector3 * const v3);
    Vector3 *v1;
    Vector3 *v2;
    Vector3 *v3;
};


ostream & operator << (ostream &out,const Face &face);


struct VerticesHash
{
    size_t operator()(const Vector3 &vertex) const;
};

struct FaceHash
{
    size_t operator()(const Face &face) const;
};

#endif // TYPES_H_INCLUDED
