#include "store.h"
#include <string>

using std::to_string;

Store::Store()
{
    num_customers_ = 0;
    num_products_ = 0;
    num_transactions_ = 0;
}

void Store::num_customers(int customer_count) { num_customers_ = customer_count; }
int Store::num_customers() { return num_customers_; }

void Store::num_products(int product_count) { num_products_ = product_count; }
int Store::num_products() { return num_products_; }

void Store::num_transactions(int transaction_count) { num_transactions_ = transaction_count; }
int Store::num_transactions() { return num_transactions_; }

bool Store::add_customer(Person customer)
{
    if (num_customers_ >= 100) return false;
    customers_[num_customers_++] = customer;
    return true;
}

bool Store::update_customer(int index, Person customer)
{
    if (index < 0 || index >= num_customers_) return false;
    customers_[index] = customer;
    return true;
}

bool Store::add_product(product item)
{
    if (num_products_ >= 100) return false;
    products_[num_products_++] = item;
    return true;
}

product Store::get_product(int index)
{
    if (index >= 0 && index < num_products_) {
        return products_[index];
    }
    return product();
}

bool Store::add_transaction(transaction ntransaction)
{
    if (num_transactions_ >= 100) return false;
    transactions_[num_transactions_++] = ntransaction;
    return true;
}

transaction Store::get_transaction(int index)
{
    if (index >= 0 && index < num_transactions_) {
        return transactions_[index];
    }
    return transaction();
}

bool Store::make_purchase(Person customer, product item, int amount)
{
    double total_cost = item.price * amount;
    credit_card card = customer.person_credit_card();

    if (card.make_purchase(total_cost)) {
        customer.person_credit_card(card);

        // Update customer inside store array
        for (int i = 0; i < num_customers_; ++i) {
            if (customers_[i].name() == customer.name()) {
                customers_[i] = customer;
                break;
            }
        }

        // Record successful transaction
        transaction t;
        t.transaction_number = num_transactions_ + 1;
        t.customer = customer;
        t.purchased_item = item;
        t.quantity = amount;
        add_transaction(t);

        return true;
    }
    return false;
}

string Store::purchase_history(Person customer)
{
    string history = "";
    for (int i = 0; i < num_transactions_; ++i) {
        if (transactions_[i].customer.name() == customer.name()) {
            history += transactions_[i].transaction_info() + "\n\n";
        }
    }
    return history;
}

string Store::product_info()
{
    string info = "Products:\n";
    for (int i = 0; i < num_products_; ++i) {
        info += products_[i].product_info();
        if (i < num_products_ - 1) {
            info += "\n";
        }
    }
    return info;
}

string Store::transaction_info()
{
    string info = "All Transactions:\n";
    for (int i = 0; i < num_transactions_; ++i) {
        info += transactions_[i].transaction_info();
        if (i < num_transactions_ - 1) {
            info += "\n";
        }
    }
    return info;
}

string Store::store_info()
{
    string info = "Customers:\n";
    for (int i = 0; i < num_customers_; ++i) {
        info += customers_[i].person_info();
        if (i < num_customers_ - 1) {
            info += "\n";
        }
    }
    info += "\n" + product_info() + "\n" + transaction_info();
    return info;
}
// gets a customer from the store using their position in the array
Person Store::get_customer(int index)
{
    // returns the customer at the specified index
    return customers_[index];
}