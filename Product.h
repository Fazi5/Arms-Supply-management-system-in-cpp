#include <iostream>
#include <fstream>
#include<string>
#include<iomanip>
using namespace std;

const int MAX_PRODUCTS = 20;
    int numProducts = 0;
struct Product {
    int id;
    string name;
    string type;
    double amount;
}products[MAX_PRODUCTS],temp_products[MAX_PRODUCTS];
    void addProduct() {
        cout << setw(10) << "----------" << setw(10) << endl;
        cout <<setw(10)<<"Adding Product\n";
        cout << setw(10) << "----------" << setw(10) << endl;
        if (numProducts < MAX_PRODUCTS) {
            Product newProduct;

            cout << "Enter product ID: ";
            cin >> newProduct.id;

            cin.ignore(); 
            cout << "Enter product name: ";
            getline(cin, newProduct.name);

            cout << "Enter product type: ";
            getline(cin, newProduct.type);

            cout << "Enter product amount: ";
            cin >> newProduct.amount;

            
            products[numProducts] = newProduct;
            numProducts++;
            cout << setw(10) << "----------" << setw(10) << endl;
            cout << "Product added successfully!\n";
            cout << endl;
        }
        else {
            cout << setw(10) << "----------" << setw(10) << endl;
            cout << "Cannot add more products. Maximum limit reached.\n";
            cout << endl;
        }
    }

    void viewProducts(){
        cout << setw(10) << "----------" << setw(10) << endl;
        cout << "Viewing The Existing Product\n";
        cout << setw(10) << "----------" << setw(10) << endl;
        if (numProducts > 0) {
            cout << "Product List:\n";
            cout << "-Product ID-" << setw(10) << "-Product Name-" << setw(10) << "-Product Type-" << setw(10) << "-Product Amount-" << endl;
            for (int i = 0; i < numProducts; i++) {
                cout << products[i].id << setw(10) << products[i].name << setw(10) << products[i].type << setw(10) << products[i].amount << endl;
            }
        }
        else {
            cout << "No products available.\n";
        }
    }

   

    int searchProduct(int searchId){
        for (int i = 0; i < numProducts; i++) {
            if (products[i].id == searchId) {
                return i; 
            }
        }
        return -1; 
    }

    void searchAndDisplayProduct(){
        cout << setw(10) << "----------" << setw(10) << endl;
        cout << "Searching The Existing Product\n";
        cout << setw(10) << "----------" << setw(10) << endl;
        int searchId;
        cout << "Enter product ID to search: ";
        cin >> searchId;

        int find = searchProduct(searchId);
        if (find != -1) {
            cout << "Product found in Program at Entry no " << find << ":\n";
            cout << "-Product ID-" << setw(10) << "-Product Name-" << setw(10) << "-Product Type-" << setw(10) << "-Product Amount-" << endl;
            cout << products[find].id << setw(10) << products[find].name << setw(10) << products[find].type << setw(10) << products[find].amount << endl;
            cout << setw(10) << "----------" << setw(10) << endl;
            cout << "Product found Successfully.\n";
            cout << endl;
        }
        else {
            cout << setw(10) << "----------" << setw(10) << endl;
            cout << "Product not found.\n";
            cout << endl;
        }
    }

    void updateProduct() {
        cout << setw(10) << "----------" << setw(10) << endl;
        cout << "Updating The Exsiting Product\n";
        cout << setw(10) << "----------" << setw(10) << endl;
        int searchId;
        cout << "Enter product ID to update: ";
        cin >> searchId;

        int find = searchProduct(searchId);
        if (find != -1) {
            
            cin.ignore();
            
            cout << "Enter new product name: ";
            getline(cin, products[find].name);

            cout << "Enter new product type: ";
            getline(cin, products[find].type);

            cout << "Enter new product amount: ";
            cin >> products[find].amount;

            cout << setw(10) << "----------" << setw(10) << endl;
            cout << "Product updated successfully!\n";
            cout << endl;
        }
        else {
            cout << setw(10) << "----------" << setw(10) << endl;
            cout << "Product not found.\n";
            cout << endl;
        }
    }

    void deleteProduct() {
        cout << setw(10) << "----------" << setw(10) << endl;
        cout << "Deleting Product Entery\n";
        cout << setw(10) << "----------" << setw(10) << endl;
        int searchId;
        cout << "Enter product ID to delete: \n";
        cin >> searchId;

        int find = searchProduct(searchId);
        if (find != -1) {
            
            for (int i = find; i < numProducts - 1; i++) {
                products[i] = products[i + 1];
            }
            numProducts--;

            cout << setw(10) << "----------" << setw(10) << endl;
            cout << "Product deleted successfully!\n";
            cout << endl;
        }
        else {
            cout << setw(10) << "----------" << setw(10) << endl;
            cout << "Product not found.\n";
            cout << endl;
        }
    }

    void storeProductsToFile() {
        ofstream file("production.txt");
        if (!file.is_open()) {
            cerr << "Error opening file\n";
            return;
        }

        for (int i = 0; i < numProducts; i++) {
            file << products[i].id << ' ' << products[i].name << ' ' << products[i].type << ' ' << products[i].amount << '\n';
        }

        cout << "Products stored to file successfully!\n";
    }

    void readProductsFromFile() {
        ifstream fout("production.txt");
        if (!fout.is_open()) {
            cerr << "Error opening file\n";
            return;
        }

        while (fout >> products[numProducts].id >> products[numProducts].name >> products[numProducts].type >> products[numProducts].amount) {
            numProducts++;
            if (numProducts >= MAX_PRODUCTS) {
                cerr << "Maximum limit reached. Some products may not be loaded.\n";
                break;
            }
        }

        cout << "Products read from file successfully!\n";
    }
    void temp_readProductsFromFile() {
        ifstream fin("production.txt");
        if (!fin.is_open()) {
            cerr << "Error opening file\n";
            return;
        }

        while (fin >> temp_products[numProducts].id >> temp_products[numProducts].name >> temp_products[numProducts].type >> temp_products[numProducts].amount) {
            numProducts++;
            if (numProducts >= MAX_PRODUCTS) {
                cerr << "Maximum limit reached. Some products may not be loaded.\n";
                break;
            }
        }

        cout << "Products read from file successfully!\n";
    }
    void Productmenu() {

        readProductsFromFile();
        int choice;
        do {
            cout << setw(10) << "----------" << setw(10) << endl;
            cout << "----------Product_Menu----------\n";
            cout << setw(10) << "----------" << setw(10) << endl;
            cout << "----------" << setw(10) << "----------" << endl;
            cout << "1.Add Product \n2.View Product\n3.Search Product\n4.Update Product\n5.Delete Product\n6.Exit Menu\n";
            cout << "Enter your choice: ";

            cin >> choice;

            switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                viewProducts();
                break;
            case 3:
                searchAndDisplayProduct();
                break;
            case 4:
                updateProduct();
                break;
            case 5:
                deleteProduct();
                break;
            case 6:
                
                storeProductsToFile();
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