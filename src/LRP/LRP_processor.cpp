#include "LRP_processor.h"
#include <fstream>
#include <iostream>
#include "LRP_operate.h"
#define operatebytelen 7
  struct LRP_processor::ProcessHandle{
     long currentpointer;
     long operatelen;
     long bufferlen;
     operate* operateArray;
     int32_t* buffer;
     ~ProcessHandle(){
        if(operateArray){
            delete[] operateArray;
        }
     }
  };

  LRP_processor::LRP_processor():mModel(new ProcessHandle()){}

  LRP_processor::~LRP_processor(){}

  void LRP_processor::setBuffer(LRP_buffer *buffer){
    buffer->getBufferPtr(&mModel->buffer,&mModel->bufferlen);
  }
  void LRP_processor::compileRunable(const char* r){
     
     //openfile and get file size
     std::ifstream infile;
     infile.open(r, std::ios_base::binary);
     infile.seekg(0, std::ios_base::end);
     long len = infile.tellg();
     std::cout << "size = " << len <<"   sizeofunion = " << sizeof(operate) <<std::endl;
     
     //readfile to operateArray
     infile.seekg(0, std::ios_base::beg);
     mModel->operatelen = len / operatebytelen;
     mModel->operateArray = new operate[mModel->operatelen];
     infile >> (char *)(mModel->operateArray);
   
     //print result
     for(int i=0 ; i!= mModel->operatelen; ++i){
        std::cout << "opt index = " << i 
                  << "\r\n"
                  << " 0_opt  = " << (int)(mModel->operateArray[i].op) 
                  << " 0_dat0 = " << (mModel->operateArray[i].data.data0) 
                  << " 0_dat1 = " << (mModel->operateArray[i].data.data1) 
                  << " 0_dat2 = " << (mModel->operateArray[i].data.data2) 
                  << "\r\n\r\n" 
                  << std::endl;
     }
  }
  void LRP_processor::run(){
     while(mModel->currentpointer < mModel->operatelen){
        opeArrayList[mModel->operateArray[mModel->currentpointer].op]
        (mModel->buffer, &(mModel->operateArray[mModel->currentpointer].data), &mModel->currentpointer);
     }
  }