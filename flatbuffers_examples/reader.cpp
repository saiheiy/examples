#include "examples_generated.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

int main(){
    std::ifstream ifs("pos.fbo", std::ios::binary);
    ifs.seekg(0, std::ios::end);
    std::streamsize size = ifs.tellg();
    ifs.seekg(0, std::ios::beg);
    std::vector<char> buffer(size) ;
    ifs.read(buffer.data(), size);
    flatbuffers::Verifier verifier((uint8_t *) buffer.data(), buffer.size());
    bool ok = Examples::VerifyPositionBuffer(verifier);
    if(ok){
        auto pos = Examples::GetPosition(buffer.data());
        std::cout << "qty: " <<  pos->qty() << ", "
            << "name: " << pos->name()->c_str() << ", "
            << "accountId: " << pos->accountId() << std::endl;
    }
    else{
        throw std::runtime_error("verify failed");
    }
    
    
    return 0;
}
