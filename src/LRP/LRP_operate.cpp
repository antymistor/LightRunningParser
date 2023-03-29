#include "LRP_operate.h"

void SET(int32_t* buffer, data* data, long* p){               
   buffer[data->data0] = ((int32_t)(data->data1) << 16) + data->data2;
   ++*p;
}

void COP(int32_t* buffer, data* data, long* p){
   buffer[data->data0] = buffer[data->data1];
   ++*p;
}
void ADD(int32_t* buffer, data* data, long* p){
   buffer[data->data0] = buffer[data->data1] + buffer[data->data2];
   ++*p;
}
void DEL(int32_t* buffer, data* data, long* p){
   buffer[data->data0] = buffer[data->data1] - buffer[data->data2];
   ++*p;
}
void MUL(int32_t* buffer, data* data, long* p){
    buffer[data->data0] = buffer[data->data1] * buffer[data->data2];
   ++*p;

}
void DIV(int32_t* buffer, data* data, long* p){
    buffer[data->data0] = buffer[data->data1] / buffer[data->data2];
   ++*p;
}
void MAX(int32_t* buffer, data* data, long* p){
   buffer[data->data0] = buffer[data->data1] > buffer[data->data2] ? buffer[data->data1] : buffer[data->data2];
   ++*p;
}
void MIN(int32_t* buffer, data* data, long* p){
   buffer[data->data0] = buffer[data->data1] < buffer[data->data2] ? buffer[data->data1] : buffer[data->data2];
   ++*p;
}
void AND(int32_t* buffer, data* data, long* p){
   buffer[data->data0] = buffer[data->data1] && buffer[data->data2];
   ++*p;
}
void OR(int32_t* buffer, data* data, long* p){
   buffer[data->data0] = buffer[data->data1] || buffer[data->data2];
   ++*p;
}
void NOT(int32_t* buffer, data* data, long* p){
    buffer[data->data0] = buffer[data->data1] !=0 ;
   ++*p;
}
void BIG(int32_t* buffer, data* data, long* p){
   buffer[data->data0] = buffer[data->data1] > buffer[data->data2];
   ++*p;
}
void SMA(int32_t* buffer, data* data, long* p){
   buffer[data->data0] = buffer[data->data1] < buffer[data->data2];
   ++*p;
}
void EQA(int32_t* buffer, data* data, long* p){
   buffer[data->data0] = buffer[data->data1] == buffer[data->data2];
   ++*p;
}
void IF(int32_t* buffer, data* data, long* p){
   *p = buffer[data->data0] ? data->data1 : data->data2;
}
void JUM(int32_t* buffer, data* data, long* p){
   *p = data->data0;
}


