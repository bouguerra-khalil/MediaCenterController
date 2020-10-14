#ifndef photo
#define photo 
#include"Media.h"


class Photo:public Media
{
private:
    double latitude; 
    double longitude;
public:
    Photo(string _name="", string _path="" ,double _latitude=0.0 , double _longitude=0.0 ):Media(_name,_path),latitude(_latitude),longitude(_longitude){};
    
    double getLatitude()const{ return latitude;}
    
    double getLongitude() const{ return longitude ; }
    
    void setLatitude(double _latitude){ latitude=_latitude;}
    
    void setLongitude(double _longitude){ longitude=_longitude;}

    void print(ostream & stream ) const override{
        stream<<"____Photo File____"<<endl
        <<"Name: "<<name<<endl
        <<"Path: "<<path<<endl
        <<"latitude: "<<latitude<<endl 
        <<"longitude: "<<longitude<<endl
        <<"_________________"<<endl ; 
    }
    void play() const {
        string command="eog "+path+" &";
        system(command.c_str()); 
    }

    ~Photo() override{
        cerr<<"[!][!]Photo Object "<<name<<" deleted"<<endl ; 
    };
};
#endif