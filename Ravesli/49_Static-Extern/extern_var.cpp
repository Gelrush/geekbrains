
int g_n(3); // неконстантные глобальные переменные имеют внешнюю связь по умолчанию
static const double g_gravity(9.8); // для константы не возможно применить предварительное объявление

// Эта функция определена как static и может быть использована только внутри этого файла.
// Попытки доступа к ней через прототип функции будут безуспешными
static int add(int a, int b)
{
    return a + b;
}

namespace Constants
{
    // Фактические глобальные переменные
    extern const double pi(3.14159);
    extern const double avogadro(6.0221413e23);
    extern const double my_gravity(9.2);
}
