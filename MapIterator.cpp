#include "Map.h"
#include "MapIterator.h"
#include <exception>
using namespace std;


// Bester Fall: θ(1)
// Schlechster Fall: θ(1)
// Durchschnittlicher Fall: θ(1)
// Allgemeine Komplexitat: θ(1)
MapIterator::MapIterator(const Map& d) : map(d)
{
	this->index = 0;
}

// Bester Fall: θ(1)
// Schlechster Fall: θ(1)
// Durchschnittlicher Fall: θ(1)
// Allgemeine Komplexitat: θ(1)
void MapIterator::first() {
	this->index = 0;
}

// Bester Fall: θ(1)
// Schlechster Fall: θ(1)
// Durchschnittlicher Fall: θ(1)
// Allgemeine Komplexitat: θ(1)
void MapIterator::next() {
	if(this->index < this->map.nrElems){
        this->index++;
    }else{
        throw exception();
    }
}

// Bester Fall: θ(1)
// Schlechster Fall: θ(1)
// Durchschnittlicher Fall: θ(1)
// Allgemeine Komplexitat: θ(1)
TElem MapIterator::getCurrent(){
    if(valid())
        return this->map.elements[this->index];
    else {
        throw exception();
    }
}

// Bester Fall: θ(1)
// Schlechster Fall: θ(1)
// Durchschnittlicher Fall: θ(1)
// Allgemeine Komplexitat: θ(1)
bool MapIterator::valid() const {
	if(this->index < this->map.nrElems)
        return true;
	return false;
}



