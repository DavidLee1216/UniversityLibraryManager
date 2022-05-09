#include "pch.h"
#include "CppUnitTest.h"
#include "../libraryManager/items.h";
#include "../libraryManager/items.cpp";

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestProject
{
	TEST_CLASS(TestProject)
	{
	public:
		
		TEST_METHOD(TestAddBookItem)
		{
			Catalogue catalog;
			string name = "gone with wind";
			string year = "1234";
			string author = "scalet";
			string publisher = "usa";
			string edition = "first";
			catalog.addBookItem(name, year, author, publisher, edition);
			Assert::AreEqual(catalog.mEntries.back()->name, name);
		}
		TEST_METHOD(TestIssueUpdateReturn) {
			Catalogue catalog;
			string name = "gone with wind";
			string year = "1234";
			string author = "scalet";
			string publisher = "usa";
			string edition = "first";
			catalog.addBookItem(name, year, author, publisher, edition);
			Bank* bank = new Bank();
			catalog.issueItem(1, "tester", bank);
			Assert::AreEqual(catalog.mEntries.front()->borrowed, true);
			catalog.updateReturned(1);
			Assert::AreEqual(catalog.mEntries.front()->borrowed, false);
			delete bank;
		}
	};
}
