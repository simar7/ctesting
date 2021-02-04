//
// Created by Simarpreet Singh on 2021-02-02.
//

//#include <assert.h>
//#include <stdbool.h>
//#include "tracee.bpf.h"
#include <linux/types.h>
#include "tracee.bpf.c" // hack to call static __inline methods

void test_has_prefix(){
    int ok;
    ok = has_prefix("hello", "hello world", 11);
    assert(true==ok);

    ok = has_prefix("foo", "hello world", 11);
    assert(false==ok);
}

int main(int argc, char *argv[]){
    test_has_prefix();

    return(0);
}
