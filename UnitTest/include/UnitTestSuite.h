#ifndef UNIT_TEST_SUITE_H
#define UNIT_TEST_SUITE_H
#include <string>
#include <list>
#include "UnitTestRunnable.h"
namespace CXF {
    class UnitTestSuite : public UnitTestRunnable{
        std::string mSummary;
        std::string mFailMsgLines;
        std::string mLogStr;
        std::list<UnitTestRunnable*> mRunnables;
        public:
            UnitTestSuite();
            virtual ~UnitTestSuite();
            int count();
            int failCount();
            const std::string& summary();
            std::string failMsgLines();
            
            void add(UnitTestRunnable* );
            void run();
            std::string report();
            void print();
    };
}



#endif//UNIT_TEST_SUITE_H