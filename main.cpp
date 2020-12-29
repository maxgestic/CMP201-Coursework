#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void print(std::vector<string> const &input)
{
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}

int bm(){

    //boyer-moore function

    string data, pattern, current, check_data;
    int pattern_position = 0, data_position = 0;

    //debug values
    data = "the quick brown fox jumps over the lazy dog";
    pattern = "fox jumps";

    int pattern_size = pattern.size();
   // cout << endl << "Size=" << pattern_size << endl;
    vector<string> pattern_array(pattern_size);



    data_position = pattern_size - 1;

    for (int x = 0; x < pattern_size; x++){

        // adding each letter of pattern to array
        pattern_array[x] = (pattern.at(x));
        //cout << endl << "Current Array is ";
        //print(pattern_array);
        //cout << endl;

    }

    while (true){

        if (data_position > data.size()){

            cout << endl << "Search term not in data" << endl;

            return 0;

        }

        current = data.at(data_position);

        int c = pattern_size;

        for(int x = 0; x < pattern_size; x++ ){

            cout << endl << "Checking " << pattern_array[x] << " Against " << current << endl;

            if (pattern_array[x] != current){

                c--;

            }

        }

        cout << endl << "C=" << c << endl;

        if (c == 0){

            cout << "No pattern found";

            data_position = data_position + pattern_size;
            //cout << endl << "New data p=" << data_position << endl;
        }
        else{

            cout << "Letter matched";

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

                    cout << endl << "Checking " << pattern_array[n] << " Against " << check_data << endl;

                    if ( check_data == pattern_array[n]){

                        cout << endl << "Matching letter" << endl;

                        check_v++;

                        data_position++;

                    }
                    else{

                        cout << endl << "Letter no match breaking for loop" << endl;

                        break;

                    }

                }

                if (check_v == pattern_size){

                    cout << endl << "Word has been found at index " << data_position-pattern_size << endl;
                    return 0;

                }

        }

    }

    return 0;

}

int rk(){

    //rabin-karp function
    return 0;

}

int run_both(){

    //initialising running both algorithms one after another testing performance
    return 0;

}

int run_boyer(){

    //initialising running just boyer moore and measuring performance

    bm();

    return 0;

}

int run_rabin(){

    //initialising running just rabin karp and measuring performance
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

            //run_rabin();
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