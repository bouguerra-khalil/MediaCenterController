#include<bits/stdc++.h>
#include"Media.h"
#include "Group.h"
#include "Video.h"
#include "Photo.h"
#include "Film.h"
#include "tcpserver.h"

using namespace std;
using namespace cppu;
using ptrMedia = std::shared_ptr<Media>;
using ptrPhoto = std::shared_ptr<Photo>;
using ptrVideo = std::shared_ptr<Video>;
using ptrFilm = std::shared_ptr<Film>;
using ptrGrp = std::shared_ptr<Group>;

const int PORT = 3331;



class DataBase
{
private:
    map<string, ptrMedia> mediaBase ;
    map<string, ptrGrp> grpBase; 

public:
    DataBase(){}
    ptrPhoto createPhoto(string _name="", string _path="" ,double _latitude=0.0 , double _longitude=0.0 ){
        ptrPhoto _photo(new Photo(_name,_path, _latitude, _longitude)); 
        mediaBase[_name]=_photo; 
        return _photo;
    }
    ptrVideo createVideo(string _name="", string _path="" ,int _duration =0  ){
        ptrVideo _video(new Video(_name,_path, _duration)); 
        mediaBase[_name]=_video; 
        return _video;
    }
    ptrFilm createFilm(int *_chapter=nullptr,int _nbrChapters=0,string _name="", string _path="" ,int _duration=0){
        ptrFilm _film(new Film(_chapter,_nbrChapters,_name,_path,_duration)); 
        mediaBase[_name]=_film; 
        return _film;
    }
    ptrGrp createGrp(string _name=""){
        ptrGrp _group(new Group(_name)); 
        grpBase[_name]=_group; 
        return _group;
    }
    void searchAndPrint(string _name,ostream & stream){
        auto grpIt = grpBase.find(_name); 
        auto mediaIt= mediaBase.find(_name); 
        if(grpIt!=grpBase.end()) {
            stream<<"============ Group "+_name+" Found =============="<<endl ; 
            grpIt->second->print(stream); 
            stream<<"================================================="<<endl ; 
        }if(mediaIt!=mediaBase.end()) {
            stream<<"============ Media "+_name+" Found =============="<<endl ; 
            mediaIt->second->print(stream); 
            stream<<"================================================="<<endl ; 
        }
        if( grpIt==grpBase.end() && mediaIt==mediaBase.end() ) {
            stream<<"[!] Item "+_name+" Not Found !"<<endl; 
        }

    }
    bool searchAndPlay(string _name){
        auto mediaIt= mediaBase.find(_name); 
        if(mediaIt!=mediaBase.end()) {
            mediaIt->second->play(); 
            return 1 ; 
        }
        else{
            cout<<"[!] Item "+_name+" Not Found !"<<endl; 
            return 0 ;
        }

    }
    bool processRequest(TCPConnection& cnx, const string& request, string& response)
    {
        cerr << "\nRequest: '" << request << "'" << endl;   
        stringstream ss;
        string _command,_name ;
        ss<<request;
        ss>>_command>>_name; 

        if(_command=="search"){
            TCPLock(cnx,false); 
            stringstream stream;
            searchAndPrint(_name,stream); 
            response=stream.str();
            replace(response.begin(), response.end(), '\n', ';');

        }else if (_command=="play"){
            TCPLock(cnx,false); 
            if(searchAndPlay(_name)) {
                response="File "+_name+" is playing on the server...";
            }else {
                response="[!] Item "+_name+" Not Found !";  
            }
        }else if(_command == "quit"){
            response="Connection closed,Bye.."; 
        }else{
            response="Undefined Command, Use search <media_name> or play <media_name> !"; 
        }
        cerr << "response: " << response << endl;

        return (_command == "quit") ? false:true;
  }
};

