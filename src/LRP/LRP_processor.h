#ifndef __LRP_PROCESSOR__
#define __LRP_PROCESSOR__
#include "LRP_buffer.h"
class LRP_processor{
public :
  LRP_processor();
  void setBuffer(LRP_buffer *buffer);
  void setRunable(const char* r);  
  void run(); 
private:
  struct ProcessHandle;
  std::unique_ptr<ProcessHandle> mModel;
};

#endif