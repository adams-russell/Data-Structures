#include "omp.h"
#include <iostream>
#include <vector>

int i, total, size, angle;
std::vector<int> vec1, vec2, product;

int vecMultiply(std::vector<int>& vec1, std::vector<int>& vec2, std::vector<int>& product, int total, int angle, int size);
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
	std::cout << vecMultiply(vec1, vec2, product, total, angle, size);

	system("pause");
	return 0;
}

int vecMultiply(std::vector<int>& vec1, std::vector<int>& vec2, std::vector<int>& product, int total, int angle, int size) {
	omp_lock_t writelock;
	omp_init_lock(&writelock);

	#pragma omp parallel for shared(size)
	for (i = 0; i < size; i++) {
		omp_set_lock(&writelock); //Locks guarantee atomic data updates
		product.at(i) = vec1.at(i) * vec2.at(i);
		omp_unset_lock(&writelock);
	}
	omp_destroy_lock(&writelock);

	#pragma omp parallel for shared(size)
	for (i = 0; i < size; i++) {
	 #pragma omp atomic //Atomic synchronizes data so it cannot be read or written concurrently
		std::cout << product[i];
		total += product.at(i);
	}
	return total * cos(angle);
}

void fillVec(std::vector<int>& vec, int size) {
	int num;
	for (i = 0; i < size; i++) {
		std::cin >> num;
		vec.at(i) = num;
	}
}
