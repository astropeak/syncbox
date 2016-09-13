#ifndef LOCAL_FILE_H
#define LOCAL_FILE_H

#include <iostream>
#include <boost/filesystem.hpp>
#include "File.hpp"

using namespace std;
using namespace boost::filesystem;

class LocalFile:public File {
public:
    virtual int write(const string& from, const FileID* to){
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        cout<<to->getPath()<<endl;
        copy(from, itsDestDir + "/" + to->getPath());
    }
    virtual int read(const FileID* from, const string& to){
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        copy(itsDestDir+"/"+from->getPath(), to);
    }

    static void setDestDir(const string& destDir){
        itsDestDir=destDir;
    }
private:
    int copy(const string& from, const string& to) {
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        cout<<"from: "<<from<<", to: "<<to<<endl;
        path src(from);
        path dest(to);

        path pdir(dest.parent_path());
        if (!exists(pdir)) {
            create_directories(pdir);
        }
        copy_file(src, dest, copy_option::overwrite_if_exists);
    }
    static string itsDestDir;
};
string LocalFile::itsDestDir;

#endif /* LOCAL_FILE_H */