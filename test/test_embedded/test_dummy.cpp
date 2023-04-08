#include <Arduino.h>
#include <unity.h>

// the built-in Unity library of ArduinoCore-mbed can be used,
// but we need to make sure we see the output on the intended serial port,
// which is the USB serial port here.
#ifdef ARDUINO_ARCH_MBED
REDIRECT_STDOUT_TO(Serial);
#endif

void setUp(void) { }
void tearDown(void) { }

int addition_function_under_test(int a, int b)
{
    return a + b;
}

void test_calculator_addition(void) {
    TEST_ASSERT_EQUAL(32, addition_function_under_test(25, 7));
}

void setup() {
    // wait until serial port has connected
    while(!Serial) {}
    pinMode(LED_BUILTIN, OUTPUT);
    UNITY_BEGIN();
    RUN_TEST(test_calculator_addition);
    UNITY_END();
}

void loop() {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
}
