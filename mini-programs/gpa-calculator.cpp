#include <iostream>
using namespace std;

float grade_to_score(string grade);

int main() {
    int count;
    cout << "Enter the number of subjects: ";
    cin >> count;
    int total_credit;
    float total_credit_X_score;

    for (auto i = 0; i < count; i++) {
        string subject;
        string grade;
        float score;
        int credit;

        cout << "Enter the subject name: ";
        cin >> subject;

        cout << "How many credits: ";
        cin >> credit;
        total_credit += credit;

        cout << "Grade: ";
        cin >> grade;
        score = grade_to_score(grade);
        total_credit_X_score += credit * score;
        }

    cout << "Total GPA: " << total_credit_X_score / total_credit;

    return 0;
}

float grade_to_score(string grade) {
    if (grade == "A") {
        return 4.0;
    } else if (grade.compare("B+")) {
        return 3.5;

    } else if (grade.compare("B")) {
        return 3.0;
    } else if (grade.compare("C+")) {
        return 2.5;
    } else if (grade.compare("C")) {
        return 2.0;
    } else if (grade.compare("D")) {
        return 1.5;
    } else if (grade.compare("D")) {
        return 1.0;
    } else if (grade.compare("F")) {
        return 0.5;
    } else {
        return 0;
    }

}