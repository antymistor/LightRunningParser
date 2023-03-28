#include "LRP_processor.h"
  struct LRP_processor::ProcessHandle{
     long currentpointer = 0;
     long** operateArray = nullptr;
     long* input = nullptr;
     long* output = nullptr;
     long* operate = nullptr;
  };

  LRP_processor::LRP_processor():mModel(std::make_unique<ProcessHandle>()){}

  void LRP_processor::setBuffer(LRP_buffer *buffer){
    buffer->getBufferPtr(&mModel->input, &mModel->output, &mModel->operate);
  }
  void LRP_processor::setRunable(const char* r){

  }
  void LRP_processor::run(){

  }