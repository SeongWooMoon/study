/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	int n, k, A,B, max_k,sum_a,sum_b,l;
	int win, lose, ck, d_win, d_lose;
	vector<int> card_A;
	vector<int> card_B;
	unordered_map<int, int> umap;
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
		sum_a = 0;
		sum_b = 0;

		cin >> n >> k;

		for(int i = 0; i < n ; i++){
		
			cin >> A;
			card_A.push_back(A);
			//sum_a += A;
		}
		for(int j = 0; j < n ; j++){

                        cin >> B;
                        card_A.push_back(B);
			//sum_b += B;
                }

        for(auto tmp: card_A)
            umap[tmp]++;

		ck = k/2+1;

		//cout << "ck " << umap[ck] << endl;

		for(int i = 1 ; i < ck+1 ; i++)
                l += umap[i]*i;

		if(umap[k] >= 3){
			win = 5;
			lose = 4;
		}
		else if(umap[k] > 1 && k <= l){
			win = 7;
                        lose = 2;
		}
		else{
			win = 6;
			lose = 3;
		}

		if(n == 1){
			win = 2;
                        lose = 2;
		}

		
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << win << " " << lose << endl;

		card_A.clear();
		card_B.clear();
		umap.clear();
	}

	return 0;//Your program should return 0 on normal termination.
}
