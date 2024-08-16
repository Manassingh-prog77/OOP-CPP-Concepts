#include <iostream>
using namespace std;
class Students {
public:
    string name;
    double* cgpaPtr;

    Students(string name, double cgpa) {
        this->name = name;
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
    } 

    ~Students() {
        cout << "Hi, I delete everything"<< endl;
        //If you are using Deep copy concept So you need to create new created pointer as well in copy constructor
        delete cgpaPtr;
    }

    void getInfo(){
        cout << "name: " << name <<endl;
        cout << "cgpa: " << *cgpaPtr <<endl;
    }   
};

class Person{
public:
    string name;
    int age;
    //Constructor
    // Person(){
    //     cout << "Parent Constructor"<< endl;
    // }

    //Parametrized Constructor
    Person(string n, int a){
        this->name = n;
        this->age = a;
    }

};

class children : public Person{
public: 
    int rollno;
    // children(){
    //     cout << "Child Constructor"<< endl;
    // }

    //For parametrized constructor Parent Class
    children(string name, int age, int rollno) : Person(name, age){
        this->rollno = rollno;
    }
    void getInfo(){
        cout << "name: " << name <<endl;
        cout << "age: " << age <<endl;
        cout << "roll no: " << rollno <<endl;
    }   
};

class Teacher : public children{
public:
    string researchArea; 
Teacher(string name, int age, int rollno, string research): children(name, age, rollno){
    this->researchArea = research;
}
    void getInfo(){
        cout << "Name: " << name <<endl;
        cout << "Age: " << age <<endl;
        cout << "Roll no: " << rollno <<endl;
        cout << "Research Area: " << researchArea <<endl;
    }  
};

class GradStud{
public: 
   string name;
   int rollno;
};

class coachingTeacher{
public: 
   string subject;
   double salary;
};

class TA : public GradStud, public coachingTeacher {
};

int main(){
    //Destructor
    Students s1("rahul kumar", 8.9);
    s1.getInfo();

    //Inheritance:- Improves Code Reusability
    //Single level Inheritance
    children c1("rahul",21,1234);
    //See Parent constructor run first then child constructor
    c1.getInfo();

    //Multi-level Inheritance
    Teacher t1("Teacher",22,123,"Physics");
    t1.getInfo();

    //Multiple Inheritance
    TA t2;
    t2.name = "Tony Stark";
    t2.subject = "Engineering";

    cout<< t2.name<<endl;
    cout<< t2.subject<<endl;

    //Hierarchial Inheritance :- 
    //In this type of Inheritance you can create multiple classes using the same base / Parent class. 

    //Hybrid Inheritance :-
    //Combination of Multi-level and Multiple inheritance is Hybrid Inheritance
    //In this we can create multiple child nodes from one base class and for that base we could continue it to multiple level
    //For visual representation
//                                      Parent class
// (Multiple Inheritace)               /             \
// (Multi-level Inheritace)      child1            child2
//                                 |                  
//                                child1a
//                                 |
//                                child1b
    return 0;
}