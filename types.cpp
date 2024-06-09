#include "types.h"
#include <iomanip>

Vector3::Vector3(float x, float y, float z)
    : x(x), y(y), z(z)
{
}

bool Vector3::operator==(const Vector3& v) const
{
    return (x==v.x) && (y==v.y) && (z==v.z);
}

//only use for set
bool Vector3::operator < (const Vector3& v) const
{
    return (x < v.x) && (y < v.y) && (z < v.z);
}


ostream & operator << (ostream &out,const Vector3 &vector)
{

    out <<std::setprecision(10) <<"v "<<vector.x <<" " << vector.y << " " << vector.z <<" ";
    return out;
}


size_t VerticesHash::operator()(const Vector3 &vertex) const
{
    size_t h1 = hash<float>()(vertex.x);
    size_t h2 = hash<float>()(vertex.y);
    size_t h3 = hash<float>()(vertex.z);
    return h1 ^ (h2 << 1) ^ (h3 << 2);
}

Face::Face(Vector3 * const v1,Vector3 * const v2,Vector3 * const v3)
    : v1(v1), v2(v2), v3(v3)
{
}

ostream & operator << (ostream &out,const Face &face)
{
    out<<"{"<<*face.v1<<","<<*face.v2 <<","<<*face.v3 <<"}";
    return out;
}


size_t FaceHash::operator()(const Face &face) const
{
    size_t h1 = VerticesHash()(*face.v1);
    size_t h2 = VerticesHash()(*face.v2);
    size_t h3 = VerticesHash()(*face.v3);

    return h1 ^ (h2 << 1) ^ (h3 << 2);
}
