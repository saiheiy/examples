// automatically generated by the FlatBuffers compiler, do not modify

package Examples;

import java.nio.*;
import java.lang.*;
import java.util.*;
import com.google.flatbuffers.*;

@SuppressWarnings("unused")
public final class Order extends Table {
  public static Order getRootAsOrder(ByteBuffer _bb) { return getRootAsOrder(_bb, new Order()); }
  public static Order getRootAsOrder(ByteBuffer _bb, Order obj) { _bb.order(ByteOrder.LITTLE_ENDIAN); return (obj.__assign(_bb.getInt(_bb.position()) + _bb.position(), _bb)); }
  public void __init(int _i, ByteBuffer _bb) { bb_pos = _i; bb = _bb; }
  public Order __assign(int _i, ByteBuffer _bb) { __init(_i, _bb); return this; }

  public byte side() { int o = __offset(4); return o != 0 ? bb.get(o + bb_pos) : 0; }
  public short qty() { int o = __offset(6); return o != 0 ? bb.getShort(o + bb_pos) : 0; }
  public String symbol() { int o = __offset(8); return o != 0 ? __string(o + bb_pos) : null; }
  public ByteBuffer symbolAsByteBuffer() { return __vector_as_bytebuffer(8, 1); }
  public byte possecType() { int o = __offset(10); return o != 0 ? bb.get(o + bb_pos) : 0; }
  public Table possec(Table obj) { int o = __offset(12); return o != 0 ? __union(obj, o) : null; }

  public static int createOrder(FlatBufferBuilder builder,
      byte side,
      short qty,
      int symbolOffset,
      byte possec_type,
      int possecOffset) {
    builder.startObject(5);
    Order.addPossec(builder, possecOffset);
    Order.addSymbol(builder, symbolOffset);
    Order.addQty(builder, qty);
    Order.addPossecType(builder, possec_type);
    Order.addSide(builder, side);
    return Order.endOrder(builder);
  }

  public static void startOrder(FlatBufferBuilder builder) { builder.startObject(5); }
  public static void addSide(FlatBufferBuilder builder, byte side) { builder.addByte(0, side, 0); }
  public static void addQty(FlatBufferBuilder builder, short qty) { builder.addShort(1, qty, 0); }
  public static void addSymbol(FlatBufferBuilder builder, int symbolOffset) { builder.addOffset(2, symbolOffset, 0); }
  public static void addPossecType(FlatBufferBuilder builder, byte possecType) { builder.addByte(3, possecType, 0); }
  public static void addPossec(FlatBufferBuilder builder, int possecOffset) { builder.addOffset(4, possecOffset, 0); }
  public static int endOrder(FlatBufferBuilder builder) {
    int o = builder.endObject();
    return o;
  }
}

