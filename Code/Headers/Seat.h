#pragma once
#include <iostream>
#include <string>
#include <sstream>

enum class SeatAvailability {
	FREE,
	PAID,
	RESERVED
};

class Seat {
private:
	unsigned int seatId = 0;
	SeatAvailability availability = SeatAvailability::FREE;

	static unsigned int TOTAL_SEATS;

public:

	// - Getters/Setters

	int getSeatId();
	SeatAvailability getAvailability();

	void setAvailability(SeatAvailability newAvailability);

	// - Constructors/Destructors

	Seat(const Seat& anotherSeat);
	Seat(unsigned int seatId, SeatAvailability availability);
	Seat(unsigned int seatId);
	Seat();

	// - Other operators

	Seat operator=(const Seat& anotherSeat);

	// upgrade the seat to a paid seat
	Seat operator++();
	Seat operator++(int);
	// downgrade the seat to a free seat
	Seat operator--();
	Seat operator--(int);

	// print a verbose version of the seat
	explicit operator std::string();

	// - Stream operators

	friend std::ostream& operator << (std::ostream& out, const SeatAvailability availability);
	friend std::ostream& operator << (std::ostream& out, const Seat& seat);

	friend std::istream& operator >> (std::istream& in, SeatAvailability& availability);
	friend std::istream& operator >> (std::istream& in, Seat& seat);
};

