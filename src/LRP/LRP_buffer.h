#ifndef __LRP_BUFFER__
#define __LRP_BUFFER__

#include <memory>
class LRP_processor;
class LRP_buffer{
  friend class LRP_processor;
public :
  struct LrpBufferInfo{
    long inputsize;
    long outputsize;
    long operatebuffersize;
  };
  static LRP_buffer* createLrpBuffer(LrpBufferInfo info);
  void synBuffer(int32_t* input, int32_t* output = nullptr);
  ~LRP_buffer();

private:
  LRP_buffer();
  struct BufferHandle;
  std::unique_ptr<BufferHandle> mModel;
  void getBufferPtr(int32_t ** bufferbase, long* len);
};
#endif