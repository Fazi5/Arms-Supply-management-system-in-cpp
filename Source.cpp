#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include"Product.h"
#include"Shipment.h"
#include"Officer.h"
using namespace std;
void Mainmenu();
int main() {
    while (true) {
        Mainmenu();
    }
	return 0;
}
void Mainmenu(){
        cout << "\n<----------ARMS SUPPLY MANAGMENT SYSTEM.---------->\n";
        cout << "<-----MAIN___MENU----->\n";
        cout << "1.Product Info.\n2.Shipments Info.\n3.Officer Info.\n4.Exit menu.\n";
        
        
        
        int options;
        cin >> options;

        switch (options) {
        case 1:
            Productmenu();
            break;
        case 2:
	        Shipmentmenu();
            break;
        case 3:
            Officermenu();
            break;
        case 4:
            exit(1);
        default:
            cout << "Invalid Option! Try again.\n";
            break;
        }
    
}