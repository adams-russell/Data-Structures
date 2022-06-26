#include <vector>
#include <iostream>
#include <cmath>

int i, total, size, angle;
std::vector<int> vec1,vec2,product;

int vecMultiply(std::vector<int>& vec1, std::vector<int>& vec2, std::vector<int>& product, int total, int angle);
void fillVec(std::vector<int>& vec, int size);

int main() {
	//Get angle
	std::cout << "Input vector angle: " << std::endl;
	std::cin >> angle;


	//Get size for vectors, which must be the same
	std::cout << "How many items in each vector?" << std::endl;
	std::cin >> size;
	vec1.resize(size);
	vec2.resize(size);
	product.resize(size);
	
	//Fill each vector
	fillVec(vec1, size);
	fillVec(vec2, size);

	//Multiply vectors
	std::cout << vecMultiply(vec1, vec2, product, total, angle);
}

int vecMultiply(std::vector<int>& vec1, std::vector<int>& vec2, std::vector<int>& product, int total, int angle) {
	for (i = 0; i < vec1.size(); i++) {
		product.at(i) = vec1.at(i) * vec2.at(i);
	}
	for (i = 0; i < product.size(); i++) {
		std::cout << product[i];
		total += product.at(i);
	}
	return total * cos(angle);
}

void fillVec(std::vector<int>& vec,int size) {
	int num;
	for (i = 0; i < size; i++) {
		std::cin >> num;
		vec.at(i) = num;
	}
}
