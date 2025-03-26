#include <iostream>
using namespace std;

int main() {
    // Example of unformatted output using write
    char buffer[] = "HAPPY BIRTHDAY";
    cout.write(buffer, 10);  		// Outputs the first 10 bytes of buffer
    // This will output "HAPPY BIRT"
    return 0;
}
