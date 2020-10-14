#ifndef media
#define media

#include<bits/stdc++.h>

using namespace std;


class Media
{
protected:
    string name; 
    string path; 
public:
    Media();
    Media(string _name , string _path);
    string getName() const;
    string getPath() const;
    void setName(string _name);
    void setPath(string _path);
    virtual void print(ostream & stream ) const;
    virtual void play()const = 0 ;
    virtual ~Media();
};
#endif
