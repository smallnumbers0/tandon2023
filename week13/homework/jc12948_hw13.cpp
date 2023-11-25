//This program is a world simulation of Doodlebugs and Ants. Honestly, I think we are also living in a simulation like this.
//Jacky Choi NYU Tandon Bridge

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

const char ANTS = 'o';
const char DOODLEBUGS = 'X';
const char EMPTY_SPACE = '-';
const int GRID_DIMENSION = 20;
const int MOVE_LEFT = -1;
const int MOVE_RIGHT = 1;
const int MOVE_UP = -20;
const int MOVE_DOWN = 20;
const int GRID_SIZE = 400;
const int NUM_INITIAL_ANTS = 100;
const int NUM_INITAL_DOODLEBUGS = 5;

class World;
class Organism;
class Doodlebug;
class Ant;

class World {
    friend class Ant;
    friend class Organism;
    friend class Doodlebug;
    int time_step = 1;
    int organism_age = 1;

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
    int get_breed_count() const;

    World();
};


class Organism {
    int location;
    char type = EMPTY_SPACE;
    int age = 0;
protected:
    int breed_count = 0;
    
public:
    void set_type(char new_type);
    char get_type() const;
    virtual void move(){}; 
    virtual void breed(){};
    int get_location() const;
    void set_location(int new_location);
    int get_age() const;
    void increment_age();
    int get_breed_count() const;

    Organism(){type = EMPTY_SPACE;};
};

class Ant: public Organism {
    int ant_location;
    char type = ANTS;
public:
    void move(vector<Organism> &world);   //find adjacent empty spots and randomly move every time step, if out of bounds or all adjacent full, stay still
    void breed(vector<Organism> &world, vector<Ant> &ants, int &time_step); //find adjacent empty spots and breed every 3 time steps. 
    int get_ant_location() const;
    void set_ant_location(int new_location);
    
    Ant(){type = ANTS;};
};

class Doodlebug: public Organism { //derived classes can overwrite virtual function of organism class
    int doodlebug_location;
    char type = DOODLEBUGS;
    int starve_count = 0;
public:
    void move(vector<Organism> &world, vector<Ant> &ants);   //find adjacent empty spots and randomly move every time step, if there are ants, it will eat the ant instead
    void breed(vector<Organism> &world, vector<Doodlebug> &doodlebugs, int time_step); //find adjacent empty spots and breed every 8 time steps
    void starve(vector<Organism> &world, vector<Doodlebug> &doodlebugs); //3 time steps and doodle starves and dies
    int get_starve_count(); 
    int get_doodlebug_location() const;
    void set_doodlebug_location(int new_location);

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
            world.move_doodlebugs();
            world.breed_doodlebugs();
            world.starve();
            world.move_ants();
            world.breed_ants();
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
    for(int i = 0; i <= GRID_SIZE; i++) {
        world.push_back(Organism());
        world[i].set_location(i);
    }
}

void World::initialize_world() {
    srand(time(0));
/**Add 5 Doodlebugs**/
    for (int i = 0; i < NUM_INITAL_DOODLEBUGS; i++) {
        int location = rand() % GRID_SIZE + 1;
        if (world[location].get_type() == EMPTY_SPACE) {
            doodlebugs.push_back(Doodlebug());
            doodlebugs[doodlebugs.size() - 1].set_doodlebug_location(location);
            world[location].set_type(DOODLEBUGS);
        }
    }
/**Add 100 Ants**/
    for (int i = 0; i < NUM_INITIAL_ANTS; i++) {
        int location = rand() % GRID_SIZE + 1;
        if (world[location].get_type() == EMPTY_SPACE) {
            ants.push_back(Ant());
            ants[ants.size() - 1].set_ant_location(location);
            world[location].set_type(ANTS);
        }
    }
}

void World::display() const {
    int location = 1;
    for(int i = 1; i <= GRID_DIMENSION; i++) {
        for(int j = 1; j <= GRID_DIMENSION; j++) {
            
            if(world[location].get_type() == EMPTY_SPACE) {
                // cout<<location;
                cout<<EMPTY_SPACE<<" ";
                
            }
            else if(world[location].get_type() == ANTS) {
                // cout<<location;
                cout<<ANTS<<" ";
            }
            else if(world[location].get_type() == DOODLEBUGS) {
                // cout<<location; 
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

int Organism::get_age() const {
    return age;
}

void Organism::increment_age() { //breed count will be the one that resets to 0.
    breed_count++; 
    age++;
}

int Organism::get_breed_count() const {
    return breed_count;
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

//This function will set each ant in the grid to move in a random direction as long as it is not occupied. It will also increment the age and breed_counter of the Ant
void Ant::move(vector<Organism> &world) { 
    
    int new_location;
    int random_direction;
    vector <int>direction = {MOVE_LEFT, MOVE_RIGHT, MOVE_UP, MOVE_DOWN}; // -1 for left/ +1 for right/ -20 for up/ + 20 for down

    random_direction = direction[rand() % 4];
    new_location = ant_location + random_direction;
    increment_age(); //This function also increments breed_count

   
        if((world[new_location].get_type() == EMPTY_SPACE) && (new_location >=1 && new_location <= GRID_SIZE)) { //check if new location is out of bounds.
            if(((ant_location - 1) % GRID_DIMENSION == 0) && (new_location % GRID_DIMENSION != 0)) {
                world[ant_location].set_type(EMPTY_SPACE);
                ant_location = new_location;
                world[ant_location].set_type(ANTS);
            
            }
            else if(ant_location % GRID_DIMENSION == 0 && new_location % GRID_DIMENSION != 1) {
                world[ant_location].set_type(EMPTY_SPACE);
                ant_location = new_location;
                world[ant_location].set_type(ANTS);
        
            }  
            else if(ant_location % GRID_DIMENSION != 0) {
                world[ant_location].set_type(EMPTY_SPACE);
                ant_location = new_location;
                world[ant_location].set_type(ANTS);
                
            }
    }

    //check for empty adjacent spaces around each ant.
    //randomly move to one of the empty spaces.
    //set previous ant location to empty space.
}

//This function will add a new ant to the grid as long as there is an adhacent empty space. It will also add the ant to the vector.
//Breed will only happen if the ant is 3 or more time steps old and breed count is included so if there is no empty space yet, the ant can still breed on the 4th or 5th .... infinite time steps and the counter resets to zero
void Ant::breed(vector<Organism> &world, vector<Ant> &ants, int &time_step) {
    vector<int> directions = {MOVE_LEFT, MOVE_RIGHT, MOVE_UP, MOVE_DOWN};
    
    if (get_age() >= 3 && get_breed_count() >= 3) { // ae is also included so new breeded ants added dont breed immediately since each ant inherits the same breed function and added to the vector.
        bool breed = false;
        int breed_direction = 0;
        int breed_location = ant_location + directions[breed_direction];

        while (breed == false && get_breed_count() >= 3) {
            if (world[breed_location].get_type() == EMPTY_SPACE && (breed_location >= 1 && breed_location <= GRID_SIZE)) {
                if ((breed_location % GRID_DIMENSION != 1) && (ant_location % GRID_DIMENSION == 0)) {
                    world[breed_location].set_type(ANTS);
                    ants.push_back(Ant());
                    ants[ants.size() - 1].set_ant_location(breed_location);  //This sets the location ofthe world to where the ant is bred to the char 'o'
                    breed = true;
                    breed_count = 0;
                } 
                else if ((breed_location % GRID_DIMENSION != 0) && ((ant_location - 1) % GRID_DIMENSION == 0)) {
                    world[breed_location].set_type(ANTS);
                    ants.push_back(Ant());
                    ants[ants.size() - 1].set_ant_location(breed_location);
                    breed = true;
                    breed_count = 0;
                } 
                else if (ant_location % GRID_DIMENSION != 0) {
                    world[breed_location].set_type(ANTS);
                    ants.push_back(Ant());
                    ants[ants.size() - 1].set_ant_location(breed_location);
                    breed = true;
                    breed_count = 0;
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


void Doodlebug::set_doodlebug_location(int new_location) {
    doodlebug_location = new_location;
}

int Doodlebug::get_starve_count() {
    return starve_count;
}

void Doodlebug::starve(vector<Organism> &world, vector<Doodlebug> &doodlebugs) {
    //if starve counter is 3, set doodlebug location to empty space
    if(starve_count >= 3) { //all doodlebugs have a starve counter incrmeent every time step. In the function below, if they eat an ant, the counter reset to 0
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
    vector<int> directions = {MOVE_LEFT, MOVE_RIGHT, MOVE_UP, MOVE_DOWN};
    int move_direction = 0;
    bool move = false;
    int new_doodlebug_location = doodlebug_location + directions[rand() % 4];
    increment_age();
    // while(move == false) {
    for(int i = 0; i < directions.size(); i++) {
        int food_doodlebug_location = doodlebug_location + directions[rand() % 4];
        if(world[food_doodlebug_location].get_type() == ANTS && (food_doodlebug_location >= 1 && food_doodlebug_location <= GRID_SIZE)) {
            if((doodlebug_location % GRID_DIMENSION == 0) && food_doodlebug_location % GRID_DIMENSION != 1) { //Check if in rightmost column and dierction is not moving to leftmost column in 1 time step.
                world[doodlebug_location].set_type(EMPTY_SPACE);
                doodlebug_location = food_doodlebug_location;
                world[doodlebug_location].set_type(DOODLEBUGS);
                int food_location;
                for(int i = 0; i < ants.size(); i++) {
                    if(doodlebug_location == ants[i].get_ant_location()) {
                        food_location = i;
                    }
                }
                ants.erase(ants.begin() + food_location);
                starve_count = 0;
                move = true;
                break;
            }
            else if(((doodlebug_location - 1) % GRID_DIMENSION == 0) && food_doodlebug_location % GRID_DIMENSION != 0) { //Check if in leftmost oclumn and not moving to the rightmost oclumn in 1 time step.
                world[doodlebug_location].set_type(EMPTY_SPACE);
                doodlebug_location = food_doodlebug_location;
                world[doodlebug_location].set_type(DOODLEBUGS);
                int food_location;
                for(int i = 0; i < ants.size(); i++) {
                    if(doodlebug_location == ants[i].get_ant_location()) {
                        food_location = i;
                    }
                }
                ants.erase(ants.begin() + food_location);
                starve_count = 0;
                move = true;
                break;
            }
            else if (doodlebug_location % GRID_DIMENSION != 0) {
                world[doodlebug_location].set_type(EMPTY_SPACE);
                doodlebug_location = food_doodlebug_location;
                world[doodlebug_location].set_type(DOODLEBUGS);
                int food_location;
                for(int i = 0; i < ants.size(); i++) {
                    if(doodlebug_location == ants[i].get_ant_location()) {
                        food_location = i;
                    }
                }
                ants.erase(ants.begin() + food_location);
                starve_count = 0;
                move = true;
                break;
            }
        }
        // }
    }

    if(world[new_doodlebug_location].get_type() == EMPTY_SPACE && (new_doodlebug_location >= 1 && new_doodlebug_location <= GRID_SIZE) && move == false) { //Checks empty spaces after spaces with ants
        starve_count++;
        if(doodlebug_location % GRID_DIMENSION == 0 && new_doodlebug_location % GRID_DIMENSION != 1) {
            world[doodlebug_location].set_type(EMPTY_SPACE);
            doodlebug_location = new_doodlebug_location;
            world[doodlebug_location].set_type(DOODLEBUGS);
        }
        else if((doodlebug_location - 1 % GRID_DIMENSION) == 0 && new_doodlebug_location != 0) {
            world[doodlebug_location].set_type(EMPTY_SPACE);
            doodlebug_location = new_doodlebug_location;
            world[doodlebug_location].set_type(DOODLEBUGS);
        }
        else if (doodlebug_location % GRID_DIMENSION != 0) {
            world[doodlebug_location].set_type(EMPTY_SPACE);
            doodlebug_location = new_doodlebug_location;
            world[doodlebug_location].set_type(DOODLEBUGS);
        }
    }
}

void Doodlebug::breed(vector<Organism> &world, vector<Doodlebug> &doodlebugs, int time_step) {
    //if time step 8
  vector<int> directions = {MOVE_LEFT, MOVE_RIGHT, MOVE_UP, MOVE_DOWN}; 

    if (breed_count >= 8 && get_age() >= 8) {
        bool breed = false;
        int breed_direction = 0;
        int breed_location = doodlebug_location + directions[breed_direction];

        while (breed == false && get_breed_count() >= 8) {
            if (world[breed_location].get_type() == EMPTY_SPACE && (breed_location >= 1 && breed_location <= GRID_SIZE)) {
                if (breed_location % GRID_DIMENSION != 1 && (doodlebug_location % GRID_DIMENSION == 0)) {
                    world[breed_location].set_type(DOODLEBUGS);
                    doodlebugs.push_back(Doodlebug());
                    doodlebugs[doodlebugs.size() - 1].set_doodlebug_location(breed_location);
                    breed = true;
                    breed_count = 0;
                } 
                else if (breed_location % GRID_DIMENSION != 0 && ((doodlebug_location - 1) % GRID_DIMENSION == 0)) {
                    world[breed_location].set_type(DOODLEBUGS);
                    doodlebugs.push_back(Doodlebug());
                    doodlebugs[doodlebugs.size() - 1].set_doodlebug_location(breed_location);
                    breed = true;
                    breed_count = 0;
                } 
                else if (doodlebug_location % GRID_DIMENSION != 0) {
                    world[breed_location].set_type(DOODLEBUGS);
                    doodlebugs.push_back(Doodlebug());
                    doodlebugs[doodlebugs.size() - 1].set_doodlebug_location(breed_location);
                    breed = true;
                    breed_count = 0;
                }
            } 
            else if (breed == false && breed_direction == 3) {
                breed = true;
            }
            breed_direction++;
        }
    }
}

/******************************************************/

