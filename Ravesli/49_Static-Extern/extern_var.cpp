
int g_n(3); // ������������� ���������� ���������� ����� ������� ����� �� ���������
static const double g_gravity(9.8); // ��� ��������� �� �������� ��������� ��������������� ����������

// ��� ������� ���������� ��� static � ����� ���� ������������ ������ ������ ����� �����.
// ������� ������� � ��� ����� �������� ������� ����� ������������
static int add(int a, int b)
{
    return a + b;
}

namespace Constants
{
    // ����������� ���������� ����������
    extern const double pi(3.14159);
    extern const double avogadro(6.0221413e23);
    extern const double my_gravity(9.2);
}
