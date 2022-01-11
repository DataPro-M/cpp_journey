#include <iostream>
#include <vector> //including the function vector from std library
using namespace std;


void print_menu(string name);
void print_list();
void add_item();
void print_item();
void delete_item();

vector<string> list; //vector<datatype> name;
string name; //global var


int main(int arg_count, char *args[]){
    if( arg_count > 1) {
        name = string (args[1]);
        print_menu(name);
    }
    else {

        cout << "Username not supplied.. exiting program";
    };
    return 0;
}

void print_menu(string name) {
    int choice;

    cout << "\n**********************\n";
    cout << " 1 - Print list\n";
    cout << " 2 - Add to list\n";
    cout << " 3 - Delete from list\n";
    cout << " 4 - Quit\n";
    cout << " Enter your choice and press return: ";

    cin >> choice;

    if (choice == 4){
        exit(0);
    }
    else if( choice == 3) {
        delete_item();
    }
    else if( choice == 2) {
        add_item();
    }
    else if( choice == 1) {
        print_list();
    }
    else {
        cout << "Sorry choice not implemented yet!\n";
    }
}

void add_item() {
    cout << "\n\n\n\n\n\n\n";
    cout << "*** Add item ***\n";
    cout << "Type in an item and press enter: ";

    string item;
    cin >> item;

    list.push_back(item); // pushes the item to back of the queue in the list

    cout << "Successfully added an item to the list\n";

    cin.clear(); // clear the input buffer!

    print_menu(name);

}

void delete_item() {
    cout << "\n*** Delete item ***\n";
    cout << "Select an item index number to delete\n";
    if(list.size()) {
        for(int i=0;  i < (int)list.size(); i++) {
            cout << i << ": " << list[i] << "\n";
        }
    }
    else {
        cout <<"No item to delete. \n";
    }

    print_menu(name);
}

void print_list() {
    cout << "\n\n\n\n\n\n";
    cout << "*** Printing List  ***\n";

    for(int list_index=0; list_index < (int)list.size(); list_index++) {
        cout << " * " << list[list_index] << "\n";
    }

    cout << "M - menu \n";
    char choice;
    cin >> choice;

    if(choice == 'M' || choice =='m') {
        print_menu(name);
    }
    else {
        cout << "Invalid choce. Quitting. \n";
    }


}