
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

void test_TurnOffLedOne(void)
{
    LedDriver_TurnOn(1);
    LedDriver_TurnOff(1);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

void test_TurnOnMultipleLeds(void)
{
    LedDriver_TurnOn(9);
    LedDriver_TurnOn(8);
    TEST_ASSERT_EQUAL_HEX16(0x180, virtualLeds);
}

void test_TurnOffMultipleLeds(void)
{
    LedDriver_TurnAllOn();
    LedDriver_TurnOff(9);
    LedDriver_TurnOff(8);
    TEST_ASSERT_EQUAL_HEX16((~0x180)&0xffff, virtualLeds);
}

void test_TurnOnAllLeds(void)
{
    LedDriver_TurnAllOn();
    TEST_ASSERT_EQUAL_HEX16(0xffff, virtualLeds);
}
