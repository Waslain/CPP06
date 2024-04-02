/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:18:28 by fduzant           #+#    #+#             */
/*   Updated: 2024/04/02 18:59:47 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {

	if (argc != 2) {

		std::cerr << "convert: error: you need one and only one argument" << std::endl;
		return (1);
	}

    const std::string & str(argv[1]);
    try {

		ScalarConverter::convert(str);
	} catch (std::invalid_argument & e) {
		
		std::cout << "convert: error: " << e.what() << std::endl;
		return (1);
	} catch (std::out_of_range & e) {

		std::cout << "convert: error: " << e.what() << std::endl;
		return (2);
	}
	
	// std::cout << "----------" << std::endl << std::endl;
	// ScalarConverter::convert("0"); std::cout << "----------" << std::endl << std::endl;
	// ScalarConverter::convert("nan"); std::cout << "----------" << std::endl << std::endl;
    // ScalarConverter::convert("42.0f"); std::cout << "----------" << std::endl << std::endl;
	
	return (0);
}