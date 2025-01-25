#include <iostream>
#include<bits/stdc++.h>
// abstract class 
// logprocesor
using namespace std;
enum LogLevel{INFO=1,DEBUG,ERROR};
class LogProcessor{
  public:
  LogProcessor* nextLoggerProcessor;
  LogProcessor(LogProcessor* nextLoggerProcessor){
    this->nextLoggerProcessor=nextLoggerProcessor;
  }

  virtual void log(LogLevel level,std::string msg){
    if(nextLoggerProcessor!=NULL){
      nextLoggerProcessor->log(level,msg);
    }
  }
};

class InfoLogProcesor:public LogProcessor{
  public:
  InfoLogProcesor(LogProcessor* nextLoggerProcessor):LogProcessor(nextLoggerProcessor){}
  void log(LogLevel level,std::string msg){
    if(level==LogLevel::INFO){
      std::cout<<"INFO: "<<msg<<std::endl;
    }else{
      LogProcessor::log(level,msg);
    }
  }
};

class DebugLogProcesor:public LogProcessor{
  public:
DebugLogProcesor(LogProcessor* nextLoggerProcessor):LogProcessor(nextLoggerProcessor){}
  void log(LogLevel level,std::string msg){
    if(level==LogLevel::DEBUG){
      std::cout<<"DEBUG: "<<msg<<std::endl;
    }else{
      LogProcessor::log(level,msg);
    }
  }
};
class ErrorLogProcessor:public LogProcessor{
  public:
ErrorLogProcessor(LogProcessor* nextLoggerProcessor):LogProcessor(nextLoggerProcessor){}
  void log(LogLevel level,std::string msg){
    if(level==LogLevel::ERROR){
      std::cout<<"ERROR: "<<msg<<std::endl;
    }else{
      LogProcessor::log(level,msg);
    }
  }
};

int main() { 
  std::cout << "Welcome to Log Processor!\n";

  LogProcessor* logProcessor= new LogProcessor(NULL);
  logProcessor = new InfoLogProcesor(new DebugLogProcesor(new ErrorLogProcessor(logProcessor)));

  logProcessor->log(LogLevel::DEBUG,"debug");
  logProcessor->log(LogLevel::ERROR,"error");
  logProcessor->log(LogLevel::INFO,"info");


}