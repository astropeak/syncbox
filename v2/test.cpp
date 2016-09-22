#include <iostream>
#include <string>
using namespace std;

#include "File.hpp"
#include "SshFile.hpp"
#include "LocalFile.hpp"
#include "FileInfo.hpp"
#include "Checker.hpp"
#include "SyncTrans.hpp"


int main(int argc, char *argv[])
{
    SshFile file1("localhost", 22, "/home/astropeak/.ssh/16901.pem");
    // SshFile file11("localhost", 22, "/home/astropeak/.ssh/16901.pem");
    LocalFile file2;
    SyncTrans st(file1, file2);

    // st.execute("/home/luooofuq/h/tmp/1.c", "/home/luooofuq/tmp/2.c");
    // st.execute("/tmp/a", "/home/luooofuq/tmp/a");
    // st.execute("/tmp/b", "/home/luooofuq/tmp/b");

    SyncTrans st1(file1, file1);
    // st1.execute("/home/luooofuq/tmp/a", "/tmp/cc");
    // SyncTrans st1(file1, file11);
    st1.execute("/tmp/a", "/tmp/cc");
    return 0;
}
