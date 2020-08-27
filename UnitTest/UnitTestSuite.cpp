#include "UnitTestSuite.h"
#include <iostream>
#include <sstream>
namespace CXF
{
    UnitTestSuite::UnitTestSuite()
    {
    }
    void UnitTestSuite::run()
    {
        for (auto it = mRunnables.begin(); it != mRunnables.end(); it++)
        {
            UnitTestRunnable *runnable = *it;
            runnable->run();
            mSummary += runnable->summary();
            mFailMsgLines += runnable->failMsgLines();
        }
    }
    const std::string &UnitTestSuite::summary()
    {
        return mSummary;
    }
    std::string UnitTestSuite::failMsgLines()
    {
        return mFailMsgLines;
    }
    std::string UnitTestSuite::report()
    {
        std::stringstream ss;
        ss << summary() << std::endl;
        int total = count();
        int fail_count = failCount();
        if (fail_count == 0)
        {
            ss << "OK (" << total << (total == 1 ? " test)" : " test1)") << std::endl;
        }
        else
        {
            if (fail_count == 1)
                ss << "There was 1 failure:" << std::endl;
            else
                ss << "There were " << fail_count << " failures:" << std::endl;
            
            for (auto it = mRunnables.begin(); it != mRunnables.end(); it++)
            {
                UnitTestRunnable *runnable = *it;
                ss << runnable->failMsgLines();
            }
            ss<<std::endl<<"!!!FAILURES!!!"<<std::endl;
            ss<<"Runs: "<<total;
            ss<<" Passes: "<<total-fail_count;
            ss<<" Fails: "<<fail_count<<std::endl;
        }

        return ss.str();
    }
    void UnitTestSuite::add(UnitTestRunnable *runnable)
    {
        mRunnables.push_back(runnable);
    }
    void UnitTestSuite::print()
    {
        std::cout << report() << std::endl;
    }
    UnitTestSuite::~UnitTestSuite()
    {
        for (auto it = mRunnables.begin(); it != mRunnables.end(); it++)
        {
            UnitTestRunnable *runnable = *it;
            delete runnable;
        }
        mRunnables.clear();
    }
    int UnitTestSuite::count()
    {
        int cnt = 0;
        for (auto it = mRunnables.begin(); it != mRunnables.end(); it++)
        {
            UnitTestRunnable *runnable = *it;
            cnt += runnable->count();
        }
        return cnt;
    }
    int UnitTestSuite::failCount()
    {
        int fail_cnt = 0;
        for (auto it = mRunnables.begin(); it != mRunnables.end(); it++)
        {
            UnitTestRunnable *runnable = *it;
            fail_cnt += runnable->failCount();
        }
        return fail_cnt;
    }
} // namespace CXF