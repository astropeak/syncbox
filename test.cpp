#include "LocalFile.hpp"
#include "LocalTimeStampChecker.hpp"
#include "VersionChecker.hpp"
#include "SyncTrans.hpp"
#include "FileDecorator.hpp"
#include "PathFileID.hpp"
#include "LocalVersion.hpp"
#include "VersionTimeStampChecker.hpp"
#include "SyncFiles.hpp"

int main(int argc, char *argv[])
{
    string destDir = "/home/astropeak/tmp/localFile";
    string name=        "tmp/github/files/README.md";

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
    // string from=dir+"/"+name;
    string files1[]={
        "tmp/github/files/README.md",
        "tmp/1.c",
        "xj/1234.VSP"
                          };

    vector<string> files(files1, files1+sizeof(files1)/sizeof(files1[0]));
    string dir = "/home/astropeak";
    SyncFiles syncFiles(syncTrans, files, dir);
    int t=0;
    while(true) {
        cout<<"\n==== "<<t<<" ====\n";
        syncFiles.execute();
        sleep(2);
        t+=2;
    }

    return 0;
}
