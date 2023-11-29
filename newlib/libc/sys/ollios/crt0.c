#include <fcntl.h>
 
extern void exit(int code);
extern int main(int argc, char** argv);
char** environ;
 
void _start(int argc, char** argv, char** _environ) {
    /*size_t environ_length = 0;
    while (_environ[environ_length] != NULL) {
        environ_length += 1;
    }

    environ = malloc(sizeof(char*) * (environ_length + 1));

    for (size_t i = 0 ; i < environ_length ; i++) {
        environ[i] = malloc(strlen(_environ[i]) + 1);
        strcpy(environ[i], _environ[i]);
    }
    environ[environ_length-1] = 0;*/
    environ = _environ;

    int ex = main(argc, argv);
    exit(ex);
}

