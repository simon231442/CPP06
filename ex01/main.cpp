#include "Serializer.hpp"
#include <iostream>
#include <iomanip>

int	main(void)
{
	Data		data = {666};
	uintptr_t	data_reint = Serializer::serialize(&data);
	Data*		data_ptr;

	std::cout << std::setw(45) << std::left << "addresse de Data :";
	std::cout << std::hex << (&data) << std::endl;

	std::cout << std::setw(45) << std::left << "addresse de Data reinterprete en uintptr_t :";
	std::cout << "0x" << data_reint << std::endl;

	data_ptr = Serializer::deserialize(data_reint);
	std::cout << std::setw(45) << std::left << "uintptr_t deserialise :";
	std::cout << data_ptr << std::endl;


	std::cout << std::endl << "la valeur du pointeur original est-t'elle la meme que la valeur du pointeur desérialisé ?" << std::endl;
	std::cout << "--------> " << (&data == data_ptr ? "oui" : "non") << std::endl;

	return 0;
}
