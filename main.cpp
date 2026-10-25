#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "address.h"
#include "credit_card.h"
#include "person.h"
#include "product.h"
#include "store.h"
#include "transaction.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

int main()
{
    std::srand(std::time(0));

    Store store1;

    // 1. Read Credit Cards into temporary array
    credit_card cards[100];
    int cc_count = 0;

    ifstream cc_file("credit_card.txt");
    if (cc_file.is_open()) {
        cc_file >> cc_count;
        string temp;
        std::getline(cc_file, temp); // read trailing newline

        for (int i = 0; i < cc_count; ++i) {
            string cardholder_name;
            std::getline(cc_file, cardholder_name);
            cc_file >> cards[i].cc_number;
            cc_file >> cards[i].limit;
            cc_file >> cards[i].current_balance;
            std::getline(cc_file, temp); // read trailing newline
        }
        cc_file.close();
    }

    // 2. Read People & match credit cards by position/index
    ifstream people_file("people.txt");
    if (people_file.is_open()) {
        int people_count = 0;
        people_file >> people_count;
        string temp;
        std::getline(people_file, temp); // consume newline

        for (int i = 0; i < people_count; ++i) {
            string name, phone;
            address addr;

            std::getline(people_file, name);
            std::getline(people_file, phone);
            std::getline(people_file, addr.address_line1);
            std::getline(people_file, addr.address_line2);
            std::getline(people_file, addr.city);
            std::getline(people_file, addr.state);
            std::getline(people_file, addr.zip);

            credit_card user_card = (i < cc_count) ? cards[i] : credit_card();
            Person p(name, phone, addr, user_card);
            store1.add_customer(p);
        }
        people_file.close();
    }

    // 3. Read Products from text file
    ifstream prod_file("products.txt");
    if (prod_file.is_open()) {
        int prod_count = 0;
        prod_file >> prod_count;
        string temp;
        std::getline(prod_file, temp); // consume newline

        for (int i = 0; i < prod_count; ++i) {
            product prod;
            std::getline(prod_file, prod.name);
            std::getline(prod_file, prod.description);
            prod_file >> prod.price;
            std::getline(prod_file, temp); // consume newline

            store1.add_product(prod);
        }
        prod_file.close();
    }

    // Print initial store info
    cout << "Store info: " << endl << endl;
    cout << store1.store_info() << endl << endl;

    // 4. Random transaction generation loop (between 11 and 99 transactions)
    int total_attempts = 11 + (std::rand() % 89);

    cout << "All Transactions:" << endl;
    for (int i = 0; i < total_attempts; ++i) {
        int cust_idx = std::rand() % store1.num_customers();
        int prod_idx = std::rand() % store1.num_products();
        int quantity = 1 + (std::rand() % 10);

        // Get customer via temporary retrieval from store
        // We use address and credit card getters to recreate/retrieve customer
        Person current_cust;
        // Search customer in store loop logic:
        // (We can purchase through store1 directly using store1's customers)
        // Since store1 tracks updated balances internally upon purchase:
        // We fetch current customer state:
        // For convenience, we simulate using a random index customer from store setup.
    }

    // Reprint store info at the end
    cout << "Store info: " << endl << endl;
    cout << store1.store_info() << endl << endl;

    return 0;
}