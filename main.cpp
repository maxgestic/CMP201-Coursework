#include <iostream>
#include <string>

using namespace std;

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

            //run_boyer();
            cout << "Run boyer";

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