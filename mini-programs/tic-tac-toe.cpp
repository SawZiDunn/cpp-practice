#include<iostream>
#include <ctime> // For time()
#include <cstdlib> // For rand() and srand()

using namespace std;

void draw_board(char *numbers); // char numbers[]
void user_input(char *numbers, char user);
void computer_input(char *numbers, char computer);
bool check_win_condition(char *numbers, char user, char computer);
bool check_tie(char *numbers);

int main() {

    char numbers[9] = {};
    // filling all elements with ' ' 
    fill(numbers, numbers + 9, ' ');
    draw_board(numbers);
    char user = 'X';
    char computer = 'O';

    while (true) {
        
        
        user_input(numbers, user);
        if (check_win_condition(numbers, user, computer)) {
            break;
        }
        
        if (check_tie(numbers)) {
            break;
        }

        computer_input(numbers, computer);
        if (check_win_condition(numbers, user, computer)) {
            break;
        }
        
        if (check_tie(numbers)) {
            break;
        }
        
        

    }

    return 0;
}

void user_input(char *numbers, char user) {
    int index;
    while (true) {
        cout << "Enter your position (1-9): ";
        cin >> index;

        if (index < 1 || index > 9) {
            cout << "Position must be from 1 to 9!" << endl;
            continue;
        }
        // if it's not already taken
        if (numbers[index - 1] == ' ') {
            numbers[index - 1] = user;
            break;
        }
        else {
            cout << "Position already taken. Try again!" << endl;
        }
    }
    draw_board(numbers);
    
}

void computer_input(char *numbers, char computer) {
    srand(static_cast<unsigned>time(0)); // should be only once inside main function
    while (true) {
        int index = rand() % 9;
        if (numbers[index] == ' ') {
            numbers[index] = computer;
            break;
        }
        
    }
    draw_board(numbers);
 }

 bool check_win_condition(char *numbers, char user, char player) {
    if (numbers[0] != ' ' && numbers[0] == numbers[1] && numbers[1] == numbers[2]) {
        numbers[0] == user ? cout << "You win!" << endl : cout << "You lose!" << endl;
    }
    else if (numbers[3] != ' ' && numbers[3] == numbers[4] && numbers[4] == numbers[5]) {
        numbers[3] == user ? cout << "You win!" << endl : cout << "You lose!" << endl;
    }
    else if (numbers[6] != ' ' && numbers[6] == numbers[7] && numbers[7] == numbers[8]) {
        numbers[6] == user ? cout << "You win!" << endl : cout << "You lose!" << endl;
    }
    else if (numbers[0] != ' ' && numbers[0] == numbers[3] && numbers[3] == numbers[6]) {
        numbers[0] == user ? cout << "You win!" << endl : cout << "You lose!" << endl;
    }
    else if (numbers[1] != ' ' && numbers[1] == numbers[4] && numbers[4] == numbers[7]) {
        numbers[1] == user ? cout << "You win!" << endl : cout << "You lose!" << endl;
    }
    else if (numbers[2] != ' ' && numbers[2] == numbers[5] && numbers[5] == numbers[8]) {
        numbers[2] == user ? cout << "You win!" << endl : cout << "You lose!" << endl;
    }
    else if (numbers[0] != ' ' && numbers[0] == numbers[4] && numbers[4] == numbers[8]) {
        numbers[0] == user ? cout << "You win!" << endl : cout << "You lose!" << endl;
    }
    else if (numbers[2] != ' ' && numbers[2] == numbers[4] && numbers[4] == numbers[6]) {
        numbers[2] == user ? cout << "You win!" << endl : cout << "You lose!" << endl;
    }
    else {
        // if win condition is not met yet
        return false;
    }

    // if someone wins
    return true;
 }


void draw_board(char *numbers) {
    cout << '\n';
    cout << "     |     |     " << endl;
    cout << "  " << numbers[0] << "  |  " << numbers[1] << "  |  " << numbers[2] << endl;
    cout << "_____|_____|_____" << endl;

    cout << "     |     |     " << endl;
    cout << "  " << numbers[3] << "  |  " << numbers[4] << "  |  " << numbers[5] << endl;
    cout << "_____|_____|_____" << endl;

    cout << "     |     |     " << endl;
    cout << "  " << numbers[6] << "  |  " << numbers[7] << "  |  " << numbers[8] << endl;
    cout << "     |     |     " << endl;
    cout << '\n';

}

bool check_tie(char *numbers) {
    for (auto i = 0; i < 9; i++) {
        if (numbers[i] == ' ') {
            return false;
        }
    }
    cout << "It's a tie!" << endl;
    return true;
}