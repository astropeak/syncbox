#ifndef TIMESTAMPCHECKER_H
#define TIMESTAMPCHECKER_H

#include "Checker.hpp"

class TimeStampChecker: public Checker{
public:
    int execute(const string& client, const FileID& server) = 0;
};

#endif /* TIMESTAMPCHECKER_H */