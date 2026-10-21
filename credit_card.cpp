//implementation code for credit_card struct here
#include "credit_card.h"
#include <cstdio> // for snprintf

// checks if purchase can be made
bool credit_card::make_purchase(double purchase_amount)
{
    // does not allow a negative purchase amount
    if(purchase_amount < 0)
    {
        return false;
    }
    // checks if purchase is within the limit
    if(current_balance + purchase_amount <= limit)
    {
        current_balance = current_balance + purchase_amount;
        return true;
    }
    // purchase cannot be made if it goes over the limit
    return false;
}

// checks if payment can be made
bool credit_card::make_payment(double payment_amount)
{
    // does not allow negative payments
    if(payment_amount < 0)
    {
        return false;
    }
    // checks if payment is in the current balance
    if(payment_amount <= current_balance)
    {
        current_balance = current_balance - payment_amount;
        return true;
    }
    // payment cannot be made if it goes over balance
    return false;
}

// returns credit card info as a string
std::string credit_card::credit_card_info()
{
    // char creates space to store the credit card information
    char info[200];

    // formats the info with two decimal places
   std::snprintf(info,sizeof(info),
        "Credit Card Number: %d\n" 
        "Credit Card Limit: $%.2f\n"
        "Current Balance: $%.2f",
        cc_number, limit, current_balance);

    return std::string(info);
}
