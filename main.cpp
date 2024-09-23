#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printSeatingChart(const char seats[5][4]) {
    cout << "  A B C D\n";  // Column labels
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << " ";  // Row labels
        for (int j = 0; j < 4; j++) {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }
    cout << "0: Available   X: Unavailable\n";
}

bool isSeatAvailable(char seats[5][4], int row, char col) {
    int colIndex = col - 'A';
    return seats[row][colIndex] == '0';
}

void assignSeat(char seats[5][4], int row, char col) {
    int colIndex = col - 'A';
    seats[row][colIndex] = 'X';  // seat as unavailable
}

// Function to validate row and column input
bool validateInput(int row, char col) {
    return (row >= 1 && row <= 5) && (col >= 'A' && col <= 'D');
}


int main() {
    // Initialize a 5x4 grid of available seats
    char seats[5][4] = {
        {'0', '0', '0', '0'},
        {'0', '0', '0', '0'},
        {'0', '0', '0', '0'},
        {'0', '0', '0', '0'},
        {'0', '0', '0', '0'}
    };

    vector<string> assignedSeats;
    int availableSeats = 20;
    string input;
    int row;
    char col;
    bool continueBooking = true;

    while (continueBooking && availableSeats > 0) {
        printSeatingChart(seats);

        // Ask the user for seat selection
        cout << "Enter seat row (1-5) and column (A-D) (e.g., 2D): ";
        cin >> row >> col;

        // Adjust row to zero-based index
        row -= 1;

        // Validate input and check seat availability
        if (row >= 0 && row < 5 && col >= 'A' && col <= 'D') {
            if (isSeatAvailable(seats, row, col)) {
                assignSeat(seats, row, col);
                assignedSeats.push_back(to_string(row + 1) + col);
                availableSeats--;
                cout << "Seat " << row + 1 << col << " assigned successfully.\n";
            } else {
                cout << "Sorry, seat " << row + 1 << col << " is already taken.\n";
            }
        } else {
            cout << "Invalid seat. Please enter a valid row and column.\n";
        }

        // Ask if the user wants to continue
        if (availableSeats > 0) {
            cout << "Would you like to book another seat? (yes/no): ";
            cin >> input;
            if (input != "yes") {
                continueBooking = false;
            }
        }
    }

    // Print the final seating chart and summary
    cout << "\nFinal Seating Chart:\n";
    printSeatingChart(seats);
    cout << availableSeats << " seats are still available.\n";

    // Display all assigned seats in the order they were booked
    if (!assignedSeats.empty()) {
        cout << "Order assigned: ";
        for (size_t i = 0; i < assignedSeats.size(); i++) {
            cout << assignedSeats[i];
            if (i < assignedSeats.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }

    return 0;
}
