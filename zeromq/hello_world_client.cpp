#include <zmq.hpp>
#include <string>
#include <iostream>

int main(){
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_REQ);

    std::cout << "Connecting to hello world server.." << std::endl;
    socket.connect("tcp://localhost:5555");

    for(int rn=0; rn != 10; ++rn){
        zmq::message_t request(5);
        memcpy(request.data(), "Hello", 5);
        std::cout << "Sending Hello " << rn << "..." << std::endl;
        socket.send(request);
        zmq::message_t reply;
        socket.recv(&reply);
        std::string *reply_str = static_cast<std::string *>(reply.data());
        std::cout << "Received reply: " << reply_str << std::endl;
    }
    return 0;
}
