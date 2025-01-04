#include<iostream>

using namespace std;
void bubble_sort(int numbers[], int size);

int main() {
    int numbers[] = {5, 4, 3, 2, 1};
    int size = sizeof(numbers) / sizeof(int);
    bubble_sort(numbers, size);
    
    for (int i : numbers) {
        cout << i << endl;
    }
    
}

void bubble_sort(int numbers[], int size) {
    int count = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
            count ++;

            
        }
    }

    cout << "looping count: " << count << endl;


}