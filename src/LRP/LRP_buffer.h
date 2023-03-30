#ifndef __LRP_BUFFER__
#define __LRP_BUFFER__

#include <memory>
class LRP_processor;
class LRP_buffer{
  friend class LRP_processor;
public :
  static LRP_buffer* createLrpBuffer(long size);
  void synBuffer(int32_t* input, bool isin, long len, long offset = 0 );
  ~LRP_buffer();

private:
  LRP_buffer();
  struct BufferHandle;
  std::unique_ptr<BufferHandle> mModel;
  void getBufferPtr(int32_t ** bufferbase, long* len);
};
#endif