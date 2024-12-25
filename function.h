#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <set>

using namespace std;

ifstream file_in;
ofstream file_out;

class variable
{

public:
};

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

string create_table(string s)
{

    stringstream ss(s);
    bool keyword_checked = false;
    string word;
    string table_name;

    vector<string> header_key;

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
            header_key.push_back(word); // adding all the key into the header vector
        }
    }

    for (string i : header_key) // checking the header vector
    {

        // cout << i << " ";
    }

    return table_name;
}

void insert_record(string s, string table_name)
{

    vector<string> v1; // 10 vector as column to store data
    vector<string> v2;
    vector<string> v3;
    vector<string> v4;
    vector<string> v5;
    vector<string> v6;
    vector<string> v7;
    vector<string> v8;
    vector<string> v9;
    vector<string> v10;

    string word;
    stringstream ss(s);
    string elements;
    int sequence = 0;

    while (ss >> word)
    {
        if (word.find('INSERT') != string::npos || word.find('INTO') != string::npos) // passes insert or into
        {
        }

        else if (word.find('VALUES') != string::npos) // passes values

        {
        }

        else if (word.find(table_name) != string::npos) // passes table name
        {
        }
        else
        {
            // removing unwanted parenthesis in both side of the string
            elements = word.substr(1, word.size() - 2);
            cout << "The record are " << elements << endl;

            vector<string> record;
            string temp;
            istringstream stream(elements);

            while (getline(stream, temp, ',')) // while loop to form a usable vector which include all the data
            {
                // Remove the single quotes
                if (temp.front() == '\'')
                {
                    temp = temp.substr(1, temp.size() - 2);
                }
                record.push_back(temp);
            }

            int size = record.size(); // size of how many keys

            for (int i = 0; i < size; i++) // loop through all the data vector and insert the data into them
            {
                if (i == 0) // insert into first column
                {
                    v1.push_back(record[0]);
                }
                else if (i == 1) // insert into second column
                {
                    v2.push_back(record[1]);
                }
                else if (i == 2)
                {
                    v3.push_back(record[2]);
                }
                else if (i == 3)
                {
                    v4.push_back(record[3]);
                }
                else if (i == 4)
                {
                    v5.push_back(record[4]);
                }
                else if (i == 5)
                {
                    v6.push_back(record[5]);
                }
                else if (i == 6)
                {
                    v7.push_back(record[6]);
                }
                else if (i == 7)
                {
                    v8.push_back(record[7]);
                }
                else if (i == 8)
                {
                    v9.push_back(record[8]);
                }
                else if (i == 9)
                {
                    v10.push_back(record[9]);
                }
            }
        }
    }
}

void select_record(const string &command, const string &table_name, const vector<string> &headers, const vector<vector<string>> &records)
{
    string select_item, where_item;
    bool is_distinct = false;

    if (command.find("*") != string::npos)
    {
        cout << "Results:" << endl;

        for (const auto &header : headers)
        {
            cout << header << "\t";
        }
        cout << endl;

        // Print records
        for (const auto &record : records)
        {
            for (const auto &value : record)
            {
                cout << value << "\t";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "SELECT command not fully implemented." << endl;
    }

    if (command.find("DISTINCT") != string::npos)
    {
        is_distinct = true;
    }

    size_t where_pos = command.find("WHERE");
    if (where_pos != string::npos)
    {
        select_item = command.substr(0, where_pos);
        where_item = command.substr(where_pos + 6); // skip "WHERE" (skip 6 characters including space)
    }
    else
    {
        select_item = command;
    }

    // determine the columns to select
    vector<string> columns_to_select;
    size_t from_pos = select_item.find("FROM");
    if (from_pos != string::npos)
    {
        string columns_part = select_item.substr(7, from_pos - 7); // start at 7, skip "SELECT" which is 7 char long
        stringstream ss(columns_part);
        string column;
        while (getline(ss, column, ','))
        {
            columns_to_select.push_back(column);
        }
    }

    if (columns_to_select.size() == 1 && columns_to_select[0].find("*") != string::npos)
    {
        columns_to_select = headers;
    }

    // filter the record based on "WHERE"
    vector<vector<string>> filtered_records;
    for (const auto &record : records)
    {
        if (!where_item.empty())
        {
            stringstream ss(where_item);
            string column, condition, value;

            getline(ss, column, ' ');
            ss >> condition;
            getline(ss, value);

            if (value.front() == '\'')
            {
                value = value.substr(1, value.size() - 2);
            }

            auto col_it = find(headers.begin(), headers.end(), column);
            if (col_it == headers.end())
            {
                cerr << "Column " << column << " not found in headers." << endl;
                return;
            }
            size_t col_index = distance(headers.begin(), col_it);

            bool condition_met = false;
            if (condition == "=")
            {
                condition_met = (record[col_index] == value);
            }
            else if (condition == "!=")
            {
                condition_met = (record[col_index] != value);
            }

            if (condition_met)
            {
                filtered_records.push_back(record);
            }
            else
            {
                filtered_records.push_back(record);
            }
        }
    }
    set<vector<string>> distinct_records;
    if (is_distinct)
    {
        for (const auto &record : filtered_records)
        {
            vector<string> selected_values;
            for (const auto &column : columns_to_select)
            {
                auto col_it = find(headers.begin(), headers.end(), column);
                if (col_it == headers.end())
                {
                    cerr << "Column " << column << " not found in headers." << endl;
                    return;
                }
                size_t col_index = distance(headers.begin(), col_it);
                selected_values.push_back(record[col_index]);
            }
            distinct_records.insert(selected_values);
        }
    }

    cout << "Results : " << endl;
    if (is_distinct)
    {
        for (const auto &record : distinct_records)
        {
            for (const auto &value : record)
            {
                cout << value << "\t";
            }
            cout << endl;
        }
    }
    else
    {
        for (const auto &record : filtered_records)
        {
            for (const auto &column : columns_to_select)
            {
                auto col_it = find(headers.begin(), headers.end(), column);
                if (col_it == headers.end())
                {
                    cerr << "Column " << column << " not found in headers." << endl;
                    return;
                }
                size_t col_index = distance(headers.begin(), col_it);
                cout << record[col_index] << "\t";
            }
            cout << endl;
        }
    }
}
