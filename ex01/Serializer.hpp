#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <cstint>
# include "Data.hpp"

class serializer {
	private :
		serializer();
		serializer(serializer const & src);
		~serializer();

		serializer&	operator=(serializer const & rhs);
	public :
		static uintptr_t	serialize(Data* ptr);
		Data* 				deserialize(uintptr_t raw);
		};

#endif
