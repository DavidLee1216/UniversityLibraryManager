#include "items.h"
#include <iostream>
#include <string>
//#include <format>
#include <fstream>
#include <stdio.h>

using namespace std;


bool isNumber(const string& str)
{
	for (char const& c : str) {
		if (isdigit(c) == 0) return false;
	}
	return true;
}

Entry::Entry() {
	cout << "Please enter the name of the entry:";
	cin >> name;
	cout << "Please enter the year of the entry:";
	cin >> year;
	borrowed = false;
	borrowedBy = "";
}

Entry::Entry(int _id, string _name, string _year, itemKind _kind, bool _borrowed=false, string _borrowedBy="") {
	serialNumber = _id;
	name = _name;
	year = _year;
	kind = _kind;
	borrowed = _borrowed;
	borrowedBy = _borrowedBy;
}

Entry::~Entry() {

}

bool Entry::entryBorrowed() {
	return false;
}

void Entry::entyReturned() {

}

void Entry::printDetails() {
	string strBorrowed = "borrowed:" + borrowed ? "True" : "False";
	string strBorrowedBy = "\nborrowedBy:" + borrowedBy;
	string strName = "\nname:" + name;
	string strYear = "\nyear:" + year;
	string strItemKind = "\nitemKind:" + (kind == MUSICALBUM) ? "MUSICALBUM" : (kind == BOOK) ? "BOOK" : "Film";
	cout << strBorrowed + strBorrowedBy + strName + strYear + strItemKind << endl;
}

MusicAlbum::MusicAlbum() {
	cout << "Please enter artist:";
	cin >> artist;
	cout << "Please enter recordLabel:";
	cin >> recordLabel;
}

MusicAlbum::~MusicAlbum() {

}

MusicAlbum::MusicAlbum(int _id, string _name, string _year, itemKind _kind, bool _borrowed, string _borrowedBy, string _artist, string _recordLabel): Entry(_id, _name, _year, _kind, _borrowed, _borrowedBy) {
	artist = _artist;
	recordLabel = _recordLabel;
}

void MusicAlbum::printDetails() {
	Entry::printDetails();
	string strArtist = "artist:" + artist;
	string strRecordLabel = "\nrecordLabel:" + recordLabel;
	cout << strArtist + strRecordLabel << endl;
}

Book::Book() {
	cout << "Please enter author:";
	cin >> author;
	cout << "Please enter publisher:";
	cin >> publisher;
	cout << "Please enter edition:";
	cin >> edition;
}

Book::~Book() {

}

Book::Book(int _id, string _name, string _year, itemKind _kind, bool _borrowed, string _borrowedBy, string  _author, string _publisher, string _edition) :Entry(_id, _name, _year, _kind, _borrowed, _borrowedBy) {
	author = _author;
	publisher = _publisher;
	edition = _edition;
}

void Book::printDetails() {
	Entry::printDetails();
	string strAuthor = "author:" + author;
	string strPublisher = "\npublisher:" + publisher;
	string strEdition = "\nedition:" + edition;
	cout << strAuthor + strPublisher + strEdition << endl;
}

Film::Film() {
	cout << "Please enter director: ";
	cin >> director;
	cout << "Please enter language: ";
	cin >> language;
}

Film::~Film() {

}

Film::Film(int _id, string _name, string _year, itemKind _kind, bool _borrowed, string _borrowedBy, string _director, string _language) :Entry(_id, _name, _year, _kind, _borrowed, _borrowedBy) {
	director = _director;
	language = _language;
}

void Film::printDetails() {
	Entry::printDetails();
	string strDirector = "director: " + director;
	string strLanguage = "language: " + language;
	cout << strDirector + strLanguage << endl;
}

Catalogue::Catalogue() {

}

Catalogue::~Catalogue() {

}

void Catalogue::addItem() {
	cout << "Please enter item kind: (kind must be one of 1(album), 2(book), 3(film)) ";
	string szKind;
	itemKind kind;
	cin >> szKind;
	if (szKind.compare("1") != 0 && szKind.compare("2") != 0 && szKind.compare("3") != 0)
	{
		cout << "Please enter right kind" << endl;
		return;
	}
	if (szKind.compare("1") == 0)
		kind = MUSICALBUM;
	else if (szKind.compare("2") == 0)
		kind = BOOK;
	else
		kind = FILM;
	cout << "Please enter the name of item: " << endl;
	string szName;
	cin.ignore();
	getline(cin, szName);
	cout << "Please enter year: ";
	string szYear;
	cin >> szYear;
	while (!isNumber(szYear)) {
		cout << "The year must be number. Please type again: ";
		cin >> szYear;
	}
	if (kind == MUSICALBUM)
	{
		string artist, recordLabel;
		cout << "Please enter artist name: ";
		cin >> artist;
		cout << "Please enter recordLabel: ";
		cin >> recordLabel;
		addAlbumItem(szName, szYear, artist, recordLabel);
	}
	else if (kind == BOOK)
	{
		string author, publisher, edition;
		cout << "Please enter author: ";
		cin >> author;
		cout << "Please enter publisher: ";
		cin >> publisher;
		cout << "Please enter edition: ";
		cin >> edition;
		addBookItem(szName, szYear, author, publisher, edition);
	}
	else
	{
		string director, language;
		cout << "Please enter director: ";
		cin >> director;
		cout << "Please enter language: ";
		cin >> language;
		addFilmItem(szName, szYear, director, language);
	}
	cout << "Successfully add the item." << endl;

}

void Catalogue::addAlbumItem(string name, string year, string artist, string recordLabel) {
	int size = (int)mEntries.size();
	Entry* lastEntry = 0;
	if (size > 0)
		lastEntry = mEntries.back();
	int serial = size>0 ? lastEntry->serialNumber + 1 : 1;
	Entry* entry = new MusicAlbum(serial, name, year, MUSICALBUM, false, "", artist, recordLabel);
	mEntries.push_back(entry);
}

void Catalogue::addBookItem(string name, string year, string author, string publisher, string edition) {
	int size = (int)mEntries.size();
	Entry* lastEntry = 0;
	if (size > 0)
		lastEntry = mEntries.back();
	int serial = size > 0 ? lastEntry->serialNumber + 1 : 1;
	Entry* entry = new Book(serial, name, year, BOOK, false, "", author, publisher, edition);
	mEntries.push_back(entry);
}

void Catalogue::addFilmItem(string name, string year, string director, string language) {
	int size = (int)mEntries.size();
	Entry* lastEntry = 0;
	if (size > 0)
		lastEntry = mEntries.back();
	int serial = size > 0 ? lastEntry->serialNumber + 1 : 1;
	Entry* entry = new Film(serial, name, year, FILM, false, "", director, language);
	mEntries.push_back(entry);
}

Entry* Catalogue::findItem(int serial) {
	list<Entry*>::iterator it;
	for (it = mEntries.begin(); it != mEntries.end(); ++it) {
		if ((* it)->serialNumber == serial) {
			return *it;
		}
	}
	return NULL;
}

void Catalogue::deleteItem() {
	int serial;
	cout << "Please enter the serial number of item you are going to delete. ";
	cin >> serial;
	deleteItem(serial);
}

void Catalogue::deleteItem(int serial) {
	Entry* entry = findItem(serial);
	bool res = deleteItem(entry);
	if(!res)
		cout << "The item does not exist" << endl;
	else
		cout << "Successfully deleted the item" + to_string(serial) << endl;

}

bool Catalogue::deleteItem(Entry* entry) {
	if (entry == NULL) {
		return false;
	}
	mEntries.remove(entry);
	return true;
}

void Catalogue::findItem() {
	int serial;
	cout << "Please enter a serial number you are going to find. ";
	cin >> serial;
	Entry* entry = findItem(serial);
	if (entry == NULL)
	{
		cout << "Cannot find the item" << endl;
		return;
	}
	cout << "name: " + entry->name << endl;
	cout << "year: " + entry->year << endl;
	string strBorrowed = entry->borrowed ? "True" : "False";
	cout << "borrowed: " + strBorrowed << endl;
	cout << "borrowedBy: " + entry->borrowedBy << endl;
	if (entry->kind == MUSICALBUM) {
		cout << "kind: album" << endl;
		cout << "artist: " + ((MusicAlbum*)entry)->artist << endl;
		cout << "recordLabel: " + ((MusicAlbum*)entry)->recordLabel << endl;
	}
	else if (entry->kind == BOOK) {
		cout << "kind: book" << endl;
		cout << "author: " + ((Book*)entry)->author << endl;
		cout << "publisher: " + ((Book*)entry)->publisher << endl;
		cout << "edition: " + ((Book*)entry)->edition << endl;
	}
	else if (entry->kind == FILM) {
		cout << "kind: film" << endl;
		cout << "director: " + ((Film*)entry)->director << endl;
		cout << "language: " + ((Film*)entry)->language << endl;
	}
}

void Catalogue::issueItem(Bank* bank) {
	int serial;
	cout << "Please enter a serial number you are going to issue ";
	cin >> serial;
	cout << "Please enter member number: ";
	string number;
	cin >> number;
	issueItem(serial, number, bank);
}

void Catalogue::issueItem(int serial, string number, Bank* bank) {
	Entry* entry = findItem(serial);
	if (entry == NULL) {
		cout << "Invalid serial number" << endl;
		return;
	}
	if (entry->kind == FILM) {
		cout << "Please charge fee: ";
		int fee = 0;
		while (fee <= 0)
		{
			cin >> fee;
			if (fee > 0)
				break;
			cout << "Please enter a integer number greater than 0" << endl;
		}
		PayForFilm payForFilm(serial, number, fee);
		bank->listPayForFilm.push_back(payForFilm);
	}
	entry->borrowedBy = number;
	entry->borrowed = true;
	cout << "Successfully issued the item " + to_string(serial) + " to " + number << endl;
}

void Catalogue::updateReturned() {
	int serial;
	cout << "Please enter a serial number you are going to find";
	cin >> serial;
	updateReturned(serial);
	cout << "Successfully updated the returned item" << endl;
}

void Catalogue::updateReturned(int serial) {
	Entry* entry = findItem(serial);
	entry->borrowedBy = "";
	entry->borrowed = false;
}

void Catalogue::saveData() {
	FILE* file;
	errno_t err = fopen_s(&file, "data.dat", "wb");
	if (err==0) {
		list<Entry*>::iterator it;
		int size = (int)mEntries.size();
		fwrite(&size, sizeof(int), 1, file);
		fwrite("\r\n", 2, 1, file);
		for (it = mEntries.begin(); it != mEntries.end(); ++it) {
			Entry* entry = *it;
			fwrite(&entry->serialNumber, sizeof(int), 1, file);
			int len = (int)entry->name.length();
			fwrite(&len, 1, 1, file);
			fwrite(entry->name.c_str(), strlen(entry->name.c_str()), 1, file);
			len = (int)entry->year.length();
			fwrite(&len, 1, 1, file);
			fwrite(entry->year.c_str(), strlen(entry->year.c_str()), 1, file);
			fwrite(&entry->borrowed, 1, 1, file);
			len = (int)entry->borrowedBy.length();
			fwrite(&len, 1, 1, file);
			fwrite(entry->borrowedBy.c_str(), strlen(entry->borrowedBy.c_str()), 1, file);
			fwrite(&entry->kind, 1, 1, file);
			if (entry->kind == MUSICALBUM) {
				len = (int)((MusicAlbum*)entry)->artist.length();
				fwrite(&len, 1, 1, file);
				fwrite(((MusicAlbum*)entry)->artist.c_str(), strlen(((MusicAlbum*)entry)->artist.c_str()), 1, file);
				len = (int)((MusicAlbum*)entry)->recordLabel.length();
				fwrite(&len, 1, 1, file);
				fwrite(((MusicAlbum*)entry)->recordLabel.c_str(), strlen(((MusicAlbum*)entry)->recordLabel.c_str()), 1, file);
			}
			else if (entry->kind == BOOK) {
				len = (int)((Book*)entry)->author.length();
				fwrite(&len, 1, 1, file);
				fwrite(((Book*)entry)->author.c_str(), strlen(((Book*)entry)->author.c_str()), 1, file);
				len = (int)((Book*)entry)->publisher.length();
				fwrite(&len, 1, 1, file);
				fwrite(((Book*)entry)->publisher.c_str(), strlen(((Book*)entry)->publisher.c_str()), 1, file);
				len = (int)((Book*)entry)->edition.length();
				fwrite(&len, 1, 1, file);
				fwrite(((Book*)entry)->edition.c_str(), strlen(((Book*)entry)->edition.c_str()), 1, file);
			}
			else {
				len = (int)((Film*)entry)->director.length();
				fwrite(&len, 1, 1, file);
				fwrite(((Film*)entry)->director.c_str(), strlen(((Film*)entry)->director.c_str()), 1, file);
				len = (int)((Film*)entry)->language.length();
				fwrite(&len, 1, 1, file);
				fwrite(((Film*)entry)->language.c_str(), strlen(((Film*)entry)->language.c_str()), 1, file);
			}
			fwrite("\r\n", 2, 1, file);
		}
		fclose(file);
		cout << "Successfully saved to data.dat" << endl;
	}
	else {
		cout << "The file data.dat was not opened" << endl;
	}
}

void Catalogue::readData() {
	FILE* file;
	errno_t err = fopen_s(&file, "data.dat", "rb");
	string line;
	if (err==0) {
		mEntries.clear();
		int size = 0;
		fread(&size, sizeof(int), 1, file);
		fseek(file, 2, SEEK_CUR);
		int i = 0;
		while (i < size) {
			i++;
			int offset = 0;
			int serial;
			fread(&serial, sizeof(int), 1, file);
			int nameLen = 0;
			fread(&nameLen, 1, 1, file);
			char cname[255];
			fread(cname, nameLen, 1, file);
			cname[nameLen] = 0;
			string name(cname);
			int yearLen = 0;
			fread(&yearLen, 1, 1, file);
			char cyear[255];
			fread(cyear, yearLen, 1, file);
			cyear[yearLen] = 0;
			string year(cyear);
			bool borrowed = false;
			fread(&borrowed, 1, 1, file);
			int borrowedByLen = 0;
			fread(&borrowedByLen, 1, 1, file);
			char cborrowedBy[255];
			fread(cborrowedBy, borrowedByLen, 1, file);
			cborrowedBy[borrowedByLen] = 0;
			string borrowedBy(cborrowedBy);
			char kind;
			fread(&kind, 1, 1, file);
			Entry* entry;
			if (kind == MUSICALBUM) {
				int artistLen = 0;
				fread(&artistLen, 1, 1, file);
				char cartist[255];
				fread(cartist, artistLen, 1, file);
				cartist[artistLen] = 0;
				string artist(cartist);
				int recordLabelLen = 0;
				fread(&recordLabelLen, 1, 1, file);
				char crecordLabel[255];
				fread(crecordLabel, recordLabelLen, 1, file);
				crecordLabel[recordLabelLen] = 0;
				string recordLabel(crecordLabel);
				entry = new MusicAlbum(serial, name, year, MUSICALBUM, borrowed, borrowedBy, artist, recordLabel);
			}
			else if(kind == BOOK) {
				int authorLen = 0;
				fread(&authorLen, 1, 1, file);
				char cauthor[255];
				fread(cauthor, authorLen, 1, file);
				cauthor[authorLen] = 0;
				string author(cauthor);
				int publisherLen = 0;
				fread(&publisherLen, 1, 1, file);
				char cpublisher[255];
				fread(cpublisher, publisherLen, 1, file);
				cpublisher[publisherLen] = 0;
				string publisher(cpublisher);
				int editionLen = 0;
				fread(&editionLen, 1, 1, file);
				char cedition[255];
				fread(cedition, editionLen, 1, file);
				cedition[editionLen] = 0;
				string edition(cedition);
				entry = new Book(serial, name, year, BOOK, borrowed, borrowedBy, author, publisher, edition);
			}
			else {
				int directorLen = 0;
				fread(&directorLen, 1, 1, file);
				char cdirector[255];
				fread(cdirector, directorLen, 1, file);
				cdirector[directorLen] = 0;
				string director(cdirector);
				int languageLen = 0;
				fread(&languageLen, 1, 1, file);
				char clanguage[255];
				fread(clanguage, languageLen, 1, file);
				clanguage[languageLen] = 0;
				string language(clanguage);
				entry = new Film(serial, name, year, FILM, borrowed, borrowedBy, director, language);

			}
			mEntries.push_back(entry);
			fseek(file, 2, SEEK_CUR);
		}
		fclose(file);
	}
	else {
		cout << "Cannot open data.dat file" << endl;
	}
}