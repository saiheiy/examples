#include <zmq.hpp>
#include <string>
#include <iostream>
#include <unistd.h>

int main(){
    zmq::context_t context(1);
    zmq::socket_t socket (context, ZMQ_REP);
    socket.bind("tcp://*:5555");
    while (true){
        zmq::message_t request;
        socket.recv(&request);
        std::string *req_str = static_cast<std::string *>(request.data());
        std::cout << "Received request: " <<  *req_str << std::endl;
        sleep(1);

        zmq::message_t reply(5);
        memcpy(reply.data(), "World", 5);
        socket.send(reply);
    }
    return 0;
}
