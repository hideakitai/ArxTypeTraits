#include <ArxTypeTraits.h>

void setup()
{
    Serial.begin(115200);
    delay(2000);


    std::function<float(int, float, String)> f = [](int i, float f, String s) -> float
    {
        return (float)i * f * s.toFloat();
    };

    Serial.print(f(1, 1.1, "1.5")); // 1.65
}

void loop()
{
}
