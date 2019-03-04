/* 
 Fill this table:
 Data structure     Reserve or not      front or back       Time Costs
 --------------     --------------      -------------       ----------
 dequeue            Yes                 front
 dequeue            No                  front
 dequeue            Yes                 back
 dequeue            No                  back
 vector             Yes                 front
 vector             No                  front
 vector             Yes                 back
 vector             No                  back
 */

#include <deque>
#include <vector>
#include <iostream>

#include <chrono>
#include <ctime>

// Reference: https://stackoverflow.com/a/27856440/807695
#define TIMEIT(function) \
    auto start = std::chrono::system_clock::now();\
    for (int i=0; i<= 1000; ++i) {function();}\
    auto end = std::chrono::system_clock::now();\
    std::chrono::duration<double> elapsed_seconds = end-start;\
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";


using namespace std;

void test() {
    deque<string> t(
        {
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
        }
    );

    t.push_back("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb");
}
int main() {
    TIMEIT(test);
    return 0;
}