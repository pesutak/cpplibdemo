// client.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "libdynamic.h"
#include "libstatic.h"

int main()
{
	
	std::cout << "dynamic: " << dynFn(42) << "\n";
	std::cout << "static: " << fixer::BigAlgo::statFn(21) << "\n";

}

