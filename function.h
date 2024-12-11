#include <iostream>

#include <vector>
#include <string>
#include <fstream>

using namespace std;

ifstream file_in;
ofstream file_out;

string remove_non_alpha(string s)
{

    int j;

    for (int i = 0; i < s.size(); i++)
    {
        // locate non alphabet character can remove it
        if ((s[i] >= 'A' && s[i] <= 'Z') || // loop to check if the character ASCII number is somewhere between A -> Z
            (s[i] >= 'a' && s[i] <= 'z'))   // '||' is use to return true if only the both statement is true
        {
            s[j] = s[i];
            j++;
        }
    }
    //  return the non special character string by using the locater j
    return s.substr(0, j);
}

void open_file(string s)
{

    stringstream ss(s);
    string word;
    string file_name;
    while (ss >> word)
    {
        if (word.find('CREATE') != string::npos) // skipping the 'create' letter for retrieving the file name behind of it
        {
        }
        else
        {
            file_name = word;
            cout << file_name << endl;
            file_out.open(file_name);
        }
    }
}

void create_database()
{

    cout << "creating databases" << endl;
}

void create_table(string s)
{

    stringstream ss(s);
    bool keyword_checked = false;

    string word;
    string table_name;
    string keys;
    vector<string> header_key;
    vector<string> data_type;

    while (ss >> word) // loop through every word of the command itself
    {

        if (word.find('CREATE') != string::npos) // ignore and passes create
        {
        }
        else if (word.find('TABLE') != string::npos) // ignore and  passes table
        {
        }
        else
        {
            keyword_checked = true;
        }

        if (keyword_checked == true)
        {
            table_name = word;
            cout << remove_non_alpha(table_name) << " is created" << endl; // output the table name after removing unecessary symbol
            break;
        }
    }
    while (ss >> word)
    {
        if (word.find('INT') != string::npos)
        {
        }
        else if (word.find('TEXT') != string::npos)
        {
        }
        else
        {
            header_key.push_back(word); // adding the pure key into the header vector
        }
    }

    for (string i : header_key) // checking the header vector
    {

        cout << i << " ";
    }
}