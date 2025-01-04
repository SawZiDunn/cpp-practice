#include<iostream>
#include<string>

using namespace std;

char computer_generate();
char get_user_choice();
void show_choice(char x, string option_type);
string calculate_result(char user_choice, char computer_choice);


int main() {
    char user_choice = get_user_choice();
    show_choice(user_choice, "User Choice");

    char computer_generated_input = computer_generate();
    show_choice(computer_generated_input, "Computer Choice");

    string result = calculate_result(user_choice, computer_generated_input);
    cout << result << endl;
    return 0;
}


string calculate_result(char user_choice, char computer_choice) {
    string result;

    switch (user_choice) {
        case 'r':
            if (computer_choice == 'p') {
                result = "You lose.";
            }
            else if (computer_choice == 's') {
                result = "You win";
            } else {
                result = "Draw";
            }

            break;
        case 'p':
            if (computer_choice == 'r') {
                result = "You win.";
            }
            else if (computer_choice == 's') {
                result = "You lose";
            } else {
                result = "Draw";
            }
            break;
        case 's':
            if (computer_choice == 'p') {
                    result = "You win.";
                }
                else if (computer_choice == 'r') {
                    result = "You lose";
                } else {
                    result = "Draw";
                }
            break;
    }

    return result;



}

char get_user_choice() {
    char choice;

    do {
        cout << "***************************\n";
        cout << "'r' for Rock\n'p' for Paper\n's' for Scissors\n";
        cout << "Your Choice: ";
        cin >> choice;
        choice = tolower(choice);

    } while (choice != 'r' && choice != 'p' && choice != 's');

    return choice;
}

char computer_generate() {
    srand(time(0));
    int option = (rand() % 3) + 1;

    switch (option) {
        case 1:
            return 'r';
        
        case 2:
            return 'p';
        
        case 3:
            return 's';
    }
    
    return 0;
}

void show_choice(char x, string option_type) {
    switch (x) {
        case 'r':
            cout << option_type + ": Rock" << endl;
            break;
        case 'p':
            cout << option_type + ": Paper" << endl;
            break;
        case 's':
            cout << option_type + ": Scissors" << endl;
            break;
    }
}