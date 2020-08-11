/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int Answer;
int gcd(int,int);

int main(int argc, char** argv)
{
        int T, test_case;
        /*
           The freopen function below opens input.txt file in read only mode, and afterward,
           the program will read from input.txt file instead of standard(keyboard) input.
           To test your program, you may save input data in input.txt file,
           and use freopen function to read from the file when using cin function.
           You may remove the comment symbols(//) in the below statement and use it.
           Use #include<cstdio> or #include <stdio.h> to use the function in your program.
           But before submission, you must remove the freopen function or rewrite comment symbols(//).
         */

        // freopen("input.txt", "r", stdin);

        cin >> T;
        for(test_case = 0; test_case  < T; test_case++)
        {

                string str1;
                vector<int> val;
                int a,f,s;

                char *str_buf = new char[100];
                getline(cin, str1);
                strcpy(str_buf,str1.c_str());


                char *ptr = strtok(str_buf, "x-= ");
                while (ptr != NULL)
                {
                 
                 cout << ptr << endl;
                 a = atoi(ptr);
                 val.push_back(a);
                 ptr = strtok(NULL, "x-= ");
                 
                 delete [] str_buf;
                }

                s = val[1] + val[2];
                f = val[0];

                int up, down;
                up = s/gcd(s,f);
                down = f/gcd(s,f);
                /////////////////////////////////////////////////////////////////////////////////////////////
                /*
                   Implement your algorithm here.
                   The answer to the case will be stored in variable Answer.
                 */
                /////////////////////////////////////////////////////////////////////////////////////////////

                // Print the answer to standard output(screen).
                cout << "Case #" << test_case+1 << endl;
                cout << up << " / " << down << endl;
                
                

        }

        return 0;//Your program should return 0 on normal termination.
}

int gcd(int a, int b)
{
        int c;
        while (b != 0)
        {
                c = a % b;
                a = b;
                b = c;
        }
        return a;
}
