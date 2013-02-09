#include "random.h"
#include <cstdlib>
#include <algorithm>

Random::Random()
{
    //ctor
}

Random::~Random()
{
    //dtor
}
int Random::Rand(int min, int max)
{
    if(min==max)
        return min;
    return int(Rand(float(min), float(max)));
}

float Random::Rand(float min, float max)
{
    if(min>max)
    {
        std::swap(min,max);
    }
    static bool inited=false;
    if(!inited)
    {
        srand(time(NULL));
        inited=true;
    }
    if(min==max)
        return min;
    float r = (float)rand()/(float)RAND_MAX;
    return r*(max-min)+min;
}
