#include <iostream>
#include <fstream>
#include<string>
#include<iomanip>
using namespace std;

const int MAX_SHIPMENTS = 20;
int numShipments = 0;
struct Shipment {
    int id;
    string name,from, to;
}Shipments[MAX_SHIPMENTS],temp_shipment[MAX_SHIPMENTS];
void addShipment() {
    cout << setw(10) << "----------" << setw(10) << endl;
    cout << setw(10) << "Adding Shipment\n";
    cout << setw(10) << "----------" << setw(10) << endl;
    if (numShipments < MAX_SHIPMENTS) {
        Shipment newShipment;

        
        cout << "Enter Shipment ID: ";
        cin >> newShipment.id;

        cin.ignore();
        cout << "Enter Shipment name: ";
        getline(cin, newShipment.name);

        cout << "Enter Where is Shipment from: ";
        getline(cin, newShipment.from);

        cout << "Enter Where is Shipment Headed to: ";
        getline(cin, newShipment.to);

        Shipments[numShipments] = newShipment;
        numShipments++;
        cout << setw(10) << "----------" << setw(10) << endl;
        cout << "Shipment added successfully!\n";
        cout << endl;
    }
    else {
        cout << setw(10) << "----------" << setw(10) << endl;
        cout << "Cannot add more Shipments. Maximum limit reached.\n";
        cout << endl;
    }
}

void viewShipments() {
    cout << setw(10) << "----------" << setw(10) << endl;
    cout << "Viewing The Existing Shipment\n";
    cout << setw(10) << "----------" << setw(10) << endl;
    if (numShipments > 0) {
        cout << "Shipment List:\n";
        cout << "-Shipment ID-" << setw(10) << "-Shipment Name-" << setw(10) << "-Shipment from-" << setw(10) << "-Shipment to-" << endl;
        for (int i = 0; i < numShipments; i++) {
            cout << Shipments[i].id << setw(20) << Shipments[i].name << setw(20) << Shipments[i].from << setw(20) << Shipments[i].to << endl;
        }
    }
    else {
        cout << "No Shipments available.\n";
    }
}



int searchShipment(int searchId) {
    for (int i = 0; i < numShipments; i++) {
        if (Shipments[i].id == searchId) {
            return i;
        }
    }
    return -1;
}

void searchAndDisplayShipment() {
    cout << setw(10) << "----------" << setw(10) << endl;
    cout << "Searching The Existing Shipment\n";
    cout << setw(10) << "----------" << setw(10) << endl;
    int searchId;
    cout << "Enter Shipment ID to search: ";
    cin >> searchId;

    int find = searchShipment(searchId);
    if (find != -1) {
        cout << "Shipment found in Program at Entry no " << find << ":\n";
        cout << "-Shipment ID-" << setw(10) << "-Shipment Name-" << setw(10) << "-Shipment from-" << setw(10) << "-Shipment to-" << endl;
        cout << Shipments[find].id << setw(20) << Shipments[find].name << setw(20) << Shipments[find].from << setw(20) << Shipments[find].to << endl;
        cout << setw(10) << "----------" << setw(10) << endl;
        cout << "Shipment found Successfully.\n";
        cout << endl;
    }
    else {
        cout << setw(10) << "----------" << setw(10) << endl;
        cout << "Shipment not found.\n";
        cout << endl;
    }
}

void updateShipment() {
    cout << setw(10) << "----------" << setw(10) << endl;
    cout << "Updating The Exsiting Shipment\n";
    cout << setw(10) << "----------" << setw(10) << endl;
    int searchId;
    cout << "Enter Shipment ID to update: ";
    cin >> searchId;

    int find = searchShipment(searchId);
    if (find != -1) {

        cin.ignore();

        cout << "Enter new Shipment name: ";
        getline(cin, Shipments[find].name);

        cout << "Enter new Shipment from: ";
        getline(cin, Shipments[find].from);

        cout << "Enter new Shipment to: ";
        cin >> Shipments[find].to;

        cout << setw(10) << "----------" << setw(10) << endl;
        cout << "Shipment updated successfully!\n";
        cout << endl;
    }
    else {
        cout << setw(10) << "----------" << setw(10) << endl;
        cout << "Shipment not found.\n";
        cout << endl;
    }
}

void deleteShipment() {
    cout << "     " << "----------" << "     " << endl;
    cout << "Deleting Shipment Entery\n";
    cout << "     " << "----------" << "     " << endl;
    int searchId;
    cout << "Enter Shipment ID to delete: \n";
    cin >> searchId;

    int find = searchShipment(searchId);
    if (find != -1) {
        // Delete Shipment by shifting elements
        for (int i = find; i < numShipments - 1; i++) {
            Shipments[i] = Shipments[i + 1];
        }
        numShipments--;

        cout << setw(10) << "----------" << setw(10) << endl;
        cout << "Shipment deleted successfully!\n";
        cout << endl;
    }
    else {
        cout << setw(10) << "----------" << setw(10) << endl;
        cout << "Shipment not found.\n";
        cout << endl;
    }
}

void storeShipmentsToFile() {
    ofstream fout("Shipmention.txt");
    if (!fout.is_open()) {
        cerr << "Error opening file\n";
        return;
    }

    for (int i = 0; i < numShipments; i++) {
        fout << Shipments[i].id << ' ' << Shipments[i].name << ' ' << Shipments[i].from << ' ' << Shipments[i].to << '\n';
    }

    cout << "Shipments stored to file successfully!\n";
}

void readShipmentsFromFile() {
    ifstream fin("Shipmention.txt");
    if (!fin.is_open()) {
        cerr << "Error opening file\n";
        return;
    }

    while (fin >> Shipments[numShipments].id >> Shipments[numShipments].name >> Shipments[numShipments].from >> Shipments[numShipments].to) {
        numShipments++;
        if (numShipments >= MAX_SHIPMENTS) {
            cerr << "Maximum limit reached. Some Shipments may not be loaded.\n";
            break;
        }
    }

    cout << "Shipments read from file successfully!\n";
}
void temp_readShipmentsFromFile() {
    ifstream fin("Shipmention.txt");
    if (!fin.is_open()) {
        cerr << "Error opening file\n";
        return;
    }

    while (fin >> temp_shipment[numShipments].id >> temp_shipment[numShipments].name >> temp_shipment[numShipments].from >> temp_shipment[numShipments].to) {
        numShipments++;
        if (numShipments >= MAX_SHIPMENTS) {
            cerr << "Maximum limit reached. Some Shipments may not be loaded.\n";
            break;
        }
    }

    cout << "Shipments read from file successfully!\n";
}

void Shipmentmenu() {

    
    readShipmentsFromFile();
    int choice;
    do {
        cout << setw(10) << "----------" << setw(10) << endl;
        cout << "----------Shipment_Menu----------\n";
        cout << setw(10) << "----------" << setw(10) << endl;
        cout << "----------" << setw(10) << "----------" << endl;
        cout << "1.Add Shipment \n2.View Shipment\n3.Search Shipment\n4.Update Shipment\n5.Delete Shipment\n6.Exit Menu\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice) {
        case 1:
            addShipment();
            break;
        case 2:
            viewShipments();
            break;
        case 3:
            searchAndDisplayShipment();
            break;
        case 4:
            updateShipment();
            break;
        case 5:
            deleteShipment();
            break;
        case 6:
            // Store Shipments to file before exiting
            storeShipmentsToFile();
            cout << setw(10) << "----------" << setw(10) << endl;
            cout << "Exiting the program.\n";
            cout << setw(10) << "----------" << setw(10) << endl;
            break;
        default:
            cout << setw(10) << "----------" << setw(10) << endl;
            cout << "Invalid choice. Try again.\n";
            cout << setw(10) << "----------" << setw(10) << endl;
        }
    } while (choice != 6);
}