#include "../headers/file.h"

char File::filename[] = "Data.dat";

void File::start() {
	fp.open(File::filename, fstream::in);

	// if file doesnt exist, make it
	if (!fp.is_open()) {
		std::cout << "First Time setup, creating files." << std::endl;
		fp.open(filename, fstream::out);

		firstTimeSetup();
	}
	// if file exists, work with it
	else {
		std::cout << "Succes." << std::endl;
		fp.close();
		fp.open(filename, fstream::in);

		loadData();
	}
}

void File::firstTimeSetup() {
	// Rooms
	Room Projector1("Projector1", 0, 40, 4, 10);
	Room Projector2("Projector2", 1, 46, 7, 12);
	Room Arena("Arena", 1, 120, 15, 5);


	// Locations
	Location Cinema("Cinema", "Str. Genso 2");
	Cinema.addEvent("Violet Evergarden", 87, Projector1, 30, 16, 27, Month::MARCH, 2023);
	Cinema.addEvent("Akiba Maid War", 88, Projector2, 15, 10, 15, Month::FEBRUARY, 2023);
	Cinema.addEvent("Death Note", 85, Projector2, 30, 16, 27, Month::MARCH, 2023);

	Location Stadium("Stadium", "Str. Light 5");
	Stadium.addEvent("Croatia v Brazilia", 120, Arena, 30, 14, 12, Month::APRIL, 2023);
	Stadium.addEvent("Bulgaria v Romania", 120, Arena, 45, 18, 19, Month::APRIL, 2023);

	// make the locations array
	this->totalLocations = Location::getTotalLocations();
	this->locations = new Location[totalLocations];
	locations[0] = Cinema;
	locations[1] = Stadium;

	fp << totalLocations << std::endl;
	for (size_t i = 0; i < totalLocations; ++i) {
		fp << locations[i] << std::endl;
	}

	// Tickets
	Ticket ticket1(Cinema.getEvents()[0], 2, 2, 1);
	Ticket ticket2(Cinema.getEvents()[0], 2, 3, 1);
}

void File::loadData() {
	// read number of locations and make a location array based on that
	fp >> this->totalLocations;
	this->locations = new Location[totalLocations];

	// read the locations
	for (size_t i = 0; i < totalLocations; ++i) {
		fp >> locations[i];
	}
}

void File::end() {
	// update the file
	fp.close();
	fp.open(File::filename, fstream::out | fstream::trunc);

	if (!fp.is_open())
		throw;
	else {
		fp << totalLocations << std::endl;
		for (size_t i = 0; i < totalLocations; ++i) {
			fp << locations[i] << std::endl;
		}
	}
}