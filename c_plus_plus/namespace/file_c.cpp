#include "file_a.h"
#include "file_b.h"
#include "file_c.h"
#include "stdio.h"

using namespace AName::AAName;
using namespace CName;

//namespace CName {
C::C() {
    printf("C::C()\n");
	a = new A;
}

C::~C() {
    printf("C""~C()\n");
	if (a) {
		delete a;
		a = NULL;
	}
}
//}

