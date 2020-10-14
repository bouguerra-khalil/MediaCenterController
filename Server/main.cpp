
#include <bits/stdc++.h>
#include"Media.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include"DataBase.h"
#define Scenario2 0 //Class non instensiable  
#define Scenario4 0
#define Scenario5 0
#define Scenario6 0
#define Scenario7 0
#define Scenario8 0
#define Scenario9 0
#define Scenario10 0
#define Scenario11 1


using ptrMedia = std::shared_ptr<Media>;
using ptrPhoto = std::shared_ptr<Photo>;
using ptrVideo = std::shared_ptr<Video>;
using ptrFilm = std::shared_ptr<Film>;
using ptrGrp = std::shared_ptr<Group>;


using namespace std;

int main(int argc, const char* argv[])
{



    #if Scenario2
    
        //Test Etape 2 (Classe Media)

        Media *  media_1 = new Media() ;//instanciation de la class media avec constrecteur sans arguments
        Media * media_2=new Media("Photo_1","Media/1.jpg"); //instanciation de la class media avec constrecteur avec arguments
        //le test des les accesseurs et  modifieurs
        string name = media_2->getName();
        string path = media_2->getPath();
        media_1->setName(name); 
        media_1->setPath(path);
        //le test des la methode d'affichage 
        media_1->print(cout); 
        media_2->print(cout); 
        //destruction d'objets 
        delete media_1; 
        delete media_2; 

    #endif




    #if Scenario4
    
        //Test Etape 4 (Classe Photo et Videos )

        Media *  photo_media = new Photo() ;//instanciation de la class photo avec constrecteur sans arguments
                                        //avec un pointeur Media 
        Photo * photo=new Photo("Photo_1","Media/1.jpg",5.0,3.14); //instanciation de la class photo avec constrecteur avec arguments
                                                            // avec un pointeur  Photo 
        Video * video= new Video("video_1","Media/1.mp4",122) ;//instanciation de la class Video avec constrecteur avec arguments

        //le test des les accesseurs et  modifieurs
        string name = photo->getName();
        double latitude = photo->getLatitude();
        photo->setLongitude(latitude*0.5); 
        photo_media->setName("photo_media"); 
        photo_media->setPath("1.jpg");
        //le test des la methode d'affichage 
        photo_media->print(cout); 
        photo->print(cout); 
        video->print(cout);
        //le test des la methode de jouer media 
        photo_media->play(); 
        photo->play();
        video->play();
        //destruction d'objets 
        delete photo; 
        delete photo_media; 
        delete video;

    #endif


    #if Scenario5

        //Le test de la 5e Etape: Traitement générique

        vector<Media*> mediaList ; //vecteur de pointeur sur des objets media ( une liste qui comporte à la fois des photos et des vidéos.) 
        mediaList.push_back(new Photo("Photo 1","Media/1.jpg",1,1)); 
        mediaList.push_back(new Photo("Photo 2","Media/1.jpg",2,2)); 
        mediaList.push_back(new Photo("Photo 3","Media/1.jpg",3,3)); 
        mediaList.push_back(new Video("Video 1","Media/1.mp4",1)); 
        mediaList.push_back(new Video("Video 2","Media/1.mp4",2)); 
        mediaList.push_back(new Video("Video 3","Media/1.mp4",3)); 
        
        for (auto& item:mediaList){ //
            item->print(cout);
            item->play();
        }

    #endif


    #if Scenario6

        //Le test de la 6e étape: Films et tableaux
        
        //on utilise des tableaux dynamiques pour pouvoir les supprimer plus tard 
        int *chapter=new int[8]; 
        chapter[0]=1; 
        
        int *chapter_2=new int[8];
        chapter_2[0]=2;

        Film *film  = new Film(chapter,8,"film1","Media/1.mp4",350); 
        film->print(cout) ;
        //On vérifie bien que l'encapsulation est bien appliquée avec le constrecteur , 
        //En changeant le tableau dans l'appelant sans qu'il change dans l'objet,
        //Et en supprimant le tableau de l'appelant sans le perdre dans l'objet.

        chapter[0]=99;  
        film->print(cout);  
        delete[] chapter ;  
        film->print(cout); 
        // On test que l'encapsulation est conservéé  meme avec les modifieurs.
        film->setChapter(chapter_2,8); 
        chapter_2[0]=666;
        delete[] chapter_2; 
        film-> print(cout); 
        //On teste que les acceseurs ne permet pas la modifications du tableau puisque 
        //le type de retour est const int  
        //  int * tab = film->getChapters(); //=> Ne marche pas ;
        const int * tab = film->getChapters() ;
        delete film ; 

    #endif


    #if Scenario7 

        //test de la 7e étape: Destruction et copie des objets

        //On vérifie bien que l'encapsulation est bien appliquée avec le constrecteur par copie  et par operateur =  , 
        //En changeant le tableau dans l'appelant sans qu'il change dans l'objet,
        //Et en supprimant le tableau de l'appelant sans le perdre dans l'objet.
        int *chapter=new int[8]; 
        chapter[0]=1; 
        
        int *chapter_2=new int[8];
        chapter_2[0]=2;

        Film film_1(chapter, 8 , "film1"); //objet cree avec constrecteur normal 
        Film film_2(film_1); // //objet cree avec constrecteur par copie. 
        Film film_3(chapter_2,8,"film3") ; //objet cree avec constrecteur normal 
        film_3=film_1; //copie par operateur = 
        film_1.setChapter(chapter_2,8); //le changement de tableau de l'objet film_1
        film_1.setName("film1_edited"); //et le changement du nom de l'objet film_1
        film_2.print(cout);  //Sans aucun changement ou effet sur les copies 
        film_3.print(cout);  //Sans aucun changement ou effet sur les copies 
        
    #endif

    #if Scenario8 || Scenario9

        //       Le Test de la 8e étape: Créer des groupes
        //                       &&
        //Le test de la 9e étape: Gestion automatique de la mémoire
    

        Group * g_photo = new Group("Photo Group"); 
        Group * g_video = new Group("Video Group"); 
        Group * summer = new Group("Summer Media Group "); 
        for ( int i = 1 ; i < 4 ;i ++)
        {
            ptrMedia _photo (new Photo("Photo"+to_string(i),to_string(i)+".jpg",5*i,3.14*i)); 
            ptrMedia _video (new Video("Video"+to_string(i),to_string(i)+".jpg",31*i));
            g_photo->push_back(_photo);
            g_video->push_back(_video); 
            (i&1)?summer->push_back(_photo):summer->push_back(_video);// ajouter des objet de photo et video en alternance.
        }

        cout<<"====== "+g_photo->getName()+" Group==============="<<endl ; // Le test d'accesseur de nom de groupe 
        g_photo->print(cout);                                             // Le test de la methode d'affichage de groupe 
        cout<<"====== "+g_video->getName()+" Group==============="<<endl ; 
        g_video->print(cout);                                             
        delete g_photo; // On supprime le groupe de photos  
        delete g_video; //On supprime le groupe de videos
        cout<<"====== "+summer->getName()+" Group==============="<<endl ; 
        summer->print(cout); //Malgre qu'on a supprimé les groupes de photos et videos , 
                            //les objets photos et videos persistent encore.  
        summer->erase(summer->begin()); //l'objet pointe par le premier element du groupe summer n'est pointé
                                        // que par ce pointeur smart ( counter =  1) 
                                        //=>  si on supprime ce pointeur ( count=0 )
                                        //=> destruction automatique de l'objet 
                                        //=> pas de fruit de memoire .
        summer->print(cout);

    #endif


    #if Scenario10

        //Le test de la 10e étape: Gestion cohérente des données
        
        DataBase * dataBase = new DataBase() ; 
        ptrPhoto _photo_1 = dataBase->createPhoto("Photo1","Media/1.jpg",0.2,3.14);
        ptrPhoto _photo_2 = dataBase->createPhoto("Photo2","Media/2.jpg",0.4,6.14);
        ptrVideo _video_1 = dataBase->createVideo("Video1","Media/1.mp4",30);
        ptrVideo _video_2 = dataBase->createVideo("Video2","Media/2.mp4",30);
        ptrFilm _film_1 = dataBase->createFilm(new int[10],10,"Film1","Media/1.mkv",30);
        ptrFilm _film_2 = dataBase->createFilm(new int[5],5,"Film2","Media/2.mkv",300);
        ptrGrp _grp_1 = dataBase->createGrp("Group1");
        ptrGrp _grp_2 = dataBase->createGrp("Group2");
        _grp_1->push_back(_photo_1);
        _grp_1->push_back(_video_1); 
        _grp_1->push_back(_film_1); 
        _grp_2->push_back(_photo_2);
        _grp_2->push_back(_video_2); 
        _grp_2->push_back(_film_2);
        dataBase->searchAndPlay("Photo1"); 
        dataBase->searchAndPlay("image785"); 
        dataBase->searchAndPrint("Group1",cout); 
        dataBase->searchAndPrint("Split 2019",cout);
        
    #endif

    #if Scenario11
    
        //Le test de la 11e étape: Client / serveur

        shared_ptr<TCPServer> server(new TCPServer());
        shared_ptr<DataBase> base(new DataBase());
        base->createPhoto("photo1","Media/1.jpg"); 
        base->createVideo("vid1","Media/1.mp4");
        server->setCallback(*base, &DataBase::processRequest);
        cout << "Starting Server on port " << PORT <<"...."<< endl;
        if (server->run(PORT) < 0) {
            cerr << "Could not start Server on port " << PORT << endl;
        }   
  
    #endif        
    


 









    return 0;
}
