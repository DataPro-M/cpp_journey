#include <iostream>
#include <atomic>
using namespace std;

//----------- Address Resolution Operator ----------------
//Use ‘&’ before a variable name to use it’s address in memory
// rather than the value stored.
void address_resolution_operator(){
    int x = 5;
	cout << "The address of x is " << &x << endl;
}

//----------- de-refrence operator -------------------
/* 
    Use ‘*’ before a variable name to use 
    the value it points to rather than the address stored.
*/
void dereference_operator(){ 

    int x = 4;	
	int* y = &x;
	cout << "The value stored at x is " << *y << endl;
    
}

//----------- Pointers -------------------
/*
    A pointer is a variable that can hold the address of another variable. 
    Just like regular data types, they must have their own type which 
    refers to the type of the data at the address pointed to.
*/
void pointer_()
{   
    // 'pointVar' --> a pointer ___ 'p' --> a normal variable
    int* pointVar, var; 
    var = 5;

    // assign address of var to pointVar
    pointVar = &var;

    // Note:
    //    'pointVar' and '*pointVar' is completely different. 
    //    We cannot do something like *pointVar = &var;

    // access value pointed by pointVar
    cout << "value pointed by pointVar:   " << *pointVar << endl;   // Output: 5
    cout << "address pointed by pointVar: " << pointVar  << endl;   // Output: ?
}

//----------- Pointer Arithmetic -------------------
/*
    Perform integer addition or subtraction operations on pointers, 
    taking the data type’s size into account to return the correct 
    address of the next item.
*/
void pointer_arithmetic(){
    int x[5] = {1,2,3,4,5};
	int* x_ptr = &x[0];
    cout << "x                   = " << x << endl;
    cout << "*x                  = " << *x << endl;
	cout << "Value of x_ptr      = " << x_ptr << endl;
	cout << "Value of x_ptr + 1  = " << x_ptr + 1 << endl;

	char y[7] = "OK_C++";
	char* y_ptr = &y[0];
    cout << "y is:               = " << y << endl;
    cout << "*y is:              = " << *y << endl;
	cout << "Value of y_ptr      = " << y_ptr << endl;
	cout << "Value of y_ptr + 1  = " << y_ptr + 1 << endl;
}





//-----------  main func -------------------
int main(int argc, char* argv[]) {    
    
	int x = 0; // Automatically infer type. Not a type in itself.

	while(x != 5) {
        cout << "\n\n" << endl;
        cout << "Select an option" << endl;
        cout << "1. Address resolution operator" << endl;
        cout << "2. Dereference Operator" << endl;
        cout << "3. Pointers" << endl;
        cout << "4. Pointer Arithmetic" << endl;
        cout << "5. Quit\n" << endl;

        cin >> x;
        if (cin.fail()) {
            //Not an int.
            goto label; 
        }
        printf("\033c"); // For Linux/Unix : clear console
        
		switch(x) {
            case 1:
                address_resolution_operator();                               
                break; 

            case 2:
                dereference_operator();
                break;

            case 3:                 
                pointer_();
                break;

            case 4:
                pointer_arithmetic();
                break; 
             
            default:          
                return 0;
            
        }         
	}
    label:
        cout << "\nInvalid choice. Quiting! \n" << endl; 
	return 0;
}