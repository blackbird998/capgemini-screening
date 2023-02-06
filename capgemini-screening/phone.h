#pragma once


#include <string>
#include <vector>

class Phone
{
private:
	std::string brandName;
	std::string modelName;
	std::string formFactor;
	unsigned int yearOfIssue;
	float screenSize;
	float price;
public:
	Phone();
	Phone(std::string _brandName, std::string _modelName, std::string _formFactor, unsigned int _yearOfIssue, float _screenSize, float _price);
	~Phone();


	std::string getBrandName() { return brandName; }
	std::string getModelName() { return modelName; }
	std::string getFormFactor() { return formFactor; }
	unsigned int getYearOfIssue() { return yearOfIssue; }
	float getScreenSize() { return screenSize; }
	float getPrice() { return price; }
	

};

