#include <functional>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <unordered_map>
#include <utility>
#include <unistd.h>
using namespace std;


int generate_random(int min, int max)
{
    return rand()%(max + 1 - min) + min;   
}

void number_generator(int num, int* arry)
{
    
    for(int i = 0; i < 3; i++)
    {
        int random = generate_random(num-10, num+10);
        if(random == num)
        {
            while(random == num)
            {
                random = generate_random(num-10, num+10);
            }
        }
        *arry = random;
        arry += 1;
    }
}

string equation_generator(int num1, int num2, int* arry, int* ans)
{
    unordered_map<int, string> dict;
    int num;
    string a, b;
    num = generate_random(1, 3);
    a = to_string(num1);
    b = to_string(num2);
    dict.insert(make_pair(1, a + " + " + b + " = "));
    dict.insert(make_pair(2, a + " - " + b + " = "));
    dict.insert(make_pair(3, a + " * " + b + " = "));
    switch (num) 
    {
        case 1:
            *ans =  num1 + num2;
            break;     
        case 2:
            *ans =  num1 - num2;
            break;
        case 3:
            *ans =  num1 * num2;
            break;
    }

    cout << " ans " << *ans << endl;
    number_generator(*ans, arry); 
    return dict[num];
}

int main()
{
    int ans;
    int* ptn_ans = &ans;
    int arry[3];
    srand(time(NULL));
    int num1 = rand() % 50 + 10;
    int num2 = rand() % 50 + 1;
    cout << " num1 " << num1 << " num2 " << num2 << endl;
    cout << equation_generator(num1, num2, arry, ptn_ans) << endl;
    cout << *ptn_ans << endl;
    for(int i = 0; i < 3; i++)
    {
        cout << arry[i] << endl;
    }
}