#include <iostream>
#include <conio.h>
#include <cstdarg>
#include <windows.h>
#include <vector>
#include <sstream>



std::vector<std::string> f(char *, ...);

template <typename T>
std::string ToString(T tX) //������� �������������� ��������� ����� ������ � ��� string
{
    std::ostringstream oStream;
    oStream << tX;
    return oStream.str();
}

int main()
{
    std::vector<std::string> result;
    //char str[] = "iuLcpfd";
    char str[] = "ifLci";
    char c = 's';
    //result = f(str, 456356,90u,9238409380L,c,&c,.2326f,2.35848465);
    result = f(str, 546,9.363636f,9238409380L,c,123456); 
    /*
    � ������ ������ int, float(+-), long, char(����� ���������) ��������� �������� ���������,
    ������ � ����������� �������, ��� ������������ ��� ���� ������, ���������� ������������ �����
    */
    std::ostream_iterator<std::string> ositer(std::cout, ", ");
    std::copy(result.begin(), result.end(), ositer);
    return 0;
}

std::vector<std::string> f(char* str, ...)
{
    
    std::vector<std::string> result;

    char** pos = &str; //������������� ��������� �� ������ ����������, ���������� � �������
            //������ ��������� �������� �� ���, ��� ����������, ���������� � �������, ��������� � ����� �� �������
    int i = 0;
    pos+=1; //���������� �������� �� ��������� ���������� � �����
    while (str[i])
    {
        switch (str[i]) //� ����������� �� �����, ��������� ���������� ���������������� �������� �� ����
        {
            //���������� ���� ��������� ����� ����������
            int* pp_i;
            unsigned int* pp_u;
            long long* pp_L;
            char* pp_c;
            char** pp_p;
            double* pp_f; //���������� ���� float ��� �� ���������������� ��� ����, �� � ������ ������������ ��� �����,
                //��������� ��� �� �� ��������
            double* pp_d;


        case 'i':
           pp_i = (int*)pos; //���� �������� � ����
           std::cout << "adress: \t" << pp_i << "\tvalue = \t" << *pp_i << std::endl;
           result.push_back(ToString(*pp_i)); //�������� �������������� ��������������� �
                //string ���������� � ������ �����������
           ++pp_i; //�������� �� ���������
           pos = (char**)pp_i; //����� �������� ��������� � ���� (char**) ��� �� ��������� ��������� ���������� �� �����
           
            break;

        case 'u':
            pp_u = (unsigned int *)pos;
            std::cout << "adress: \t" << pp_u << "\tvalue = \t" << *pp_u << std::endl;
            result.push_back(ToString(*pp_u));
            ++pp_u;
            pos = (char**)pp_u;

            break;

        case 'L':
            pp_L = (long long*)pos;
            std::cout << "adress: \t" << pp_L << "\tvalue = \t" << *pp_L << std::endl;
            result.push_back(ToString(*pp_L));
            ++pp_L;
            pos = (char**)pp_L;
            break;

        case 'c':
            pp_c = (char*)pos;
            std::cout << "adress: \t" << pp_c << "\t\tvalue = \t" << *pp_c << std::endl;
            result.push_back(ToString(*pp_c));
            //++pp_c;
            pos = (char**)pp_c;
            ++pos; //��� ���������� ���� char ��������� �����. ����� �������� � ���� (char**) 
                //� ����� ��� ����������� pos. ����� �� ��������
            break;

        case 'p':
            pp_p = (char**)pos;
            std::cout << "adress: \t" << (int)(*pp_p) << "\tvalue = \t" << (int)(pp_p) << std::endl;
            result.push_back(ToString((int)(*pp_p)));
            
            ++pp_p;
            pos = (char**)pp_p;
            break;

        case 'f':
            pp_f = (double*)pos;
            std::cout << "adress: \t" << pp_f << "\tvalue = \t" << *pp_f << std::endl;
            result.push_back(ToString(*pp_f));
            ++pp_f;
            pos = (char**)pp_f;
            break;

        case 'd':
            pp_d = (double*)pos;
            std::cout << "adress: \t" << pp_d << "\tvalue = \t" << *pp_d << std::endl;
            result.push_back(ToString(*pp_d));
            ++pp_d;
            pos = (char**)pp_d;
            break;

        default:
            
            break;
        }

        ++i;

    }
    return result;
}