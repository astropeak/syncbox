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
    SshFile file1("localhost", 8080, "/home/astropeak/.ssh/16901.pem");
    LocalFile file2;
    SyncTrans st(file2, file2);

    st.execute("/home/luooofuq/h/tmp/1.c", "/home/luooofuq/tmp/2.c");
    return 0;
}
