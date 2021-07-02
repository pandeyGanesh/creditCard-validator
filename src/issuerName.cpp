#include "issuerName.h"    // <iostream> <vector>

identityNode :: identityNode(std::string company){
    companyName = company;
    for(int i=0; i<LIMIT; ++i){
        next[i] = NULL;
    }
}

void identityNode :: insert(std::string company, std::string from, std::string to){
    if(from==to){
        // From and To are same values

        // From and To are same values with size 1
        if( from.size() ==1 ){
            if( (this->next[(int)(from[0]-'0')]) == NULL ){
                this->next[(int)(from[0]-'0')] = new identityNode(company);
            }
            else if( (this->next[(int)(from[0]-'0')])->companyName == "" ){
                this->next[(int)(from[0]-'0')]->companyName = company;
            }
            else{
                std::cout<<"Cannot add Company "<<company<<std::endl;
            }
        }

        else{
            // From and To are same values with size > 1
            if( (this->next[(int)(from[0]-'0')]) == NULL ){
                this->next[(int)(from[0]-'0')] = new identityNode();
            }
            std::string beg = from.substr(1,std::string::npos);
            std::string end = beg;
            this->next[(int)(from[0]-'0')]->insert(company,beg,end);
        }
    }
    else{
        // From and To are different values

        if( from.size() == 1 ){
            // From and To are different values with size 1
            int start = (int)(from[0]-'0');
            int end = (int)(to[0]-'0');
            for(int i=start; i<=end; ++i){
                if( (this->next[i]) == NULL ){
                    this->next[i] = new identityNode(company);
                }
                else if( (this->next[i])->companyName == "" ){
                    this->next[i]->companyName = company;
                }
                else{
                    std::cout<<"Cannot add Company "<<company<<std::endl;
                }
            }
        }
        else{
            // From and To are different values with size > 1

            if( (int)(from[0]-'0')==(int)(to[0]-'0') ){
                // From and To are different values with size > 1; first element is same
                if( (this->next[(int)(from[0]-'0')]) == NULL ){
                    this->next[(int)(from[0]-'0')] = new identityNode();
                }
                std::string beg = from.substr(1,std::string::npos);
                std::string end = to.substr(1,std::string::npos);
                this->next[(int)(from[0]-'0')]->insert(company,beg,end);
            }
            else{
                // From and To are different values with size > 1; first element is different

                // Processing the From node
                std::string newEnd = from.substr(0,1);
                for(int i=1; i<from.size(); ++i){
                    newEnd += "9";
                }
                this->insert(company,from,newEnd);


                // Making nodes for all values between from and to
                int start = (int)(from[0]-'0');
                int end = (int)(to[0]-'0');
                for(int i=start+1; i<end; ++i){
                    this->insert(company,std::to_string(i),std::to_string(i));
                }


                // Processing the End Node
                std::string newStart = to.substr(0,1);
                for(int i=1; i<to.size(); ++i){
                    newStart += "0";
                }
                this->insert(company,newStart,to);

            }
        }
    }
}

std::string identityNode :: search(std::string credit_card){
    if (credit_card==""){
        return this->companyName;
    }
    //std::cout<<"Called\t";
    std::string result = this->companyName;
    //std::cout<<result<<"\n";
    std::string nextBest = "";

    identityNode *nextNum = this->next[(int)(credit_card[0]-'0')];
    if (nextNum!=NULL){
        nextBest = nextNum->search(credit_card.substr(1,std::string::npos));
    }
    
    if(nextBest!=""){
        return nextBest;
    }
    return result;
}

void identityNode :: display(){
    std::cout<<companyName<<"\n";
    for(int i=0; i<LIMIT; ++i){
        if(next[i]==NULL){
            std::cout<<0<<"\t";
        }
        else{
            std::cout<<1<<"\t";
        }
    }
    std::cout<<"\n";
    for(int i=0; i<LIMIT; ++i){
        if(next[i]!=NULL){
            std::cout<<i<<"--> \t";
            next[i]->display();
        }
    }
    std::cout<<"\n\n";
}

bool identityNode :: isLeaf(){
    for(int i=0; i<LIMIT; ++i){
        if (next[i] != NULL)
            return false;
    }
    return true;
}

void identityNode :: display(std::string message){
    if(this->isLeaf()){
        std::cout<<message<<" !"<<std::endl;
    }
    else{
        for(int i=0; i<LIMIT; ++i){
            if (next[i] != NULL){
                std::string newMessage = message + " -- (" + std::to_string(i) +") " + this->next[i]->companyName + " ";
                //newMessage += ;
                this->next[i]->display(newMessage);
            }
        } 
    }
}

identityNode initializer(){
    identityNode root;
    root.insert("American Express","34","34");
    root.insert("American Express","37","37");
    root.insert("China T-Union","31","31");
    root.insert("China UnionPay","62","62");
    root.insert("Diners Club International","36","36");
    root.insert("Diners Club United States & Canada","54","54");
    root.insert("Discover Card","6011","6011");
    root.insert("Discover Card","622126","622925");
    root.insert("Discover Card","644","644");
    root.insert("Discover Card","645","645");
    root.insert("Discover Card","646","646");
    root.insert("Discover Card","647","647");
    root.insert("Discover Card","648","648");
    root.insert("Discover Card","649","649");
    root.insert("Discover Card","65","65");
    root.insert("UkrCard","60400100","60420099");
    root.insert("Rupay","60","60");
    root.insert("Rupay","6521","6522");
    root.insert("InterPayment","636","636");
    root.insert("InstaPayment","637","639");
    root.insert("JCB","3528","3589");
    root.insert("Maestro UK","6759","6759");
    root.insert("Maestro UK","676770","676770");
    root.insert("Maestro UK","676774","676774");
    root.insert("Maestro","5018","5018");
    root.insert("Maestro","5020","5020");
    root.insert("Maestro","5038","5038");
    root.insert("Maestro","5893","5893");
    root.insert("Maestro","6304","6304");
    root.insert("Maestro","6759","6759");
    root.insert("Maestro","6761","6761");
    root.insert("Maestro","6762","6762");
    root.insert("Maestro","6763","6763");
    root.insert("Dankort","5019","5019");
    root.insert("Dankort (Visa co-branded)","4571","4571");
    root.insert("MIR","2200","2204");
    root.insert("NPS Pridnestrovie","6054740","6054744");
    root.insert("Mastercard","2221","2720");
    root.insert("Mastercard","51","55");
    root.insert("Troy","6","9");
    root.insert("Visa","4","4");
    root.insert("Visa Electron","4026","4026");
    root.insert("Visa Electron","417500","417500");
    root.insert("Visa Electron","4508","4508");
    root.insert("Visa Electron","4844","4844");
    root.insert("Visa Electron","4913","4913");
    root.insert("Visa Electron","4917","4917");
    root.insert("UATP","1","1");
    return root;
}