/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <unordered_map>
#include <vector>


using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	int N, N_size;
	vector<int> n_vec;
	unordered_map<int,int> value_to_count;

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
	int num;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		cin >> N;

		for(N_size = 0; N_size < N; N_size++)
		{
		cin >> num;
		n_vec.push_back(num);
		}

			for (auto a : n_vec) {
            		value_to_count[a]++;     // 각 value에 해당하는 count 값을 key에 저장해둔다.
        		}
				int xor_num = 0;			
        			for (const pair<int,int>& p : value_to_count) {
            			const int value = p.first;
            			const int hitcount = p.second;
				
				if(hitcount%2 == 1)	
				xor_num = xor_num ^ value;
				}

		Answer = xor_num;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
