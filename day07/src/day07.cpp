#include <iostream>
#include <atomic>
using namespace std;

//----------- type_qualifiers -------------------
void type_qualifiers()
{ 
    cout << "Demonstrating Type Qualifiers\n";
 
    // A way of expressing additional information about a value 
    // through the type system to ensure correctness in the use of the data.

    const int a = 1; // a, once defined, is constant and cannot be changed
	std::atomic<int> b; // b can only be modified by one thread at a time
    // c can be modified externally. the program will check x's value before using it, 
    // even if it hasn't been modified locally.
	volatile int c;

    cout << "'a' is:" << typeid(a).name() 
    << "\n'b' is: " << typeid(b).name()  
    << "\n'c' is: " << typeid(c).name()
    << endl;

}

//----------- inline function -------------------
/*
C++ provides an inline functions to reduce the function call overhead. 
Inline function is a function that is expanded in line when it is called. 
When the inline function is called whole code of the inline function gets 
inserted or substituted at the point of inline function call. 
This substitution is performed by the C++ compiler at compile time. 
Inline function may increase efficiency if it is small.
*/

inline int cube_inline(int s)
{       
    /*
    Compiler may not perform inlining in such circumstances like:
        1) If a function contains a loop. (for, while, do-while)
        2) If a function contains static variables.
        3) If a function is recursive.
        4) If a function return type is other than void, and the return 
            statement doesn’t exist in function body.
        5) If a function contains switch or goto statement.
    */
    return s*s*s;
}

//----------- inline function in class----------------
// The best programming style is to just write the prototype of function 
// inside the class and specify it as an inline in the function definition.
class operation
{
public:    
    int square(int s); // declare the function
};
  
inline int operation::square(int s) // use inline prefix
{     
    return s*s;
}

//----------- ternary_operator ----------------
/*
A conditional operator that provides a shorter syntax for the if statement. The first 
operand is a boolean expression; if the expression is true then the value of 
the second operand is returned otherwise the value of the third operand is returned.
*/
void ternary_operator(){

	int x = 4;
	x < 0 ? cout << "x is negative" << endl : cout << "x is 0 or positive" << endl;

}

//----------- Address Resolution Operator ----------------
//Use ‘&’ before a variable name to use it’s address in memory
// rather than the value stored.
void address_resolution_operator(){
    int x = 5;
	cout << "The address of x is " << &x << endl;
}


//-----------  main func -------------------
int main(int argc, char* argv[]) {    
    
	int x = 0; // Automatically infer type. Not a type in itself.

	while(x != 6) {
        cout << "\n\n" << endl;
        cout << "Select an option" << endl;
        cout << "1. Type Qualifiers" << endl;
        cout << "2. Inline function" << endl;
        cout << "3. Inline function in class" << endl;
        cout << "4. Ternary operator" << endl;
        cout << "5. Address resolution operator" << endl;
        cout << "6. Quit\n" << endl;

        cin >> x;
        if (cin.fail()) {
            //Not an int.
            goto label; 
        }
        printf("\033c"); // For Linux/Unix : clear console
        
		switch(x) {
            case 1:
                type_qualifiers();                               
                break; 

            case 2:
                cout << "\nDemonstrating Inline functions\n";               
                cout << "The cube of 3 is: " << cube_inline(3) << "\n"; 
                break;

            case 3:                 
                cout << "Program using inline function\n";
                operation Op;
                cout << "The square of 3 is: " << Op.square(3) << "\n";
                
                break;

            case 4:
                ternary_operator();
                break;
            
            case 5:            
                address_resolution_operator();                                
                break;
             
            default:          
                return 0;
            
        }         
	}
    label:
        cout << "\nInvalid choice. Quiting! \n" << endl; 
	return 0;
}




