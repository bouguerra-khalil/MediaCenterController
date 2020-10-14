
#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "tcpserver.h"
using namespace std;
using namespace cppu;

const int PORT = 3331;

class MyBase {
public:
  /* This method is called evreytime there is a request to be executed
   * 
   * Arguments:
   * - 'request' contains the request 
   * - 'response'  indicate the response of the server to the client
   * -  If it send false the connection is closed 
   * - si la fonction renvoie false la connexion est close.
   *
   * This method can be called in parallel ( multiple threads ) one thread for each client   *
   */
  bool processRequest(TCPConnection& cnx, const string& request, string& response)
  {
    //For now the server respond with just "OK"+resuqest ( To be Editted later )
    cerr << "\nRequest: '" << request << "'" << endl;
    response = "OK: " + request;
    cerr << "response: " << response << endl;
    // Return false  to close the connection 
    return true;
  }
};


int main(int argc, char* argv[])
{
  // create the TCP server 
  shared_ptr<TCPServer> server(new TCPServer());
  
  // create the object that handle the data 
  shared_ptr<MyBase> base(new MyBase());

  // the server calls this method everytime it recieves a request 
  server->setCallback(*base, &MyBase::processRequest);
  
  cout << "Starting Server on port " << PORT << endl;
  int status = server->run(PORT);
  
  // in case of error 
  if (status < 0) {
    cerr << "Could not start Server on port " << PORT << endl;
    return 1;
  }
  
  return 0;
}

