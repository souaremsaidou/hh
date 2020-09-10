#include <iostream>

// user-defined type
class UDT
{
private:
    /* data */
public:
    UDT(/* args */);

    UDT(const UDT &)
    {
        std::cout << "user-defined copy ctor\n";
    }

    UDT(UDT &&o)
    noexcept
    {
        std::cout << "user-defined move ctor\n";
    }

    // user-defined copy assignment, copy-and-swap form
    UDT &operator=(UDT &other)
    {
        std::cout << "copy assignment of UDT\n";
        return *this;
    }

    // user-defined move assignment
    UDT &operator=(UDT &&other)
    {
        std::cout << "move assignment of UDT\n";
        return *this;
    }

    // destructor prevents implicit move assignment
    ~UDT();
};

UDT::UDT(/* args */)
{
    std::cout << "constructor\n";
}

UDT::~UDT()
{
    std::cout << "-- destructor\n";
}

UDT foo()
{
    std::cout << "foo\n";
    // UDT local_udt;
    // return local_udt;
    return UDT();
}

int main(int, char **)
{
    //the compiler to create temporary objects
    // foo();

    // copy elision
    // Omits copy and move (since C++11) constructors,
    // resulting in zero-copy pass-by-value semantics.
    UDT udt(foo());
}
