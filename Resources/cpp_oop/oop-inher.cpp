#include <bits/stdc++.h>
using namespace std;

class Person{
    public:
    string name;
    int age;

    Person(string name, int age){
        this->name=name;
        this->age=age;
    }
    Person(){
        cout << "Parent constructor called" << endl;
    }
    ~Person(){
        cout << "Parent destructor called" << endl;
    }
    void printInfo(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student: public Person{                       // class name : accessmod parentname
    public:
    int rollno;

    Student(string name,int age, int rollno): Person(name,age){            //calling parent constructor in constructor initialization
        this->rollno=rollno;
    }
    Student(){
        cout << "Child constructor called" << endl;
    }
    ~Student(){
        cout << "Child destructor called" << endl;
    }
    void printInfo(){
        Person::printInfo(); // calling parent class method
        cout << "Roll No: " << rollno << endl;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    // Inheritance : properties and methods of base(parent) class inherited by derived(child) class
    // Allows code reusability and establishes a relationship between classes

    Student s1;
    s1.name = "Kartikeya";
    s1.age = 20;
    s1.rollno = 12345;
    s1.printInfo(); // prints both parent and child class info
    // When child object is created, parent then child constructor
    // First child destructor, then parent constructor

    Person p("Kartikeya", 20);
    p.printInfo();
    cout << endl;
    Student s("Kartikeya", 20, 12345);
    s.printInfo(); // prints both parent and child class info
    cout << endl;
    return 0;
}