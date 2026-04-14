#include <sys/types.h>
#include <unistd.h>
#include <print>

extern "C" {
#include <ps5/kernel.h>
}

#include "hv_defeat.h"
#include "util.h"

int main()
{
    return run_hv_defeat();
}
