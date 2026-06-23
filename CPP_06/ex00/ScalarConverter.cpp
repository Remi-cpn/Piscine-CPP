/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:00:48 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/10 11:14:52 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <sstream>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }

enum {CHAR  = 1, INT = 2, FLOAT = 4, DOUBLE = 8};

void ScalarConverter::convert(const std::string& str){
	int bitMask = 0, swit = 0; std::string c, i, f, d;

	if (str.empty()) {bitMask |= CHAR | INT | FLOAT | DOUBLE; goto Print;}

	if (str == "nan" || str == "nanf") {bitMask |= CHAR | INT, f = "nanf", d = "nan"; goto Print;}
	if (str == "+inf" || str == "inf" || str == "+inff") {bitMask |= CHAR | INT, f = "inff", d = "inf"; goto Print;}
	if (str == "-inf" || str == "-inff") {bitMask |= CHAR | INT, f = "-inff", d = "-inf"; goto Print;}

	if (str.length() == 1 && !std::isdigit(static_cast<unsigned char>(str[0]))) {
		std::ostringstream oss;
		oss << static_cast<int>(static_cast<unsigned char>(str[0]));
		c = i = f = d = oss.str();
		goto Cast;
	}

	if (str.find_first_of("0123456789") == std::string::npos) {
		bitMask |= CHAR | INT | FLOAT | DOUBLE;
		goto Print;
	}

	for (std::string::const_iterator it = str.begin(); it != str.end(); it++){
		if (*it != '-' && *it != '.' && *it != 'f' && !std::isdigit(*it)) {bitMask |= CHAR | INT | FLOAT | DOUBLE; goto Print;}
	}

	swit = 0;
	for (std::string::const_iterator it = str.begin(); it != str.end(); it++){
		if (it == str.begin() && *it == '.') c += '0';
		swit = ((swit == 0 || swit == 2) && !std::isdigit(*it) && *it != '.' && !(it == str.begin() && *it == '-')) ? 1 : swit;
    	swit = (*it == '.') ? swit + 2 : swit;
		if (*it == '.' && swit == 2) {c += '.'; continue; }
    	swit = (swit == 2 && *it == '.') ? 1 : swit;
    	swit = (*it == 'f' && it + 1 == str.end()) ? 3 : swit;

		switch (swit){
			case 0: c += *it; break;
			case 1: bitMask |= CHAR; goto Int;
			case 2: c += *it; break;
			case 3: goto Int;
			default: break;
		}
	}
	

	
	Int:
	if (bitMask & INT) goto Float;
	swit = 0;
	for (std::string::const_iterator it = str.begin(); it != str.end(); it++) {
    	swit = (swit == 0 && !std::isdigit(*it) && *it != '-') ? 1 : swit;
    	swit = (swit == 0 && *it == '-' && it != str.begin()) ? 1 : swit;
    	swit = (*it == '.') ? 2 : swit;

    	switch (swit) {
    		case 0: i += *it; break;
    	    case 1: bitMask |= INT; goto Float;
			case 2: if (i.empty()) i += '0'; goto Float;
    	    default: break;
    	}
	}

	
	
	Float:
	if (bitMask & FLOAT) goto Double;
	swit = 0;
	for (std::string::const_iterator it = str.begin(); it != str.end(); it++){
		if (it == str.begin() && *it == '.') f += '0';
		swit = ((swit == 0 || swit == 2) && !std::isdigit(*it) && *it != '.' && !(it == str.begin() && *it == '-')) ? 1 : swit;
    	swit = (*it == '.') ? swit + 2 : swit;
		if (*it == '.' && swit == 2) {f += '.'; continue; }
    	swit = (swit == 2 && *it == '.') ? 1 : swit;
    	swit = (*it == 'f') ? ((it + 1 == str.end()) ? 3 : 1) : swit;
		
		switch(swit){
			case 0: f += *it; break;
			case 1: bitMask |= FLOAT; goto Double;
			case 2: f += *it; break;
			case 3: f += 'f'; goto Double;
			case 4: bitMask |= FLOAT; goto Double;
			default: break;
		}
	}
	if (swit == 0) {f += ".0f";}
    if (swit == 2) {f += 'f';}


	Double:
	if (bitMask & DOUBLE) goto Print;
	swit = 0;
	for (std::string::const_iterator it = str.begin(); it != str.end(); it++){
		if (it == str.begin() && *it == '.') d += '0';
		swit = ((swit == 0 || swit == 2) && !std::isdigit(*it) && *it != '.' && !(it == str.begin() && *it == '-')) ? 1 : swit;
    	swit = (*it == '.') ? swit + 2 : swit;
		if (*it == '.' && swit == 2) {d += '.'; continue; }
    	swit = (swit == 2 && *it == '.') ? 1 : swit;
    	swit = (*it == 'f' && it + 1 == str.end()) ? 3 : swit;

		switch (swit){
			case 0: d += *it; break;
			case 1: bitMask |= DOUBLE; break;
			case 2: d += *it; break;
			case 3: break;
			default: break;
		}
		if (swit == 1 || swit == 3) break;
	}
	

	

	Cast:
	if (!(bitMask & CHAR) && !c.empty()) {
		int val = std::atoi(c.c_str());
		if (val < 0 || val > 255) {
			bitMask |= CHAR;
		} else {
			char ch = static_cast<char>(val);
			c = std::isprint(static_cast<unsigned char>(ch)) ? (std::string("'") + ch + "'") : "Non displayable";
		}
	}
	if (!(bitMask & INT) && !i.empty()) {
		errno = 0;
		long val = std::strtol(i.c_str(), NULL, 10);
		if (errno == ERANGE || val < INT_MIN || val > INT_MAX) {
			bitMask |= INT;
		}
	}
	if (!(bitMask & FLOAT) && !f.empty()) {
		float val = static_cast<float>(std::strtod(f.c_str(), NULL));
		std::ostringstream oss;
		oss << val;
		f = oss.str();
		if (f.find('.') == std::string::npos && f.find_first_of("eEnN") == std::string::npos) {
			f += ".0";
		}
		f += "f";
	}
	if (!(bitMask & DOUBLE) && !d.empty()) {
		double val = std::strtod(d.c_str(), NULL);
		std::ostringstream oss;
		oss << val;
		d = oss.str();
		if (d.find('.') == std::string::npos && d.find_first_of("eEnN") == std::string::npos) {
			d += ".0";
		}
	}

	Print:
	std::cout << "char: " << (bitMask & CHAR ? "impossible" : c) << std::endl;
	std::cout << "int: "    << (bitMask & INT    ? "impossible" : i) << std::endl;
	std::cout << "float: "  << (bitMask & FLOAT  ? "impossible" : f) << std::endl;
	std::cout << "double: " << (bitMask & DOUBLE ? "impossible" : d) << std::endl;
}	
