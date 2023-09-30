#include <iostream>
using namespace std;

class AbstractEmployee { //A class must sign this contract to inherit this class
    virtual void AskForPromotion()=0;
};

class Employee:AbstractEmployee { //classes acts as a blueprint
    //put members of the class here
    private:
    
    string Company; //must be accessed through setters and getters
    int Age;
    protected:
    string Name; //encapsulated values

    public: 
    void setName(string name) { //setters set the value to the object property
        Name = name;
    }
    void setCompany(string company) {
        Company = company;
    }
    void setAge(int age) {
        if(age >= 18)
        Age = age;
    }
    string getName() { //getters have no parameters, they simply return the value of property.
        return Name; //return value of name to the encapsulated property
    }
    string getCompany() {
        return Company;
    }
    int getAge() {
        return Age;
    }
    void IntroduceYourself() {
        cout<<"Name: "<<Name<<endl;
        cout<<"Company: "<<Company<<endl;
        cout<<"Age: "<<Age<<endl;
    }
    void AskForPromotion() {
        if(Age > 30) {
            cout<<Name<<" got promoted."<<endl;
        }
        else 
            cout<<Name<<" not promoted."<<endl;
    }
    virtual void Work() {
        cout<<Name<<" is checking emails, tasks, perfmorning tasks..."<<endl;
    }

    //compiler gives us a default constructor, but we must create our own for better values
    //constructors are public most of the time
    Employee(string name, string company, int age) { //creating this constructors removes the default constructor
        Name = name;
        Company = company;
        Age = age;
    }
    Employee() { //creates own default constructor
   
    }
};

class Developer: public Employee {
public:
    string FavProgrammingLanguage;
    Developer(string name, string company, int age, string favProgrammingLanguage):Employee(name, company, age) {
        FavProgrammingLanguage = favProgrammingLanguage;
    }
    void FixBug() {
        cout<<getName()<<" fixed bug using "<<FavProgrammingLanguage<<endl;
    }
     void Work() {
        cout<<Name<<" is writing code with "<<FavProgrammingLanguage<<endl;
    }
};

class Teacher:public Employee {
public:
    string Subject;
    void PrepareLesson() {
        cout<<Name<<" is preparing "<<Subject<<" lesson"<<endl;
    }
    Teacher(string name, string company, int age, string subject) :Employee(name, company, age) {
        Subject = subject;
    }
    void Work() {
        cout<<Name<<" is teaching "<<Subject<<endl;
    }
};

int main() {
    Employee employee1 = Employee("Me", "Lol", 25);
    Employee employee2 = Employee("NotMe", "Cookie", 20);
    Employee employee3 = Employee();

    // employee1.AskForPromotion();
    // employee2.AskForPromotion();
    Developer d = Developer("Jacky", "Strava", 24, "C++");
    // d.FixBug();
    // d.AskForPromotion();
    Teacher t = Teacher("Tyre", "School", 35, "History");
    // t.PrepareLesson();
    // t.AskForPromotion();
    // d.Work();
    // t.Work();

    Employee *e1 = &d;
    Employee *e2 = &t;

    e1->Work();
    e2->Work();


    return 0;
}