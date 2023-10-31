/*
	Условие
	Вам требуется написать функцию со следующим заголовком:

std::vector<std::string> Split(const std::string& str, char delimiter);
или
auto Split(const std::string& str, char delimiter) -> std::vector<std::string> 

	Функция должна вернуть вектор строк, полученный разбиением строки str на части по указанному символу-разделителю delimiter.
	Если разделитель встретился в начале или в конце строки str, то в начале (соответственно, в конце) вектора с результатом должна быть пустая строка.
	Если два разделителя встретились рядом, то пустая строка между ними тоже должна попасть в ответ. Для пустой строки надо вернуть пустой вектор.

	Например, Split("What_is_your_name?", '_') должна вернуть вектор из строк What, is, your иname?.
*/

/*
	Условие
	Вам требуется написать функцию Join со следующим заголовком:

std::string Join(const std::vector<std::string>& tokens, char delimiter);
или
auto Join(std::vector<std::string>& tokens, char delim) -> std::string;

	Функция должна вернуть строку, полученную склейкой элементов вектора через указанный разделитель.

	Например, Join({"What", "is", "your", "name?"}, '_') должна вернуть строку "What_is_your_name?".

	Примечание
	Если вектор tokens пустой, то функция должна вернуть пустую строку. Если в векторе tokens ровно один элемент, то он и должен вернуться в ответе.
*/
#include <string>
#include <vector>
#include "class_task.h"
 
auto Join(std::vector<std::string>& tokens, char delim) -> std::string 
{
    std::string result;
	auto it = tokens.begin();
    for (;it < tokens.end()-1 ; it++){
        result.append(*it);
		result.push_back(delim);
    }
	result.append(*it);
	return result;
}

auto Split(const std::string& str, char delimiter) -> std::vector<std::string> 
{
    std::vector<std::string> result;
	std::string buff;
	for (auto symbool : str) {
		if (symbool != delimiter) {
			buff.push_back(symbool);
		}
		else {
			result.push_back(buff);
			buff.clear();
		}
	}
	if (!buff.empty())
		result.push_back(buff);
	return result;
}