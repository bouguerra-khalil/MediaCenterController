#include <iostream>
#include <string>
#include <algorithm>
#include "cppsocket.h"
using namespace std;
using namespace cppu;

static const string HOST = "localhost";
static const int PORT = 3331;


/// Read a request from the console
/// Send the request to the server 
/// Execute the request on the server 
/// Wait for the response  and print it on the console 

int main() {
  Socket sock;
  SocketBuffer sockbuf(sock);
  
  int status = sock.connect(HOST, PORT);
  
  if (status < 0) {
    switch (status) {
      case Socket::Failed:
        cerr << "Client: Couldn't reach host "<<HOST<<":"<<PORT << endl;
        return 1;
      case Socket::UnknownHost:
        cerr << "Client: Couldn't find host "<<HOST<<":"<<PORT << endl;
        return 1;
      default:
        cerr << "Client: Couldn't connect host "<<HOST<<":"<<PORT << endl;
        return 1;
    }
  }
  
  cout << "Client connected to "<< HOST<<":"<<PORT << endl;
  
  while (cin) {
    cout << "Request: ";
    string request, response;
    
    getline(cin, request);
    if (request == "quit") return 0;
    
    // Send request to the server 
    if (sockbuf.writeLine(request) < 0) {
      cerr << "Client: Couldn't send message" << endl;
      return 2;
    }
    
    // Recieve the reponse from the server
    if (sockbuf.readLine(response) < 0) {
      cerr << "Client: Couldn't receive message" << endl;
      return 2;
    }
    
    // The server replace  '\n' with  ';' because '\n' indicate that 
    // the end of the exchange of the server anver and client.
    // So we reverse that here 
    replace(response.begin(), response.end(), ';', '\n');
    
    cout << "Response: " << response << endl;
  }
}
