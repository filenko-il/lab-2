#include "notebook.h"
///Лабораторная работа №1 Создание класса, методов print, get и set, конструкторов без параметров, с параметрами, копирования

///для демонстрации работы применяем методы setModel, setMemory и setCPU в конструкторах
Notebook::Notebook()
{
    float numberbuffer = 0.0;
    std::string stringbuffer = "UNKNOWN";
    setModel( &numberbuffer );
    setMemory( &stringbuffer );
    setCPU( numberbuffer );
}
Notebook::Notebook( float const * const model )
{
    float numberbuffer = 0.0;
    std::string stringbuffer = "UNKNOWN";
    setModel( model );
    setMemory( &stringbuffer );
    setCPU( numberbuffer );
}
Notebook::Notebook( std::string const * const memory )
{
    float numberbuffer = 0.0;
    setModel( &numberbuffer );
    setMemory( memory );
    setCPU( numberbuffer );
}
Notebook::Notebook( int const CPU )
{
    float numberbuffer = 0.0;
    std::string stringbuffer = "UNKNOWN";
    setModel( &numberbuffer );
    setMemory( &stringbuffer );
    setCPU( CPU );
}
Notebook::Notebook( float const * const model, std::string const * const memory, int const CPU )
{
    setModel( model );
    setMemory( memory );
    setCPU( CPU );
}
Notebook::Notebook( Notebook const * const notebook )
{
    setModel( &(notebook->model) );
    setMemory( &(notebook->memory) );
    setCPU( notebook->CPU );
}


void Notebook::print() const
{
    std::cout << "\nNotebook model: " << model << "    Notebook memory: " << memory << "    Notebook CPU: " << CPU;
}


void Notebook::setModel( float const * const model )    ///Установлена защита от изменения значения Model ниже 0
{
    if( *model >= 0 )
    this->model = *model;
}
void Notebook::setMemory( std::string const * const memory )
{
    this->memory = *memory;
}
void Notebook::setCPU( int const CPU )                  ///Установлена защита от изменения значения CPU ниже 1
{
    if( CPU> 0 )
    this->CPU = CPU;
}
const float& Notebook::getModel() const         ///const float& - возвращаем неизменяемое значенеи по ссылке
{
    return model;
}
const std::string& Notebook::getMemory() const  ///const std::string& - возвращаем неизменяемое значенеи по ссылке
{
    return memory;
}
const int& Notebook::getCPU() const             ///const int& - возвращаем неизменяемое значенеи по ссылке
{
    return CPU;
}

///Лабораторная работа №2 Перегрузка операторов
///

Notebook& Notebook::operator ++()       ///Изменяет объект и возвращает ссылку на него
{
    this->model += 0.01;
    if(this->CPU)
    this->CPU *= 2;
    return *this;
}
Notebook Notebook::operator ++(int)     ///Изменяет объект и возвращает копию этого объекта до изменений
{
    Notebook notebook( this );
    this->model += 0.01;
    if(this->CPU)
    this->CPU *= 2;
    return &notebook;
}
Notebook& Notebook::operator --()       ///Изменяет объект и возвращает ссылку на него
{
    this->model -= 0.01;
    if(this->CPU > 1)
    this->CPU /= 2;
    return *this;
}
Notebook Notebook::operator --(int)     ///Изменяет объект и возвращает копию этого объекта до изменений
{
    Notebook notebook( this );
    this->model -= 0.01;
    if(this->CPU > 1)
    this->CPU /= 2;
    return &notebook;
}

void Notebook::operator =( Notebook const * const notebook )        ///присваивает полям левостоящего объекта соответсвующие значения полей правостоящего объекта
{
    this->model = notebook->model;
    this->memory = notebook->memory;
    this->CPU = notebook->CPU;
}

bool Notebook::operator ==( Notebook const * const notebook ) const ///проверяем каждое поле по очереди на неравенство
{                                                                   ///как только неравенство подтверждается - метод возвращает false
    if( this->model != notebook->model )                            ///иначе в конце возвращается результат проверки на равентсво полей CPU
        return false;
    if( this->memory != notebook->memory )
        return false;
    return ( this->CPU == notebook->CPU );
}
bool Notebook::operator !=( Notebook const * const notebook ) const ///проверяем каждое поле по очереди на неравенство
{                                                                   ///как только неравенство подтверждается - метод возвращает true,
    if( this->model != notebook->model )                            ///иначе в конце возвращается результат проверки на неравентсво полей CPU
        return true;
    if( this->memory != notebook->memory )
        return true;
    return ( this->CPU != notebook->CPU );
}
bool Notebook::operator >( Notebook const * const notebook ) const  ///проверяем каждое поле по очереди на меньше(если подтверждается - возвращаем false),
{                                                                   ///затем на больше(если подтверждается - возвращаем true),
    if( this->model < notebook->model )                             ///иначе в конце возвращается результат проверки на больше полей CPU
        return false;
    if( this->model > notebook->model )
        return true;
    if( this->memory < notebook->memory )
        return false;
    if( this->memory > notebook->memory )
        return true;
    return ( this->CPU > notebook->CPU );
}
bool Notebook::operator <( Notebook const * const notebook ) const  ///проверяем каждое поле по очереди на больше(если подтверждается - возвращаем false),
{                                                                   ///затем на меньше(если подтверждается - возвращаем true),
    if( this->model > notebook->model )                             ///иначе в конце возвращается результат проверки на меньше полей CPU
        return false;
    if( this->model < notebook->model )
        return true;
    if( this->memory > notebook->memory )
        return false;
    if( this->memory < notebook->memory )
        return true;
    return ( this->CPU < notebook->CPU );
}
bool Notebook::operator >=( Notebook const * const notebook ) const ///проверяем каждое поле по очереди на меньше(если подтверждается - возвращаем false),
{                                                                   ///затем на больше(если подтверждается - возвращаем true),
    if( this->model < notebook->model )                             ///иначе в конце возвращается результат проверки на больше-равно полей CPU
        return false;
    if( this->model > notebook->model )
        return true;
    if( this->memory < notebook->memory )
        return false;
    if( this->memory > notebook->memory )
        return true;
    return ( this->CPU >= notebook->CPU );
}
bool Notebook::operator <=( Notebook const * const notebook ) const ///проверяем каждое поле по очереди на больше(если подтверждается - возвращаем false),
{                                                                   ///затем на меньше(если подтверждается - возвращаем true),
    if( this->model > notebook->model )                             ///иначе в конце возвращается результат проверки на меньше-равно полей CPU
        return false;
    if( this->model < notebook->model )
        return true;
    if( this->memory > notebook->memory )
        return false;
    if( this->memory < notebook->memory )
        return true;
    return ( this->CPU <= notebook->CPU );
}


std::ostream& operator << (std::ostream &out, Notebook const * const notebook)  ///передаём в поток данные, которые хотели бы вывести и возвращаем ссылку на этот поток
{
    out << "\nNotebook model: " << notebook->model << "    Notebook memory: " << notebook->memory << "    Notebook CPU: " << notebook->CPU;
    return out;
}
std::istream& operator >> (std::istream &in, Notebook * notebook)   ///извлекаем из потока данные по очереди и присваиваем соответсвующие очереди значения полям
{                                                                   ///возвращаем ссылку на этот поток      || Установлена защита для CPU(>0) и Model(>=0)
    float model;
    in >> model;
    if( model >= 0 )
    notebook->model = model;
    in >> notebook->memory;
    int CPU;
    in >> CPU;
    if( CPU > 0 )
    notebook->CPU = CPU;
    return in;
}
