#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <sys/time.h>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

class PmergeMe {
private:
    std::vector<int> _vec;
    std::deque<int> _deq;

    void sortVector(std::vector<int>& arr);
    void sortDeque(std::deque<int>& arr);

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    bool parseInput(int argc, char** argv);
    void execute();
    void printSequence(const std::string& prefix, const std::vector<int>& seq) const;
};

#endif