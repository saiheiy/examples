package com.saihei.demo;
import org.zeromq.ZMQ;

public class HelloWorldServer{
    public static void main(String[] args) throws Exception{
        ZMQ.Context context = ZMQ.context(1);
        ZMQ.Socket socket = context.socket(ZMQ.REP);
        socket.bind("tcp://localhost:5555");
        while (!Thread.currentThread().isInterrupted()){
            byte[] request = socket.recv(0);
            System.out.println("Received : [" + new String(request, ZMQ.CHARSET) + "]");
            String reply = "World";
            socket.send(reply.getBytes(ZMQ.CHARSET), 0);
            Thread.sleep(1000);
        }
        socket.close();
        context.term();
    }
}
