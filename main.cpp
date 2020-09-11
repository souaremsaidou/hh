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
        // the copy constructor has a visible side effect (printing text)
        std::cout << "user-defined copy ctor\n";
    }

    // UDT(UDT &&o)
    // noexcept
    // {
    //     std::cout << "user-defined move ctor\n";
    // }

    // user-defined copy assignment, copy-and-swap form
    // UDT &operator=(UDT &other)
    // {
    //     std::cout << "copy assignment of UDT\n";
    //     return *this;
    // }

    // user-defined move assignment
    // UDT &operator=(UDT &&other)
    // {
    //     std::cout << "move assignment of UDT\n";
    //     return *this;
    // }

    // destructor prevents implicit move assignment
    ~UDT();
};

UDT::UDT(/* args */)
{
    std::cout << "constructor\n";
}

UDT::~UDT()
{
    std::cout << "user-defined destructor\n";
}

UDT foo()
{
    std::cout << "foo\n";
    // UDT local_udt; // direct-initialization, calls UDT::UDT()
    // return local_udt;
    return UDT();
}

//----------------------------------------------
// copy elision
//----------------------------------------------
//
// Omits copy and move (since C++11) constructors,
// resulting in zero-copy pass-by-value semantics.
void copy_elision()
{
    UDT udt(foo());
}

//----------------------------------------------
// RVO
//----------------------------------------------
// C++ standard allows an implementation to omit creating
// - a temporary used to initialize another object of the same type.
//
// GCC compiler support
// Specifying -fno-elide-constructors option disables that optimization,
// and forces G++ to call the copy constructor in all cases.
void rvo()
{
    UDT obj = foo();
}

int main(int, char **)
{
    // the compiler to create temporary objects
    // foo();

    // rvo();

    copy_elision();
}
