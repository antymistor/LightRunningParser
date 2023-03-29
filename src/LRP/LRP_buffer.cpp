#include "LRP_buffer.h"
  struct LRP_buffer::BufferHandle{
    int32_t* buffer;
    LrpBufferInfo info;  
     ~BufferHandle(){
        delete[] buffer;
     }
  };
 
  LRP_buffer::LRP_buffer():mModel(new BufferHandle()){}
  LRP_buffer* LRP_buffer::createLrpBuffer(LrpBufferInfo info){
    LRP_buffer* buffer = new LRP_buffer();
    buffer->mModel->info = info;
    buffer->mModel->buffer = new int32_t[info.inputsize + info.outputsize + info.operatebuffersize];
    return buffer;
  }
  void LRP_buffer::synBuffer(int32_t* input, int32_t* output){
    if(input){
     memcpy(mModel->buffer, input, mModel->info.inputsize);
    }
    if(output){
     memcpy(output, mModel->buffer + mModel->info.inputsize, mModel->info.outputsize);
    }
  }
  LRP_buffer::~LRP_buffer(){}

  void LRP_buffer::getBufferPtr(int32_t ** bufferbase, long* len){
    *bufferbase = mModel->buffer;
    *len = mModel->info.inputsize + mModel->info.outputsize + mModel->info.operatebuffersize;
  }
