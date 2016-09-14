#include "LocalFile.hpp"
#include "LocalTimeStampChecker.hpp"
#include "VersionChecker.hpp"
#include "SyncTrans.hpp"
#include "FileDecorator.hpp"
#include "PathFileID.hpp"
#include "LocalVersion.hpp"
#include "VersionTimeStampChecker.hpp"

int main(int argc, char *argv[])
{
    string destDir = "/home/astropeak/tmp/localFile";
    string name=        "tmp/github/files/README.md";
    string dir = "/cygdrive/e/home";

    LocalFile file1;
    file1.setDestDir(destDir);

    LocalVersion ver;
    ver.setDirs("/home/astropeak/.syncbox", destDir);


    FileDecorator file(file1, ver);

    LocalTimeStampChecker tsChk;
    tsChk.setDestDir(destDir);
    VersionChecker verChk(ver);
    VersionTimeStampChecker verTsChk(verChk, tsChk);

    SyncTrans syncTrans(file, verTsChk);
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
