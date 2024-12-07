// *********************************************************
// Program: TC3L_G06_main.cpp
// Course: CCP6114 Programming Fundamentals
// Lecture Class: TC3L
// Tutorial Class: TT5L
// Trimester: 2430
// Member_1: ID | TIEW FU SIANG | TIEW.FU.SIANG@student.mmu.edu.my |010-3706933
// Member_2: ID | NAME | EMAIL | PHONE
// Member_3: ID | NAME | EMAIL | PHONE
// Member_4: ID | NAME | EMAIL | PHONE
// *********************************************************
// Task Distribution
// Member_1:
// Member_2:
// Member_3:
// Member_4:
// *********************************************************

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "function.h"

using namespace std;

int main()
{
    ifstream file;

    file.open("fileInput1.mdb.txt");
    // open the input file

    if (!file.is_open())
    {
        cerr << "The file cannot be opened ,please check the file name \n";
        // return error if the file name is incorrect
        return 1;
    }
    string command;
    string id;

    while (getline(file, command))
    {

        istringstream iss(command);
        while (iss >> id)
        {

            cout << id << endl; // listing all the command in terminal
        }
    }

    file.close();
    return 0;
}
