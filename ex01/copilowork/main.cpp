#include "Serializer.hpp"
# include <iostream>

int	main(void)
{
	Data		data;
	Data		*originalPtr;
	uintptr_t	raw;
	Data		*restoredPtr;

	data.id = 42;
	data.name = "Bender";
	data.rating = 99.9;
	originalPtr = &data;

	raw = Serializer::serialize(originalPtr);
	restoredPtr = Serializer::deserialize(raw);

	std::cout << "Original pointer : " << originalPtr << std::endl;
	std::cout << "Serialized value : " << raw << std::endl;
	std::cout << "Restored pointer : " << restoredPtr << std::endl;

	if (restoredPtr == originalPtr)
	{
		std::cout << "[OK] deserialize() returned the original pointer." << std::endl;
		std::cout << "Data => id=" << restoredPtr->id
			<< ", name=" << restoredPtr->name
			<< ", rating=" << restoredPtr->rating << std::endl;
		return (0);
	}

	std::cout << "[KO] pointers are different." << std::endl;
	return (1);
}
