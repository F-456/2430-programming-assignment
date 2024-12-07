#include <iostream>

#include <vector>
#include <string>
using namespace std;

void reading()
{
    string name;
    int length;
    cout << "Enter your name: " << endl;

    getline(cin, name);
    cout << "The length of your name is " << name
         << endl;
}

void create_database()
{
}