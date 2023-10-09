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
    void display();
    void move_doodlebugs(); 
    void move_ants();
    void breed_doodlebugs(); 
    void breed_ants();
    void starve();  
    int next_time_step(); //increment time step by 1
    void set_time_step();
};


class Organism {
    int location;
    char type;
public:
    void set_type(char curr_type);
    char get_type();
    virtual void move(); 
    virtual void breed();
    int get_location();
    void set_location();

    Organism(){};
};

class Ant: public Organism {
    int ant_location;
    char type = 'o';
public:
    void move();   //find adjacent empty spots and randomly move every time step, if out of bounds or all adjacent full, stay still
    void breed(); //find adjacent empty spots and breed every 3 time steps. 
    int get_ant_location();
    void set_ant_location();

    Ant(){};
};

class Doodlebug: public Organism { //derived classes can overwrite virtual function of organism class
    int doodlebug_location;
    char type = 'x';
    int starve_count = 0;
public:
    void move();   //find adjacent empty spots and randomly move every time step
    void breed(); //find adjacent empty spots and breed every 8 time steps
    void starve(); //3 time steps and doodle starves and dies
    int get_starve_count(); 
    int get_doodlebug_location();
    void set_doodlebug_location();

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

void World::display() {
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            cout<<"-"<<" ";
        }
        cout<<endl;
    }
}