#include "serializer.hpp"

uintptr_t	serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* 		serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
