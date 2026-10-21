//code for person class here
#include "person.h"

// two constructors below
// constructor that sets up a person with their info
Person::Person(string name, string phone, address person_address, credit_card person_credit_card)
{
    name_ = name;
    phone_ = phone;
    person_address_ = person_address;
    person_credit_card_ = person_credit_card;
}

// constructor that sets basic vaules
Person::Person()
{
    name_ = "";
    phone_ = "";
    person_address_ = address();
    person_credit_card_ = credit_card();
}

// all setters and getters below
// set persons name
void Person:: name(string name)
{
    name_ = name;
}
// returns persons name
string Person::name()
{
    return name_;
}
// set persons phone number
void Person::phone(string phone)
{
    phone_ = phone;
}
// returns persons phone number
string Person::phone()
{
    return phone_;
}
// sets persons address
void Person:: person_address(address person_address)
{
    person_address_ = person_address;
}
// returns persons address
address Person::person_address()
{
    return person_address__;
}
// sets persons credit card
void Person:: person_credit_card(credit_card person_credit_card)
{
    person_credit_card_ = person_credit_card;
}
// returns persons credit card
credit_card Person::person_credit_card()
{
    return person_credit_card_;
}

// returns all of the person's info as a string
string Person::person_info()
{
    return "Name: " + name_ + "\n"
    + "Phone: " + phone_ + "\n"
    + person_address_.address_info() + "\n"
    + person_credit_card_.credit_card_info();
}
