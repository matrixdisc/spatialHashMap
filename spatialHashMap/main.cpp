#include "SpatialHashMap.h"
#include "GuidProivder.h"

int main()
{
	SpatialHashMap m(10,2);
	Guid guid;

	auto result = m[3];

	auto object1 = guid.New();
	auto object2 = guid.New();
	auto object3 = guid.New();

	m.Add(object1, -1.3f).Add(object2, 3.5f).Add(object3, 3.0f);
	m.Delete(object1);
	
	return 0;
}