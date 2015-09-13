#include "SpatialHashMap.h"

int main()
{
	SpatialHashMap m(10,2);

	auto result = m[3];

	m.Add(1, -1.3f).Add(2, 3.5f).Add(3, 3.0f);
	m.Delete(1);
	
	



	return 0;
}