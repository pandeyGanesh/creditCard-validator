#include "issuerName.h"
#include "issuerCategory.h"
#include "utils.h"

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
            //std::cout<<"4726428044778999\t"<<root.search("4726428044778999")<<std::endl;
            std::string stringValue = vectorToString(credit_card_number);
            std::cout<<" ISSUER NAME :\t"<<root.search(stringValue)<<std::endl;
        }
        else{
            std::cout<<"[!] CREDIT CARD NUMBER IS INVALID.\n";
        }
    }
    else{
        std::cout<<"[!] NOT A NUMERICAL VALUE.\n";
    }
    
    return 0;
}