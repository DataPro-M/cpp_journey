#include <iostream>
#include <vector> //including the function vector from std library
using namespace std;

class List{
    // members cannot be accessed (or viewed) from outside the class
    private: 

    // members cannot be accessed from outside the class, 
    // however, they can be accessed in inherited classes. 
    protected:  

    // members are accessible from outside the class
    public:
    List(){
        // constructor
    }
    ~List(){
        // destructor
    }
    vector<string> list; 
    string name; 
    
    void print_menu();
    void print_list();
    void add_item();
    void print_item();
    void delete_item();

};