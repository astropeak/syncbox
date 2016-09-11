#include "LocalFile.hpp"
#include "TimeStampChecker.hpp"
#include "PullTrans.hpp"
#include "FileDecorator.hpp"

int main(int argc, char *argv[])
{
    string destDir = "/home/astropeak/tmp/localFile";
    string name=        "Dropbox/project/syncbox/file.cpp";
    string dir = "home/astropeak";

    File* file1 =new LocalFile(destDir, name, dir);
    File* file = new FileDecorator(file1);
    Checker* chk=new TimeStampChecker(destDir, name, dir);
    PullTrans pullTrans(file, chk);

    pullTrans.execute();
    return 0;
}
