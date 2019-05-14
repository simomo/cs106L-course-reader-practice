class Test {
public:
    Test();

private:
    static double s;
    double ns1;
    double ns2;
};

double Test::s(0.0);

Test::Test() : ns1(0.0), ns2(0.0) {
    s = 0.1;
}

int main() {
    Test test;
    return 0;
}