#include <iostream>
#include <random>
#include <iomanip> // for std::setw

int main() {
    const int numRolls = 600000000;
    const int numSides = 6;       // Number of sides on the die

    // Frequency array to count the occurrences of each face
    int frequencies[numSides] = {0}; //Initializes all elements to 0

    srand(time(0));

    // Roll the die and count the frequencies
    for (int i = 0; i < numRolls; ++i) {
        // int roll = distribution(generator);
        int roll = (rand() % 6) + 1;
        frequencies[roll - 1]++; // Increment the frequency for the rolled face
    }

    // Output the results
    std::cout << "Face\tFrequency\n";
    for (int i = 0; i < numSides; ++i) {
        std::cout << (i + 1) << "\t" << frequencies[i] << '\n';
    }

    return 0;
}
