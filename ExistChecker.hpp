#ifndef EXISTCHECKER_H
#define EXISTCHECKER_H

//note: this is actual the LocalExistChecker.
class ExistChecker:public Checker{
public:
    static void setDestDir(const string& destDir){
        itsDestDir=destDir;
    }
    int execute(const string& client, const FileID& server){
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        path p1(client);
        path p2(itsDestDir+"/"+server.getPath());

        if (exists(p1)) {
            if (exists(p2)){
                return BOTH_EXIST;
            } else {
                return CLIENT_EXIST;
            }
        }else {
            if (exists(p2)) {
                return SERVER_EXIST;
            } else {
                return BOTH_NOT_EXIST;
            }
        }
    }
private:
    static string itsDestDir;
};

string ExistChecker::itsDestDir;


#endif /* EXISTCHECKER_H */