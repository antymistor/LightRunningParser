
#include "convert_utils.h"
#include <unordered_map>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "LRP_operate.h"

void split(const std::string& src, std::vector<std::string>& decvector, const char splitchar = ' ') {
    decvector.clear();
    std::istringstream iss(src);
    std::string temp;
    while (std::getline(iss, temp, splitchar)) {
        decvector.emplace_back(std::move(temp));
    }
    return;
}

static std::unordered_map<std::string, int8_t> oplist = {
    {"SET",0},
    {"COP",1},
    {"ADD",2},
    {"DEL",3},
    {"MUL",4},
    {"DIV",5},
    {"MAX",6},
    {"MIN",7},
    {"AND",8},
    {"OR" ,9},
    {"NOT",10},
    {"BIG",11},
    {"SMA",12},
    {"EQA",13},
    {"IF" ,14},
    {"JUM",15}
};

RESULT convertEasyFile2HardFile(const char* srcfile, const char* destfile, bool isBigEndian){
   std::ifstream infile(srcfile);
   std::string lineStr;
   std::vector<std::string> linevec;
   std::vector<operate> opvec;
   
   while( std::getline(infile, lineStr ) ){
      linevec.clear();
      split(lineStr, linevec, ' ');
      if(linevec.size() < 2 || linevec.size() > 4 ||  oplist.end() == oplist.find(linevec[0]) ){
        std::cout << "FAIL :: input file has errors!!" << std::endl;
          return FAIL;
      }
      operate ope;
      ope.op = oplist[linevec[0]];
      ope.data.data0 = std::stoi(linevec[1]);
      ope.data.data1 = ope.data.data2 = 0;
      if(ope.op == 0 ){  //SET
        int32_t num = std::stoi(linevec[2]);
        ope.data.data1 = num >> 16;
        ope.data.data2 = num & 0xffff;
      }else if(ope.op == 1 || ope.op == 10){ // COP NOT
         ope.data.data1 = std::stoi(linevec[2]);
      }else if(ope.op == 15){ //JUM
      }else{
         ope.data.data1 = std::stoi(linevec[2]);
         ope.data.data2 = std::stoi(linevec[3]);
      }
      opvec.emplace_back(ope);
   }
   infile.close();
   

   //write
   std::ofstream outfile(destfile, std::ios::trunc | std::ios::out | std::ios::binary);
   outfile.write( (char* )(&opvec[0]), opvec.size()*sizeof(operate));

   outfile.close();

   return OK;
}