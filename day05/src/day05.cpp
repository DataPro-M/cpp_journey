#include <iostream>

using namespace std;

void integer_promotion();
void program_arguments(int arg_c, char* arg_v[]);

int main(int argc, char* argv[]) {    
    
	int x = 0; // Automatically infer type. Not a type in itself.

	while(x != 3) {
        cout << "\nSelect an option" << endl;
        cout << "1. Integer Promotion" << endl;
        cout << "2. Program Arguments" << endl;
        cout << "3. Quit" << endl;

        cin >> x;
        if (cin.fail()) {
            //Not an int.
            goto label; 
        }
		switch(x) {
            case 1:
                integer_promotion();                
                break; // You must break the search or it will fall through to the next match.
            case 2: 
                if(argc < 2)  {
                    printf("\033c"); // For Linux/Unix : clear console
                    cout << "no arguments were given! \n\n"  << endl; // one line if statement with optional init statement before condition
                }
                else { // or you can use a block
                    cout << "\nnum of arguments: "  << argc << endl;
                    program_arguments(argc, argv);
                }	       
                
                break;
            default: // If no match is found.
                if (x ==3) cout << "\nQuiting!" << endl;
                else cout << "\nInvalid choce. \n" << endl;            
                return 0;
        }         
	}
    label:
        cout << "\nInvalid choce. Quiting! \n" << endl; 
	return 0;
}

void integer_promotion(){
    auto x = 'A';
    // x is promoted to int to compare it with the integer value of 'a'.
	if (x < 'a') cout << x << " is Less than " << "'a'" << "\n\n\n" << endl; 
	
}

void program_arguments(int arg_c, char* arg_v[]){
    cout << "Our arguments are: " << endl;
    for(auto i = 0; i < arg_c; i++) {
		cout << i+1 << ". " << arg_v[i] << endl;
	}
}


