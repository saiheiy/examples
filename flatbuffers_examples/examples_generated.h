// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_EXAMPLES_EXAMPLES_H_
#define FLATBUFFERS_GENERATED_EXAMPLES_EXAMPLES_H_

#include "flatbuffers/flatbuffers.h"

namespace Examples {

struct Cusip;

struct Order;

struct Security;

struct Position;

enum Side {
  Side_Bid = 0,
  Side_Ask = 1,
  Side_MIN = Side_Bid,
  Side_MAX = Side_Ask
};

inline const char **EnumNamesSide() {
  static const char *names[] = {
    "Bid",
    "Ask",
    nullptr
  };
  return names;
}

inline const char *EnumNameSide(Side e) {
  const size_t index = static_cast<int>(e);
  return EnumNamesSide()[index];
}

enum PosSec {
  PosSec_NONE = 0,
  PosSec_Position = 1,
  PosSec_Security = 2,
  PosSec_MIN = PosSec_NONE,
  PosSec_MAX = PosSec_Security
};

inline const char **EnumNamesPosSec() {
  static const char *names[] = {
    "NONE",
    "Position",
    "Security",
    nullptr
  };
  return names;
}

inline const char *EnumNamePosSec(PosSec e) {
  const size_t index = static_cast<int>(e);
  return EnumNamesPosSec()[index];
}

template<typename T> struct PosSecTraits {
  static const PosSec enum_value = PosSec_NONE;
};

template<> struct PosSecTraits<Position> {
  static const PosSec enum_value = PosSec_Position;
};

template<> struct PosSecTraits<Security> {
  static const PosSec enum_value = PosSec_Security;
};

bool VerifyPosSec(flatbuffers::Verifier &verifier, const void *obj, PosSec type);
bool VerifyPosSecVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types);

MANUALLY_ALIGNED_STRUCT(4) Cusip FLATBUFFERS_FINAL_CLASS {
 private:
  uint32_t c1_;
  uint32_t c2_;
  uint32_t c3_;

 public:
  Cusip() {
    memset(this, 0, sizeof(Cusip));
  }
  Cusip(const Cusip &_o) {
    memcpy(this, &_o, sizeof(Cusip));
  }
  Cusip(uint32_t _c1, uint32_t _c2, uint32_t _c3)
      : c1_(flatbuffers::EndianScalar(_c1)),
        c2_(flatbuffers::EndianScalar(_c2)),
        c3_(flatbuffers::EndianScalar(_c3)) {
  }
  uint32_t c1() const {
    return flatbuffers::EndianScalar(c1_);
  }
  uint32_t c2() const {
    return flatbuffers::EndianScalar(c2_);
  }
  uint32_t c3() const {
    return flatbuffers::EndianScalar(c3_);
  }
};
STRUCT_END(Cusip, 12);

struct Order FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_SIDE = 4,
    VT_QTY = 6,
    VT_SYMBOL = 8,
    VT_POSSEC_TYPE = 10,
    VT_POSSEC = 12
  };
  Side side() const {
    return static_cast<Side>(GetField<int8_t>(VT_SIDE, 0));
  }
  int16_t qty() const {
    return GetField<int16_t>(VT_QTY, 0);
  }
  const flatbuffers::String *symbol() const {
    return GetPointer<const flatbuffers::String *>(VT_SYMBOL);
  }
  PosSec possec_type() const {
    return static_cast<PosSec>(GetField<uint8_t>(VT_POSSEC_TYPE, 0));
  }
  const void *possec() const {
    return GetPointer<const void *>(VT_POSSEC);
  }
  template<typename T> const T *possec_as() const;
  const Position *possec_as_Position() const {
    return possec_type() == PosSec_Position ? static_cast<const Position *>(possec()) : nullptr;
  }
  const Security *possec_as_Security() const {
    return possec_type() == PosSec_Security ? static_cast<const Security *>(possec()) : nullptr;
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int8_t>(verifier, VT_SIDE) &&
           VerifyField<int16_t>(verifier, VT_QTY) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_SYMBOL) &&
           verifier.Verify(symbol()) &&
           VerifyField<uint8_t>(verifier, VT_POSSEC_TYPE) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_POSSEC) &&
           VerifyPosSec(verifier, possec(), possec_type()) &&
           verifier.EndTable();
  }
};

template<> inline const Position *Order::possec_as<Position>() const {
  return possec_as_Position();
}

template<> inline const Security *Order::possec_as<Security>() const {
  return possec_as_Security();
}

struct OrderBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_side(Side side) {
    fbb_.AddElement<int8_t>(Order::VT_SIDE, static_cast<int8_t>(side), 0);
  }
  void add_qty(int16_t qty) {
    fbb_.AddElement<int16_t>(Order::VT_QTY, qty, 0);
  }
  void add_symbol(flatbuffers::Offset<flatbuffers::String> symbol) {
    fbb_.AddOffset(Order::VT_SYMBOL, symbol);
  }
  void add_possec_type(PosSec possec_type) {
    fbb_.AddElement<uint8_t>(Order::VT_POSSEC_TYPE, static_cast<uint8_t>(possec_type), 0);
  }
  void add_possec(flatbuffers::Offset<void> possec) {
    fbb_.AddOffset(Order::VT_POSSEC, possec);
  }
  OrderBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  OrderBuilder &operator=(const OrderBuilder &);
  flatbuffers::Offset<Order> Finish() {
    const auto end = fbb_.EndTable(start_, 5);
    auto o = flatbuffers::Offset<Order>(end);
    return o;
  }
};

inline flatbuffers::Offset<Order> CreateOrder(
    flatbuffers::FlatBufferBuilder &_fbb,
    Side side = Side_Bid,
    int16_t qty = 0,
    flatbuffers::Offset<flatbuffers::String> symbol = 0,
    PosSec possec_type = PosSec_NONE,
    flatbuffers::Offset<void> possec = 0) {
  OrderBuilder builder_(_fbb);
  builder_.add_possec(possec);
  builder_.add_symbol(symbol);
  builder_.add_qty(qty);
  builder_.add_possec_type(possec_type);
  builder_.add_side(side);
  return builder_.Finish();
}

inline flatbuffers::Offset<Order> CreateOrderDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    Side side = Side_Bid,
    int16_t qty = 0,
    const char *symbol = nullptr,
    PosSec possec_type = PosSec_NONE,
    flatbuffers::Offset<void> possec = 0) {
  return Examples::CreateOrder(
      _fbb,
      side,
      qty,
      symbol ? _fbb.CreateString(symbol) : 0,
      possec_type,
      possec);
}

struct Security FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_CUSIP = 4,
    VT_TYPE = 6,
    VT_OTC = 8
  };
  const Cusip *cusip() const {
    return GetStruct<const Cusip *>(VT_CUSIP);
  }
  const flatbuffers::String *type() const {
    return GetPointer<const flatbuffers::String *>(VT_TYPE);
  }
  bool otc() const {
    return GetField<uint8_t>(VT_OTC, 0) != 0;
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<Cusip>(verifier, VT_CUSIP) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_TYPE) &&
           verifier.Verify(type()) &&
           VerifyField<uint8_t>(verifier, VT_OTC) &&
           verifier.EndTable();
  }
};

struct SecurityBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_cusip(const Cusip *cusip) {
    fbb_.AddStruct(Security::VT_CUSIP, cusip);
  }
  void add_type(flatbuffers::Offset<flatbuffers::String> type) {
    fbb_.AddOffset(Security::VT_TYPE, type);
  }
  void add_otc(bool otc) {
    fbb_.AddElement<uint8_t>(Security::VT_OTC, static_cast<uint8_t>(otc), 0);
  }
  SecurityBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  SecurityBuilder &operator=(const SecurityBuilder &);
  flatbuffers::Offset<Security> Finish() {
    const auto end = fbb_.EndTable(start_, 3);
    auto o = flatbuffers::Offset<Security>(end);
    return o;
  }
};

inline flatbuffers::Offset<Security> CreateSecurity(
    flatbuffers::FlatBufferBuilder &_fbb,
    const Cusip *cusip = 0,
    flatbuffers::Offset<flatbuffers::String> type = 0,
    bool otc = false) {
  SecurityBuilder builder_(_fbb);
  builder_.add_type(type);
  builder_.add_cusip(cusip);
  builder_.add_otc(otc);
  return builder_.Finish();
}

inline flatbuffers::Offset<Security> CreateSecurityDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const Cusip *cusip = 0,
    const char *type = nullptr,
    bool otc = false) {
  return Examples::CreateSecurity(
      _fbb,
      cusip,
      type ? _fbb.CreateString(type) : 0,
      otc);
}

struct Position FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_QTY = 4,
    VT_NAME = 6,
    VT_ACCOUNTID = 8
  };
  int32_t qty() const {
    return GetField<int32_t>(VT_QTY, 0);
  }
  const flatbuffers::String *name() const {
    return GetPointer<const flatbuffers::String *>(VT_NAME);
  }
  uint64_t accountId() const {
    return GetField<uint64_t>(VT_ACCOUNTID, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_QTY) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_NAME) &&
           verifier.Verify(name()) &&
           VerifyField<uint64_t>(verifier, VT_ACCOUNTID) &&
           verifier.EndTable();
  }
};

struct PositionBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_qty(int32_t qty) {
    fbb_.AddElement<int32_t>(Position::VT_QTY, qty, 0);
  }
  void add_name(flatbuffers::Offset<flatbuffers::String> name) {
    fbb_.AddOffset(Position::VT_NAME, name);
  }
  void add_accountId(uint64_t accountId) {
    fbb_.AddElement<uint64_t>(Position::VT_ACCOUNTID, accountId, 0);
  }
  PositionBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  PositionBuilder &operator=(const PositionBuilder &);
  flatbuffers::Offset<Position> Finish() {
    const auto end = fbb_.EndTable(start_, 3);
    auto o = flatbuffers::Offset<Position>(end);
    return o;
  }
};

inline flatbuffers::Offset<Position> CreatePosition(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t qty = 0,
    flatbuffers::Offset<flatbuffers::String> name = 0,
    uint64_t accountId = 0) {
  PositionBuilder builder_(_fbb);
  builder_.add_accountId(accountId);
  builder_.add_name(name);
  builder_.add_qty(qty);
  return builder_.Finish();
}

inline flatbuffers::Offset<Position> CreatePositionDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t qty = 0,
    const char *name = nullptr,
    uint64_t accountId = 0) {
  return Examples::CreatePosition(
      _fbb,
      qty,
      name ? _fbb.CreateString(name) : 0,
      accountId);
}

inline bool VerifyPosSec(flatbuffers::Verifier &verifier, const void *obj, PosSec type) {
  switch (type) {
    case PosSec_NONE: {
      return true;
    }
    case PosSec_Position: {
      auto ptr = reinterpret_cast<const Position *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case PosSec_Security: {
      auto ptr = reinterpret_cast<const Security *>(obj);
      return verifier.VerifyTable(ptr);
    }
    default: return false;
  }
}

inline bool VerifyPosSecVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types) {
  if (values->size() != types->size()) return false;
  for (flatbuffers::uoffset_t i = 0; i < values->size(); ++i) {
    if (!VerifyPosSec(
        verifier,  values->Get(i), types->GetEnum<PosSec>(i))) {
      return false;
    }
  }
  return true;
}

inline const Examples::Position *GetPosition(const void *buf) {
  return flatbuffers::GetRoot<Examples::Position>(buf);
}

inline bool VerifyPositionBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<Examples::Position>(nullptr);
}

inline void FinishPositionBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Examples::Position> root) {
  fbb.Finish(root);
}

}  // namespace Examples

#endif  // FLATBUFFERS_GENERATED_EXAMPLES_EXAMPLES_H_
