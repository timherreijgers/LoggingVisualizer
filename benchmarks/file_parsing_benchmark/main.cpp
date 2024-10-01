/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "log_data_context.h"

#include "benchmark/benchmark.h"

static void BM_FileReadingSmallFile(benchmark::State& state)
{
    //setup code here
    for (auto _ : state)
    {
        // This code gets timed
    }
}

BENCHMARK_MAIN();

BENCHMARK(BM_FileReadingSmallFile);