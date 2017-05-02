package com.saihei.examples;

import Examples.Position;
import com.google.flatbuffers.FlatBufferBuilder;



public class FbWriter {
    public static void main(String[] args) {
        //serialization
        FlatBufferBuilder builder = new FlatBufferBuilder(1024);
        int qty = 20;
        int name = builder.createString("IBM");
        long accountId = 919191919191L;
        Position.startPosition(builder);
        Position.addQty(builder, qty);
        Position.addName(builder, name);
        Position.addAccountId(builder, accountId);
        int pos = Position.endPosition(builder);
        builder.finish(pos);
        //byte[] buf = builder.sizedByteArray();
        java.nio.ByteBuffer buf = builder.dataBuffer();

        //deserialization
        Position read_pos = Position.getRootAsPosition(buf);
        int read_qty = read_pos.qty();
        String read_name = read_pos.name();
        long read_accountId = read_pos.accountId();
        System.out.format("qty: %d, name: %s, accountId: %d\n", read_qty, read_name, read_accountId);
    }
}
