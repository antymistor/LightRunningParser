#include <iostream>
#include "LRP_buffer.h"
#include "LRP_processor.h"
int main(){
    int32_t input[10];
    int32_t output[3];

    LRP_buffer::LrpBufferInfo info;
    info.inputsize = 10;
    info.outputsize = 3;
    info.operatebuffersize = 100;
    LRP_buffer* buffer = LRP_buffer::createLrpBuffer(info);
    buffer->synBuffer(input);
    LRP_processor* processor = new LRP_processor();
    processor->setBuffer(buffer);
    processor->compileRunable("afile.dat");
    processor->run();
    buffer->synBuffer(nullptr, output);

    delete buffer;
    delete processor;
    std::cout << "hello world LRP" <<std::endl;
    return 0;
}
