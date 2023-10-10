#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

const char ANTS = 'o';
const char DOODLEBUGS = 'X';
const char EMPTY_SPACE = '-';

class World;
class Organism;
class Doodlebug;
class Ant;

class World {
    friend class Ant;
    friend class Organism;
    friend class Doodlebug;
    int time_step = 1;

public:
    vector<Organism> world;
    vector<Ant> ants;
    vector<Doodlebug> doodlebugs;

    void display() const;
    void initialize_world();
    void initialize_ants();
    void initialize_doodlebugs();
    void move_doodlebugs(); 
    void move_ants();
    void breed_doodlebugs(); 
    void breed_ants();
    void starve();  
    int get_time_step() const; 
    void set_time_step(int new_time_step);

    World();
};


class Organism {
    int location;
    char type = EMPTY_SPACE;
public:
    void set_type(char new_type);
    char get_type() const;
    virtual void move(){}; 
    virtual void breed(){};
    int get_location() const;
    void set_location(int new_location);

    Organism(){type = EMPTY_SPACE;};
};

class Ant: public Organism {
    int ant_location;
    char type = ANTS;
    int age = 0;
public:
    void move(vector<Organism> &world);   //find adjacent empty spots and randomly move every time step, if out of bounds or all adjacent full, stay still
    void breed(vector<Organism> &world, vector<Ant> &ants, int &time_step); //find adjacent empty spots and breed every 3 time steps. 
    int get_ant_location() const;
    void set_ant_location(int new_location);
    int get_age() const;
    void increment_age();

    Ant(){type = ANTS;};
};

class Doodlebug: public Organism { //derived classes can overwrite virtual function of organism class
    int doodlebug_location;
    char type = DOODLEBUGS;
    int starve_count = 0;
    int age = 0;
public:
    void move(vector<Organism> &world, vector<Ant> &ants);   //find adjacent empty spots and randomly move every time step, if there are ants, it will eat the ant instead
    void breed(vector<Organism> &world, vector<Doodlebug> &doodlebugs, int time_step); //find adjacent empty spots and breed every 8 time steps
    void starve(vector<Organism> &world, vector<Doodlebug> &doodlebugs); //3 time steps and doodle starves and dies
    int get_starve_count(); 
    int get_doodlebug_location() const;
    void set_doodlebug_location(int new_location);
    void increment_age();
    int get_age() const;


    Doodlebug(){type = DOODLEBUGS;};
};


int main() {
    srand(time(0));
    string input;
    World world;
    world.initialize_world();
    cout<<"Please press enter to continue with the time simulation or any enter any else to stop: "<<endl;
    while(true) {
        getline(cin, input);
        if(input == "") {
            world.move_ants();
            world.move_doodlebugs();
            world.breed_ants();
            world.breed_doodlebugs();
            world.starve();
            
            world.display();
            cout<<"Time step: "<<world.get_time_step()<<endl;
            world.set_time_step(world.get_time_step() + 1);
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
    for(int i = 0; i <= 400; i++) {
        world.push_back(Organism());
        world[i].set_location(i);
    }
}

void World::initialize_world() {
    srand(time(0));
/**Add 5 Doodlebugs**/
    for (int i = 0; i < 5; i++) {
        int location = rand() % 400 + 1;
        if (world[location].get_type() == EMPTY_SPACE) {
            doodlebugs.push_back(Doodlebug());
            doodlebugs[doodlebugs.size() - 1].set_doodlebug_location(location);
            world[location].set_type(DOODLEBUGS);
        }
    }
/**Add 100 Ants**/
    for (int i = 0; i < 100; i++) {
        int location = rand() % 400 + 1;
        if (world[location].get_type() == EMPTY_SPACE) {
            ants.push_back(Ant());
            ants[ants.size() - 1].set_ant_location(location);
            world[location].set_type(ANTS);
        }
    }
}

void World::display() const {
    int location = 1;
    for(int i = 1; i <= 20; i++) {
        for(int j = 1; j <= 20; j++) {
            if(world[location].get_type() == EMPTY_SPACE) {
                cout<<EMPTY_SPACE<<" ";
            }
            else if(world[location].get_type() == ANTS) {
                cout<<ANTS<<" ";
            }
            else if(world[location].get_type() == DOODLEBUGS) {
                cout<<DOODLEBUGS<<" ";
            }
            location++;
        }
        cout<<endl;
    }
}

void World::move_ants() {
    for(int i = 0; i < ants.size(); i++) {
        ants[i].move(world);
    }
}

void World::breed_ants() {
    for(int i = 0; i < ants.size(); i++) {
        ants[i].breed(world, ants, time_step);
    }
}

void World::move_doodlebugs() {
    for(int i = 0; i < doodlebugs.size(); i++) {
        doodlebugs[i].move(world, ants);
    }
}

void World::breed_doodlebugs() {
    for(int i = 0; i < doodlebugs.size(); i++) {
        doodlebugs[i].breed(world, doodlebugs, time_step);
    }
}

void World::starve() {
    for(int i = 0; i < doodlebugs.size(); i++) {
        doodlebugs[i].starve(world, doodlebugs);
    }
}

void World::set_time_step(int new_time_step) {
    time_step = new_time_step;
}

int World::get_time_step() const {
    return time_step;
}
// void World::initialize_ants() {
//     int location = rand() % 400 + 1;
//     if(world[location].get_type() == EMPTY_SPACE) {
//         ants.push_back(Ant());
//         ants[ants.size()-1].set_ant_location(location);
//         world[location].set_type(ANTS);
//     }
// }

// void World::initialize_doodlebugs() {
//     int location = rand() % 400 + 1;
//     if(world[location].get_type() == EMPTY_SPACE) {
//         doodlebugs.push_back(Doodlebug());
//         doodlebugs[doodlebugs.size()-1].set_doodlebug_location(location);
//         world[location].set_type(DOODLEBUGS);
//     }
// }

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

int Ant::get_age() const {
    return age;
}

void Ant::increment_age() {
    age++;
}



void Ant::move(vector<Organism> &world) { 
    
    int new_location;
    int random_direction;
    vector <int>direction = {-1, 1, -20, 20}; // -1 for left/ +1 for right/ -20 for up/ + 20 for down

    random_direction = direction[rand() % 4];
    new_location = ant_location + random_direction;
    increment_age();

   
        if((world[new_location].get_type() == EMPTY_SPACE) && (new_location >=1 && new_location <= 400)) { //check if new location is out of bounds.
            if((ant_location + 1) % 20 == 0 && random_direction != 1) {
                world[ant_location].set_type(EMPTY_SPACE);
                ant_location = new_location;
                world[ant_location].set_type(ANTS);
            
            }
            else if(ant_location % 20 == 0 && random_direction != -1) {
                world[ant_location].set_type(EMPTY_SPACE);
                ant_location = new_location;
                world[ant_location].set_type(ANTS);
        
            }  
            else if(ant_location % 20 != 0) {
                world[ant_location].set_type(EMPTY_SPACE);
                ant_location = new_location;
                world[ant_location].set_type(ANTS);
                
            }
    }

    //check for empty adjacent spaces around each ant.
    //randomly move to one of the empty spaces.
    //set previous ant location to empty space.
}

void Ant::breed(vector<Organism> &world, vector<Ant> &ants, int &time_step) {
    vector<int> directions = {-1, 1, -20, 20}; // left right down up

    if (time_step % 3 == 0 && get_age() >= 3) { // Check if multiple of 3 time steps old and also get age so new breeded ants added dont breed immediately
        bool breed = false;
        int breed_direction = 0;
        int breed_location = ant_location + directions[breed_direction];

        while (breed == false) {
            if (world[breed_location].get_type() == EMPTY_SPACE && (breed_location >= 1 && breed_location <= 400)) {
                if (directions[breed_direction] != 1 && (ant_location + 1 % 20 == 0)) {
                    world[breed_location].set_type(ANTS);
                    ants.push_back(Ant());
                    ants[ants.size() - 1].set_ant_location(breed_location);
                    breed = true;
                } else if (directions[breed_direction] != -1 && ant_location % 20 == 0) {
                    world[breed_location].set_type(ANTS);
                    ants.push_back(Ant());
                    ants[ants.size() - 1].set_ant_location(breed_location);
                    breed = true;
                } else if (ant_location % 20 != 0) {
                    world[breed_location].set_type(ANTS);
                    ants.push_back(Ant());
                    ants[ants.size() - 1].set_ant_location(breed_location);
                    breed = true;
                }
            } 
            else if (breed == false && breed_direction == 3) {
                breed = true;
            }

            breed_direction++;
        }
    }
}

    //if time step 3
    //check for empty adjacent pos
    //if all adjacent locations are full, breed does not happen
    //else randomly add ant at adjacnet pos
    //add ant to vector and update location

/******************************************************/

/******************************************************/
/*******************  Doodle Bug  *********************/
/******************************************************/

int Doodlebug::get_doodlebug_location() const {
    return doodlebug_location;
}
void Doodlebug::increment_age() {
    age++;
}

int Doodlebug::get_age() const {
    return age;
}

void Doodlebug::set_doodlebug_location(int new_location) {
    doodlebug_location = new_location;
}

int Doodlebug::get_starve_count() {
    return starve_count;
}

void Doodlebug::starve(vector<Organism> &world, vector<Doodlebug> &doodlebugs) {
    //if starve counter is 3, set doodlebug location to empty space
    if(starve_count >= 3) {
        world[doodlebug_location].set_type(EMPTY_SPACE);
        for(int i = 0; i < doodlebugs.size(); i++) {
            if(doodlebug_location == doodlebugs[i].get_doodlebug_location()) {
                doodlebugs.erase(doodlebugs.begin() + i);
            }
        }
    }
}

void Doodlebug::move(vector<Organism> &world, vector<Ant> &ants) {
    //if ants are next to doodlebug, randomly move to ant location and eat it
    //set previous location to empty space
    //if no ants, randomly move to empty space adjacent to doodlebug
    vector<int> directions = {-1, 1, -20, 20};
    int move_direction = 0;
    bool move = false;
    int new_doodlebug_location = doodlebug_location + directions[rand() % 4];
    increment_age();
    // while(move == false) {
       
        if(world[new_doodlebug_location].get_type() == ANTS && (new_doodlebug_location >= 1 && new_doodlebug_location <= 400)) {
            world[new_doodlebug_location].set_type(DOODLEBUGS);
            world[doodlebug_location].set_type(EMPTY_SPACE);
            doodlebug_location = new_doodlebug_location;
            int ant_location_ptr;
            for(int i = 0; i < ants.size(); i++) {
                if(doodlebug_location == ants[i].get_ant_location()) {
                    ant_location_ptr = i;
                }
            }
            ants.erase(ants.begin() + ant_location_ptr);
            starve_count = 0;
            move = true;
        // }
        move_direction++;
    }

    if(world[new_doodlebug_location].get_type() == EMPTY_SPACE && (new_doodlebug_location >= 1 && new_doodlebug_location <= 400)) {
        starve_count++;
        if(doodlebug_location % 20 == 0 && directions[rand() % 4] != 1) {
            world[doodlebug_location].set_type(EMPTY_SPACE);
            doodlebug_location = new_doodlebug_location;
            world[doodlebug_location].set_type(DOODLEBUGS);
        }
        else if((doodlebug_location - 1 % 20) == 0 && directions[rand() % 4] != -1) {
            world[doodlebug_location].set_type(EMPTY_SPACE);
            doodlebug_location = new_doodlebug_location;
            world[doodlebug_location].set_type(DOODLEBUGS);
        }
        else if (doodlebug_location % 20 != 0) {
            world[doodlebug_location].set_type(EMPTY_SPACE);
            doodlebug_location = new_doodlebug_location;
            world[doodlebug_location].set_type(DOODLEBUGS);
        }
    }
}

void Doodlebug::breed(vector<Organism> &world, vector<Doodlebug> &doodlebugs, int time_step) {
    //if time step 8
     vector<int> directions = {-1, 1, -20, 20}; // left right down up

    if (time_step % 8 == 0 && get_age() >= 8) {
        bool breed = false;
        int breed_direction = 0;
        int breed_location = doodlebug_location + directions[breed_direction];

        while (breed == false) {
            if (world[breed_location].get_type() == EMPTY_SPACE && (breed_location >= 1 && breed_location <= 400)) {
                if (directions[breed_direction] != 1 && (doodlebug_location + 1 % 20 == 0)) {
                    world[breed_location].set_type(DOODLEBUGS);
                    doodlebugs.push_back(Doodlebug());
                    doodlebugs[doodlebugs.size() - 1].set_doodlebug_location(breed_location);
                    breed = true;
                } else if (directions[breed_direction] != -1 && doodlebug_location % 20 == 0) {
                    world[breed_location].set_type(DOODLEBUGS);
                    doodlebugs.push_back(Doodlebug());
                    doodlebugs[doodlebugs.size() - 1].set_doodlebug_location(breed_location);
                    breed = true;
                } else if (doodlebug_location % 20 != 0) {
                    world[breed_location].set_type(DOODLEBUGS);
                    doodlebugs.push_back(Doodlebug());
                    doodlebugs[doodlebugs.size() - 1].set_doodlebug_location(breed_location);
                    breed = true;
                }
            } 
            else if (breed == false && breed_direction == 3) {
                breed = true;
            }

            breed_direction++;
        }
    }

    //check for empty adjacent pos
    //if all adjacent locations are full, breed does not happen
    //else randomly add doodlebug at adjacnet pos
    //add doodlebug to vector and update location
}

/******************************************************/

