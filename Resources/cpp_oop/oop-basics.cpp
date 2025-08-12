#include <bits/stdc++.h>
using namespace std;

class Teacher{
    // properties/attributes
    private:
    double salary;
    bool salset=false;

    public:
    string name;
    string dept;
    string sub;

    // non-parameterized constructor
    Teacher(){
        // cout<< "Teacher object created!" << endl;
        dept = "cse";
    }

    // parameterized constructor
    Teacher(string name, string d, string s){
        this->name = name; // 'this' pointer refers to the current object
        dept = d;
        sub = s;
        // cout << "Teacher object created with parameters!" << endl;
    }

    // copy constructor
    Teacher(Teacher &obj){
        cout << "Details copied successfully" << endl;
        this->name = obj.name;
        this->dept = obj.dept;
        this->sub = obj.sub;
        this->salary = obj.salary;
        this->salset = obj.salset;
    }

    // methods/member functions
    void changedept(string newdept){
        dept = newdept;
    }
    //setter
    void setSalary(double s){
        salary=s;
        salset=true;
    }
    //getter
    double getSalary(){
        if(salset){
            return salary;
        } else {
            return 0;
        }
    }
    void printDetails(){
        cout << "Name: " << name << endl;
        cout << "Department: " << dept << endl;
        cout << "Subject: " << sub << endl;
        if(salset){
            cout << "Salary: " << salary << endl;
        } else {
            cout << "Salary not set!" << endl;
        }
        cout << "------------------" << endl;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    // Object is an instance of a class (an entity)
    // Class is a blueprint for creating objects
    // Properties are attributes of class (variables)
    // Methods are functions of class (functions)

    Teacher t1("qwerty","cse","cpp"); // p constructed
    Teacher t2; // np constructed
    t2.name="asdfgh";
    t2.sub="dsa";
    // t2.dept="cse";

    // Access modifiers
    // public: accessible from anywhere
    // private: accessible only within the class
    // protected: accessible within the class and its derived classes
    // default access modifier is private

    // t1.salary=100000;
    t1.setSalary(100000); // setting salary using method
    t1.printDetails(); // print details using method

    t2.setSalary(110000); // setting salary using method
    t2.printDetails(); // print details using method
    
    // Encapsulation
    // wrapping data and methods in single unit (class)
    // data hiding

    // constructor: special member function that is called when an object is created
    // same name as class, no return type, only once called when object is created to initialize object
    // memory is allocated for object when constructor is called
    // types: non-parameterized, parameterized, copy constructor
    // constructors can be overloaded (multiple constructors with different parameters) (example of polymorphism)
    // copy constructor: special constructor that creates a new object as a copy of an existing object

    Teacher t3(t1); // copies details from t1 to t3 (default copy constructor is invokedif not made custom)
    t3.printDetails(); // print details of t3

    return 0;
}