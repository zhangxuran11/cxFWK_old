#include "UnitTestSuite.h"
#include <iostream>
namespace CXF{
    UnitTestSuite::UnitTestSuite(){

    }
    void UnitTestSuite::run(){
        for(auto it = mRunnables.begin(); it!= mRunnables.end();it++){
            UnitTestRunnable* runnable = *it;
            runnable->run();
        }
    }
    void UnitTestSuite::add(UnitTestRunnable* runnable){
        mRunnables.push_back(runnable);
    }
    void UnitTestSuite::print(){
        std::cout<<"hello"<<std::endl;
    }
    UnitTestSuite::~UnitTestSuite(){

    }
}