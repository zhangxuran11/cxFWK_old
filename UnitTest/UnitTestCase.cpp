#include "UnitTestCase.h"
#include <sstream>

namespace CXF
{

    UnitTestCase::UnitTestCase(const char* name,UnitTestCaseFunc func)
    {
        isOkay = true;
        mSummary = ".";
        mCaseFunc = func;
        mName = name;
    }
    UnitTestCase::~UnitTestCase(){

    }

    void UnitTestCase::run()
    {
        mCaseFunc(this);
    }
    void UnitTestCase::assertFailured(const char *file, int line, const char *msg)
    {
        std::stringstream ss;
        ss << file << ":" << line << " " << msg;
        mMsg = ss.str();
        isOkay = false;
        mSummary = "F";
        mFailMsgLines = mName+": "+mMsg;
    }
    int UnitTestCase::count()
    {
        return 1;
    }
    int UnitTestCase::failCount()
    {
        return isOkay == true ? 0 : 1;
    }
    const std::string& UnitTestCase::summary(){
        return mSummary;
    }
     std::string UnitTestCase::failMsgLines(){
        return mName+": "+mMsg+"\n";
    }

} // namespace CXF