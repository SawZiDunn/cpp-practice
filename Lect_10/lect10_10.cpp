#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "Number of arguments: " << argc << std::endl;

    if (argc > 1) {
        std::cout << "Your arguments were:" << std::endl;
        for (int i = 0; i < argc; i++) {  // Start from 1 to skip the program name
            std::cout << "- " << argv[i] << std::endl; 
        }
    }

    return 0; 
}
