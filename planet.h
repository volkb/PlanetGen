#ifndef PLANET_H
#define PLANET_H
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <ctime>
#include <iostream>
#include <cassert>
#include <cstdlib>

using namespace std;


class Planet
{
    public:
        Planet();//default cstr
        Planet(string& p_name, vector<string>& p_traits, vector<string>& p_resources, vector<string>& p_hazards, vector<string>& p_specials); //cstr
        void allocate_characteristics(vector<string>& p_traits,vector<string>& p_resources, vector<string>& p_hazards, vector<string>& p_specials); //setter function
        int num_characteristics(); //rolls the number of characteristics per planet
        void Build_Planet(vector<string>& p_traits, vector<string>& p_resources, vector<string>& p_hazards, vector<string>& p_specials);
        void eliminate_duplicates();//checks for duplication and re-rolls if necessary
        void set_traits(vector<string>& p_traits){traits = p_traits;}
        void set_hazards(vector<string>& p_hazards){hazards = p_hazards;}
        void set_resources(vector<string>& p_resources){resources = p_resources;}
        void set_special(vector<string>& p_special){special = p_special;}
        void set_name (string& p_name) {name = p_name;}
        int char_position(int length);
        void grade_planet(); //assigns the planet a grade based upon ratios of traits:hazards:resources
        void output_to_file(); // outputs the planet to txt document
        void output_to_screen();

    private:
        string name;
        vector<string> traits;
        vector<string> hazards;
        vector<string> resources;
        vector<string> special;
        char col_grade;
        char res_grade;
};

#endif // PLANET_H
