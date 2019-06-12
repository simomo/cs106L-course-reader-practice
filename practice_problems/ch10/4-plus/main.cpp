class MyInt {
public:
    MyInt(int i);

    MyInt& operator+=(int other);
    MyInt operator+(int other);
};