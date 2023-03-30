#ifndef __CONVERT_UTILS__
#define __CONVERT_UTILS__

enum RESULT{
  OK,
  FAIL,
};

RESULT convertEasyFile2HardFile(const char* srcfile, const char* destfile, bool isBigEndian = false);


#endif