/******************************************************************************
Made in OnlineGDB by C.J. Merendino
Lab 7 - Program 1 - Minimum & Maximum
This program reads a series of integers until the sentinel value -99 is entered and displays the smallest and largest values entered..
*******************************************************************************/
#include <iostream>
using namespace std;

int main() {
    const int SENTINEL = -99;
    int number;
    int smallest;
    int largest;
    bool has_data = false;

    // Read first value before entering loop
    cout << "Enter an integer (-99 to end): ";
    cin >> number;

    // Continue reading and comparing values until sentinel is entered
    while (number != SENTINEL) {
        if (!has_data) {
            // Initialize both extrema from the first valid data value
            smallest = number;
            largest = number;
            has_data = true;
        } else {
            if (number < smallest) {
                smallest = number;
            }
            if (number > largest) {
                largest = number;
            }
        }

        cout << "Enter an integer (-99 to end): ";
        cin >> number;
    }

    // Display results or a message if no valid data was entered
    if (!has_data) {
        cout << "No data values were entered." << endl;
    } else {
        cout << "Smallest: " << smallest << endl;
        cout << "Largest: " << largest << endl;
    }

    return 0;
}