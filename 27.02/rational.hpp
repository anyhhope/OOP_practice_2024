

class Rational {
public:
    Rational() = default;

    //инкремент и декремент
    //++r
    Rational& operator++();
    //r++
    Rational operator++(int);
    //1) Скопировать текущий объект
    //2) текущий объект изменяем на единицу
    //3) Возвращаете скопированный неизмененный объект

    //int a = b++;

    //--r
    //r--

    //Геттер сеттер
    int getNum(){
        return this->num;
    };



private:
    //normalize() НОД
    //checker() значенатель из отрицательного в положительный
    int num{0};
    int denum{1}; //ограничение на 0 делить нельзя

};