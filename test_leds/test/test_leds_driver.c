
#include "unity.h"

#include "leds_driver.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_LedsOffAfterCreate(void)
{
    uint16_t virtualLeds = 0xffff;
    LedDriver_Create(&virtualLeds);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

