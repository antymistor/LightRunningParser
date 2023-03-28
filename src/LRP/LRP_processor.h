#ifndef __LRP_PROCESSOR__
#define __LRP_PROCESSOR__
#include "LRP_buffer.h"
#include <memory>
class LRP_processor{
public :
  LRP_processor();
  ~LRP_processor();
  void setBuffer(LRP_buffer *buffer);
  void compileRunable(const char* r);  
  void run(); 
private:
  struct ProcessHandle;
  std::unique_ptr<ProcessHandle> mModel;
};

#endif