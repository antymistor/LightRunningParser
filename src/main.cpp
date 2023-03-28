#include <iostream>
#include "LRP_buffer.h"
#include "LRP_processor.h"
int main(){
    long input[10];
    long output[3];

    LRP_buffer::LrpBufferInfo info;
    info.inputsize = 10;
    info.outputsize = 3;
    info.operatebuffersize = 100;
    auto buffer = LRP_buffer::createLrpBuffer(info);
    buffer->synBuffer(input);
    auto processor = new LRP_processor();
    processor->setBuffer(buffer);
    processor->compileRunable("");
    processor->run();
    buffer->synBuffer(nullptr, output);

    delete buffer;
    delete processor;
    std::cout << "hello world LRP" <<std::endl;
}
