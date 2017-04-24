#include "examples_generated.h"
#include <fstream>

int main(){
    flatbuffers::FlatBufferBuilder builder(1024);
    int32_t qty = 40;
    auto name = builder.CreateString("IBM");
    uint64_t accountId = 91919191919;
    Examples::PositionBuilder position_builder(builder);
    position_builder.add_qty(qty);
    position_builder.add_name(name);
    position_builder.add_accountId(accountId);
    auto pos = position_builder.Finish();
    builder.Finish(pos);

    std::ofstream ofs("pos.fbo", std::ofstream::binary);
    ofs.write((char *) builder.GetBufferPointer(), builder.GetSize());
    ofs.close();
    return 0;
}
