#include "LRP_buffer.h"
  struct LRP_buffer::BufferHandle{
    long* inputbuffer;
    long* outputbuffer;
    long* operatebuffer;
     ~BufferHandle(){
        if(inputbuffer){
            delete[] inputbuffer;
        }
        if(outputbuffer){
            delete[] outputbuffer;
        }
        if(operatebuffer){
            delete[] operatebuffer;
        }
     }
     LrpBufferInfo info;   
  };
 
  LRP_buffer::LRP_buffer():mModel(std::make_unique<BufferHandle>()){}
  LRP_buffer* LRP_buffer::createLrpBuffer(LrpBufferInfo info){
    auto buffer = new LRP_buffer();
    buffer->mModel->inputbuffer = new long[info.inputsize];
    buffer->mModel->outputbuffer = new long[info.outputsize];
    buffer->mModel->operatebuffer = new long[info.operatebuffersize];
    buffer->mModel->info = info;
  }
  void LRP_buffer::synBuffer(long* input, long* output){
    if(input){
     memcpy(mModel->inputbuffer, input, mModel->info.inputsize);
    }
    if(output){
     memcpy(output, mModel->outputbuffer, mModel->info.outputsize);
    }
  }
  LRP_buffer::~LRP_buffer(){}

  void LRP_buffer::getBufferPtr(long** input, long** output, long** operate){
    *input = mModel->inputbuffer;
    *output = mModel->outputbuffer;
    *operate = mModel->operatebuffer;
  }
