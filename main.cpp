#include <iostream>
#include "tree.hh"
#include <string>

using namespace std;

void dfs_start(){

    string x1, y1, x2, y2;

    cout << endl;
    cout << "Please enter the starting coordinates." << endl << "Please enter the starting X coordinate: ";
    cin >> x1;
    cout << endl << "Please enter the starting Y coordinate: ";
    cin >> y1;

    cout << endl;
    cout << "Please enter the end coordinates." << endl << "Please enter the end X coordinate: ";
    cin >> x2;
    cout << endl << "Please enter the end Y coordinate: ";
    cin >> y2;

    cout << "Coords are: (" << x1 << "," << y1 << ") and (" << x2 << "," << y2 << ")";

    return;

}


int main() {

    int menu_choice;

    cout << "Please choose from the following: ";
    cin >> menu_choice;


    if (menu_choice == 1){

        dfs_start();

    }

    return 0;

}