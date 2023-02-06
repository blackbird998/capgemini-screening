#include <iostream>
#include <vector>
#include <string.h>

#include "phone.h"

//void addPhone(std::vector<Phone> _phoneDatabase, std::string _brandName, std::string _modelName, std::string _formFactor, unsigned int _yearOfIssue, float _screenSize, float _price) {
//	
//	Phone* newPhone = new Phone(_brandName, _modelName, _formFactor, _yearOfIssue, _screenSize, _price);
//	//_phoneDatabase.push_back(newPhone);
//
//}
struct tmpPhoneData
{
	std::string tmpBrandName = "";
	std::string tmpModelName = "";
	std::string tmpFormFactor = "";
	unsigned int tmpYearOfIssue = 0;
	float tmpScreenSize = 0.0f;
	float tmpPrice = 0.0f;
};
void interface(std::vector<Phone*> phoneDatabase);
void showByBrand(std::vector<Phone*> phoneDatabase, std::string brandName);
void showByFormFactorAndScreenSize(std::vector<Phone*> phoneDatabase, std::string formFactor, float screenSize);

void showDatabase(std::vector<Phone*> phoneDatabase) {
	int interator = 0;
	for (Phone* i : phoneDatabase) {
		std::cout << "Index: " << interator++ << "\n";
		std::cout << "Brand name: ";
		std::cout << i->getBrandName()<< "\n";
		std::cout << "Model name: ";
		std::cout << i->getModelName() << "\n";
		std::cout << "Form Factor ";
		std::cout << i->getFormFactor() << "\n";
		std::cout << "Year of issue: ";
		std::cout << i->getYearOfIssue() << "\n";
		std::cout << "Screen size (in): ";
		std::cout << i->getScreenSize() << "\n";
		std::cout << "Price: ";
		std::cout << i->getPrice() << "\n\n";
	}
}
void showByBrand(std::vector<Phone*> phoneDatabase, std::string brandName) {
	int interator = 0;
	for (Phone* i : phoneDatabase) {
		if (i->getBrandName() == brandName) {
			std::cout << "\nIndex: " << interator++ << "\n";
			std::cout << "Brand name: ";
			std::cout << i->getBrandName() << "\n";
			std::cout << "Model name: ";
			std::cout << i->getModelName() << "\n";
			std::cout << "Form Factor ";
			std::cout << i->getFormFactor() << "\n";
			std::cout << "Year of issue: ";
			std::cout << i->getYearOfIssue() << "\n";
			std::cout << "Screen size (in): ";
			std::cout << i->getScreenSize() << "\n";
			std::cout << "Price: ";
			std::cout << i->getPrice() << "\n\n";
		}	
	}
}
void showByFormFactorAndScreenSize(std::vector<Phone*> phoneDatabase, std::string formFactor, float screenSize) {
	int interator = 0;
	for (Phone* i : phoneDatabase) {
		if (i->getFormFactor() == formFactor && i->getScreenSize() == screenSize) {
			std::cout << "\nIndex: " << interator++ << "\n";
			std::cout << "Brand name: ";
			std::cout << i->getBrandName() << "\n";
			std::cout << "Model name: ";
			std::cout << i->getModelName() << "\n";
			std::cout << "Form Factor ";
			std::cout << i->getFormFactor() << "\n";
			std::cout << "Year of issue: ";
			std::cout << i->getYearOfIssue() << "\n";
			std::cout << "Screen size (in): ";
			std::cout << i->getScreenSize() << "\n";
			std::cout << "Price: ";
			std::cout << i->getPrice() << "\n\n";
		}
	}
}
void showPopularBrand() {

}
void showPopularScreenSize() {

}
void interface(std::vector<Phone*> phoneDatabase) {
	tmpPhoneData tmpPhoneData;
	int index;
	int switch_on;
	std::string brandName;
	std::string formFactor;
	float screenSize;

	
	while(true){
		std::cout << "Choose action : \n1. Add phone\n2. Delete phone\n3. See reports\n4. Exit\nOption: ";
		std::cin >> switch_on;

		switch (switch_on)
		{
		case 1:
			std::cout << "Brand name: ";
			std::cin >> tmpPhoneData.tmpBrandName;
			std::cout << "Model name: ";
			std::cin >> tmpPhoneData.tmpModelName;
			std::cout << "Form Factor ";
			std::cin >> tmpPhoneData.tmpFormFactor;
			std::cout << "Year of issue: ";
			std::cin >> tmpPhoneData.tmpYearOfIssue;
			std::cout << "Screen size (in): ";
			std::cin >> tmpPhoneData.tmpScreenSize;
			std::cout << "Price: ";
			std::cin >> tmpPhoneData.tmpPrice;

			phoneDatabase.push_back(new Phone(tmpPhoneData.tmpBrandName, tmpPhoneData.tmpModelName, tmpPhoneData.tmpFormFactor, tmpPhoneData.tmpYearOfIssue, tmpPhoneData.tmpScreenSize, tmpPhoneData.tmpPrice));
			showDatabase(phoneDatabase);

			break;
		case 2:
			showDatabase(phoneDatabase);
			std::cout << "Enter index of the phone to delete: ";
			std::cin >> index;
			phoneDatabase.erase(phoneDatabase.begin() + index);
			showDatabase(phoneDatabase);
			break;
		case 3:
			std::cout << "Choose report:\n1. Show all phones by the same brand\n2. Show all phones of a given form factor and screen size\n 3. Show the name of the brand with the maximum quantity of the phones\n 4. Show TOP-3 screen sizes";
			std::cin >> switch_on;
			switch (switch_on)
			{
			case 1:
				std::cout << "Enter brand name: ";
				std::cin >> brandName;
				showByBrand(phoneDatabase, brandName);
				break;
			case 2:
				std::cout << "Enter form factor: ";
				std::cin >> formFactor;
				std::cout << "Enter screen size: ";
				std::cin >> screenSize;
				showByFormFactorAndScreenSize(phoneDatabase, formFactor, screenSize);
				break;
			case 3:
			case 4:
			default:
				std::cout << "Wrong option!\n";
				break;
			}

			break;
		case 4:
			std::cout << "\nProgram will close now.";
			return;

			break;

		default:
			break;
		}
	}
}

int main()
{
    std::cout << "Hello World!\n";
	
	
	
	std::vector<Phone*> phoneDatabase;
	interface(phoneDatabase);

	
	

}


