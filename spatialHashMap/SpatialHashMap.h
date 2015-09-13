#pragma once
#include <vector>
#include <unordered_map>
#include <list>

class SpatialHashMap
{
public:
	SpatialHashMap(int size, int resolution);
	~SpatialHashMap();
	std::list<int> operator[](float position) const
	{
		auto hash = Hash(position);
		
		return data[hash];
	}
	
	SpatialHashMap& Add(int guid, float position);
	SpatialHashMap& Delete(int guid);
	SpatialHashMap& Update(int guid, float newPosition );
	
private:
	//for each cell ->list of guids that are in this cell
	std::vector<std::list<int>> data;

	//holds each guid's cell
	std::unordered_map<int, int> existsInCell;

	int _resolution;
	int Hash(float position) const
	{
		auto cell =int(position / _resolution);
		return cell%data.size();
	}
};

