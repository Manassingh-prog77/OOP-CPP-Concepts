#include <iostream>
#include <string>
using namespace std;

//Non-Parametrized Constructor
class Teacher {
private:
    double salary;

public:
    //Constructor
    Teacher(){
        cout << "Hi, I am constructor"<<endl;
        dept = "Computer Science";
    }

    //properties/ attributes
    string name;
    string dept;
    string subject;

    //Methods
    void changeDept(string newDept) {
        dept = newDept;
    }

    //Setter-Getter Function for Private Function
    void setSalary(int s){
        salary = s;
    }

    double getSalary(){
        return salary;
    }
};

//Parametrized Constructor
class ParametrizedTeacher {
public:
    //Constructor
    ParametrizedTeacher(string name, string string){
        cout << "Hi, I am constructor"<<endl;
        this->dept = "Computer Science";
        this->name = name;
        this->subject =string;
        this->salary = 250000;
    }

    //Creating Copy Constructor
    ParametrizedTeacher(ParametrizedTeacher &obj){
        this->dept = obj.dept;
        this->name = obj.name;
        this->subject = obj.subject;
        this->salary = obj.salary;
    }

    //properties/ attributes
    string name;
    string dept;
    string subject;
    double salary;
};

class Students {
public:
    string name;
    double* cgpaPtr;

    Students(string name, double cgpa) {
        this->name = name;
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
    } 

    //Copy Constructor
    Students(Students &obj){
        this->name = obj.name;
        cgpaPtr = new double;
        *cgpaPtr = *obj.cgpaPtr;
    }

    void getInfo(){
        cout << "name: " << name <<endl;
        cout << "cgpa: " << *cgpaPtr <<endl;
    }   
};

int main(){
    Teacher t1;
    t1.name = "Teacher1";
    t1.dept = "c++";
    t1.setSalary(25000);

    cout << t1.name<< endl;
    cout << t1.getSalary();
    cout << t1.dept<< endl;
    
    //Pillars of OOPS

    //Encapsulation
      //-> Data/Properties + Methods 

    //Constructor
      //Special method invoked automatically at time of object creation. Used for intailisation 
    ParametrizedTeacher t2("Teacher2", "Maths");
    cout << t2.name<<endl <<t2.subject<<endl;

    //Copy Constructor
      //Shallow Copy - just copy values from 1 obj to another obj 
         //give problem in dynamic memory location.
    ParametrizedTeacher t3(t2);   /*--default copy constructor invoked*/
    ParametrizedTeacher t4(t2);    /*--custom copy constructor invoked*/
    cout << t3.name<<endl <<t3.subject<<endl;

    //In Deep Copy :- it creates copy of dynamically allocated memory also
    Students s1("rahul kumar", 8.9);
    Students s2(s1);
    s1.getInfo();
    *(s2.cgpaPtr) = 9.2;
    s2.getInfo();
    return 0;

    //Destructor:- Opposite of Constructor

}