#include "IIN.h"

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

std::string vectorToString(std::vector<char> number){
    std::string result = "";
    for(int index=0; index<number.size(); ++index){
        result.push_back(number[index]);
    }
    std::cout<<"\n\t"<<result<<"\n";
    return result;
}

int main(int argc, char *argv[]){
    if(argc==1){
        std::cout<<"[!] NO ARGUMENTS SUPPLIED TO PROGRAM.";
        return 0;
    }

    std::vector<char> credit_card_number;
    for(int index=0; argv[1][index]!='\0'; ++index){
        credit_card_number.push_back(argv[1][index]);
    }

    if( isNum(credit_card_number) ){
        // Is a valid number
        if( validate(credit_card_number) ){
            std::cout<<" CREDIT CARD NUMBER IS VALID.\n";
            std::cout<<" ISSUER CATEGORY :\t"<<issuerCategory(credit_card_number[0])<<std::endl;

            identityNode root;
            root = initializer();
            std::cout<<"4726428044778999\t"<<root.search("4726428044778999")<<std::endl;
            std::string stringValue = vectorToString(credit_card_number);
            std::cout<<stringValue<<"\t"<<root.search(stringValue)<<std::endl;
        }
        else{
            std::cout<<" CREDIT CARD NUMBER IS INVALID.\n";
        }
    }
    else{
        std::cout<<" NOT A NUMERICAL VALUE.\n";
    }
    
    //root.display(" ");


/*
    root.insert("Visa","4","4");
    root.insert("SIZE2","14","14");
    root.insert("SIZE2","16","16");
    root.insert("SIZE3","34","34");
    root.insert("UATP","1","1");
    root.insert("TROY","6","9");
    root.insert("ORDER69","27","45");
    root.display(" ");
*/
    //cout<<root.search("1");
    //cout<<"\n";


    /* Searching Starts*/
    
    //std::cout<<"37\t"<<root.search("37")<<std::endl;
    return 0;
}