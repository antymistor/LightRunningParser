#ifndef __LRP_BUFFER__
#define __LRP_BUFFER__

#include <memory>
class LRP_processor;
class LRP_buffer{
  friend class LRP_processor;
public :
  struct LrpBufferInfo{
    long inputsize = 0;
    long outputsize = 0;
    long operatebuffersize = 0;
  };
  static LRP_buffer* createLrpBuffer(LrpBufferInfo info);
  void synBuffer(long* input, long* output = nullptr);
  ~LRP_buffer();

private:
  LRP_buffer();
  struct BufferHandle;
  std::unique_ptr<BufferHandle> mModel;
  void getBufferPtr(long** input, long** output, long** operate);
};
#endif