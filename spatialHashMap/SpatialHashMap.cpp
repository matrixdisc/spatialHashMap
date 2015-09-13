#include "SpatialHashMap.h"



SpatialHashMap::SpatialHashMap(int size, int resolution) : _resolution(resolution)
{
	data.resize(size);
}


SpatialHashMap::~SpatialHashMap()
{
}

SpatialHashMap& SpatialHashMap::Add(int guid, float position)
{
	if(existsInCell.find(guid)==existsInCell.end())
	{
		auto hash = Hash(position);
		data[hash].push_back(guid);		
		existsInCell[guid] = hash;
	}
	return *this;

	
}

SpatialHashMap& SpatialHashMap::Delete(int guid)
{
	auto result = existsInCell.find(guid);
	if(result!=existsInCell.end())
	{
		auto adress = result->second;
		data[adress].remove(guid);
		existsInCell.erase(result);
		
	}
	return *this;
}

SpatialHashMap& SpatialHashMap::Update(int guid, float newPosition)
{
	Delete(guid);
	Add(guid, newPosition);
	return *this;
}


