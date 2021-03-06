/*
 * Parameters.cpp
 *
 *  Created on: Jun 22, 2011
 *      Author: hans
 */

#include "parameters.h"
#include "params_parser.h"
#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <sstream>

Parameter::Parameter() {
    gpu = 0;
}

void Parameter::init(Params &params){
	try{
		params.getParam("matrix", &matrixFile);
        params.getParam("datatype", &datatype);

        params.getParamOptional("vector", &vectorFile);
		params.getParamOptional("wdir", &wdir);
        params.getParamOptional("gpu", &gpu);

		if(datatype!="float" && datatype!="double"){
			throw std::invalid_argument("Unable to find data type");
		}
	} catch(std::invalid_argument &ex){
		std::cerr << ex.what() << std::endl;
		exit(EXIT_FAILURE);
	}
}

std::string Parameter::toString(){
	std::ostringstream ostr;
	ostr << " matrix=" << matrixFile
		 << " wdir=" << wdir
         << " datatype=" << datatype;
	return ostr.str();
}
