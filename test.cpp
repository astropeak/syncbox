#include "LocalFile.hpp"
#include "LocalTimeStampChecker.hpp"
// #include "VersionChecker.hpp"
#include "SyncTrans.hpp"
#include "FileDecorator.hpp"
#include "PathFileID.hpp"

int main(int argc, char *argv[])
{
    string destDir = "/home/astropeak/tmp/localFile";
    string name=        "tmp/github/files/README.md";
    string dir = "/cygdrive/e/home";

    LocalFile file1;
    file1.setDestDir(destDir);

    Version ver(destDir, name, dir);
    FileDecorator file(file1, ver);
    LocalTimeStampChecker chk;
    chk.setDestDir(destDir);

    SyncTrans syncTrans(file, chk);
    string from=dir+"/"+name;
    int t=0;
    while(true) {
        cout<<"\n==== "<<t<<" ====\n";
        syncTrans.execute(from, PathFileID(name));
        sleep(2);
        t+=2;
    }

    return 0;
}
