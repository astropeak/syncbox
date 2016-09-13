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

    File* file1 =new LocalFile();
    dynamic_cast<LocalFile*>(file1)->setDestDir(destDir);

    Version* ver = new Version(destDir, name, dir);
    File* file = new FileDecorator(file1, *ver);
    // Checker* chk=new TimeStampChecker(destDir, name, dir);
    // Checker* chk=new VersionChecker(destDir, name, dir);
    Checker* chk=new LocalTimeStampChecker();
    dynamic_cast<LocalTimeStampChecker*>(chk)->setDestDir(destDir);

    SyncTrans syncTrans(file, chk);
    // FileID* to= new PathFileID(name);
    string from=dir+"/"+name;
    syncTrans.execute(from, PathFileID(name));

    return 0;
}
