#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <streambuf>

using namespace std;


const unsigned PRIME_BASE = 257;
const unsigned PRIME_MOD = 1000000007;

unsigned lhash(const string& s)
{
    unsigned ret = 0;
    for (int i = 0; i < s.size(); i++)
    {
        ret *= PRIME_BASE; //shift over by one
        ret += s[i]; //add the current char
    }
    return ret;
}

void print(vector<string> const &input)
{
    for (int i = 0; i < input.size(); i++) {
        cout << input.at(i) << ' ';
    }
}

void print(vector<int> const &input)
{
    for (int i = 0; i < input.size(); i++) {
        cout << input.at(i) << " ";
    }
}

int bm(string data, string pattern){

    //boyer-moore function

    string current, check_data;
    int data_position = 0;

    //debug values
//    data = "fox the quick brown foxfox jumps fox over the lazy fox";
//    pattern = "fox";

    int pattern_size = pattern.size();
   //cout << endl << "Size=" << pattern_size << endl;
    vector<string> pattern_array(pattern_size);
    vector<int> indexes;



    data_position = pattern_size - 1;

    for (int x = 0; x < pattern_size; x++){

        // adding each letter of pattern to array
        pattern_array[x] = (pattern.at(x));
        //cout << endl << "Current Array is ";
        //print(pattern_array);
        //cout << endl;

    }

    while (true){

        //cout << data_position;

        if (data_position >= data.size()){

            cout << endl << "Reached end of data!" << endl;
            cout << endl << "The amount of patterns found: " << indexes.size() << endl;
            cout << endl << "Pattern was found at these indexes: " << endl;
            print(indexes);
            cout << endl;

            return 0;

        }

        current = data.at(data_position);

        int c = pattern_size;

        for(int x = 0; x < pattern_size; x++ ){

//            cout << endl << "Checking " << pattern_array[x] << " Against " << current << endl;

            if (pattern_array[x] != current){

                c--;

            }

        }

//        cout << endl << "C=" << c << endl;

        if (c == 0){

//            cout << "No pattern found";

            data_position = data_position + pattern_size;
            //cout << endl << "New data p=" << data_position << endl;
        }
        else{

//            cout << "Letter matched";

                //check what position the matched letter is in in the pattern

                int pos;

                for (pos = 0; pos < pattern_size; pos++){

                    if(pattern_array[pos] == current){

                        break;

                    }

                }

                //jump back by pos and check if its the word

            data_position = data_position - pos;

                int check_v = 0;

                for (int n = 0; n < pattern_size; n++){

                    check_data = data.at(data_position);

//                    cout << endl << "Checking " << pattern_array[n] << " Against " << check_data << endl;

                    if ( check_data == pattern_array[n]){

//                        cout << endl << "Matching letter" << endl;

                        check_v++;

                        data_position++;

                    }
                    else{

//                      cout << endl << "Letter no match breaking for loop" << endl;

                        data_position = data_position + pattern_size + 1;

                        break;

                    }

                }

                if (check_v == pattern_size){

//                    cout << endl << "Word has been found at index " << data_position-pattern_size << endl;
                    indexes.push_back(data_position-pattern_size);

                }

        }

    }

    return 0;

}

int rk(){

//    cout << endl;
//
//    cout << data;
//
//    cout << endl;
//
//    cout << pattern;
//
//    cout << endl;


    string current, check_data;
    //debug values
    string data = "The Quick Brown Fox Jumps Over The Lazy Dog";
    string pattern = "The";

    int pattern_size = pattern.size();
    unsigned int pattern_hash = lhash(pattern);
    int data_beg = 0, data_end = pattern_size - 1;

    cout << endl << "Size=" << pattern_size << endl;
    vector<string> pattern_array(pattern_size);
    vector<int> indexes;

    long long power = 1;
    for (int i = 0; i < pattern_size; i++)
        power = (power * PRIME_BASE) % PRIME_MOD;


    for (int x = 0; x < pattern_size; x++){

        // adding each letter of pattern to array
        pattern_array[x] = (pattern.at(x));
        //cout << endl << "Current Array is ";
        //print(pattern_array);
        //cout << endl;

    }

    cout << data.substr(0, pattern_size);

    unsigned int data_hash = lhash(data.substr(0, pattern_size));

    cout << "Hashes are " << data_hash << ", " << pattern_hash << endl;

    while (true){

        if (data_hash == pattern_hash){

            //cout << "match found"<< endl;
            indexes.push_back(data_beg);

        }
        else{

            //cout << "no match found next position"<< endl;

        }


        data_end++;

        data_hash = data_hash*PRIME_BASE + data[data_end];
        data_hash %= PRIME_MOD;


        data_hash -= power * data[data_beg] % PRIME_MOD;
        if (data_hash < 0) //negative can be made positive with mod
            data_hash += PRIME_MOD;

        data_beg++;

        if (data_end == data.size() - 1){

            cout << "Reached end of Data, " << indexes.size() << " instances of pattern found. Index locations are:" << endl;

            print(indexes);

            cout << endl;

            return 0;

        }

    }

}

int run_both(){

    //initialising running both algorithms one after another testing performance
    return 0;

}

int run_boyer(){

    string data, pattern, filename;

    cout << endl << "Please enter the file name: ";
    cin >> filename;
    cout << endl;
    cout << endl << "Please enter the search string: ";
    cin >> pattern;
    cout << endl;

    ifstream f(filename);

    f.seekg(0, ios::end);
    data.reserve(f.tellg());
    f.seekg(0, ios::beg);

    data.assign((istreambuf_iterator<char>(f)),istreambuf_iterator<char>());

    //cout << data;

    bm(data, pattern);

    return 0;

}

int run_rabin(){

    //initialising running just rabin karp and measuring performance

//    string data, pattern, filename;
//
//    cout << endl << "Please enter the file name: ";
//    cin >> filename;
//    cout << endl;
//    cout << endl << "Please enter the search string: ";
//    cin >> pattern;
//    cout << endl;
//
//    ifstream f(filename);
//
//    f.seekg(0, ios::end);
//    data.reserve(f.tellg());
//    f.seekg(0, ios::beg);
//
//    data.assign((istreambuf_iterator<char>(f)),istreambuf_iterator<char>());

    //cout << data;

    //rk(data, pattern);
    rk();

    return 0;

}

int main() {

    int menu_choice;
    bool chosen = false;

    while (true){

        cout << "Please choose from the following: ";
        cin >> menu_choice;


        if (menu_choice == 1){

            //run_both();
            cout << "Run both";


        }

        else if (menu_choice == 2){

            cout << "Run boyer";
            run_boyer();

        }

        else if (menu_choice == 3){

            run_rabin();
            cout << "Run rabin";

        }

        else if (menu_choice == 4){

            //Quit Program
            return 0;

        }

        else{

            cout << "Invalid Option! Please try again!";
            cout << endl;

        }



    }


}