#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

class Item {
public:
    int id;
    string name;
    double price;
    int quantity;

    Item(int i, string n, double p, int q) {
        id = i;
        name = n;
        price = p;
        quantity = q;
    }
};

class ShoppingSystem {
private:
    vector<Item> items;

public:
    void addItem() {
        int id, qty;
        double price;
        string name;

        cout << "\nEnter Item ID: ";
        cin >> id;
        cin.ignore(1000, '\n');

        cout << "Enter Item Name: ";
        getline(cin, name);

        cout << "Enter Price: ";
        cin >> price;

        cout << "Enter Quantity: ";
        cin >> qty;

        items.push_back(Item(id, name, price, qty));
        cout << "Item added successfully!\n";
    }

    void displayItems() {
        if (items.size() == 0) {
            cout << "\nNo items available!\n";
            return;
        }

        cout << "\nAvailable Items:\n";
        cout << left << setw(10) << "ID"
             << setw(20) << "Name"
             << setw(10) << "Price"
             << setw(10) << "Stock" << endl;

        for (int i = 0; i < items.size(); i++) {
            cout << left << setw(10) << items[i].id
                 << setw(20) << items[i].name
                 << setw(10) << items[i].price
                 << setw(10) << items[i].quantity << endl;
        }
    }

    void buyItem() {
        if (items.size() == 0) {
            cout << "\nNo items available to buy!\n";
            return;
        }

        int id, qty;
        displayItems();

        cout << "\nEnter Item ID to buy: ";
        cin >> id;

        for (int i = 0; i < items.size(); i++) {
            if (items[i].id == id) {
                cout << "Enter quantity: ";
                cin >> qty;

                if (qty <= 0) {
                    cout << "Invalid quantity!\n";
                    return;
                }

                if (qty > items[i].quantity) {
                    cout << "Not enough stock!\n";
                    return;
                }

                double total = qty * items[i].price;
                items[i].quantity -= qty;

                cout << "\nPurchased successfully!\n";
                cout << "Total Bill: Rs. " << total << endl;
                return;
            }
        }

        cout << "Item not found!\n";
    }
};

int main() {
    ShoppingSystem shop;
    int choice;

    do {
        cout << "\n===== DIGITAL SHOPPING SYSTEM =====\n";
        cout << "1. Add Item\n";
        cout << "2. View Items\n";
        cout << "3. Buy Item\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                shop.addItem();
                break;
            case 2:
                shop.displayItems();
                break;
            case 3:
                shop.buyItem();
                break;
            case 4:
                cout << "Thank you for using the system!\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}

