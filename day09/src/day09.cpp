#include <iostream>
#include <cstring>
using namespace std;

// ------ Structs ----------//
/*
Structs are user defined data storage objects 
containing public members by default.
*/
struct student1 {         // defining a struct
// Thus the memory occupied by the structure will be 4+40+4 = 48 bytes.
  	int roll_no;
  	char name[40];
  	int phone_number;
};


// ---- Union ------//
/*
A union is a special data type that can store different data types 
at the same memory location. You can define a union with many members, 
but only one member can contain a value at any given time. Unions 
provide an efficient way of using the same memory location for multiple 
purposes. A union’s size will be the size of the largest constituent type.
*/
union student2 {          // defining a union
    // In this, the size of the member, name is more than the size of other members 
    //so the size of a union in memory (char × 20 = 40 byte) will be 40 bytes.
	int roll_no;
  	char name[40];
  	int phone_number;
};

// ----- Bitwise Operations ----------
// Bitwise operators are used to perform bit-level operations.
void bitwise_operations(){

    unsigned char a = 5; // 00000101
	unsigned char b = 9; // 00001001

	cout << "a & b  = " << (a & b)  << endl; // 00000001
	cout << "a | b  = " << (a | b)  << endl; // 00001101
	cout << "a ^ b  = " << (a ^ b)  << endl; // 00001100
	cout << "  ~a   = " << (~a)     << endl; // 11111010
	cout << "b << 1 = " << (b << 1) << endl; // 00010010
	cout << "b >> 1 = " << (b >> 1) << endl; // 00000100
}

// ------- Typedef -----------------//
/*
typedef keyword is used to assign a new name to any existing data-type.

Advantages of typedef

    It makes the program more portable.
    typedef make complex declaration easier to understand.
    It can make your code more clear
    It can make your code easier to modify

*/
void type_def(){
    typedef unsigned int ui;
	ui i = 5, j = 8;
	cout << "i = " << i << endl;
	cout << "j = " << j << endl;

    // typedef with a struct
    typedef struct{
    int id;
    char *name;
    float percentage;
    }student; 
    // this way typedef make your declaration simpler. 
    student a,b;
}

//-----------  main func -------------------
int main(int argc, char* argv[]) {    
    
	int x = 0; // Automatically infer type. Not a type in itself.

	while(x != 5) {
        cout << "\n\n" << endl;
        cout << "Select an option" << endl;
        cout << "1. Structs" << endl;
        cout << "2. Unions" << endl;
        cout << "3. Bitwise Operations" << endl;
        cout << "4. typedef" << endl;
        cout << "5. Quit\n" << endl;

        cin >> x;
        if (cin.fail()) {
            //Not an int.
            goto label; 
        }
        printf("\033c"); // For Linux/Unix : clear console
        
		switch(x) {
            case 1:
                struct student1 s1;                
                cout << "size of structure : " << sizeof(s1) << endl;

                s1.roll_no = 1;                
                strcpy(s1.name,"Brown");                
                s1.phone_number = 1234567822;
                cout << "name : " << s1.name << endl;
                cout << "roll_no : " << s1.roll_no << endl;
                cout << "phone_number : " << s1.phone_number << endl;                             
                break; 

            case 2:
                union student2 s2;
                cout << "size of union : " << sizeof(s2) << endl;

                // In union, the second value removes the first value, 
                // i.e the value entered in the last is stored in the memory, 
                s2.roll_no = 1;                
                strcpy(s2.name,"Brown");                
                s2.phone_number = 1234567822;
                cout << "name : " << s2.name << endl;
                cout << "roll_no : " << s2.roll_no << endl;
                cout << "phone_number : " << s2.phone_number << endl;

                
                break;

            case 3:
                bitwise_operations();                 
                break;

            case 4:
                type_def();
                break; 
             
            default:          
                return 0;
            
        }         
	}
    label:
        cout << "\nInvalid choice. Quiting! \n" << endl; 
	return 0;
}