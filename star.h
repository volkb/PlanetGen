#ifndef STAR_H
#define STAR_H
#include <vector>
#include <iostream>
#include <cmath>
#include <ctime>
#include <iostream>
#include <cassert>
#include <cstdlib>


class Star
{
    public:
        Star();
        Star(string s_name, long star_size, string s_type, string s_color, int s_age, string s_status, bool hole, vector<string> mods);
        void set_name(string s_name) {s_name = name;}
        long roll_size();
        string roll_type();
        string roll_color();
        string roll_age();
        bool isBlackHole();
        string roll_status();


    private:
        long s_size; //how big is it?
        string name;
        string type; //dwarf, double helix, pulsar, neutron star, etc..
        string color;
        int age; //how old is the star
        string status; //is it stable or dying
        bool black_hole; //is this star a black hole?
        vector<string> modifications; //only to be used if one of the planets have advanced civ or destroyed advanced civ trait
};

#endif // STAR_H
