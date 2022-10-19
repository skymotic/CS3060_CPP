/*
 * RoomDimensions.h
 *
 *  Created on: Oct 18, 2022
 *      Author: Luke O'Brien
 */

#pragma once

#ifndef ROOM_DIMENSION_H
#define ROOM_DIMENSION_H

#include "FeetInches.h"

class RoomDimensions
{
private:

	FeetInches width;
	FeetInches length;
	FeetInches area;

public:

	RoomDimensions() {};
	RoomDimensions(FeetInches widthInput, FeetInches lengthInput)
	{
		width = widthInput;
		length = lengthInput;
		area = width.multiply(length);

	}

	RoomDimensions(const RoomDimensions& obj)
	{
		length = obj.length;
		width = obj.width;
		area = obj.area;
	}

	FeetInches getArea() { return area; }
	FeetInches getWidth() { return width; }
	FeetInches getLength() { return length; }
};

#endif
