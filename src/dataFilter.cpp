#include <dataContanier.h>






int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<dataObject> myData;
    dataObject a1("Кривой", { -37.23, 13.44 }, "Человек", createTime(29, 9, 2023));
    dataObject a2("Магазин", { 0.163, 2.119 }, "Здание", createTime(28, 9, 2023));
    dataObject a3("Лада", { 118.3, 982.041 }, "Машина", createTime(27, 9, 2023));
    dataObject a4("БМВ", { 26.13, 13.44 }, "Машина", createTime(1, 9, 2023));
    dataObject a5("Лед", { 100.23, 13.44 }, "Материал", createTime(24, 9, 2023));
    dataObject a6("Ель", { 15.73, -23.44 }, "Дерево", createTime(9, 2, 2023));
    dataObject a7("Егор", { 23.23, -13.44 }, "Человек", createTime(1, 6, 2016));
    dataObject a8("Макс", { 70.23, 100.44 }, "Человек", createTime(2, 1, 1999));
    myData.push_back(a1);
    myData.push_back(a2);
    myData.push_back(a3);
    myData.push_back(a4);
    myData.push_back(a5);
    myData.push_back(a6);
    myData.push_back(a7);
    myData.push_back(a8);
    dataContainer bank("bank.txt");
    bank.showObjects();
   /* auto a = groupType(bank,2);
    for (auto it : a) {
        std::cout << it.first << std::endl;
        it.second.showObjects();
    }*/
    std::cout << std::endl;
    system("pause");
}



