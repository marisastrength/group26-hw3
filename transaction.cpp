#include "transaction.h"
#include <string>

using std::to_string;

string transaction::transaction_info()
{
    return "Transaction   : " + to_string(transaction_number) + "\n" +
           "Customer:\n" + customer.person_info() + "\n" +
           "Product:\n" + purchased_item.product_info() + "\n" +
           "Quantity: " + to_string(quantity);
}