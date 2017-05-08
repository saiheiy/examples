package com.saihei.demo;
import org.zeromq.ZMQ;

public class HelloWorldClient{
    public static void main(String[] args) throws Exception{
        ZMQ.Context context = ZMQ.context(1);  //1 rep number of threads
        System.out.println("Connecting to hello world server");
        ZMQ.Socket socket = context.socket(ZMQ.REQ);
        socket.connect("tcp://localhost:5555");
        for(int rn=0; rn != 10; rn++){
            String request = "Hello";
            System.out.println("Sending Hello " + rn);
            socket.send(request.getBytes(ZMQ.CHARSET), 0);
            byte[] reply = socket.recv(0);
            System.out.println("Received " + new String(reply, ZMQ.CHARSET) + " " + rn);
        }
        socket.close();
        context.term();
    }
}
