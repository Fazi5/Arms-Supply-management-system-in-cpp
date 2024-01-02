#include <iostream>
#include <fstream>
#include<string>
#include<iomanip>
#include"Product.h"
#include"Shipment.h"
using namespace std;

const int MAX_OFFICERS = 20;
int numOfficers = 0;
struct Officer {
    int id;
    string name;
    int productid, shipmentid;
    
}Officers[MAX_OFFICERS];
void addOfficer() {
    cout << setw(10) << "----------" << setw(10) << endl;
    cout << setw(10) << "Adding Officer Info\n";
    cout << setw(10) << "----------" << setw(10) << endl;
    if (numOfficers < MAX_OFFICERS) {
        Officer newOfficer;


        cout << "Enter Officer ID:\n";
        cin >> newOfficer.id;

        cin.ignore();
        cout << "Enter Officer name:\n";
        getline(cin, newOfficer.name);

        bool check = false;
        bool* checkproduct = &check;
        do {
            cout << "Enter Which Product's Production is the officer incharge of:\n ";
            cin >> newOfficer.productid;
            for (int i = 0;i < MAX_PRODUCTS;i++) {
                if (temp_products[i].id == newOfficer.productid) {
                    cout << "The Enterd Product of ID " << products[i].id << " Exsits in the record.\n";
                    *checkproduct = true;
                    
                }
                else {
                    cout << "Wrong Product info Entered! Try Again.\n";
                }
            }
        } while (*checkproduct);

        bool* checkshipment = &check;
        do {
            cout << "Enter Which of Shipment is the Officer incharge of: \n";
            cin >> newOfficer.shipmentid;
            for (int i = 0;i < MAX_SHIPMENTS;i++) {
                if (temp_shipment[i].id == newOfficer.productid) {
                    cout << "The Enterd Product of ID " << products[i].id << " Exsits in the record.\n";
                    *checkshipment = true;

                }
                else {
                    cout << "Wrong Product info Entered! Try Again.\n";
                }
            }
        } while (*checkshipment);
        Officers[numOfficers] = newOfficer;
        numOfficers++;
        cout << setw(10) << "----------" << setw(10) << endl;
        cout << "Officer added successfully!\n";
        cout << endl;
    }
    else {
        cout << setw(10) << "----------" << setw(10) << endl;
        cout << "Cannot add more Officers. Maximum limit reached.\n";
        cout << endl;
    }
}

void viewOfficers() {
    cout << setw(10) << "----------" << setw(10) << endl;
    cout << "Viewing The Existing Officer\n";
    cout << setw(10) << "----------" << setw(10) << endl;
    if (numOfficers > 0) {
        cout << "Officer List:\n";
        cout << "-Officer ID-" << setw(10) << "-Officer Name-" << setw(10) << "-Incharge_of_product-" << setw(10) << "-Incharge_of_shipment-" << endl;
        for (int i = 0; i < numOfficers; i++) {
            cout << Officers[i].id << setw(20) << Officers[i].name << setw(20) << Officers[i].productid << setw(20) << Officers[i].shipmentid << endl;
        }
    }
    else {
        cout << "No Officers available.\n";
    }
}



int searchOfficer(int searchId) {
    for (int i = 0; i < numOfficers; i++) {
        if (Officers[i].id == searchId) {
            return i;
        }
    }
    return -1;
}



void storeOfficersToFile() {
    ofstream file("Officerion.txt");
    if (!file.is_open()) {
        cerr << "Error opening file\n";
        return;
    }

    for (int i = 0; i < numOfficers; i++) {
        file << Officers[i].id << ' ' << Officers[i].name << ' ' << Officers[i].productid << ' ' << Officers[i].shipmentid<< '\n';
    }

    cout << "Officers stored to file successfully!\n";
}

void readOfficersFromFile() {
    ifstream file("Officerion.txt");
    if (!file.is_open()) {
        cerr << "Error opening file\n";
        return;
    }

    while (file >> Officers[numOfficers].id >> Officers[numOfficers].name >> Officers[numOfficers].productid>> Officers[numOfficers].shipmentid) {
        numOfficers++;
        if (numOfficers >= MAX_OFFICERS) {
            cerr << "Maximum limit reached. Some Officers may not be loaded.\n";
            break;
        }
    }

    cout << "Officers read from file successfully!\n";
}

void Officermenu() {
    temp_readProductsFromFile();
    temp_readShipmentsFromFile();
    readOfficersFromFile();

    int choice;
    do {
        cout << setw(10) << "----------" << setw(10) << endl;
        cout << "----------Officer_Menu----------\n";
        cout << setw(10) << "----------" << setw(10) << endl;
        cout << "----------" << setw(10) << "----------" << endl;
        cout << "1.Add Officer Details \n2.View Officer\n3.Exit Menu\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice) {
        case 1:
            addOfficer();
            break;
        case 2:
            viewOfficers();
            break;
        
        case 3:
            // Store Officers to file before exiting
            storeOfficersToFile();
            cout << setw(10) << "----------" << setw(10) << endl;
            cout << "Exiting the program.\n";
            cout << setw(10) << "----------" << setw(10) << endl;
            break;
        default:
            cout << setw(10) << "----------" << setw(10) << endl;
            cout << "Invalid choice. Try again.\n";
            cout << setw(10) << "----------" << setw(10) << endl;
        }
    } while (choice != 3);
}