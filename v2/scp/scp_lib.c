#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

#include <libssh/libssh.h>
#include "examples_common.h"

int prepareFetchFile(ssh_session session, const char* name, ssh_scp* scp){
    int size;
    int mode;
    char *filename;
    int r;
    /* printf("scp:0x%x, in prepareFetchFile\n", *scp); */
    *scp=ssh_scp_new(session, SSH_SCP_READ | SSH_SCP_RECURSIVE, name);
    printf("scp:0x%x, in prepareFetchFile\n", *scp);
    /* outScp = &scp; */
    if(ssh_scp_init(*scp) != SSH_OK){
        fprintf(stderr,"error initializing scp: %s\n",ssh_get_error(session));
        ssh_scp_free(*scp);
        return -1;
    }
    /* printf("Trying to download 3 files (a,b,d) and 1 directory (c)\n"); */
    r=ssh_scp_pull_request(*scp);
    while (r != SSH_SCP_REQUEST_NEWFILE) {
        r=ssh_scp_pull_request(*scp);
        printf("request return value: %d\n", r);
        if (r==SSH_ERROR){
            printf("request SSH_ERROR\n");
            return -1;
        }
    }
    size=ssh_scp_request_get_size(*scp);
    filename=strdup(ssh_scp_request_get_filename(*scp));
    mode=ssh_scp_request_get_permissions(*scp);
    printf("downloading file %s, size %d, perms 0%o\n",filename,size,mode);
    free(filename);
    ssh_scp_accept_request(*scp);

    /*
      switch(r){
      case SSH_SCP_REQUEST_NEWFILE:
      size=ssh_scp_request_get_size(scp);
      filename=strdup(ssh_scp_request_get_filename(scp));
      mode=ssh_scp_request_get_permissions(scp);
      printf("downloading file %s, size %d, perms 0%o\n",filename,size,mode);
      free(filename);
      ssh_scp_accept_request(scp);

      //r=ssh_scp_read(scp,buffer,sizeof(buffer));
      break;
      case SSH_ERROR:
      fprintf(stderr,"Error: %s\n",ssh_get_error(session));
      ssh_scp_close(scp);
      ssh_scp_free(scp);
      return -1;
      default:
      printf("unexpected request return value: %d\n", r);
      }
    */

    return 0;
}


int prepareWriteFile(ssh_session session, const char* name, ssh_scp* scp){
    int rc;
    //TODO: need path directory part "/tmp"
    printf("aaaa\n");
    *scp = ssh_scp_new
        (session, SSH_SCP_WRITE | SSH_SCP_RECURSIVE, "/tmp");
    /* *scp = ssh_scp_new */
    /*     (session, SSH_SCP_WRITE | SSH_SCP_RECURSIVE, "/tmp"); */
    printf("bbbb\n");
    printf("scp:0x%x, in prepareWriteFile\n", *scp);
    if (*scp == NULL)
    {
        fprintf(stderr, "Error allocating scp session: %s\n",
            ssh_get_error(session));
        printf("Error 1");
        return SSH_ERROR;
    }

    rc = ssh_scp_init(*scp);
    if (rc != SSH_OK)
    {
        fprintf(stderr, "Error initializing scp session: %s\n",
            ssh_get_error(session));
        printf("Error 2");
        ssh_scp_free(*scp);
        return rc;
    }

    //TODO: need file size here: lenght
    rc = ssh_scp_push_file
        (*scp, "cc", 10000, S_IRUSR | S_IWUSR);

    if (rc != SSH_OK)
    {
        fprintf(stderr, "Can't open remote file: %s\n",
            ssh_get_error(session));

        printf("Error 3");
        return rc;
    }

    return 0;
}