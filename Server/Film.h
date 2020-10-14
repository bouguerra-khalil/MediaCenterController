#ifndef film
#define film
#include"Video.h"

class Film: public Video{

private: 
    int *chapter;
    int nbrChapters; 
public: 
    Film(int *_chapter=nullptr,int _nbrChapters=0,string _name="", string _path="" ,int _duration = 0 ):
    Video(_name,_path,_duration){
        if(_nbrChapters && _chapter){
            nbrChapters=_nbrChapters; 
            chapter=new int[nbrChapters]; 
            for ( int i = 0 ; i <nbrChapters ; i++){
                chapter[i]=_chapter[i]; 
            }
        }     
    }
    Film(const Film & from ):Video(from.name,from.path,from.duration){
        int _nbrChapters =from.getNbrChapters();
        const int *_chapter=from.getChapters(); 
        if(_nbrChapters && _chapter){
            nbrChapters=_nbrChapters; 
            chapter=new int[nbrChapters]; 
            for ( int i = 0 ; i <nbrChapters ; i++){
                chapter[i]=_chapter[i]; 
            }
        }else{
            nbrChapters=0; 
            chapter=nullptr; 
        }   
    }

    void setChapter( int * _chapter= nullptr,int _nbrChapters=0){
        if(_nbrChapters && _chapter){

            if(chapter) {
                delete[] chapter; 
            }
            nbrChapters=_nbrChapters; 
            chapter=new int[nbrChapters]; 
            for ( int i = 0 ; i <nbrChapters ; i++){
                chapter[i]=_chapter[i]; 
            }
        }
    }

    int getNbrChapters() const { return nbrChapters;}
    const int * getChapters() const { return chapter ; }

    void print(ostream & stream ) const final{
        stream<<"____Film File____"<<endl
        <<"Name: "<<name<<endl
        <<"Path: "<<path<<endl
        <<"Duration: "<<duration<<endl ;
        
        if(nbrChapters && chapter){
            stream<<"Chapters: ";
            for (int i = 0 ; i<nbrChapters; i++){
                stream<<chapter[i]<<" "; 
            }
        }else{
            stream<<"No Chapter data ";
        }
        stream<<endl<<"_________________"<<endl ; 
    }


    Film& operator= (const Film& from){
    Video::operator=(from); 
    int _nbrChapters =from.getNbrChapters();
    const int *_chapter=from.getChapters(); 
    if(_nbrChapters && _chapter){
            if(chapter) {
                delete[] chapter; 
            }
            nbrChapters=_nbrChapters; 
            chapter=new int[nbrChapters]; 
            for ( int i = 0 ; i <nbrChapters ; i++){
                chapter[i]=_chapter[i]; 
            }
    }
    else {
            nbrChapters=0 ; 
            chapter=nullptr; 
    }
    return *this;
    }
         virtual ~Film(){

         if(chapter)
         {
             delete [] chapter; 
         }
        cerr<<"[!][!][!]Film Object "<<name<<" deleted"<<endl ; 

     }
}; 

#endif