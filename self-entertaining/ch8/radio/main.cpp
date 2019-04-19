#include <map>
#include <cassert>

using namespace std;

class Radio {
public:
    double getFrequency();
    void setFrequency(double f);

    int getVolume();
    void setVolume(int v);

    double getPreset(int i);
    void setPreset(int i, double f);

private:
    double frequency;
    int volume;
    map<int, double> preset;
};

double Radio::getFrequency() {
    return frequency;
}

void Radio::setFrequency(double f) {
    assert(f <= 108.0 && f >= 78.5);
    frequency = f;
}

int Radio::getVolume() {
    return volume;
}

void Radio::setVolume(int v) {
    assert(v <= 10 && v >= 0);
    volume = v;
}

double Radio::getPreset(int i) {
    

}

void Radio::setPreset(int i, double f) {

}

int main() {
    Radio radio;
    return 0;
}