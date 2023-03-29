#ifndef __LRP_OPERATE__
#define __LRP_OPERATE__
#include <cstdint>
struct data{      //6 bytes
    int16_t data0;
    int16_t data1;
    int16_t data2;
}__attribute__ ((__packed__));

struct operate{    //7 bytes
int8_t op;
data data;
}__attribute__ ((__packed__));

typedef void(*opefun)(int32_t*, data*, long*);

void SET(int32_t* buffer, data* data, long* p); //0
void COP(int32_t* buffer, data* data, long* p); //1
void ADD(int32_t* buffer, data* data, long* p); //2
void DEL(int32_t* buffer, data* data, long* p); //3
void MUL(int32_t* buffer, data* data, long* p); //4
void DIV(int32_t* buffer, data* data, long* p); //5
void MAX(int32_t* buffer, data* data, long* p); //6
void MIN(int32_t* buffer, data* data, long* p); //7
void AND(int32_t* buffer, data* data, long* p); //8
void OR(int32_t* buffer, data* data, long* p);  //9
void NOT(int32_t* buffer, data* data, long* p); //10
void BIG(int32_t* buffer, data* data, long* p); //11
void SMA(int32_t* buffer, data* data, long* p); //12
void EQA(int32_t* buffer, data* data, long* p); //13
void IF(int32_t* buffer, data* data, long* p);  //14
void JUM(int32_t* buffer, data* data, long* p); //15

const opefun opeArrayList[16] = {SET,COP,ADD,DEL,MUL,DIV,MAX,MIN,
                                 AND,OR ,NOT,BIG,SMA,EQA,IF ,JUM};

#endif