#include <condition_variable>
#include <mutex>
#include <thread>
#include "gtest/gtest.h"
using namespace std;
namespace
{
  // 实现多线程的交替执行
  class ZeroEvenOdd
  {
  private:
    int n;
    mutex mtx;
    condition_variable cv;
    int k = 0;

  public:
    vector<int> output;

    ZeroEvenOdd(int n)
    {
      this->n = n;
    }

    void zero()
    {
      for (int i = 1; i <= n; i++)
      {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [&]
                { return k == 0; });
        output.push_back(0);
        k = i;
        cv.notify_all();
      }
    }

    void even()
    {
      for (int i = 2; i <= n; i += 2)
      {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [&]
                { return k == i; });
        output.push_back(i);
        k = 0;
        cv.notify_all();
      }
    }

    void odd()
    {
      for (int i = 1; i <= n; i += 2)
      {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [&]
                { return k == i; });
        output.push_back(i);
        k = 0;
        cv.notify_all();
      }
    }
  };

  class LeetCodeSmpl : public testing::Test
  {
  protected:
    void SetUp() override {}
    void TearDown() {}
  };

  TEST_F(LeetCodeSmpl, DefaultConstructor)
  {
    int n = 10000;
    ZeroEvenOdd solution(n);
    thread p1([&]()
              { solution.zero(); });
    thread p2([&]()
              { solution.even(); });
    thread p3([&]()
              { solution.odd(); });
    p1.join();
    p2.join();
    p3.join();
    vector<int> ret;
    for (int i = 1; i <= n; i++)
    {
      ret.push_back(0);
      ret.push_back(i);
    }

    ASSERT_EQ(ret, solution.output);
  }
}
