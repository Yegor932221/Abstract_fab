#ifndef MYCLASS_H
#define MYCLASS_H

class MyClass {
public:
    void testFunc1() {
    }
    virtual void testFunc3() const {
    }
protected:
    static void testFunc4() {
        printf("Hello, world!\n");
    }
private:
    static void testFunc2() {
    }
};\

#endif // MYCLASS_H
