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
    {auto start = std::chrono::system_clock::now();\
    function();\
    auto end = std::chrono::system_clock::now();\
    std::chrono::duration<double> elapsed_seconds = end-start;\
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";}


using namespace std;

const string largeString = "a";

const int largeNum = 1000 * 10;

void vector_pushback_noreserve() {
    vector<string> v;
    for (int i = 0; i <= largeNum; ++i) {
        v.push_back(largeString);
    }
}

void vector_pushback_reserve() {
    vector<string> v;
    v.reserve(largeNum);
    for (int i = 0; i <= largeNum; ++i) {
        v.push_back(largeString);
    }
}

void vector_insert_noreserve() {
    vector<string> v;
    for (int i = 0; i <= largeNum; ++i) {
        v.insert(v.begin(), largeString);
    }
}

void vector_insert_reserve() {
    vector<string> v;
    v.reserve(largeNum);
    for (int i = 0; i <= largeNum; ++i) {
        v.insert(v.begin(), largeString);
    }
}

void deque_pushback_noreserve() {
    deque<string> deq;
    for (int i = 0; i <= largeNum; ++i) {
        deq.push_back(largeString);
    }
}

int main() {
    TIMEIT(vector_pushback_reserve);
    TIMEIT(vector_pushback_noreserve);
    TIMEIT(vector_insert_reserve);
    TIMEIT(vector_insert_noreserve);
    TIMEIT(deque_pushback_noreserve);
/*  elapsed time: 0.003989s
    elapsed time: 0.004039s
    elapsed time: 0.566814s
    elapsed time: 0.553537s
    elapsed time: 0.002033s */
    return 0;
}