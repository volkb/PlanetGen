#ifndef SYSTEM_H
#define SYSTEM_H
#include "star.h"
#include "planet.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstdlib>


class system
{
    public:
        system();

    protected:

    private:
        Star Center_point;
        vector<Planet> planets;
        int num_pos_planets //max number of possible planets

};

#endif // SYSTEM_H
