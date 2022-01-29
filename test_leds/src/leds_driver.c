#include "leds_driver.h"
enum {ALL_LEDS_OFF = 0, ALL_LEDS_ON = ~0};
enum {FIRST_LED = 1, LAST_LED = 16};

static uint16_t * ledsAddress;
static uint16_t ledsImage;
static bool IsLedOutOfBounds(int ledNumber);
static void setLedImageBit(int ledNumber);
static uint16_t convertLedNumberToBit(int ledNumber);
static void updateHardware(void);
static void clearLedImageBit(int ledNumber);

void LedDriver_Create(uint16_t * address)
{
    ledsAddress = address;
    ledsImage = ALL_LEDS_OFF;
    *ledsAddress = ledsImage;
}

void LedDriver_TurnOn(int ledNumber)
{
    if (IsLedOutOfBounds(ledNumber))
        return;

    setLedImageBit(ledNumber);
    updateHardware();
}

void LedDriver_TurnOff(int ledNumber)
{
    if (IsLedOutOfBounds(ledNumber))
        return;

    clearLedImageBit(ledNumber);
    updateHardware();
}

void LedDriver_TurnAllOn(void)
{
    ledsImage = ALL_LEDS_ON;
    updateHardware();
}

void LedDriver_TurnAllOff(void)
{
    ledsImage = ALL_LEDS_OFF;
    updateHardware();
}

static bool IsLedOutOfBounds(int ledNumber)
{
    if ((ledNumber < FIRST_LED) || (ledNumber > LAST_LED)) return true;
    return false;
}

static void setLedImageBit(int ledNumber)
{
    ledsImage |= convertLedNumberToBit(ledNumber);
}

static uint16_t convertLedNumberToBit(int ledNumber)
{
    return 1 << (ledNumber - 1);
}

static void updateHardware(void)
{
    *ledsAddress = ledsImage;
}

static void clearLedImageBit(int ledNumber)
{
    ledsImage &= ~convertLedNumberToBit(ledNumber);
}