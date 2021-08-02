#include <issuerCategory.h>

std::string issuerCategory(char MII){
    // MII is the first digit of credit card number
    // It determines the category of issuer.
    switch (MII){
        case '1'    :   return "Airlines";  break;
        case '2'    :   return "Airlines/Financial"; break;
        case '3'    :   return "Travel and Entertainment"; break;
        case '4'    :   
        case '5'    :   return "Banking and Financial"; break;
        case '6'    :   return "Merchandising and Banking/Financial"; break;
        case '7'    :   return "Petroleum Industry"; break;
        case '8'    :   return "Healthcare and Telecommunications"; break;
        case '9'    :   return "National standard body"; break;
    }
    return "0";
}
