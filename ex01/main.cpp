/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:07:13 by fduzant           #+#    #+#             */
/*   Updated: 2024/04/08 16:09:32 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// This function is used to print the data of the Data struct
void	printData(Data *data) {

	std::cout << "  Name: " << data->name << std::endl;
	std::cout << "  Lastname: " << data->lastname << std::endl;
	std::cout << "  Age: " << data->age << std::endl;
}

// This is the main function that will test the Serializer class
int main(void) {

	Data	data("Duzant", "Franck", 26);
	
	std::cout << "Original data ->" << std::endl;
	printData(&data);
	
	std::cout << std::endl << "Serializing. . ." << std::endl;
	uintptr_t	serializedData = Serializer::serialize(&data);
	std::cout << "serialized data : " << serializedData << std::endl;

	std::cout << std::endl << "Deserializing. . ." << std::endl;	
	Data *	reData = Serializer::deserialize(serializedData);
	std::cout << "Deserialized data ->" << std::endl;
	printData(reData);
	
	return (0);
}