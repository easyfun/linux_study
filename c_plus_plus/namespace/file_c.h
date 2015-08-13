#ifndef FILE_C_H
#define FILE_C_H

namespace AName {
namespace AAName {    
    class A;
}
}

class B;

namespace CName {
class C{
public:
    C();
    ~C();
public:
    B* b;
    AName::AAName::A* a;
};
}

#endif
