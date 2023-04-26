
#ifndef CARD_H
#define CARD_H

class CCard {
public:
	void setNumber(int number);
	void setSuite(int suite);
	int getNumber();
	int getSuite();
	int getStatus();
	void iterateStatus();

private:
	int suite;
	int number;
	int draw_status = 0;
};

#endif // !CARD_H