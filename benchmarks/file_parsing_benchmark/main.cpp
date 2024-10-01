/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "log_data_context.h"

#include "benchmark/benchmark.h"

#include <array>
#include <cstddef>

static constexpr std::array m_defaultLines =
    {
        "[00-00-2000 00.00.00][TRACE] This is a trace message",
        "[00-00-2000 00.00.01][DEBUG] This is a debug message",
        "[00-00-2000 00.00.02][INFO] This is a info message",
        "[00-00-2000 00.00.03][WARNING] This is a warning message",
        "[00-00-2000 00.00.04][ERROR] This is a error message",
        "[00-00-2000 00.00.05][CRITICAL] This is a critical message"};

class MockFile : public Model::IFileReader
{
public:
    explicit MockFile(size_t maxIndex) :
        m_maxIndex(maxIndex)
    {
        populateVectorOfStrings();
    }

    void setPath(const std::filesystem::path&) noexcept override {}
    [[nodiscard]] auto exists() const noexcept -> bool override { return true; }
    [[nodiscard]] auto hasNextLine() -> bool override { return m_index < m_maxIndex; }
    [[nodiscard]] auto readNextLine() -> std::string override
    {
        return m_lines[m_index++];
    }

private:
    size_t m_index{0};
    size_t m_maxIndex;
    std::vector<std::string> m_lines;

    void populateVectorOfStrings()
    {
        m_lines.reserve(m_maxIndex);
        for (size_t i = 0; i < m_maxIndex; i++)
        {
            m_lines.emplace_back(m_defaultLines[i % m_defaultLines.size()]);
        }
    }
};

static void BM_FileReadingSmallFile(benchmark::State& state)
{
    Model::LogDataContext context(std::make_unique<MockFile>(100));

    for (auto _ : state)
    {
        context.openFile("");
        context.closeFile();
    }
}

static void BM_FileReadingBigFile(benchmark::State& state)
{
    Model::LogDataContext context(std::make_unique<MockFile>(1'000'000));

    for (auto _ : state)
    {
        context.openFile("");
        context.closeFile();
    }
}

BENCHMARK_MAIN();

// We need to set the Iterations to 1 since the code will only be run once when the file is loaded. It needs to be fast the first time
BENCHMARK(BM_FileReadingSmallFile)->Unit(benchmark::kMicrosecond)->Iterations(1);
BENCHMARK(BM_FileReadingBigFile)->Unit(benchmark::kMillisecond)->Iterations(1);