#ifndef CHECKER_H
#define CHECKER_H

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



class Checker{
public:
    Checker(FileInfo& fi1, FileInfo& fi2):itsFi1(fi1), itsFi2(fi2){
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
    }
    // path is the file path. The two paths should match the two FileInfo provided in the constructor.
    // Is this way good?
    int execute(const string& path1, const string& path2){
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        FI_Data fid1 =itsFi1.getInfo(path1);
        FI_Data fid2 =itsFi2.getInfo(path2);

        //do the comparision.
        return CLIENT_NEW;
    }
private:
    FileInfo& itsFi1;
    FileInfo& itsFi2;
};

#endif /* CHECKER_H */