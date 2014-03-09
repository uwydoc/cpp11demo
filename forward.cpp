// forward.cpp
//
// Use `std::forward` to do perfect forwarding.
//
#include <utility>
#include <memory>
#include <iostream>

namespace impl {

// Possible implementation of `std::make_shared`
template<typename T, typename... Args>
std::shared_ptr<T> make_shared(Args... args)
{
    return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
}

}

class IntType {
public:
    IntType(int i): _i(i) {}

    operator int() { return _i; }

private:
    int _i;
};

int main()
{
    std::shared_ptr<IntType> ptr = impl::make_shared<IntType>(100);
    std::cout << int(*ptr) << std::endl;
}
