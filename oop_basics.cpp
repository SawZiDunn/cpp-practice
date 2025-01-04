#include <iostream>

using namespace std;

class Bank{
public:
    explicit Bank(string user_name, string email, string password): user_name(user_name), user_email(email), user_password{password} {
        // setter(name, email, password);
        // we can use this keyword if we use the same parameter name and attribute name
        // this -> user_name = user_name;
        
    }

    void setter(string name, string email, string password){
        
        user_name = name;
        user_email = email;
        user_password = password;
    }

    string get_username() const{
        return user_name;

    }

    string get_email() const{
        return user_email;

    }

private:
    string user_name;
    string user_email;
    string user_password;

protected:
};

int main(){
    // classic constructor syntac
    // Bank bank("saw", "s@gmail.com", "123");
    // concise, modern style, introduced in cpp 11
    Bank bank{"saw", "s@gmail.com", "123"};
    // or
    // Bank bank = {"saw", "s@gmail.com", "123"}; // if we use explicit keyword, we can't initialize an obj like this.
  
    cout << bank.get_email() << endl;
    cout << bank.get_username() << endl;
    
    

    return 0;
}
