/*
 * RoomCarpet.h
 *
 *  Created on: Oct 18, 2022
 *      Author: Luke O'Brien
 */

#pragma once

#ifndef ROOM_CARPET_H
#define ROOM_CARPET_H

#include "RoomDimensions.h"

class RoomCarpet
{
private:

	RoomDimensions room;
	double priceBySqrMeter;

public:

	RoomCarpet(RoomDimensions roomInput, double priceInput)
	{
		room = roomInput;
		priceBySqrMeter = priceInput;
	}

	double getCost()
	{
		return room.getArea().toFeet() * priceBySqrMeter;
	}

	RoomDimensions getDemensions()
	{
		return room;
	}
};

#endif
