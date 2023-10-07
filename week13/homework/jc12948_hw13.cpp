//Doodlebug

#include <iostream>
using namespace std;

class World {
public:
    void display() const{
        for(int i = 0; i < 20; i++) {
            for(int j = 0; j < 20; j++) {
                cout<<" - ";
            }
            cout<<endl<<endl;
        }
    }
};
class Organism;
class Doodlebug;
class Ant;

//move
//breed
//starve
//pass_away


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