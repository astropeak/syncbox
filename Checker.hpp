#ifndef CHECKER_H
#define CHECKER_H

class Checker{
public:
    virtual int execute(void) = 0;
    Checker(string& destDir, string& name, string& dir):itsDestDir(destDir), itsName(name), itsDir(dir) {
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
    }
private:
    string itsDestDir;
    string itsName;
    string itsDir;
};

static const int SERVER_NEW=1;
static const int CLIENT_NEW=2;
static const int BOTH_NEW=3;

#endif /* CHECKER_H */