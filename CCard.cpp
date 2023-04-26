#include "CCard.h"

void CCard::setNumber(int number) { 
	this->number = number; 
}

void CCard::setSuite(int suite) { 
	this->suite = suite; 
}

int CCard::getNumber() { 
	return number; 
}

int CCard::getSuite() { 
	return suite; 
}

int CCard::getStatus() { 
	return draw_status; 
}

void CCard::iterateStatus() { 
	this->draw_status++; 
}