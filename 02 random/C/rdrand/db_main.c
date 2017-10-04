/* Copyright © 2015, Intel Corporation.  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

-       Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.
-       Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.
-       Neither the name of Intel Corporation nor the names of its contributors
may be used to endorse or promote products derived from this software
without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY INTEL CORPORATION "AS IS" AND ANY EXPRESS OR
IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
EVENT SHALL INTEL CORPORATION BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE. */

/*! \file main.c
*  \brief Test Program to demonstrate DRNG Lib.
*
* This is the main file of the test project.
* It demonstrates the use of different APIs for RDSEED and RDRAND.
*/

#include <limits.h>
#include <stdio.h>

#include "drng.h"

/*! \def RDRAND_CUTOFF
*	Minimum number of RDRAND results required
*/

/*! \def MAX_RETRY_LIMIT
*	Maximum number of rdseed retries when nesting multiple calls to rdseed in a wrapper function.
*/
#define MAX_RETRY_LIMIT 75


#ifdef _NOT_WIN32
#define RAND_MAX ULLONG_MAX
    uint64_t u64, ub, lb, nrand;
#else
#define RAND_MAX ULONG_MAX
    uint32_t u32, ub, lb, nrand;
#endif


int Get_RdRand() {

    int r;

    /* -------------------- Sample code for RDRAND Starts here --------------- */

    if (RdRand_isSupported()) {

#ifdef _NOT_WIN32
        r = rdrand_64(&u64, 10);
		if (r != DRNG_SUCCESS) printf("rdrand instruction failed with code %d\n", r);
        return 1;
#else
        r = rdrand_32(&u32, 10);
        if (r != DRNG_SUCCESS) printf("rdrand instruction failed with code %d\n", r);
        return 1;
#endif
    } else {
        printf("\nRdRand instruction is not supported by your system\n");
        return 0;
    }

    /* --------------------- Sample code for RDRAND Ends here ------------------ */

}


int Validate_Bounds() {
    int bounds_ok, limit_ok;
    bounds_ok = ub > lb;
    if (!bounds_ok) printf("Upper bound must be greater than lower bound\n");
    limit_ok = ub + 1 <= RAND_MAX;
    if (!limit_ok) {
#ifdef _NOT_WIN32
        printf("Upper bound must be less than %llu\n", RAND_MAX);
#else
        printf("Upper bound must be less than %u\n", RAND_MAX);
#endif
    }
    if (bounds_ok && limit_ok) return 1;
    return 0;
}


int Get_Bounds() {
    int ok;
    do {
        printf("Please give me a positive integer for the random int's lower bound: ");
#ifdef _NOT_WIN32
        scanf("%llu", &lb);
#else
        scanf("%u", &lb);
#endif
        printf("Please give me a positive integer for the random int's upper bound: ");
#ifdef _NOT_WIN32
        scanf("%llu", &ub);
#else
        scanf("%u", &ub);
#endif
        ok = Validate_Bounds();
    } while ( !ok );
    return 0;
}


int Get_Interval_RdRand()
{
#ifdef _NOT_WIN32
    uint64_t
    num_bins = (uint64_t) ub + 1 - lb,
    num_rand = (uint64_t) RAND_MAX,
    bin_size = num_rand / num_bins,
    x,
    defect = num_rand % num_bins;
#else
    uint32_t
    num_bins = (uint32_t) ub + 1,
    num_rand = (uint32_t) RAND_MAX,
    bin_size = num_rand / num_bins,
    x,
    defect = num_rand % num_bins;
#endif
    int r;
    do {
        r = Get_RdRand();
#ifdef _NOT_WIN32
        x = u64;
//        printf("%llu\t%llu\t%llu\t%llu\t%llu\n", num_bins, num_rand, bin_size, x, defect);
#else
        x = u32;
//        printf("%u\t%u\t%u\t%u\t%u\n", num_bins, num_rand, bin_size, x, defect);
#endif
    }
    // keep pulling random ints until
    while (num_rand - defect <= x);
    nrand = x/bin_size + lb;
    return 0;
}


int print_header()
{
#ifdef _NOT_WIN32
    printf("Lower bound: %llu, Upper bound: %llu\n", lb, ub);
#else
    printf("Lower bound: %u, Upper bound: %u\n", lb, ub);
#endif
    return 0;
}

int print_nrand() {
    char * s = "Bounded DRNG ";
#ifdef _NOT_WIN32
    char * t = "(uint64): ";
    printf("%llu\n",nrand);
#else
    char * t = "(uint32)";
    printf("%u\n",nrand);
#endif
    return 0;
}


int write_nrand() {
    FILE *f = fopen("random_number_output.txt", "a");
    if (f == NULL) {
        printf("Error opening file!\n");
        return -1;
    }
#ifdef _NOT_WIN32
    fprintf(f, "%llu\n",nrand);
#else
    fprintf(f, "%u\n",nrand);
#endif
    fclose(f);
    return 0;
}


int main(int argc, char *argv[])
{
    int r;
    if (Get_Bounds() ) return -1;
    print_header();
    for (int i=0; i<99999; i++) {
        r = Get_Interval_RdRand();
        if ( r ) return -1;
        write_nrand();
    }
    return 0;
}

