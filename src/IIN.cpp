#include "IIN.h"    // <iostream> <vector>

identityNode :: identityNode(string company){
    companyName = company;
    for(int i=0; i<LIMIT; ++i){
        next[i] = NULL;
    }
}

void identityNode :: insert(string company, string from, string to){
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
                cout<<"Cannot add Company "<<company<<endl;
            }
        }

        else{
            // From and To are same values with size > 1
            if( (this->next[(int)(from[0]-'0')]) == NULL ){
                this->next[(int)(from[0]-'0')] = new identityNode();
            }
            string beg = from.substr(1,string::npos);
            string end = beg;
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
                    cout<<"Cannot add Company "<<company<<endl;
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
                string beg = from.substr(1,string::npos);
                string end = to.substr(1,string::npos);
                this->next[(int)(from[0]-'0')]->insert(company,beg,end);
            }
            else{
                // From and To are different values with size > 1; first element is different

                // Processing the From node
                string newEnd = from.substr(0,1);
                for(int i=1; i<from.size(); ++i){
                    newEnd += "9";
                }
                this->insert(company,from,newEnd);


                // Making nodes for all values between from and to
                int start = (int)(from[0]-'0');
                int end = (int)(to[0]-'0');
                for(int i=start+1; i<end; ++i){
                    this->insert(company,to_string(i),to_string(i));
                }


                // Processing the End Node
                string newStart = to.substr(0,1);
                for(int i=1; i<to.size(); ++i){
                    newStart += "0";
                }
                this->insert(company,newStart,to);

            }
        }
    }
}

string identityNode :: search(string credit_card){
    while ((getchar()) != '\n');
    if (credit_card==""){
        return this->companyName;
    }
    //cout<<"Called\t";
    string result = this->companyName;
    //cout<<result<<"\n";
    string nextBest = "";

    identityNode *nextNum = this->next[(int)(credit_card[0]-'0')];
    if (nextNum!=NULL){
        nextBest = nextNum->search(credit_card.substr(1,string::npos));
    }
    
    if(nextBest!=""){
        return nextBest;
    }
    return result;
}

void identityNode :: display(){
    cout<<companyName<<"\n";
    for(int i=0; i<LIMIT; ++i){
        if(next[i]==NULL){
            cout<<0<<"\t";
        }
        else{
            cout<<1<<"\t";
        }
    }
    cout<<"\n";
    for(int i=0; i<LIMIT; ++i){
        if(next[i]!=NULL){
            cout<<i<<"--> \t";
            next[i]->display();
        }
    }
    cout<<"\n\n";
}

bool identityNode :: isLeaf(){
    for(int i=0; i<LIMIT; ++i){
        if (next[i] != NULL)
            return false;
    }
    return true;
}

void identityNode :: display(string message){
    if(this->isLeaf()){
        cout<<message<<" !"<<endl;
    }
    else{
        for(int i=0; i<LIMIT; ++i){
            if (next[i] != NULL){
                string newMessage = message + " -- (" + to_string(i) +") " + this->next[i]->companyName + " ";
                //newMessage += ;
                this->next[i]->display(newMessage);
            }
        } 
    }
}