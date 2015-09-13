#include "GuidProivder.h"



Guid::Guid()
{
	i = 0;
}


Guid::~Guid()
{
}

int Guid::New()
{
	return i++;
}