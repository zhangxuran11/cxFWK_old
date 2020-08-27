#ifndef UNIT_TEST_CASE_H
#define UNIT_TEST_CASE_H
#include "UnitTestRunnable.h"
#include <string>
namespace CXF {
    class UnitTestCase : public UnitTestRunnable{
        bool isOkay;
        std::string mName;
        std::string mMsg;
        std::string mFailMsgLines;
        std::string mSummary;
        public:
            typedef bool (*UnitTestCaseFunc)(UnitTestCase*);
        private:
            std::string mLogStr;
            UnitTestCaseFunc mCaseFunc;
        public:
            void assertFailured(const char* file,int line,const char* msg);
            UnitTestCase(const char* name,UnitTestCaseFunc func);
            ~UnitTestCase();
            void run();
            int count();
            int failCount();
            const std::string& summary();
            std::string failMsgLines();
            void print();
    };
}
#endif//UNIT_TEST_CASE_H
