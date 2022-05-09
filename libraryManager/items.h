#ifndef _ITEM_H
#define _ITEM_H


#include <string>
#include <list>

using namespace std;

enum itemKind {MUSICALBUM, BOOK, FILM };

class Entry
{
public:
	bool borrowed;
	string borrowedBy;
	string name;
	string year;
	itemKind kind;
	int serialNumber;

	Entry();
	Entry(int _id, string _name, string _year, itemKind _kind, bool _borrowed, string _borrowedBy);
	~Entry();
	bool entryBorrowed();
	void entyReturned();
	virtual void printDetails();
};

class MusicAlbum:public Entry
{
public:
	string artist;
	string recordLabel;

	MusicAlbum();
	MusicAlbum(int _id, string _name, string _year, itemKind _kind, bool _borrowed, string _borrowedBy, string _artist, string _recordLabel);

	~MusicAlbum();

	void printDetails();
};

class Book:public Entry
{
public:
	string author;
	string publisher;
	string edition;
	Book();
	Book(int _id, string _name, string _year, itemKind _kind, bool _borrowed, string _borrowedBy, string _author, string _publisher, string _edition);

	~Book();

	void printDetails();

};

class Film:public Entry
{
public:
	string director;
	string language;
	Film();
	Film(int _id, string _name, string _year, itemKind _kind, bool _borrowed, string _borrowedBy, string _director, string _language);

	~Film();

	void printDetails();
};

struct Member {
	int number;
	string name;
};

class Members {
public:
	list<Member> listMembers;

	Members();
	~Members();

	bool addMember(string strName);
	bool removeMember(string strName);
	bool removeMember(int nNumber);
	int getMemberNumber(string strName);
};

struct PayForFilm {
	int serial;
	string member;
	int amount;
	PayForFilm() {};
	PayForFilm(int _serial, string _member, int _amount) {
		serial = _serial;
		member = _member;
		amount = _amount;
	}
};

class Bank {
public:
	Bank(){};
	~Bank(){};
	list<PayForFilm> listPayForFilm;
};

class Catalogue {
public:
	list<Entry*> mEntries;
	Catalogue();
	~Catalogue();
	void addItem();
	void deleteItem();
	void findItem();
	void issueItem(Bank* bank);
	void updateReturned();
	void saveData();
	void readData();
public:
	void addAlbumItem(string name, string year, string artist, string recordLabel);
	void addBookItem(string name, string year, string author, string publisher, string edition);
	void addFilmItem(string name, string year, string director, string language);
	void deleteItem(int serial);
	bool deleteItem(Entry* entry);
	void issueItem(int serial, string number, Bank* bank);
	void updateReturned(int serial);
	Entry* findItem(int serial);
};

#endif // !_ITEM_H
