#include <iostream>
#include <array>

using namespace std;
int double_number_a(int x);
void double_number_b(int* x);


int main() {
    int x; 
    cout << "Inser an int number less than 3!" << endl;
    cin >> x;
    
	switch(x) {
        case 1:
            int y;
            y = double_number_a(x);
            cout << "You entered: " << x << endl;
            cout << "We doubled it to: " << y << endl;
            break; // You must break the search or it will fall through to the next match.
        case 2:            
            cout << "You entered: " << x << endl;
            double_number_b(&x);
            cout << "We doubled it to: " << x << endl;
            break;
        default: // If no match is found.
            cout << "Invalid choce. Quitting. \n" << endl;
            break;
	}
	return 0;
}


// Double the number passed in as 'x', returning the new value to the function caller.
int double_number_a(int x) {
	return 2 * x;
}

// Double the number pointed to by 'x', storing the result in the original variable.
void double_number_b(int* x) {
	*x *= 2;
}