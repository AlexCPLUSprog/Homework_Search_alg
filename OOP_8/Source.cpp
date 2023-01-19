#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <tuple>


class DataManager { // создаем класс ДатаМенеджер
public:	// в паблике создаем:
	int mostSearchedKey() {	// функцию для нахождения часто встречаемого ключа из вектора интов, созданного в прайвате
		std::unordered_map<int, int> keyAmount;	// создаем мапу, в которой 1 инт - позиция числа в векторе(ну или сам ключ), а 2 инт - число повторений
		for (size_t i = 0; i < _keys.size(); i++) {	// создаем цикл, чтобы пройтись по вектору от начала до конца
			const auto& [it, isInserted] = keyAmount.insert({_keys[i], 1});	// создаем константную пару с автоматическим выбором типов данных, в которой указан итератор и булевое значение на проверку вставки
			if (!isInserted) {	// создаем условие, когда вставка не происходит(потому как уже есть такой ключ). При первой проверки нового числа, понятное дело, мы сюда даже не зайдем
				auto value = it->second; // создаем переменную с автоматическим выбором типов данных и говорим, что она является 2 элементом в паре мапы(ну то есть как раз тот счетчик)
				value++;	// мы его прибавляем,т.к раз вставка не произошла,то число уже встречалось,а значит плюсуем 1
				keyAmount[_keys[i]] = value;	// И это значение мы добавляем к этому ключу(к примеру нашей единице,которая будет равна уже не <1,1>, а <1,2> (Квадратные скобки гарантированно добавляют значения)
			}
		}
		// По истечению вектора и подсчета всех частовстречаемых значений, создаем пару, которая также принимает ключ и количество его повторений в векторе
		std::pair<int, int> keyBiggestValue = {0,0}; // указываем по умолчанию по нулям, затем создаем цикл, в котором начинаем проверять каждую мапу(или пару в мапе,не понял) из перечня (в нашем случае 5 штук их (на каждую цифру))
		for (std::unordered_map<int, int>::const_iterator it = keyAmount.begin(); it != keyAmount.end(); it++) {	
			if (keyBiggestValue.second < it->second) { // сравниваем доставаемый "счетчик"(второе значение мапы) у мапы с предыдущим значением и если он больше то:
				keyBiggestValue = std::make_pair(it->first, it->second); // делаем нашу переменную максимально используемой(создаем пару,где итератор указывает на обе части мапы и заменяем предыдущее значение, если оно было меньше по использованию)
			}
		}
		return keyBiggestValue.first; // затем уже возвращаем у этой пары первое значение, которое покажет цифру, которая больше всего встречается
	}

private:	// в прайвате создаем вектор интов под названием "_keys"
	std::vector<int> _keys = { 1,1,2,2,4,2,6,7,7,7,2 };
};

int divide(int a, int b) {
	if (b == 0) {
		throw "division by zero";
	}
	return a / b;
}

int errorFunc() {
	throw 0;
	return 1;
}

int main() {

	// тапл включается библиотекой <tuple>, может есть в <utility>
	/*std::tuple<int, std::string, double, float> t{1, "hey", 2.4, 2.3f};	// тапл как пара, но принимает больше двух значений
	const auto& [a, b, c, d] = t;
	std::cout << a << " " << b << " " << c << " " << d << '\n';

	std::cout << std::get<0>(t) << '\n';	// обращение к 0 элементу через функцию std::get

	std::vector <std::tuple<int, double, std::string>> vec;
	vec.push_back({ 55, 5.4, "bob" });
	vec.push_back({ 98, 6.8, "Alex" });

	for (size_t i = 0; i < vec.size(); i++) {
		const auto& [x, y, z] = vec[i];
		std::cout << x << " " << y << " " << z << '\n';
	}*/

	DataManager dm;		// создаем переменную
	std::cout << dm.mostSearchedKey() << '\n';	// используем функцию

	// try...catch
	/*int x = 10, y = 0;
	try {
		errorFunc() << '\n';
		std::cout << divide(x, y) << '\n';
	}
	catch (const char* msg) {
		std::cerr << msg << '\n';	// дискриптор cerr как дискриптор cout, но более заточен под ошибки
	}
	catch (int e) {
		std::cerr << e << '\n';
	}

	catch(...){	// catch all
		std::cerr << "Some exception has occured" << '\n';
	}*/

	/*std::vector<int> v{ 1,2,3 };
	try {
		int z = v.at(10);
	}
	catch (const std::out_of_range& e) {
		std::cerr << e.what() << '\n';
	}*/

}

