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
static const int SERVER_ADDED=5;
static const int CLIENT_ADDED=6;
static const int SERVER_DELETED=7;
static const int CLIENT_DELETED=8;
static const int BOTH_DELETED=9;

static const int SERVER_EXIST=11;
static const int CLIENT_EXIST=12;
static const int BOTH_EXIST=13;
static const int BOTH_NOT_EXIST=14;


#endif /* CHECKER_H */