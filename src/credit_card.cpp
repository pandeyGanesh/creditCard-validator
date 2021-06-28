#include <iostream>
#include <vector>

using namespace std;

bool isNum(vector<char> number){
    // Checks only for postitive number as Credit card number
    // cannot be negative
    for(int index=0; index<number.size(); ++index){
        if(!isdigit(number[index]))
            return false;
    }
    return true;
}

string issuerCategory(char MII){
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

bool validate(vector<char> number){
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

int main(int argc, char *argv[]){
    if(argc==1){
        cout<<"[!] NO ARGUMENTS SUPPLIED TO PROGRAM.";
    }
    vector<char> credit_card_number;
    for(int index=0; argv[1][index]!='\0'; ++index){
        credit_card_number.push_back(argv[1][index]);
    }

    if( isNum(credit_card_number)){
        bool result = validate(credit_card_number);
        cout<<"\nIS THE CREDIT CARD VALID ?\t"<<((result)?"True":"False");
        if(result){
            cout<<"\nISSUER CATEGORY :\t"<<issuerCategory(credit_card_number[0]);
        }
    }
    else
        cout<<"ENTER ONLY NUMERICAL VALUES";
    cout<<"\n";
    return 0;
}