#include <iostream>
using namespace std;

class Student{
public: 
    string name;

    //Parametrized & non-Parametrized Constructor
    Student(){
        cout<< "non-parameterized\n";
    }

    Student(string name) {
        this->name = name;
        cout << "parameterized\n";
    }
    void getInfo(){
        cout<< "Name: " << name<<endl;
    }
};

class Print{
public:
   void show(int n){
    cout << n<<endl;
   }
   void show(char n){
    cout << n<<endl;
   }
};

class Parent{
public:
   void getInfo(){
    cout << "Parent Class"<<endl;
   } 

   virtual void hello(){
    cout << "Hello Parent class"<<endl;
   }
};


class Child{
public:
   void getInfo(){
    cout << "Child Class"<<endl;
   } 

   virtual void hello(){
    cout << "Hello Child class"<<endl;
   }
};

class Shape{//abstract class
    virtual void draw() = 0;  //Pure Virtual Function
};

class Circle: public Shape{
public: 
    void draw(){
        cout << "Drawing a Circle\n";
    }
};

void func(){
    static int x = 0;
    cout << "x = " << x<<endl;
    x++; 
}

class A{
public: 
    int x;

    void incX(){
        x = x + 1;
    }
};
 
int main(){
    //Polymorphism
        //-> Constructor Overloading
    Student s1;
    s1.name = "student1";
    Student s2("student2");
    s1.getInfo();
    s2.getInfo();
    //Compile Time Polymorphism
        //-> Function Overloading
        Print p1;
        p1.show('a');
        //->Operator Overloading :- Study it Yourself 

    //RunTime Ploymorphism / Dynamic Polymorphism
        //Function Overriding :-
        // Here we can see element of child class or Parent class in whichever the object has benn made will override the property of other class and they will be called 
        // Like P1 is object of Parent class so method getInfo of parent class is called & similarly C1 is obejct of child class so getInfo of child class is called overriding getInfo() of Parent class
        Parent P1;
        P1.getInfo();
        Child C1;
        C1.getInfo();

        //Virtual Functions :- Works similar to Function Overriding
        //Only use virtual keyword
        Parent P2;
        P2.hello();
        Child C2;
        C2.hello();

        //Abstraction :- Hiding all Unneccessary details & showing only the important parts
          /*Abstract Classes :- They are not meant for creating objects they are imaginary classes which are only used as blue print 
          for other classes*/
        Circle c5;
        c5.draw();

        //Static Keyword :- In Static variable if there is any change in value then the changed value of Func is always saved. 
        func();
        func();
        func();

        //Using Static keyword in classes of c++
        A obj;
        obj.x = 0;
        cout << "obj.x = "<<obj.x << endl;
        obj.incX();
        cout << "obj.x = "<< obj.x << endl;
        //Any object with static keyword will run for LifeTime of the Program and will end only when Program ends
    //TO explore more
      //Friends Function
    return 0;
}