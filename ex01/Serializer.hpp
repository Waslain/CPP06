#pragma once

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
	public:
		virtual ~Serializer();
		
		Serializer &operator=(const Serializer &src);

		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
	private:
		Serializer();
		Serializer(const Serializer &copy);
};