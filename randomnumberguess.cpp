#include <iostream>
#include <cstdlib>  
#include <ctime>    

using namespace std;

int main() {
    // Initialize random seed
    srand(time(0));

    int number = rand() % 100 + 1; // Random number between 1 and 100
    int guess;

    cout << "I have chosen a number between 1 and 100.\n";
    cout << "Try to guess it!\n";

    do {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess > number) {
            cout << "Too high! Try again.\n";
        } else if (guess < number) {
            cout << "Too low! Try again.\n";
        } else {
            cout << "Congratulations! You guessed the correct number.\n";
        }

    } while (guess != number);

    return 0;
}