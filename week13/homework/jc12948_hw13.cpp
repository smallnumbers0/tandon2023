#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class World;
class Organism;
class Doodlebug;
class Ant;

class World {
    friend class Ant;
    friend class Organism;
    friend class Doodlebug;
    int time_step;

public:
    vector<Organism> world;
    vector<Ant> ants;
    vector<Doodlebug> doodlebugs;

    void display() const;
    void move_doodlebugs(); 
    void move_ants();
    void breed_doodlebugs(); 
    void breed_ants();
    void starve();  
    int get_time_step() const; //increment time step by 1
    void set_time_step();

    World();
};


class Organism {
    int location;
    char type = '-';
public:
    void set_type(char new_type);
    char get_type() const;
    void move(); 
    void breed();
    int get_location() const;
    void set_location(int new_location);

    Organism(){type = '-';};
};

class Ant: public Organism {
    int ant_location;
    char type = 'o';
public:
    void move(vector<Organism> &world);   //find adjacent empty spots and randomly move every time step, if out of bounds or all adjacent full, stay still
    void breed(vector<Organism> &world, vector<Ant> &ants, int &time_step); //find adjacent empty spots and breed every 3 time steps. 
    int get_ant_location() const;
    void set_ant_location(int new_location);

    Ant(){};
};

class Doodlebug: public Organism { //derived classes can overwrite virtual function of organism class
    int doodlebug_location;
    char type = 'x';
    int starve_count = 0;
public:
    void move(vector<Organism> &world, vector<Ant> &ants);   //find adjacent empty spots and randomly move every time step, if there are ants, it will eat the ant instead
    void breed(vector<Organism> &world, vector<Doodlebug> &doodlebugs, int time_step); //find adjacent empty spots and breed every 8 time steps
    void starve(vector<Organism> &world, vector<Doodlebug> &doodlebugs); //3 time steps and doodle starves and dies
    int get_starve_count(); 
    int get_doodlebug_location() const;
    void set_doodlebug_location(int new_location);

    Doodlebug(){};
};


int main() {
    int time_count = 1;
    string input;
    World world;
    cout<<"Please press enter to continue with the time simulation or any enter any else to stop: "<<endl;
    getline(cin, input);
    while(true) {
        cout<<"Time: "<<time_count<<endl;
        getline(cin, input);
        if(input == "") {
            world.display();
            time_count++;
        }
        else {
            break;
        }

    }
    return 0;
}
/******************************************************/
/*****************  World Simulation  *****************/
/******************************************************/

World::World() {
    int location = 0;
    for(int i = 1; i <= 400; i++) {
        world.push_back(Organism());
        world[location].set_location(location);
        location++;
    }
}

void World::display() const {
    int location = 0;
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            if(world[location].get_type() == '-') {
                cout<<'-';
            }
            else if(world[location].get_type() == 'o') {
                cout<<'o';
            }
            else if(world[location].get_type() == 'x') {
                cout<<'x';
            }
            location++;
        }
        cout<<endl;
    }
}

/******************************************************/
/*****************  General Organism  *****************/
/******************************************************/

void Organism::set_type(char new_type) {
    type = new_type; 
}

char Organism::get_type() const{
    return type;
}

int Organism::get_location() const {
    return location;
}

void Organism::set_location(int new_location) {
    location = new_location;
}

/******************************************************/
/***********************  Ant  ************************/
/******************************************************/

int Ant::get_ant_location() const {
    return ant_location;
}

void Ant::set_ant_location(int new_location) {
    ant_location = new_location;
}

// void Ant::move(vector<Organism> &world) { // -1 for left/ +1 for right/ -20 for up/ + 20 for down

// }

// void Ant::breed(vector<Organism> &world, vector<Ant> &ants, int &time_step) {
    
// }

/******************************************************/

/******************************************************/
/*******************  Doodle Bug  *********************/
/******************************************************/

int Doodlebug::get_doodlebug_location() const {
    return doodlebug_location;
}

void Doodlebug::set_doodlebug_location(int new_location) {
    doodlebug_location = new_location;
}

int Doodlebug::get_starve_count() {
    return starve_count;
}

// void Doodlebug::starve(vector<Organism> &world, vector<Doodlebug> &doodlebugs) {

// }

// void Doodlebug::move(vector<Organism> &world, vector<Ant> &ants) {

// }

// void Doodlebug::breed(vector<Organism> &world, vector<Doodlebug> &Doodlebug, int time_step) {

// }

/******************************************************/

