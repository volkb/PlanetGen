#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "planet.h"

using namespace std;

int main()
{
    int choice;
    string temp = "";
    int counter = 0;
    vector<string> traits;
    vector<string> hazards;
    vector<string> resources;
    vector<string> special;
    cout<<"Welcome to the Planet Generator!"<<endl;
    cout<<"Choose an Option"<<endl;
    cout<<"     1. Random Planet"<<endl;
    cout<<"     2. Series of Random Planets in a system"<<endl;
    cout<<"     3. Create a Specific Planet"<<endl;
    //cin>>choice; TO UPGRADE LATER
    choice = 1;

//======================================================================
//Readin Characteristics from Files
//======================================================================
    //for traits
    ifstream in_str("traits.txt");
      if (!in_str.good()) {
        cerr << "Can't open " << "traits.txt" << " to read.\n";
        assert(in_str.good());
      }
      while (!in_str.eof()) {
        in_str >> temp;
        if(in_str.eof()){
            break;
        }
        traits.push_back(temp);
        counter++;
      }
      counter = 0;
      temp = "";
      in_str.close();
      in_str.clear();

      //for hazards
      in_str.open("hazards.txt");
      if (!in_str.good()) {
        cerr << "Can't open " << "hazards.txt" << " to read.\n";
        assert(in_str.good());
      }
      while (!in_str.eof()) {
        in_str >> temp;
        if(in_str.eof()){
            break;
        }
        hazards.push_back(temp);
        counter++;
      }

      counter = 0;
      temp = "";
      in_str.close();
      in_str.clear();

      //for resources
      in_str.open("resources.txt");
      if (!in_str.good()) {
        cerr << "Can't open " << "resources.txt" << " to read.\n";
        assert(in_str.good());
      }
      while (!in_str.eof()) {
        in_str >> temp;
        if(in_str.eof()){
            break;
        }
        resources.push_back(temp);
        counter++;
      }

      counter = 0;
      temp = "";
      in_str.close();
      in_str.clear();

      //for specials
      in_str.open("special.txt");
      if (!in_str.good()) {
        cerr << "Can't open " << "specials.txt" << " to read.\n";
        assert(in_str.good());
      }
      while (!in_str.eof()) {
        in_str >> temp;
        if(in_str.eof()){
            break;
        }
        special.push_back(temp);
        counter++;
      }
      in_str.close();
      in_str.clear();

//======================================================================
//======================================================================
    if (choice == 1){//will generate planet class at random
        Planet new_planet;
        new_planet.Build_Planet(traits,resources,hazards,special);
        new_planet.output_to_screen();

    }
    if (choice == 2) {//using choice 1 logic, generate multiple planets in a system

    }
    if (choice == 3){//will ask for input and using a basic cstr, builds a planet to output.
        int num_resources;
        int num_traits;
        int num_hazards;
        int num_specials;

        vector<string> p_resources;
        vector<string> p_traits;
        vector<string> p_hazards;
        vector<string> p_specials;
        string name;

        cout<<"How many Resources will the Planet have?"<<endl;
        cin>>num_resources;
        cout<<"How many Traits will the planet have?"<<endl;
        cin>>num_traits;
        cout<<"How many Hazards will the Planet have?"<<endl;
        cin>>num_hazards;
        cout<<"how many Specials will the Planet have?"<<endl;
        cin>>num_specials;

        for(int i=0; i<num_resources; ++i){
            cout<<"Enter Resource #"<<i+1<<endl;
            cin>>temp;
            p_resources.push_back(temp);
        }

        for(int i=0; i<num_traits; ++i){
            cout<<"Enter Trait #"<<i+1<<endl;
            cin>>temp;
            p_traits.push_back(temp);
        }

        for(int i=0; i<num_hazards; ++i){
            cout<<"Enter Hazard #"<<i+1<<endl;
            cin>>temp;
            p_hazards.push_back(temp);
        }

        for(int i=0; i<num_specials; ++i){
            cout<<"Enter Special #"<<i+1<<endl;
            cin>>temp;
            p_specials.push_back(temp);
        }

        cout<<"Enter a Name for this Planet"<<endl;
        cin>>name;

        Planet new_planet(name,p_traits,p_resources,p_hazards,p_specials);
        cout<<endl;
        new_planet.output_to_screen();
        ///implement editing tools once planet has been created

    }
    return 0;
}
