/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	int m_num, day, menu, total;
	int A_menu, B_menu;
	vector<int> A_cal;
	vector<int> B_cal;
	vector<int> total_A;
	vector<int> total_B;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
 		cin >> menu >> day; 
		
		m_num = menu;

		for(int i = 0; i < menu; i++)
		{
		cin >> A_menu;	
		A_cal.push_back(A_menu);
		}

		for(int j = 0; j < menu; j++)
                {
                cin >> B_menu;

                B_cal.push_back(B_menu);
                }	

		sort(A_cal.begin(), A_cal.end());
		sort(B_cal.begin(), B_cal.end());

		
		int max_min = 0;
		
		if(m_num == day){

			for(int k = 0; k < m_num; k++){
			
			total_A.push_back(A_cal[k] + B_cal[k]);
			total_B.push_back(A_cal[k] + B_cal[m_num-k-1]);
			
			}
			max_min = min(*max_element(total_A.begin(), total_A.end()),*max_element(total_B.begin(), total_B.end()));

			Answer = max_min;
		}
		else if(m_num > day){
			int tmp = m_num - day;
			
			for(int k = 0; k < m_num-tmp; k++){

                        total_A.push_back(A_cal[k] + B_cal[k]);
                        total_B.push_back(A_cal[k] + B_cal[m_num-tmp-k-1]);

			}

                        max_min = min(*max_element(total_A.begin(), total_A.end()),*max_element(total_B.begin(), total_B.end()));

			Answer = max_min;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;

		A_cal.clear();
		B_cal.clear();
		total_A.clear();
		total_B.clear();

	}

	return 0;//Your program should return 0 on normal termination.
}
