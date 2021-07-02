#include "utils.h"

bool isNum(std::vector<char> number){
    // Checks only for postitive number as
    // Credit card number cannot be negative
    for(int index=0; index<number.size(); ++index){
        if(!isdigit(number[index]))
            return false;
    }
    return true;
}

bool validate(std::vector<char> number){
    // Add a check for 16 digits
    int sum = 0, digit = 0;
    // First digit from the right is not doubled
    // Every second digit is doubled.
    bool toDouble = false;
    for(int index=number.size()-1; index>=0; --index){
        digit = (int)(number[index]-'0');
        (toDouble==true) && (digit*=2);
        (digit>9)?(digit-=9):(digit);
        sum += digit;
        toDouble = !toDouble;
    }
    if (sum%10==0)
        return true;
    return false;
}

std::string vectorToString(std::vector<char> number){
    std::string result = "";
    for(int index=0; index<number.size(); ++index){
        result.push_back(number[index]);
    }
    return result;
}