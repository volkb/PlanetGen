#include "planet.h"

Planet::Planet()
{
    name = "";
    traits = {""};
    resources = {""};
    hazards = {""};
    special = {""};
    col_grade = 'F';
    res_grade = 'F';
}

Planet::Planet(string& p_name, vector<string>& p_traits, vector<string>& p_resources, vector<string>& p_hazards, vector<string>& p_specials)
{
    name = p_name;
    traits = p_traits;
    resources = p_resources;
    hazards = p_hazards;
    special = p_specials;
    grade_planet();
}

void Planet::Build_Planet(vector<string>& p_traits, vector<string>& p_resources, vector<string>& p_hazards, vector<string>& p_specials)
{
    srand (time(0));
    int num_traits = num_characteristics();
    int num_resources = num_characteristics();
    int num_hazards = num_characteristics();
    int num_specials = (num_characteristics() - 3);
    if (num_specials < 0) {num_specials = 0;}
    vector<string> planet_traits;
    vector<string> planet_resources;
    vector<string> planet_hazards;
    vector<string> planet_special;

    for(int i=0; i<num_traits; ++i){
        int pos = char_position(p_traits.size());
        planet_traits.push_back(p_traits[pos]);
    }

    for(int i=0; i<num_resources; ++i){
        int pos = char_position(p_resources.size());
        planet_resources.push_back(p_resources[pos]);
    }

    for(int i=0; i<num_hazards; ++i){
        int pos = char_position(p_hazards.size());
        planet_hazards.push_back(p_hazards[pos]);
    }

    for(int i=0; i<num_specials; ++i){
        int pos = char_position(p_specials.size());
        planet_special.push_back(p_specials[pos]);
    }
    string p_name = "";
    allocate_characteristics(planet_traits,planet_resources,planet_hazards,planet_special);
}

int Planet::char_position(int length){//helper function for characteristic rolling
        int rolls;
        int roll = 0;
        roll = rand() % length - 0;
        return roll;
}

void Planet::allocate_characteristics(vector<string>& p_traits,vector<string>& p_resources, vector<string>& p_hazards, vector<string>& p_specials)
{
    traits = p_traits;
    resources = p_resources;
    hazards = p_hazards;
    special = p_specials;
    grade_planet();
}

void Planet::output_to_screen(){
    cout<<"Stellar Chart Recorded for Planet: "<<name<<endl;
    cout<<"     Traits: "<<endl;
    if(traits.size() == 0){//outputs traits to screen
        cout<<"       None";
    }else{
        for(int i=0; i<traits.size(); ++i){
            cout<<"       "<<traits[i];
        }
    }
    cout<<endl;
    cout<<endl;

    cout<<"     Resources: "<<endl;
    if(resources.size() == 0){
        cout<<"       None";
    }else{
        for(int i=0; i<resources.size(); ++i){
            cout<<"       "<<resources[i];
        }
    }
    cout<<endl;
    cout<<endl;

    cout<<"     Hazards: "<<endl;
    if(hazards.size() == 0){
        cout<<"       None";
    }else{
        for(int i=0; i<hazards.size(); ++i){
            cout<<"       "<<hazards[i];
        }
    }
    cout<<endl;
    cout<<endl;

    cout<<"     Orbit Scanner: "<<endl;
    if(special.size() == 0){
        cout<<"       None";
    }else{
        for(int i=0; i<special.size(); ++i){
            cout<<"       "<<special[i];
        }
    }
    cout<<endl;
    cout<<endl;
    cout<< "     Colonization Score: "<<col_grade<<endl;
    cout<< "     Mining Score: "<<res_grade<<endl;
}

int Planet::num_characteristics()
{
    ///FIND A BETTER DICE ALGORITHM
       int rolls;
        int roll = 0;
        roll = rand() % 100 - 0;
        //this_thread::sleep_for (chrono::milliseconds(250));
        //srand (time(NULL));
        roll += rand() % 100 - 0;
        //this_thread::sleep_for (chrono::milliseconds(250));
        //srand (time(NULL));
        roll += rand() % 100 - 0;
        roll /= 3;
        if (roll <= 25){
            rolls = 0;
        }else if (roll <= 50 && roll > 25){
            int temp_roll = 0;
            temp_roll = rand() % 100 - 0;
            if (roll > 50){
                rolls = 2;
            } else {
                rolls = 1;
            }
        } else if ( roll <= 75 && roll > 50){
            int temp_roll = 0;
            temp_roll = rand() % 100 - 0;
            if (roll > 50){
                rolls = 3;
            } else {
                rolls = 2;
            }
        } else if (roll <= 100 && roll > 75 ){
            int temp_roll = 0;
            temp_roll = rand() % 100 - 0;
            if (roll > 50){
                rolls = 4;
            } else {
                rolls = 3;
            }
    }
    return rolls;
}

void Planet::grade_planet()
{
    //COL GRADES
    //A = traits are twice as present as hazards
    //B = There is exactly one more traits than hazards
    //C = average planet
    //F = The planet has no Traits or Hazards
    //H = The planet has twice as many hazards than traits

    //RES GRADES
    //A = Resources are twice as present as hazards
    //B = There is exactly one more Resources than hazards
    //C = average Planet
    //F = The planet has no Resources
    //H = The planet has twice as many Hazards than Resources
    //R = The planet has 3 or more resources and no Hazards

    //COL GRAGE
    if(traits.size() == hazards.size()*2){
        col_grade = 'A';
    }else if (traits.size()-1 == hazards.size()){
        col_grade = 'B';
    }else if(traits.size() == 0 && hazards.size() == 0){
        col_grade = 'F';
    } else if(hazards.size() == traits.size()*2){
        col_grade = 'H';
    }else{
        col_grade = 'C';
    }

    //RES GRADE
    if(resources.size() == hazards.size()*2){
        res_grade = 'A';
    }else if (resources.size()-1 == hazards.size()){
        res_grade = 'B';
    }else if(resources.size() == 0 && hazards.size() == 0){
        res_grade = 'F';
    } else if(hazards.size() == resources.size()*2){
        res_grade = 'H';
    }else if(resources.size() > 3 && hazards.size() == 0){
        res_grade = 'R';
    }else{
        res_grade = 'C';
    }
}



