
#include "unity.h"

#include "leds_driver.h"
static uint16_t virtualLeds;
void setUp(void)
{
    virtualLeds = 0xffff;
}

void tearDown(void)
{
}

void test_LedsOffAfterCreate(void)
{
    LedDriver_Create(&virtualLeds);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

void test_TurnOnLedOne(void)
{
    LedDriver_TurnOn(1);
    TEST_ASSERT_EQUAL_HEX16(1, virtualLeds);
}
