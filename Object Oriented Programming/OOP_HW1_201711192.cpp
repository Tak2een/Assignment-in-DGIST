// OOP_HW1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// function for Problem 1
int count_odd_nums(const unsigned int* array, int size) {
	int number{ 0 };
	for (int i = 0; i < size; ++i)
		if (array[i] % 2 == 1) { // find odd number conditions
			++number; // counting the number of odd number
		}
	return  number;
}

// function for Problem 2
int normalize(double* array, int size) {
	double max_value = array[0]; // set the maximum value
	double min_value = array[0]; // set the minimum value
	for (int i = 0; i < size; ++i) {
		if (array[i] < min_value) { // find minimum value for each array
		min_value = array[i];
			}
		else if (array[i] > max_value) {  // find maximum value for each array
			max_value = array[i];
			}
		}
	for (int j = 0; j < size; ++j) {
		array[j] = (array[j] - min_value) / (max_value - min_value); // normalized for each cell
	}
	return 0;
}

// function for Problem 3
int find_nth(const int* array, int size, int n) {
	int temp;
	int* arra = (int*)malloc(sizeof(int)*size); // allocate the memory that has same size of array
	for (int i = 0; i < size; ++i) { // append elements in array to created array
		arra[i] = array[i];
	}
	for (int i = 0; i < size - 1 ; ++i) {  // excuting selection sort algorithm
		for (int j = i + 1; j < size; ++j) {
			if (arra[i] < arra[j]) { // sorting descending order
				temp = arra[j]; // swap index i and index j
				arra[j] = arra[i];
				arra[i] = temp;
			}
		}
	}
	if (n > 0 && n <= size)
		return arra[n-1]; // nth largest element in n-1 index array
	else
		return 0;


}

// function for Problem 4
int count_pattern(const char* str, const char* pattern) {
	int pattern_length = 0; 
	int string_length = 0; 
	
	for (int i = 0; pattern[i] != 0; ++i) { // calculate the pattern length
		++pattern_length;
	}

	for (int j = 0; str[j] != 0; ++j) { // calculate the string length that given 

		++string_length;
	}

	int search_range = string_length - pattern_length + 1; // define the searching_range
	int frequency = 0; // initialize counting value

	for (int k = 0; k < search_range; ++k) { // k is index of string for 0 to searching range
		int a = 0; // pattern 
		for (int m = 0; m < pattern_length; ++m) { // counting if each string index are same with pattern  
			if (str[k + m] == pattern[m])
				a += 1;
		if (a == pattern_length) // pattern length == counting a
			frequency += 1;
		}
	}

	return frequency;
}

// function for Problem 5
char* create_shortest_palindrome(const char* src, char* dst) {
	int size = 0; // count string's length

	for (int i = 0; src[i] != 0; ++i) {
		++size;
	}

	for (int j = 0; j < size + 1; ++j) { // first, dst's index for 0 to size, dst = src
		dst[j] = src[j];
	}

	int left = 0; // compare the pattern for index size - 1
	int right = size - 1;

	while (right > left) {
		if (dst[left] == dst[right])
			--right;
		else if (dst[left] != dst[right] && right != size - 1)
			++right;
		++left;
	}

	int pattern = 0; // find pattern for last index of string
	if (left == right)
		pattern = (size - 1 - right) * 2 + 1;
	else
		pattern = (size - 1 - right) * 2;

	for (int i = 0; i < size - pattern + 1; ++i) {
		dst[size + i] = dst[size - pattern - i - 1]; // then, extend the string
	}
	return dst;
}



int main() {
	using std::cout;
	using std::endl;
	
	// Problem 1
	unsigned int a[] = { 0, 1, 2, 3, 5 };
	std::size_t size_a = sizeof(a) / sizeof(int);
	cout << "Problem 1: " << count_odd_nums(a, (int)size_a) << endl;
	
	// Problem 2
	double b[] = { 1, 2, 2, 3, 2 };
	std::size_t size_b = sizeof(b) / sizeof(double);
	normalize(b, (int)size_b);
	cout << "Problem 2: ";
	for (unsigned int i = 0; i < size_b; ++i) {
		cout << b[i] << " ";
	}
	cout << endl;

	// Problem 3
	int c[] = { 1, 5, 3, 2, 4 };
	cout << "Problem 3: " << find_nth(c, sizeof(c) / sizeof(int), 3) << endl;

	// Problem 4
	cout << "Problem 4: ex1) " << count_pattern("AABBBBAA", "AA") << endl;
	cout << "Problem 4: ex2) " << count_pattern("AABBBBAA", "BB") << endl;

	// Problem 5
	char d[100] = { 0 };
	cout << "Problem 5: ex1) " << create_shortest_palindrome("ABCD", d) << endl;
	cout << "Problem 5: ex2) " << create_shortest_palindrome("AABBCC", d) << endl;
	return 0;



}



// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
