#ifndef group
#define group
#include"Media.h"
#include<bits/stdc++.h>
using ptrMedia = std::shared_ptr<Media>;

using namespace std ; 
class Group : public list<ptrMedia >{
    private: 
        string name ; 
    public : 
        Group(string _name="" ):list<ptrMedia>(),name(_name){}
        string getName()const {return name ; }
        void print(ostream & stream)const{
            stream<<"The Group :"<<name<<endl ; 
            for (auto item :*this)
            {
                item->print(stream); 
                stream<<"________________________"<<endl ; 
            }
        }

}; 
#endif