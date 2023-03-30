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
     //readfile to operateArray
     infile.seekg(0, std::ios_base::beg);
     mModel->operatelen = len / operatebytelen;
     if(mModel->operateArray){
         delete[] mModel->operateArray;
     }
     mModel->operateArray = new operate[mModel->operatelen];
     infile.read((char *)(mModel->operateArray), mModel->operatelen* sizeof(operate));
   //   //print result
   //   for(int i=0 ; i!= mModel->operatelen; ++i){
   //      std::cout << "index = [" << i << "]  "
   //                << (int)(mModel->operateArray[i].op) 
   //                << " " << (mModel->operateArray[i].data.data0) 
   //                << " " << (mModel->operateArray[i].data.data1) 
   //                << " " << (mModel->operateArray[i].data.data2) 
   //                << std::endl;
   //   }
  }
  void LRP_processor::run(){
     while(mModel->currentpointer < mModel->operatelen){
        opeArrayList[mModel->operateArray[mModel->currentpointer].op]
        (mModel->buffer, &(mModel->operateArray[mModel->currentpointer].data), &mModel->currentpointer);
     }
  }