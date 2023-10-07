//Doodlebug

#include <iostream>
using namespace std;

class World;
class Organism;
class DoodleBug;
class Ant;


int main() {
    int time_count = 1;
    string input;
    cout<<"Please press enter to continue with the time simulation or any enter any else to stop: "<<endl;
    cin.get();
    while(true) {
        cout<<"Time: "<<time_count<<endl;
        getline(cin, input);
        if(input == "") {
            time_count++;
        }
        else {
            break;
        }
    }
    return 0;
}