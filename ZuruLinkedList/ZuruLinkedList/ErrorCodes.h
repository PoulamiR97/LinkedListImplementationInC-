#include <iostream>
#include <string>
using namespace std;


#pragma once

enum ERR_CODE
{
	E_SUCCESS = 0,
	E_FAILURE = -1,
	E_INVALID_INPUT = -2,
	E_FILE_NOT_FOUND = -3
};


string operation_status(ERR_CODE type) {
    switch (type) {
    case E_SUCCESS:
        return "Operation status: SUCCESS";
    case E_FAILURE:
        return "Operation status: FAILURE";
    case E_INVALID_INPUT:
        return "Operation status: INVALID INPUT ";
    case E_FILE_NOT_FOUND:
        return "Operation status: FILE_NOT_FOUND";
    default:
        return "Invalid operation";
    }
}   

/// <summary>
/// Direction : Succeeding or Preceeding
/// </summary>
enum Direction
{
    Succeeding, 
    Preceeding
};