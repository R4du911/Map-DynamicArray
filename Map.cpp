#include "Map.h"
#include "MapIterator.h"

 //13.ADT Map – repräsentiert mithilfe eines dynamischen Arrays von Paaren der Form (key, value)

// Bester Fall: θ(1)
// Schlechster Fall: θ(1)
// Durchschnittlicher Fall: θ(1)
// Allgemeine Komplexitat: θ(1)
Map::Map() {
    this->cap = 5;
    this->nrElems = 0;
    this->elements = new TElem[cap];

}

// Bester Fall: θ(1)
// Schlechster Fall: θ(1)
// Durchschnittlicher Fall: θ(1)
// Allgemeine Komplexitat: θ(1)
Map::~Map() {
    delete[] this->elements;
}

// Bester Fall: θ(1)
// Schlechster Fall: θ(1)
// Durchschnittlicher Fall: θ(1)
// Allgemeine Komplexitat: θ(1)
Map::Map(const Map& original){
    this->cap = original.cap;
    this->nrElems = original.nrElems;
    this->elements = new TElem[original.cap];
    for(int index=0;index<this->cap;index++) {
        this->elements[index] = original.elements[index];
    }
}

// Bester Fall: θ(n)
// Schlechster Fall: θ(n^2)
// Allgemeine Komplexitat: O(n^2)
Map Map::filter(TKey index1, TKey index2) {
    if(index1 > index2){
        TKey aux = index2;
        index2 = index1;
        index1 = aux;
    }
    Map new_map=Map(*this);
    for(int index=0;index<new_map.nrElems;index++){
        if(new_map.elements[index].first < index1 || new_map.elements[index].first > index2) {
            int pos_remove = index;
            while (pos_remove < new_map.nrElems) {
                new_map.elements[pos_remove] = new_map.elements[pos_remove + 1];
                pos_remove++;
            }
            new_map.nrElems--;
            index--;
        }
    }

    return new_map;
}

// Bester Fall: θ(1)
// Schlechster Fall: θ(n)
// Durchschnittlicher Fall: θ(n)
// Allgemeine Komplexitat: O(n)
TValue Map::add(TKey c, TValue v) {
    // make more place
    if (this->nrElems == this->cap) {
        this->cap = this->cap * 2;
        TElem *newvec = new TElem[this->cap];
        int index = 0;
        while (index < this->nrElems) {
            newvec[index] = this->elements[index];
            index++;
        }
        delete[] this->elements;
        this->elements = newvec;
    }

    int index = 0;
    while (index < this->nrElems) {
        if (this->elements[index].first == c) {
            TValue old = this->elements[index].second;
            this->elements[index].second = v;
            return old;
        }
        index++;
    }
    TElem newpair(c, v);
    this->elements[this->nrElems] = newpair;
    this->nrElems++;
    return NULL_TVALUE;
}

// Bester Fall: θ(1)
// Schlechster Fall: θ(n)
// Durchschnittlicher Fall: θ(n)
// Allgemeine Komplexitat: O(n)
TValue Map::search(TKey c) const {
    int index = 0;
    while (index < this->nrElems) {
        if (this->elements[index].first == c)
            return this->elements[index].second;
        index++;
    }
    return NULL_TVALUE;
}

// Bester Fall: θ(n)
// Schlechster Fall: θ(n)
// Durchschnittlicher Fall: θ(n)
// Allgemeine Komplexitat: θ(n)
TValue Map::remove(TKey c) {
    int index = 0;
    while (index < this->nrElems) {
        if (this->elements[index].first == c) {
            TValue old = this->elements[index].second;
            while (index < this->nrElems) {
                this->elements[index] = this->elements[index + 1];
                index++;
            }
            this->nrElems--;

            // make less space
            if (this->nrElems <= this->cap / 4) {
                this->cap = this->cap / 2;
                TElem *newvec = new TElem[this->cap];
                int index_newvec = 0;
                while (index_newvec < this->nrElems) {
                    newvec[index_newvec] = this->elements[index_newvec];
                    index_newvec++;
                }
                delete[] this->elements;
                this->elements = newvec;
            }
            return old;
        }
        index++;
    }
    return NULL_TVALUE;
}

// Bester Fall: θ(1)
// Schlechster Fall: θ(1)
// Durchschnittlicher Fall: θ(1)
// Allgemeine Komplexitat: θ(1)
int Map::size() const {
    return this->nrElems;
}

// Bester Fall: θ(1)
// Schlechster Fall: θ(1)
// Durchschnittlicher Fall: θ(1)
// Allgemeine Komplexitat: θ(1)
bool Map::isEmpty() const {
    return this->nrElems == 0;
}

// Bester Fall: θ(1)
// Schlechster Fall: θ(1)
// Durchschnittlicher Fall: θ(1)
// Allgemeine Komplexitat: θ(1)
MapIterator Map::iterator() const {
    return MapIterator(*this);
}



