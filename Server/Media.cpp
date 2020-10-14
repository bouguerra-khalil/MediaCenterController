#include"Media.h"


Media::Media():name(""),path(""){}

Media::Media(string _name , string _path):name(_name),path(_path){}
    
string Media::getName() const{return name; }

string Media::getPath() const{return path; }

void Media::setName(string _name){name = _name; }

void Media::setPath(string _path){path = _path; }

void Media::print(ostream & stream) const{
        stream<<"____Media File____"<<endl<<"Name: "<<name<<endl<<"Path: "<<path<<endl<<"_________________"<<endl ;
    }

Media::~Media(){
        cerr<<"[!] Media Object "<<name<<" deleted"<<endl ; 
    }

