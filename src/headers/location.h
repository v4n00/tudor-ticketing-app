#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "event.h"

class Location {
private:

	unsigned int locationId;
	char* name = nullptr;
	char* address = nullptr;
	Event** events = nullptr;
	unsigned int runningEvents = 0;

	static unsigned int TOTAL_LOCATIONS;

	// - Setters

	void setLocationId(unsigned int locationId);
	void setName(const char* name);
	void setAddress(const char* address);
	void setEvents(Event** events);
	void setRunningEvents(unsigned int runningEvents);

public:

	// - Public Interface
	
	// - Getters
	unsigned int getLocationId();
	char* getName();
	char* getAddress();
	Event** getEvents();
	unsigned int getRunningEvents();

	// - Constructors / Destructor

	// copy constructor
	Location(const Location& anotherLocation);
	Location(const char* name, const char* address, Event** events, unsigned int runningEvents);
	Location();
	~Location();

	// - Operators
	
		// copy assignment

	Location operator=(const Location& anotherLocation);

		// typecast operator

	explicit operator std::string();

		// compare operators

	bool operator==(const Location& anotherLocation);
	bool operator!=(const Location& anotherLocation);

		// stream operators

	friend std::ostream& operator << (std::ostream& out, const Location& location);
	friend std::istream& operator >> (std::istream& in, Location& location);
};