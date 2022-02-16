#include <iostream>
#include <cstring>
using namespace std;

// ---  Enumerations  ---------//
/*
A user-defined data type, used to assign names to integral 
constants to make a program easier to read and maintain.
*/
enum week { 
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday 
};

// --  Variadic Functions  ------//
// Create a function with an arbitrary argument count for more flexibility.
#include <cstdarg>

int varia_sum(int count, ...)
{
	int total;
	
	va_list args;
	va_start(args, count);            /* Initialize the argument list. */

    total = 0;
	for(int i = 0; i < count; i++) {
        total += va_arg(args, int);  /* Get the next argument value. */
	}
	va_end(args);                    /* Clean up. */
	return total;
}



// -------------- Threads -----------------//
/*
Used to execute one or more subthreads to allow for parallel processing
in the same memory space, usually resulting in a performance improvement 
in a larger program.
*/
#include <thread> // std::thread

void thread_func(string msg, int n, char c) {
    cout<< "\n[Inside " << msg << "]: Thread :: ID  = " 
            << this_thread::get_id() << endl; 
    for (int i=0; i<n; ++i) { cout << c; }
}


// --------- Mutex --------//
/*
Mutual exclusion functionality. Can be used to serialize access of shared
variables between concurrent threads.
*/
#include <mutex>  //std::mutex

mutex mtx;           // mutex for critical section

void print_block (string name, int n, char c) {
  // critical section (exclusive access to std::cout signaled by locking mtx):
  mtx.lock();
  cout << name << " is going to print ...\n";
  for (int i=0; i<n; ++i) { std::cout << c; }
  std::cout << '\n';
  mtx.unlock();
}


//-----------  main func -------------------
int main(int argc, char* argv[]) {    
    
	int x = 0; // Automatically infer type. Not a type in itself.

	while(x != 5) {
        cout << "\n\n" << endl;
        cout << "Select an option" << endl;
        cout << "1. Enumerations" << endl;
        cout << "2. Variadic Functions" << endl;
        cout << "3. Threads" << endl;
        cout << "4. Mutex" << endl;
        cout << "5. Quit\n" << endl;

        cin >> x;
        if (cin.fail()) {
            //Not an int.
            goto label; 
        }
        printf("\033c"); // For Linux/Unix : clear console
        
		switch(x) {
            case 1:
                week today;
                today = Wednesday;
                cout << "Today is day " << today+1 << "\n";

                int i;
                // Traversing the week enum
                for (i = Sunday; i <= Saturday; i++) {
                    cout << i << " ";
                }                          
                break; 

            case 2:
            {
                int numbers[3] = {5, 10, 15};
                int sum_of_numbers = varia_sum(3, numbers[0], numbers[1], numbers[2]);
                cout << "Sum of the array: " << sum_of_numbers << endl;
                break;
            }

            case 3:
            {
                // Constructs the new thread and runs it. Does not block execution.
                thread threadObj1(thread_func, "Thread_1", 50,'*');
                thread threadObj2(thread_func, "Thread_2",50,'$');
                
                   

                /*
                Makes the main thread wait for the new thread to finish execution, 
                therefore blocks its own execution.
                */
                threadObj1.join();    
                threadObj2.join();    
                cout<<"\n[main function]: Exiting from Main Thread"<<endl;
                break;
            }

            case 4:
            {
                
                thread th1 (print_block,"Thread_1", 50,'*');
                thread th2 (print_block,"Thread_2",50,'$');

                th1.join();
                th2.join();
            }
                break; 
             
            default:          
                return 0;
            
        }         
	}
    label:
        cout << "\nInvalid choice. Quiting! \n" << endl; 
	return 0;
}