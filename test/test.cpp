#include <assert.h>
#include "../src/calculator.h"
#include <cifuzz/cifuzz.h>
#include <fuzzer/FuzzedDataProvider.h>
#include <cstdint>
#include <cstddef>
#include <string>

FUZZ_TEST_SETUP()
{
    // Perform any one-time setup required by the FUZZ_TEST function.
}

FUZZ_TEST(
    const uint8_t *data,
    size_t size)
{
    FuzzedDataProvider fuzzed_data(data, size);

    float a  = fuzzed_data.ConsumeIntegral<int>();
    float b  = fuzzed_data.ConsumeIntegral<int>();
    char  op = fuzzed_data.ConsumeIntegral<char>();

    float result = calculator(a, op, b);
}
