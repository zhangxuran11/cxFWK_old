#include "UnitTestCase.h"
namespace CXF {
    
    UnitTestCase::UnitTestCase(UnitTestCaseFunc func){
        mCaseFunc = func;
    }

    void UnitTestCase::run(){
        mCaseFunc(this);
    }

}