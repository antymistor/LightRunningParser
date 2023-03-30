#include <iostream>
#include "LRP_buffer.h"
#include "LRP_processor.h"
#include "convert_utils.h"
int main(int argc,char *argv[]){
    convertEasyFile2HardFile("origin.txt","origin.dat");
    
    int32_t* buffer = nullptr;
    unsigned inputlen = 0;
    if(argc > 1){
        inputlen = argc - 1;
        buffer = new int32_t[inputlen + 1];
        for(int i = 1; i != argc ; ++i){
            buffer[i-1] = std::stoi(std::string(argv[i]));
        }
    }
    if(buffer == nullptr){
        inputlen = 2;
        buffer = new int32_t[3];
        buffer[0]= 19; buffer[1]=56; buffer[2]=0; 
    }
    LRP_buffer* lrbuffer = LRP_buffer::createLrpBuffer(33);
    lrbuffer->synBuffer(buffer,true, inputlen, 0);
    LRP_processor* processor = new LRP_processor();
    processor->setBuffer(lrbuffer);
    processor->compileRunable("origin.dat");
    processor->run();
    lrbuffer->synBuffer(buffer + 2, false, 1, inputlen);

    delete lrbuffer;
    delete processor;
    delete[] buffer;
    std::cout << "hello world LRP --> ret = "<< buffer[inputlen]  <<std::endl;
    return 0;
}
