#ifndef video 
#define video 
#include"Media.h"


class Video:public Media
{
protected:
    int duration; 
public:
    Video(string _name="", string _path="" ,int _duration = 0 ):Media(_name,_path),duration(_duration){};
    
    int getDuration()const{ return duration;}
    
    void setDuration(double _duration){ duration=_duration;}
    

    void print(ostream & stream ) const override{
        stream<<"____Video File____"<<endl
        <<"Name: "<<name<<endl
        <<"Path: "<<path<<endl
        <<"Duration: "<<duration<<endl 
        <<"_________________"<<endl ; 
    }
    void play() const {
        string command="mpv "+path+" &";
        system(command.c_str()); 
    }

    ~Video() override{
        cerr<<"[!][!]Video Object "<<name<<" deleted"<<endl ; 
    };
};
#endif