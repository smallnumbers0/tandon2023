class Dog :public Pet {
    double earSize;
public:
    Dog() : Pet(20000) {}
    void speak() const{ cout<< "Woof" << endl; }
    void setSize (double newSize) {earSize = newSize; }
    double getSize() const { return earSize; }
};

int main() {
    Pet** pArray = new Pet*[3];
    pArray[0] = new Cat();
    pArray[1] = new Dog();
    pArray[2] = new Cat();


}