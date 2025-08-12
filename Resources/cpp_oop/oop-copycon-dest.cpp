#include <bits/stdc++.h>
using namespace std;

class Student{
    public:
    string name;
    double* cgpaPtr;

    Student(string name, double cgpa){
        this->name=name;
        cgpaPtr=new double;
        *cgpaPtr=cgpa;
    }

    // shallow copy constructor involving pointers
    // both objects will point to the same memory location of cgpaPtr
    // so if one object changes the value, the other will also reflect that change
    // this is default behavior in C++ when using pointers
    // Student(Student &obj){
    //     // cout << "Details copied successfully" << endl;
    //     this->name = obj.name;
    //     this->cgpaPtr = obj.cgpaPtr; // copying the pointer, not the value
    // }
    // to avoid this, we need to implement a deep copy constructor

    // deep copy constructor (not default)
    Student(Student &obj){
        this->name = obj.name;
        this->cgpaPtr=new double;
        *cgpaPtr=*obj.cgpaPtr; // copying the value pointed by the pointer
    }

    // destructor
    ~Student(){
        cout<<"Destructor for "<<name<<endl;
        delete cgpaPtr; // deallocating memory allocated by the constructor
        // if we don't do this, memory leak will occur
    }

    void getinfo(){
        cout << "Name: " << name << endl;
        cout << "CGPA: " << *cgpaPtr << endl;
        cout << "Address of cgpaPtr: " << cgpaPtr << endl;
        cout << "-------------------------" << endl;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    
    // shallow copy: copies all member values from one obj to another (default type) (used in oop1.cpp)
    // deep copy: shallow copy + dynamically allocated memory pointed by members (if any) is also copied

    Student s1("Asdfgh", 9.5);
    s1.getinfo();

    Student s2(s1);
    *(s2.cgpaPtr)=9.1;
    s2.name="Qwerty";
    // s1.getinfo(); // cgpa of s1 also changes bcz same ptr is used (in shallow copy)
    // in deep copy, no change in s1's cgpa since new memory is allocated for s2's cgpaPtr
    s2.getinfo();

    // destructor: deallocates memory allocated by the constructor (implemented by default in cpp, shallow type)
    // for dynamically allocated memory, we need to implement a custom destructor

    return 0;
}