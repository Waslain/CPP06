/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:52:00 by fduzant           #+#    #+#             */
/*   Updated: 2024/04/08 16:06:29 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

struct Data
{
	const std::string &name;
	const std::string &lastname;
	const int age;
	Data(const std::string &name, const std::string &lastname, const int age) : name(name), lastname(lastname), age(age) {}
};
