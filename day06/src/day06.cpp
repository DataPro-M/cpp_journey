#include <iostream>
using namespace std;

void autoStorageClass()
{
 
    cout << "Demonstrating auto class\n";
 
    // Declaring an auto variable
    // No data-type declaration needed
    auto a = 32;
    auto b = 3.2;
    auto c = "autoStorage";
    auto d = 'G';
 
    // printing the auto variables
    cout << a << " \n";
    cout << b << " \n";
    cout << c << " \n";
    cout << d ;
}

//----------- Extern storage class -------------------
// declaring the variable which is to
// be made extern an initial value can
// also be initialized to z
int z;
void externStorageClass()
{
 
    cout << "\nDemonstrating extern class\n";
 
    // telling the compiler that the variable
    // z is an extern variable and has been
    // defined elsewhere (above the main
    // function)
    extern int z;
 
    // printing the extern variables 'x'
    cout << "Value of the variable 'z'"
         << "declared, as extern: " << z << "\n";
 
    // value of extern variable x modified
    z = 2;
 
    // printing the modified values of
    // extern variables 'z'
    cout
        << "Modified value of the variable 'z'"
        << " declared as extern: \n"
        << z;
}

//----------- static variables -------------------
// Function containing static variables
// memory is retained during execution
int staticFun()
{
    cout << "For static variables: ";
    static int count = 0;
    count++;
    return count;
}
 
// Function containing non-static variables
// memory is destroyed
int nonStaticFun()
{
    cout << "For Non-Static variables: ";
 
    int count = 0;
    count++;
    return count;
}

//----------- register Storage Class -------------------
// This storage class declares register 
// variables which have the same functionality 
// as that of the auto variables.
void registerStorageClass()
{
 
    cout << "Demonstrating register class\n";
 
    // declaring a register variable
    register char b = 'G';
 
    // printing the register variable 'b'
    cout << "Value of the variable 'b'"
         << " declared as register: " << b;
}


//-----------  mutable keyword -------------------
// Sometimes there is a requirement to modify one or more data
// members of class/struct through const function even though 
// you don’t want the function to update other members of class/struct. 
class Test {
    public:
        int x;
 
    // defining mutable variable y
    // now this can be modified
    mutable int y;
 
    Test()
    {
        x = 4;
        y = 10;
    }
}; 

//-----------  main func -------------------
int main(int argc, char* argv[]) {    
    
	int x = 0; // Automatically infer type. Not a type in itself.

	while(x != 6) {
        cout << "\n\n" << endl;
        cout << "Select an option" << endl;
        cout << "1. auto Storage Class" << endl;
        cout << "2. extern Storage Class" << endl;
        cout << "3. static/NonStatic Vars" << endl;
        cout << "4. register Storage Class" << endl;
        cout << "5. mutable keyword" << endl;
        cout << "6. Quit\n" << endl;

        cin >> x;
        if (cin.fail()) {
            //Not an int.
            goto label; 
        }
        printf("\033c"); // For Linux/Unix : clear console
        
		switch(x) {
            case 1:
                autoStorageClass(); 
                               
                break; 

            case 2:                 
                externStorageClass();
                break;

            case 3:                 
                // Calling the static parts
                cout << staticFun() << "\n";
                cout << staticFun() << "\n";
            
                // Calling the non-static parts            
                cout << nonStaticFun() << "\n";
                cout << nonStaticFun() << "\n";
                break;

            case 4:
                // To demonstrate register Storage Class                 
                registerStorageClass(); 
                break;
            
            case 5: 
            {                
                // t1 is set to constant
                // A const member function such as this is disallowed 
                // from modifying any member variables of that class. 
                const Test t1;
            
                // trying to change the value
                t1.y = 20;
                cout << "'t1.y' is a mutable var and changed to: " << t1.y;
            
                // Uncommenting below lines
                // will throw error
                // t1.x = 8;
                // cout << t1.x;
                                
                break;
            }    
            default: // If no match is found.
                //if (x == 6) cout << "\nQuiting!" << endl;
                //else cout << "\nInvalid choice. \n" << endl; 
                cout << nonStaticFun() << "\n";           
                return 0;
            
        }         
	}
    label:
        cout << "\nInvalid choice. Quiting! \n" << endl; 
	return 0;
}




