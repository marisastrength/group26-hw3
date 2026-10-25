#include "product.h"
#include <cstdio>

std::string product::product_info()
{
    char price_str[30];
    std::snprintf(price_str, sizeof(price_str), "$%.2f", price);

    return "Name: " + name + "\n" +
           "Description: " + description + "\n" +
           "Price: " + std::string(price_str);
}