#include <vector>
#include <deque>
#include <ctime>
#include <iostream>
#include <iomanip>  // setw
#include <stdlib.h>  // rand

using namespace std;

const int INSERT_TIMES = 1000 * 300;

void GenerateRandom(vector<int>& rands, int num);

int main() {
    cout << "insert:" << endl;
    clock_t begin, end;
    vector<int> v;

    begin = clock();
    for (int i = 0; i < INSERT_TIMES; ++i) {
        v.insert(v.begin(), 1);
    }
    end = clock();
    cout << setw(15) << "vector: " << setw(10) << double(end - begin) / CLOCKS_PER_SEC << endl;

    deque<int> d;
    begin = clock();
    for (int j = 0; j < INSERT_TIMES; ++j) {
        d.insert(d.begin(), 1);
    }
    end = clock();
    cout << setw(15) << "deque: " << setw(10) << double(end - begin) / CLOCKS_PER_SEC << endl;


    cout << "push_back:" << endl;
    v.clear();
    d.clear();

    begin = clock();
    for (int i = 0; i < INSERT_TIMES; ++i) {
        v.push_back(1);
    }
    end = clock();
    cout << setw(15) << "vector: " << setw(10) << double(end - begin) / CLOCKS_PER_SEC << endl;

    begin = clock();
    for (int j = 0; j < INSERT_TIMES; ++j) {
        d.push_back(1);
    }
    end = clock();
    cout << setw(15) << "deque: " << setw(10) << double(end - begin) / CLOCKS_PER_SEC << endl;


    cout << "random access:" << endl;
    int randomNums = 20;
    vector<int> rands;

    GenerateRandom(rands, randomNums);

    begin = clock();
    for (int i = 0; i < INSERT_TIMES; ++i) {
        v[rands[i % randomNums]];
    }
    end = clock();
    cout << setw(15) << "vector: " << setw(10) << double(end - begin) / CLOCKS_PER_SEC << endl;

    begin = clock();
    for (int j = 0; j < INSERT_TIMES; ++j) {
        d[rands[j % randomNums]];
    }
    end = clock();
    cout << setw(15) << "deque: " << setw(10) << double(end - begin) / CLOCKS_PER_SEC << endl;


    cout << "iterator:" << endl;

    begin = clock();
    for (int i = 0; i < v.size(); ++i) {
        v[i];
    }
    end = clock();
    cout << setw(15) << "vector: " << setw(10) << double(end - begin) / CLOCKS_PER_SEC << endl;

    begin = clock();
    for (int j = 0; j < INSERT_TIMES; ++j) {
        d[j];
    }
    end = clock();
    cout << setw(15) << "deque: " << setw(10) << double(end - begin) / CLOCKS_PER_SEC << endl;
}


void GenerateRandom(vector<int>& rands, int num) {
    for (int i = 0; i < num; ++i) {
        rands.push_back(rand() % INSERT_TIMES);
    }
}