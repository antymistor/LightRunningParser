#include "LRP_buffer.h"
  struct LRP_buffer::BufferHandle{
    int32_t* buffer;
    long size;
  };
 
  LRP_buffer::LRP_buffer():mModel(new BufferHandle()){}
  LRP_buffer* LRP_buffer::createLrpBuffer(long size){
    LRP_buffer* buffer = new LRP_buffer();
    buffer->mModel->size = size;
    buffer->mModel->buffer = new int32_t[size];
    return buffer;
  }
  void LRP_buffer::synBuffer(int32_t* input, bool isin, long len, long offset){
    if(isin){
      memcpy(mModel->buffer + offset, input, len * sizeof(int32_t));
    }else{
      memcpy(input, mModel->buffer + offset, len * sizeof(int32_t));
    }
  }
  LRP_buffer::~LRP_buffer(){}

  void LRP_buffer::getBufferPtr(int32_t ** bufferbase, long* len){
    *bufferbase = mModel->buffer;
    *len = mModel->size;
  }
