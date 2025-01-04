#include<iostream>
using namespace std;

int main(){
    string names[] = {"name0", "name1", "name2", "name3"};
    // storing the reference of the array to a pointer
    // no need to use & since array is already a reference, not like int and string
    string *pNames = names;
    cout << pNames << endl;
    
    return 0;
}