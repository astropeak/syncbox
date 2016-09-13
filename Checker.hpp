#ifndef CHECKER_H
#define CHECKER_H

class Checker{
public:
    virtual int execute(const string& client, const FileID& server) = 0;
};

static const int SERVER_NEW=1;
static const int CLIENT_NEW=2;
static const int BOTH_NEW=3;
static const int EQUAL=4;

#endif /* CHECKER_H */