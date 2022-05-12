#include "bb/pool.h"

int main() {
    bb::pool::obj(100).push([](){
        printf("test\n");
    });
    bb::pool::objWait().push([](){
        printf("test\n");
    });
    return 0;
}
