#include "../Headers/Seat.h"

unsigned int Seat::TOTAL_SEATS = 0;

// - Getters/Setters

int Seat::getSeatId() {
	return this->seatId;
}

SeatAvailability Seat::getAvailability() {
	return this->availability;
}

void Seat::setAvailability(SeatAvailability newAvailability) {
	this->availability = newAvailability;
}

// - Constructors/Destructors

Seat::Seat(const Seat& anotherSeat) {
	this->seatId = anotherSeat.seatId;
	this->availability = anotherSeat.availability;
}

Seat::Seat(unsigned int seatId, SeatAvailability availability) {
	this->seatId = seatId;
	this->availability = availability;
}

Seat::Seat(unsigned int seatId) {
	this->seatId = seatId;
	this->availability = SeatAvailability::FREE;
}

Seat::Seat() {
	this->seatId = ++TOTAL_SEATS;
	this->availability = SeatAvailability::FREE;
}

// - Other operators

Seat Seat::operator=(const Seat& anotherSeat) {
	this->seatId = anotherSeat.seatId;
	this->availability = anotherSeat.availability;
	return *this;
}

Seat Seat::operator++() {
	this->availability = SeatAvailability::PAID;
	return *this;
}

Seat Seat::operator++(int) {
	Seat temp(*this);
	operator++();
	return temp;
}

Seat Seat::operator--() {
	this->availability = SeatAvailability::FREE;
	return *this;
}

Seat Seat::operator--(int) {
	Seat temp(*this);
	operator--();
	return temp;
}

Seat::operator std::string() {
	std::stringstream ss;
	ss << "Seat #" << this->seatId << " is currently: " << this->availability;
	return ss.str();
}

// - Stream operators

std::ostream& operator << (std::ostream& out, const SeatAvailability availability) {
	switch (availability) {
	case SeatAvailability::FREE:
		out << "free"; break;
	case SeatAvailability::RESERVED:
		out << "reserved"; break;
	case SeatAvailability::PAID:
		out << "paid"; break;
	default:
		out << "unknown";
	}
	return out;
}

std::ostream& operator << (std::ostream& out, const Seat& seat) {
	out << "#" << seat.seatId << " - " << seat.availability;
	return out;
}

std::istream& operator >> (std::istream& in, SeatAvailability& availability) {
	int i = 0;
	if (!(in >> i) || i > 2) {
		availability = (SeatAvailability)0;
		return in;
	}
	else
		availability = (SeatAvailability)i;
	return in;
}

std::istream& operator >> (std::istream& in, Seat& seat) {
	std::cout << "Insert seatId: ";
	in >> seat.seatId;
	std::cout << "Insert availability: ";
	in >> seat.availability;
	return in;
}